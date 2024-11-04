# backend.py
#
# This is terrible coding practice but we're time constrained and so
# fuck it we're gonna live dangerously lol. I'm "fork"ing yet again
# from infinite_loop.py, this time to pull out the matplotlib display
# and provide something that can be run from the web frontend.
#
# Author: Jade

from typing import Optional, Tuple, Dict, List
import logging
import threading
import time

from ..path_finder import PathFinder
from ..toolhead_trajectory import ToolheadTrajectory
from ..motion.toolhead import Toolhead
from ..motion.moonraker import MoonrakerSocket
from ..motion.styles import SimpleStraightLines, ArcSquiggles
from ..constants import OPEN_SAUCE_MAP_CONFIG
from .mouse import Mouse, MouseState

from ..ccv import CatVision


logger = logging.getLogger(__name__)


"""
For this "minimum viable autonomy" approach we'll start out by
putting mice in known starting locations. Our first move will
be to pick them up and head 
"""
MOUSE_STARTING_LOCATIONS = [
    (6, 15),  # in the middle of the left upper ramp (between the two mouseholes)
    (32, 15),  # middle of the right upper ramp (panel 3) (between mouse holes)
]

# Note that the infinite_loop steers to the entrance of the house,
# whereas here we're navigating to the very back of the house --
# which is why their coordinates are different
MOUSE_HOUSES = [
    (7, 17),  # top left
    (5, 9),  # lower left
    (21, 17),  # top middle
    # (37, 8),  # lower right house NOT IN OPERATION right now (making weird clunking sounds @ Doreen's)
    (19, 3),  # down into the bottom middle house
]


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

        self.ccv = CatVision(callback=self._update_vision)
        self.cats_last_seen_lock = threading.Lock()
        self.cats_last_seen: List[Dict] = None

        self.mice = [
            Mouse(
                location=starting_location,
                houses=MOUSE_HOUSES,
                path_finder=self.path_finder,
            )
            for starting_location in MOUSE_STARTING_LOCATIONS
        ]
        self.active_mouse_index = 0

    def run(self):
        # Start the first set of movements
        self.should_stop.clear()
        self.toolhead.follow_path(self.toolhead_path)
        self.mouse_thread = threading.Thread(target=self._run_loop)
        self.mouse_thread.start()

        self.ccv.start()  # start background thread doing webcam capture

    def stop(self):
        if self.worker_thread:
            self.should_stop.set()
            self.worker_thread.join()

    def _run_loop(self):
        """
        Background thread: Run the mouse around
        """

        while not self.should_stop.is_set():
            logger.info("Todo move the mouse around")

            active_mouse = self.mice[self.active_mouse_index]

            cat_distance = self._distance_from_cat(self.cat)
            new_path_segment = active_mouse.move(cat_distance=cat_distance)
            if new_path_segment:
                self.toolhead_path.extend(new_path_segment)
                self.toolhead.paused_or_pausing.wait()

            # TODO switch mice!!!!

    def _update_vision(self, cats: List[Dict], mice: List[Dict]):
        """
        Callback invoked within the CatVision.run()
        """
        with self.cats_last_seen_lock:
            self.cats_last_seen = cats
        time.sleep(0.1)  # does this make sense? just to be sure we don't hog the CPU

    def _distance_from_cat(self) -> float:
        """
        Accesses cats_last_seen to figure out how far the nearest cat is.
        """
        with self.cats_last_seen_lock:
            self.cats_last_seen

        raise NotImplementedError
