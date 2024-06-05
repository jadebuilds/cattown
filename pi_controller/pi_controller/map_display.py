import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import threading
import time

from .custommap import load_from_file
from .pathplanner import PathFinder

class Game:
    def __init__(self):
        self.map = load_from_file('pi_controller/map.csv')
        self.fig, self.ax = plt.subplots()
        self.cax = self.ax.matshow(self.map, cmap='Grays')

        # Initialize the plot
        self.mouse, = self.ax.plot([], [], 'bo')
        self.cat, = self.ax.plot([], [], 'ro')
        self.path_line, = self.ax.plot([], [], 'b--')
        self.game_over_text = self.ax.text(0.5, 0.5, '', transform=self.ax.transAxes, ha='center', va='center', color='red', fontsize=16, bbox={'facecolor': 'white', 'alpha': 0.5, 'pad': 10})
        self.game_active = True
        
        self.mouse_location = (1, 1)
        self.cat_location = (40, 40)
        self.mouse_goal_location = (40, 82)

        self.path_finder = PathFinder('pi_controller/map.csv')
        self.path = self.path_finder.go_to_coords(self.mouse_location, self.mouse_goal_location)
        
        self.lock = threading.Lock()

        self.fig.canvas.mpl_connect('motion_notify_event', self.on_mouse_move)
        self.ani = animation.FuncAnimation(self.fig, self.animate, init_func=self._animation_init, interval=100, blit=True)

    def _animation_init(self):
        self.mouse.set_data([], [])
        self.path_line.set_data([], [])
        return self.mouse, self.cat, self.path_line, self.game_over_text

    def animate(self, i):
        with self.lock:
            x, y = zip(*self.path)
            self.mouse.set_data([self.mouse_location[1]], [self.mouse_location[0]])
            self.cat.set_data([self.cat_location[1]], [self.cat_location[0]])
            self.path_line.set_data(y, x)
            if not self.game_active:
                return self.mouse, self.cat, self.path_line, self.game_over_text
        return self.mouse, self.cat, self.path_line

    def _advance_path(self):
        while len(self.path) > 1 and self.game_active:
            time.sleep(0.1)
            with self.lock:
                self.mouse_location = self.path.pop(0)
                if self.cat_location == self.mouse_location:
                    self.game_over_text.set_text('Caught by the cat!')
                    self.mouse.set_color('black')  
                    self.fig.canvas.draw() 
                    self.game_active = False 

    # cursor move, not the mouse toy. 
    def on_mouse_move(self, event):
        if event.inaxes:
            x, y = round(event.xdata), round(event.ydata)
            with self.lock:
                self.cat_location = (y, x)
                if not self.game_active:
                    return
                if self.cat_location == self.mouse_location:
                    self.game_over_text.set_text('Caught by the cat!')
                    self.mouse.set_color('black')  
                    self.fig.canvas.draw() 
                    self.game_active = False 
                    return
                cat_is_close = abs(self.cat_location[0] - self.mouse_location[0]) or abs(self.cat_location[1] - self.mouse_location[1]) <= 6
                mouse_is_on_map = 0 <= x < self.map.shape[0] and 0 <= y < self.map.shape[1]
                if cat_is_close and mouse_is_on_map:
                    self.mouse_location = self.path.pop(0)
                    threading.Thread(target=self.update_path).start()

    def update_path(self):
        new_path = self.path_finder.redraw_path(self.mouse_location, self.cat_location)
        if new_path:
            self.path = new_path

    def run(self):
        thread = threading.Thread(target=self._advance_path, daemon=True)
        thread.start()
        plt.show()

if __name__ == '__main__':
    game = Game()
    game.run()
