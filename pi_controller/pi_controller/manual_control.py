# manual_control.py
# 
# "Fork" of map_display.py which uses the cursor to drive the mouse.
# 
# Author: Jade

from typing import Optional, Tuple
import logging
logging.getLogger('matplotlib').setLevel(logging.INFO)  # https://stackoverflow.com/questions/35325042/python-logging-disable-logging-from-imported-modules
import colorlog
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle  
import matplotlib.animation as animation
import numpy as np
import threading
import time
import traceback
import sys

from .custommap import load_from_file
from .path_finder import PathFinder
from .toolhead_trajectory import ToolheadTrajectory
from .motion.toolhead import Toolhead
from .motion.moonraker import MoonrakerSocket
from .motion.mock_driver import MockMotionDriver
from .motion.styles import SimpleStraightLines
from .constants import OPEN_SAUCE_MAP_CONFIG

logger = logging.Logger(__name__)

class Game:
    def __init__(self):
        self.lock = threading.Lock()
        self.path_finder = PathFinder('pi_controller/map.csv')
        self.toolhead = Toolhead(
            MockMotionDriver(),
            # MoonrakerSocket('cattown001.local'),
            SimpleStraightLines(speed_mm_s=800.0, map_config=OPEN_SAUCE_MAP_CONFIG),
            OPEN_SAUCE_MAP_CONFIG
        )
        self.toolhead_path = ToolheadTrajectory()

        # Initialize the plot
        self.map = load_from_file('pi_controller/map.csv')
        
        self.fig, self.ax = plt.subplots()
        self.cax = self.ax.matshow(self.map, cmap='Grays', origin='lower')
        self.mouse, = self.ax.plot([], [], 'bo')
        self.cursor, = self.ax.plot([], [], 'ro')
        self.path_line, = self.ax.plot([], [], 'b--')

        self.last_cursor_location: Optional[Tuple[int, int]] = None

        # Event listener and the animation function in the main thread
        self.fig.canvas.mpl_connect('motion_notify_event', self.on_cursor_move)
        self.fig.canvas.mpl_connect('button_press_event', self.on_click)
        self.ani = animation.FuncAnimation(self.fig, self.animate, init_func=self._animation_init, interval=100, blit=True)


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
                self.cursor.set_data([self.last_cursor_location[0]], [self.last_cursor_location[1]])
                objects_to_animate = objects_to_animate + (self.cursor,)
            
            path_tiles = self.toolhead_path.get_tiles()
            if path_tiles:
                x, y = zip(*path_tiles)  # zip into two lists of X and Y values
                self.path_line.set_data(x, y)
                objects_to_animate = objects_to_animate + (self.path_line,)

        return objects_to_animate
        

    # Event listener for cursor movements
    # Updates the cat coordinates for the animation library & recalculates path if cat is close. 
    def on_cursor_move(self, event):
        if event.inaxes:
            x, y = round(event.xdata), round(event.ydata)
            with self.lock:
                self.last_cursor_location = (x, y)

    def on_click(self, event):
        if event.inaxes:
            x, y = round(event.xdata), round(event.ydata)
            logger.info(f"Click on {x}, {y}! Let's go there")
            self.toolhead_path.clear()  # clears back to last_committed()
            new_segment = self.path_finder.go_to_coords(
                start=self.toolhead_path.last_committed(),
                goal=(x, y)
            )
            if not new_segment:
                logger.warning(f"Failed to plan between {self.toolhead_path.last_committed()} and {(x,y)}!!!")
            else:
                self.toolhead_path.extend(new_segment)

    def run(self):
        # Start the first set of movements 
        self.toolhead.follow_path(self.toolhead_path)
        plt.show()


def main():
    try:
        logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
        logging.getLogger().handlers[0].setFormatter(
            colorlog.ColoredFormatter("%(asctime)s %(log_color)s[%(levelname)s] %(module)s: %(message)s")
        )
        game = Game()
        game.run()
    except Exception as e:
        traceback.print_exc()


if __name__ == '__main__':
    main()
