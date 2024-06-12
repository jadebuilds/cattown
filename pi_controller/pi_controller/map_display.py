# map_display.py
# 
# Emulator, lets us test the paths we've drawn using custommap and pathfinder 
# module. Uses matplot for animations. Can use cursor as the cat to see how the 
# the pathfinder will react. 
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
from .motion.pathfollow import Toolhead
from .motion.moonraker import MoonrakerSocket
from .motion.styles import SimpleStraightLines
from .constants import OPEN_SAUCE_MAP_CONFIG

logger = logging.Logger(__name__)

class Game:
    def __init__(self):
        self.game_active = True
        self.lock = threading.Lock()
        self.path_finder = PathFinder('pi_controller/map.csv')
        self.toolhead_path = ToolheadTrajectory()
        self.minimum_path_len = 2
        self.cat_closeness_threshhold = 2
        self.path_follower = Toolhead(
            MoonrakerSocket('cattown001.local'),
            SimpleStraightLines(speed_mm_s=200.0, map_config=OPEN_SAUCE_MAP_CONFIG),
            OPEN_SAUCE_MAP_CONFIG
        )

        # Initialize the plot
        self.map = load_from_file('pi_controller/map.csv')
        self.fig, self.ax = plt.subplots()
        self.cax = self.ax.matshow(self.map, cmap='Grays', origin='lower')
        self.mouse, = self.ax.plot([], [], 'bo')
        self.cat, = self.ax.plot([], [], 'ro')
        self.path_line, = self.ax.plot([], [], 'b--')
        self.game_over_text = self.ax.text(0.5, 0.5, '', transform=self.ax.transAxes, ha='center', va='center', color='red', fontsize=16, bbox={'facecolor': 'white', 'alpha': 0.5, 'pad': 10})
        self.mouse_box = Rectangle((0, 0), 3, 3, fill=False, edgecolor='black', linewidth=1)  
        self.ax.add_patch(self.mouse_box) 
        self.mouse_box.set_visible(False)

        # Initialize the parameters
        self.mouse_location = self.path_follower.get_current_tile()
        self.cat_location = (10, 13)
        self.mouse_goal_location = (6, 8)
        self.path = self.path_finder.go_to_coords(self.mouse_location, self.mouse_goal_location)

        # Event listener and the animation function in the main thread
        self.fig.canvas.mpl_connect('motion_notify_event', self.on_cursor_move)
        self.ani = animation.FuncAnimation(self.fig, self.animate, init_func=self._animation_init, interval=100, blit=True)


    # Animation initization function 
    def _animation_init(self):
        self.mouse.set_data([], [])
        self.path_line.set_data([], [])
        return self.mouse, self.cat, self.path_line, self.game_over_text

    # Animation function 
    def animate(self, i):
        self.mouse_box.set_visible(True)
        with self.lock:
            if not self.game_active:
                logger.info("Caught by the cat!")
                self.game_over_text.set_text("Caught by the cat!")
                self.mouse.set_color("black")  
                self.fig.canvas.draw() 
            elif self.path:
                x, y = zip(*self.path)
                self.mouse.set_data([self.mouse_location[1]], [self.mouse_location[0]])
                self.cat.set_data([self.cat_location[1]], [self.cat_location[0]])
                self.path_line.set_data(y, x)
                self.mouse_box.set_xy((self.mouse_location[1] - 1.5, self.mouse_location[0] - 1.5))

        return self.mouse, self.cat, self.path_line, self.mouse_box, self.game_over_text
        

    # Advances the mouse's path by popping off new coordinates from the path list 
    def _location_refresh(self):
        while self.game_active:
            time.sleep(0.1)
            with self.lock:
                # Check if we need to draw a new path 
                # Under 2 coordinates should give us some time to plan a new path
                if len(self.path) < self.minimum_path_len: 
                    self.update_path()
                if self.path:
                    self.mouse_location = self.path_follower.get_current_position()
                    if self.cat_location == self.mouse_location:
                        self.game_active = False 
                else:
                    logger.debug("No coordinates left in path to advance")

    # Event listener for cursor movements
    # Updates the cat coordinates for the animation library & recalculates path if cat is close. 
    def on_cursor_move(self, event):
        if event.inaxes:
            x, y = round(event.xdata), round(event.ydata)
            with self.lock:
                if not self.game_active:
                    return

                self.cat_location = (y, x)
                # If cat cought the mouse
                if self.cat_location == self.mouse_location:
                    self.game_active = False 
                    return
                
                # If the cat is close, draw a new path
                dx_too_close = abs(self.cat_location[0] - self.mouse_location[0]) < self.cat_closeness_threshhold
                dy_too_close = abs(self.cat_location[1] - self.mouse_location[1]) < self.cat_closeness_threshhold
                cat_is_too_close = dx_too_close or dy_too_close 
                if cat_is_too_close:
                    # if self.path: self.mouse_location = self.path.pop(0)
                    self.update_path() 

    # Update path if there is a path returned.
    def update_path(self):
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

        thread = threading.Thread(target=self._location_refresh, daemon=True)
        thread.start()
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
