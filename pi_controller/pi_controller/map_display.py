import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import threading
import time

from custommap import load_from_file
from pathplanner import Node, Path, go_to_coords

map = load_from_file('pi_controller/map.csv')
print(map)

path = go_to_coords(map, (1,1), (40, 80))
print(path)

fig, ax = plt.subplots()
cax = ax.matshow(map, cmap='Grays')

# Initialize the plot
mouse, = ax.plot([], [], 'bo')  # Mouse as a red dot
cat, = ax.plot([], [], 'ro')  # Cat as a blue dot
path_line, = ax.plot([], [], 'b--')  # Path as a dashed blue line

def init():
    mouse.set_data([], [])
    path_line.set_data([], [])
    return mouse, path_line

lock = threading.Lock()
mouse_location = (1,1)
cat_location = (40, 40)
path = go_to_coords(map, (1,1), (40, 82))

def animate(i):
    with lock:
        x, y = zip(*path)
        mouse.set_data([mouse_location[1]], [mouse_location[0]])
        cat.set_data([cat_location[0]], [cat_location[1]])
        path_line.set_data(y, x)
    return mouse, cat, path_line

def _advance_path():
    global path, mouse_location
    while len(path) > 1:
        time.sleep(0.1)
        with lock:
            mouse_location = path.pop(0)
            print(f"Updated location: {mouse_location}")

# Event handling for COMPUTER mouse moves (are we confused yet?)
def on_mouse_move(event):
    global cat_location
    if event.inaxes:
        x, y = int(event.xdata + 0.5), int(event.ydata + 0.5)  # rounding to nearest integer
        with lock:
            cat_location = (x, y)


# Connect the event handler
fig.canvas.mpl_connect('motion_notify_event', on_mouse_move)


thread = threading.Thread(target=_advance_path, daemon=True)
thread.start()

ani = animation.FuncAnimation(fig, animate, init_func=init, interval=100, blit=True)

plt.show()
