# map_display.py
# 
# Our GameEngine animates what is happening between our movement 
# system using the KlipperSocket and what the camera module 
# detects is a cat. Uses pathfinder to keep the mouse moving 
# between coordinates. 
#  
# Author: Zoda

import logging

logging.getLogger('matplotlib').setLevel(logging.INFO)
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
        self.minimum_path_len = 2
        self.cat_closeness_threshhold = 2
        self.path_finder = PathFinder('pi_controller/map.csv')
        self.toolhead_path = ToolheadTrajectory()
        self.path_follower = Toolhead(
            MockMotionDriver(),
            # MoonrakerSocket('cattown001.local'),
            SimpleStraightLines(speed_mm_s=800.0, map_config=OPEN_SAUCE_MAP_CONFIG),
            OPEN_SAUCE_MAP_CONFIG
        )

        # Initialize the plot
        self.map = load_from_file('pi_controller/map.csv')
        self.fig, self.ax = plt.subplots()
        self.cax = self.ax.matshow(self.map, cmap='Grays', origin='lower')
        self.mouse, = self.ax.plot([], [], 'bo')
        self.cat, = self.ax.plot([], [], 'ro')
        self.path_line, = self.ax.plot([], [], 'b--')
        self.mouse_box = Rectangle((0, 0), 3, 3, fill=False, edgecolor='black', linewidth=1)  
        self.ax.add_patch(self.mouse_box) 
        self.mouse_box.set_visible(False)

        # Initialize the parameters
        self.mouse_location = self.path_follower.get_current_tile()
        self.cat_location = (13, 8)
        self.mouse_goal_location = (13, 4)
        self.path = self.path_finder.go_to_coords(self.mouse_location, self.mouse_goal_location)

        # Event listener and the animation function in the main thread
        self.fig.canvas.mpl_connect('motion_notify_event', self.on_cursor_move)
        self.ani = animation.FuncAnimation(self.fig, self.animate, init_func=self._animation_init, interval=100, blit=True)


    # Animation initization function 
    def _animation_init(self):
        self.mouse.set_data([], [])
        self.path_line.set_data([], [])
        return self.mouse, self.cat, self.path_line

    # Animation function 
    def animate(self, i):
        with self.lock:
            if len(self.path) < self.minimum_path_len: 
                logger.debug(f"Increasing path, path length currently {len(self.path)}")
                self.get_new_path() 
            
            self.mouse_location = self.path_follower.get_current_tile()
            self.mouse.set_data([self.mouse_location[0]], [self.mouse_location[1]])
            self.cat.set_data([self.cat_location[0]], [self.cat_location[1]])
            self.mouse_box.set_visible(True)
            self.mouse_box.set_xy((self.mouse_location[0] - 1.5, self.mouse_location[1] - 1.5))
            path_tiles = self.toolhead_path.get_tiles()
            if path_tiles:
                x, y = zip(*path_tiles)  # zip into two lists of X and Y values
                self.path = path_tiles
                self.path_line.set_data(x, y)

        return self.mouse, self.cat, self.path_line, self.mouse_box, 
    


    # Event listener for cursor movements
    # Updates the cat coordinates for the animation library & recalculates path if cat is close. 
    def on_cursor_move(self, event):
        if event.inaxes:
            x, y = round(event.xdata), round(event.ydata)
            with self.lock:
                self.cat_location = (x, y)
                
                # If the cat is close, draw a new path
                dx_too_close = abs(self.cat_location[0] - self.mouse_location[0]) < self.cat_closeness_threshhold
                dy_too_close = abs(self.cat_location[1] - self.mouse_location[1]) < self.cat_closeness_threshhold
                cat_is_too_close = dx_too_close and dy_too_close 
                if cat_is_too_close:
                    self.get_new_path() 

    # Update path if there is a path returned.
    def get_new_path(self, replace: bool = False):
        new_path = self.path_finder.redraw_path_if_necessary(
            start=self.toolhead_path.last_committed(), 
            cat_location=self.cat_location, 
            path=self.path, 
            cat_closeness_threshhold=1, 
            check_upcoming_tiles=4,
            minimum_path_len=self.minimum_path_len
        )
        if new_path:
            self.path = new_path
            self.toolhead_path.clear()
            self.toolhead_path.extend(new_path)
            logger.debug("New path returned")
        else:
            logger.debug("No new path returned")

    def run(self):
        # Start the first set of movements 
        self.toolhead_path.extend(self.path)
        self.path_follower.follow_path(self.toolhead_path)
        
        plt.show()


def main():
    try:
        logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
        game = Game()
        game.run()
    except Exception as e:
        traceback.print_exc()


if __name__ == '__main__':
    logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
    main()
