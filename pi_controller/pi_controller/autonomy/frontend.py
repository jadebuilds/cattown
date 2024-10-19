"""
Serves a frontend using nicegui that allows us to run the
"""

import logging
from nicegui import ui
import queue
import threading

from ..ccv import CatVision

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

# Example buttons to generate log entries
ui.button("Start!", on_click=lambda: logger.info("Starting autonomous thingie"))
ui.button("Stop", on_click=lambda: logger.warning("This is a warning message"))


# --------------------------------------------------------------------------- #
# Start computer vision
# --------------------------------------------------------------------------- #


# ccv = CatVision()
# ccv.start()


# def thread_do_print():
#     logger.info(ccv.find_cats())


# TODO feed video from the opencv
# https://github.com/zauberzeug/nicegui/blob/main/examples/opencv_webcam/main.py

ui.run()

# ccv.stop()
