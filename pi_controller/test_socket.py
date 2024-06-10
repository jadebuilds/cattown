from pi_controller.printer import KlipperSocket
from pi_controller.motion import DirectMove, RelativeMove, Point, SimpleSquigglePath, MapConfig
from pi_controller.mice import MouseHouse, PickUpMouse, DropOffMouse
import time

k = KlipperSocket('/home/fes/printer_data/comms/klippy.sock')
map_config=MapConfig(50., 62., 47.)

# squiggle = SimpleSquigglePath(
#     map_path=[
#         (0, 0), (0, 1), (0, 2), (0, 3),
#         (0, 4), (1, 4), (2, 4), (3, 4),
#         (4, 4), (4, 3), (4, 2), (4, 1),
#         (4, 0), (3, 0), (2, 0), (1, 0),
#         (1, 1), (1, 2), (2, 2), (3, 2), 
#         (3, 3), (3, 4), (4, 4),
#     ],
#     map_config=map_config,
#     speed_mm_s=500
# )


panel_2_house = MouseHouse((19, 5), occupied=False)

k.enqueue_motion(DropOffMouse(panel_2_house, map_config))


time.sleep(10)
k.stop()
