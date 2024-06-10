from pi_controller.printer import KlipperSocket
from pi_controller.motion import DirectMove, RelativeMove, SimpleSquigglePath, MapConfig
from pi_controller.mice import MouseHouse, PickUpMouse, DropOffMouse
import time
from pi_controller.constants import OPEN_SAUCE_MAP_CONFIG

k = KlipperSocket('/home/fes/printer_data/comms/klippy.sock')
map_config = OPEN_SAUCE_MAP_CONFIG

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


panel_2_house = MouseHouse((19, 16), occupied=False)

# Let's see what objects exist
# k._send_command({
#     "method": "objects/list", 
# })

k._send_command({
    "method": "objects/subscribe", 
    "params": {"objects": {"toolhead": ["position"]}}
})
# k._send_command({
#     "method": "objects/subscribe", 
#     "params": {"objects": {"gcode_move": ["position"]}}
# })
# k._send_command({
#     "method": "objects/subscribe", 
#     "params": {"objects": {"gcode_move": ["gcode_position"]}}
# })
# k._send_command({
#     "method": "objects/subscribe", 
#     "params": {"objects": {"webhooks": ["state"]}}
# })

# This doesn't seem very useful?? This is supposed to be human-facing terminal output, 
# but I don't see anything from it when I subscribe to it
# k._send_command({
#     "method": "gcode/subscribe_output"
# })

#k.enqueue_motion(DirectMove((19, 15)))
k.enqueue_motion(DropOffMouse(panel_2_house, map_config))
k.enqueue_motion(PickUpMouse(panel_2_house, map_config))


time.sleep(10)
k.stop()
