# manual_control.py
#
# "Fork" of map_display.py which uses the cursor to drive the mouse.
#
# Author: Jade

from typing import Optional, Tuple
import logging

logging.getLogger("matplotlib").setLevel(
    logging.INFO
)  # https://stackoverflow.com/questions/35325042/python-logging-disable-logging-from-imported-modules
import colorlog
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
import matplotlib.animation as animation
import numpy as np
import threading
import time
import traceback
import sys
import random

from .custommap import load_from_file
from .path_finder import PathFinder
from .toolhead_trajectory import ToolheadTrajectory
from .motion.toolhead import Toolhead
from .motion.moonraker import MoonrakerSocket
from .motion.mock_driver import MockMotionDriver
from .motion.styles import SimpleStraightLines, ArcSquiggles
from .constants import OPEN_SAUCE_MAP_CONFIG

logger = logging.getLogger(__name__)


class Game:
    def __init__(self):
        self.lock = threading.Lock()
        self.path_finder = PathFinder("pi_controller/map.csv")
        self.toolhead = Toolhead(
            # MockMotionDriver(),
            MoonrakerSocket("cattown001.local"),
            SimpleStraightLines(speed_mm_s=350.0, map_config=OPEN_SAUCE_MAP_CONFIG),
            # ArcSquiggles(speed_mm_s=500, map_config=OPEN_SAUCE_MAP_CONFIG),
            OPEN_SAUCE_MAP_CONFIG,
        )
        self.toolhead_path = ToolheadTrajectory()

        # Initialize the plot
        self.map = load_from_file("pi_controller/map.csv")
        self.fig, self.ax = plt.subplots()
        self.cax = self.ax.matshow(self.map, cmap="Grays", origin="lower")
        (self.mouse,) = self.ax.plot([], [], "bo")
        (self.cursor,) = self.ax.plot([], [], "ro")
        (self.path_line,) = self.ax.plot([], [], "b--")

        self.last_cursor_location: Optional[Tuple[int, int]] = None

        # Animation (no input on this one!)
        self.ani = animation.FuncAnimation(
            self.fig,
            self.animate,
            init_func=self._animation_init,
            interval=100,
            blit=True,
        )

    # Animation initization function
    def _animation_init(self):
        self.mouse.set_data([], [])
        self.path_line.set_data([], [])
        return self.mouse, self.cursor, self.path_line

    # Animation function
    def animate(self, i):
        with self.lock:
            mouse_location = self.toolhead.get_current_tile()
            self.mouse.set_data([mouse_location[0]], [mouse_location[1]])

            objects_to_animate = (self.mouse,)  # mouse always active

            if self.last_cursor_location:
                self.cursor.set_data(
                    [self.last_cursor_location[0]], [self.last_cursor_location[1]]
                )
                objects_to_animate = objects_to_animate + (self.cursor,)

            path_tiles = self.toolhead_path.get_tiles()
            if path_tiles:
                x, y = zip(*path_tiles)  # zip into two lists of X and Y values
                self.path_line.set_data(x, y)
                objects_to_animate = objects_to_animate + (self.path_line,)

        return objects_to_animate

    def on_click(self, event):
        if event.inaxes:
            x, y = round(event.xdata), round(event.ydata)
            logger.info(f"Click on {x}, {y}! Let's go there")

            new_segment = self.path_finder.go_to_coords(
                start=self.toolhead_path.last_committed(), goal=(x, y)
            )
            if not new_segment:
                logger.warning(
                    f"Failed to plan between {self.toolhead_path.last_committed()} and {(x,y)}!!!"
                )
            else:
                self.toolhead_path.clear()  # clears back to last_committed()
                self.toolhead_path.extend(new_segment)

    def run(self):
        # Start the first set of movements
        self.toolhead.follow_path(self.toolhead_path)
        worker_thread = threading.Thread(target=self._run_loop)
        worker_thread.start()
        plt.show()

    def _run_loop(self):
        houses = [
            (5, 17),  # top left
            (3, 9),  # lower left
            (19, 17),  # top middle
            (37, 8),  # lower right house (for a good long horizontal run)
            (17, 3),  # down into the bottom middle house
            # I'm tempted to visit the upper right too but we keep dropping the mouse here,
            # and for autonomous operation that would kinda suck :(
        ]
        tile_index = 0
        while True:
            logger.info(f"Making a move to {houses[tile_index]}")
            new_path_segment = self.path_finder.go_to_coords(
                self.toolhead.get_current_tile(), houses[tile_index]
            )
            self.toolhead_path.extend(new_path_segment)
            # loop around
            tile_index = (tile_index + 1) % len(houses)
            self.toolhead.paused_or_pausing.wait()  # wait until done moving to push new content
            time.sleep(5.0 + random.random() * 15)  # wait a bit before moving again


def main():
    try:
        logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
        logging.getLogger().handlers[0].setFormatter(
            colorlog.ColoredFormatter(
                "%(asctime)s %(log_color)s[%(levelname)s] %(module)s: %(message)s"
            )
        )
        game = Game()
        game.run()
    except Exception as e:
        traceback.print_exc()


if __name__ == "__main__":
    main()
