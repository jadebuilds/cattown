import websockets.sync
import websockets.sync.client
from .driver import MotionDriver
from .commands import MotionCommand
from .utils import ThreadSafeMonotonicCounter
from ..constants import Point

import websockets
import json
import threading
import time


PRIMARY_WEBSOCKET_URL = "ws://{hostname}/websocket"
BRIDGE_WEBSOCKET_URL = "ws://{hostname}/klipper"  # just in case it's useful


import websockets
import threading


class MoonrakerSocket(MotionDriver):

    def __init__(self, hostname: str):
        """
        Given the hostname of a machine we can connect to it.
        Note that this will be .

        For remote devices, should usually be of the format "cattown###.local".
        For local devices, ... what? I don't actually know yet
        """
        self.hostname = hostname
        self.ws = websockets.sync.client.connect(
            PRIMARY_WEBSOCKET_URL.format(hostname=hostname)
        )
        # Start a worker thread to 
        # N.B. there's probably some fancy way to do this using async
        # but I am a synchronous kinda girl and I have no fucking clue how async
        # works and no desire to start learning now lol I'm like a grandmother 
        # looking down her pince nez at your gosh darned fancy new iPad
        self.rx_thread = threading.Thread(target=self._receive, daemon=True)
        self.should_exit = threading.Event()  # thread will need to access this once start()'ed
        self.rx_thread.start()
        
        self.next_cmd_id = ThreadSafeMonotonicCounter()

        # Subscribe to everything
        self._send({
            "method": "printer.objects.subscribe",
             "params": {
                 "objects": {
                    #  "gcode": None,
                    #  "gcode_move": None,
                    #  "stepper_enable": None,
                     "motion_report": None,
                    #  "webhooks": None,
                 }
             }
        })

    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~ MotionDriver API ~~~~~~~~~~~~~~~~~~~~~~~~~~~

    def enqueue_motion(self, motion: MotionCommand):
        return super().enqueue_motion(motion)

    def get_current_position(self) -> Point:
        return super().get_current_position()
    
    def clear_queue(self):
        return super().clear_queue()
    
    def stop(self):
        self.ws.close()
    
    # ~~~~~~~~~~~~~~~~~~~~~~~~~~~ Websocket stuff ~~~~~~~~~~~~~~~~~~~~~~~~~~~

    def _send(self, message: dict):
        """
        Populate default fields like jsonrpc and ID, then send over the websocket.
        """
        message["jsonrpc"] = "2.0"
        message["id"] = self.next_cmd_id.get()
        self.ws.send(json.dumps(message))


    def _receive(self):
        """
        Infinite loop of receiving from the websocket, as a child thread so that
        it can run in the background.
        """
        while not self.should_exit.is_set():
            try:
                message: str = self.ws.recv(timeout=0.5)  # takes up to half a second to clean up
            except TimeoutError:
                continue

            data = json.loads(message)
            if "motion_report" in message:
                print(data)  # TODO for initial investigation, remove me


if __name__ == "__main__":
    moonraker = MoonrakerSocket("cattown001.local")
    time.sleep(10)
