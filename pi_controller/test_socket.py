from pi_controller.printer import KlipperSocket
from pi_controller.motion import DirectMove, RelativeMove, Point
import time

k = KlipperSocket('/home/fes/printer_data/comms/klippy.sock')
k.enqueue_motion(DirectMove(Point(0, 0), speed_mm_s=1000))
k.enqueue_motion(DirectMove(Point(0, 100), speed_mm_s=1000))
k.enqueue_motion(DirectMove(Point(100, 100), speed_mm_s=1000))
k.enqueue_motion(DirectMove(Point(100, 0), speed_mm_s=1000))
k.enqueue_motion(DirectMove(Point(0, 0), speed_mm_s=1000))
time.sleep(2)
k.stop()
