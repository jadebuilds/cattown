# backend.py
#
# This is terrible coding practice but we're time constrained and so
# fuck it we're gonna live dangerously lol. I'm "fork"ing yet again
# from infinite_loop.py, this time to pull out the matplotlib display
# and provide something that can be run from the web frontend.
#
# Author: Jade

from typing import Optional, Tuple
import logging
import threading
import time
import random
from enum import Enum

from ..path_finder import PathFinder
from ..toolhead_trajectory import ToolheadTrajectory
from ..motion.toolhead import Toolhead
from ..motion.moonraker import MoonrakerSocket
from ..motion.styles import SimpleStraightLines, ArcSquiggles
from ..constants import OPEN_SAUCE_MAP_CONFIG

logger = logging.getLogger(__name__)


class GameState(Enum):
    # TODO use me!!!

    TOODLING_AROUND = 1  # cruise between pre-defined waypoints
    RUNNING_AWAY = 2  # run to the nearest


class Game:
    def __init__(self):
        self.lock = threading.Lock()
        self.path_finder = PathFinder("../pi_controller/map.csv")
        self.toolhead = Toolhead(
            # MockMotionDriver(),
            MoonrakerSocket("cattown001.local"),
            SimpleStraightLines(speed_mm_s=350.0, map_config=OPEN_SAUCE_MAP_CONFIG),
            # ArcSquiggles(speed_mm_s=500, map_config=OPEN_SAUCE_MAP_CONFIG),
            OPEN_SAUCE_MAP_CONFIG,
        )
        self.toolhead_path = ToolheadTrajectory()
        self.last_cursor_location: Optional[Tuple[int, int]] = None
        self.worker_thread: Optional[threading.Thread] = None
        self.should_stop = threading.Event()

    def run(self):
        # Start the first set of movements
        self.should_stop.clear()
        self.toolhead.follow_path(self.toolhead_path)
        self.worker_thread = threading.Thread(target=self._run_loop)
        self.worker_thread.start()

    def stop(self):
        if self.worker_thread:
            self.should_stop.set()
            self.worker_thread.join()

    def _run_loop(self):
        houses = [
            (5, 17),  # top left
            (3, 9),  # lower left
            (19, 17),  # top middle
            (17, 3),  # down into the bottom middle house
            # I'm tempted to visit the upper right too but we keep dropping the mouse here,
            # and for autonomous operation that would kinda suck :(
        ]
        tile_index = 0
        while not self.should_stop.is_set():
            logger.info(f"Making a move to {houses[tile_index]}")
            new_path_segment = self.path_finder.go_to_coords(
                self.toolhead.get_current_tile(), houses[tile_index]
            )
            self.toolhead_path.extend(new_path_segment)
            # loop around
            tile_index = (tile_index + 1) % len(houses)
            self.toolhead.paused_or_pausing.wait()  # wait until done moving to push new content
            time.sleep(5.0 + random.random() * 15)  # wait a bit before moving again
