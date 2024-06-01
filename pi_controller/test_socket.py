from pi_controller.printer import KlipperSocket
from pi_controller.motion import DirectMove, RelativeMove, Point, SimpleSquigglePath, MapConfig
import time

k = KlipperSocket('/home/fes/printer_data/comms/klippy.sock')
# k.enqueue_motion(DirectMove(Point(0, 0), speed_mm_s=1000))
# k.enqueue_motion(DirectMove(Point(0, 100), speed_mm_s=1000))
# k.enqueue_motion(DirectMove(Point(100, 100), speed_mm_s=1000))
# k.enqueue_motion(DirectMove(Point(100, 0), speed_mm_s=1000))
# k.enqueue_motion(DirectMove(Point(0, 0), speed_mm_s=1000))

squiggle = SimpleSquigglePath(
    map_path=[
        (0, 0), (0, 1), (0, 2), (0, 3),
        (0, 4), (1, 4), (2, 4), (3, 4),
        (4, 4), (4, 3), (4, 2), (4, 1),
        (4, 0), (3, 0), (2, 0), (1, 0),
        (1, 1), (1, 2), (2, 2), (3, 2), 
        (3, 3), (3, 4), (4, 4),
    ],
    map_config=MapConfig(20., 15., 15.),
    speed_mm_s=3000
)

k.enqueue_motion(squiggle)
time.sleep(10)
k.stop()
