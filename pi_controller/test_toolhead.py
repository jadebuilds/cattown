import logging

logging.basicConfig(level=logging.DEBUG, format="%(asctime)s [%(levelname)s] %(module)s: %(message)s")

from pi_controller.motion.moonraker import MoonrakerSocket
from pi_controller.motion.toolhead import Toolhead
from pi_controller.toolhead_trajectory import ToolheadTrajectory
from pi_controller.motion.styles import SimpleStraightLines
from pi_controller.constants import OPEN_SAUCE_MAP_CONFIG
import time





#map_config = OPEN_SAUCE_MAP_CONFIG

#m = MoonrakerSocket('cattown001.local')
#m = MockMotionDriver(speed_mm_s=200.)

path = ToolheadTrajectory()
path.extend([(4, 6), (5, 6), (6,6), (7,6), (7,7), (7,8), (8,8)])

toolhead = Toolhead(
    MoonrakerSocket('cattown001.local'),
    SimpleStraightLines(speed_mm_s=200.0, map_config=OPEN_SAUCE_MAP_CONFIG),
    OPEN_SAUCE_MAP_CONFIG
)

toolhead.follow_path(path)

time.sleep(1)

path.extend([
    (9, 8), (10,8), (11,8), (12,8)
])

time.sleep(10)
print("Ten seconds elapsed")
path.extend([
    (12,9), (12,10), (13, 10), (14, 10), (15, 10),
])
