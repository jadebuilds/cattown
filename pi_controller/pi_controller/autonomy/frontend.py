"""
Serves a frontend using nicegui that allows us to run the
"""

from typing import Optional
import logging
import queue
import threading

from ..ccv import CatVision
from .backend import Game

import base64
import signal
import time

import cv2
import numpy as np
from fastapi import Response

from nicegui import Client, app, core, run, ui


# --------------------------------------------------------------------------- #
# Set up logging text area
# --------------------------------------------------------------------------- #

# Create a queue to hold log records
log_queue = queue.Queue()


# Define a custom logging handler that puts log records into the queue
class UiLogHandler(logging.Handler):
    def emit(self, record):
        log_entry = self.format(record)
        log_text_area.push(log_entry)


# Set up the logger
logger = logging.getLogger("NiceGUIApp")
logger.setLevel(logging.DEBUG)
log_handler = UiLogHandler()
log_handler.setFormatter(
    logging.Formatter("%(asctime)s [%(levelname)s] %(module)s: %(message)s")
)
logger.addHandler(log_handler)

# Set up the NiceGUI interface
log_text_area = ui.log(max_lines=20).classes("w-full h-100")

# --------------------------------------------------------------------------- #
# Control buttons
# --------------------------------------------------------------------------- #

game: Optional[Game] = None


def start():
    logger.info("< start pressed >")
    # global game
    # if not game:
    #     logger.info("Starting the game!")
    #     game = Game()
    #     game.run()


def stop():
    logger.info("< stop pressed >")
    # global game
    # if game:
    #     logger.info("Stopping the game...")
    #     game.stop()


# Example buttons to generate log entries
ui.button("Start!", on_click=start)
ui.button("Stop", on_click=stop)


# --------------------------------------------------------------------------- #
# Start computer vision
# --------------------------------------------------------------------------- #


# ccv = CatVision()
# ccv.start()


# def thread_do_print():
#     logger.info(ccv.find_cats())


# --------------------------------------------------------------------------- #
# Set up video streaming
# --------------------------------------------------------------------------- #

# Borrowed shamelessly from the example:
# https://github.com/zauberzeug/nicegui/blob/main/examples/opencv_webcam/main.py

# In case you don't have a webcam, this will provide a black placeholder image.
black_1px = "iVBORw0KGgoAAAANSUhEUgAAAAEAAAABCAYAAAAfFcSJAAAAAXNSR0IArs4c6QAAAA1JREFUGFdjYGBg+A8AAQQBAHAgZQsAAAAASUVORK5CYII="
placeholder = Response(
    content=base64.b64decode(black_1px.encode("ascii")), media_type="image/png"
)


def convert(frame: np.ndarray) -> bytes:
    """Converts a frame from OpenCV to a JPEG image.

    This is a free function (not in a class or inner-function),
    to allow run.cpu_bound to pickle it and send it to a separate process.
    """
    _, imencode_image = cv2.imencode(".jpg", frame)
    return imencode_image.tobytes()


def setup() -> None:
    # OpenCV is used to access the webcam.
    video_capture = cv2.VideoCapture(0)

    @app.get("/video/frame")
    # Thanks to FastAPI's `app.get` it is easy to create a web route which always provides the latest image from OpenCV.
    async def grab_video_frame() -> Response:
        if not video_capture.isOpened():
            return placeholder
        # The `video_capture.read` call is a blocking function.
        # So we run it in a separate thread (default executor) to avoid blocking the event loop.
        _, frame = await run.io_bound(video_capture.read)
        if frame is None:
            return placeholder
        # `convert` is a CPU-intensive function, so we run it in a separate process to avoid blocking the event loop and GIL.
        jpeg = await run.cpu_bound(convert, frame)
        return Response(content=jpeg, media_type="image/jpeg")

    # For non-flickering image updates and automatic bandwidth adaptation an interactive image is much better than `ui.image()`.
    video_image = ui.interactive_image().classes("w-full h-full")
    # A timer constantly updates the source of the image.
    # Because data from same paths is cached by the browser,
    # we must force an update by adding the current timestamp to the source.
    ui.timer(
        interval=0.1,
        callback=lambda: video_image.set_source(f"/video/frame?{time.time()}"),
    )

    async def disconnect() -> None:
        """Disconnect all clients from current running server."""
        for client_id in Client.instances:
            await core.sio.disconnect(client_id)

    def handle_sigint(signum, frame) -> None:
        # `disconnect` is async, so it must be called from the event loop; we use `ui.timer` to do so.
        ui.timer(0.1, disconnect, once=True)
        # Delay the default handler to allow the disconnect to complete.
        ui.timer(1, lambda: signal.default_int_handler(signum, frame), once=True)

    async def cleanup() -> None:
        # This prevents ugly stack traces when auto-reloading on code change,
        # because otherwise disconnected clients try to reconnect to the newly started server.
        await disconnect()
        # Release the webcam hardware so it can be used by other applications again.
        video_capture.release()

    app.on_shutdown(cleanup)
    # We also need to disconnect clients when the app is stopped with Ctrl+C,
    # because otherwise they will keep requesting images which lead to unfinished subprocesses blocking the shutdown.
    signal.signal(signal.SIGINT, handle_sigint)


# All the setup is only done when the server starts. This avoids the webcam being accessed
# by the auto-reload main process (see https://github.com/zauberzeug/nicegui/discussions/2321).
app.on_startup(setup)

ui.run()
