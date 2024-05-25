import cv2 as cv
import numpy as np 

# Read stride and resolution:
#with open('/sys/class/graphics/fb0/stride') as f:
#	stride = int(f.read())
#print(f'Read stride: {stride}')


def show_frame(frame):
	frame_c = cv.cvtColor(frame, cv.COLOR_BGR2BGR565)
	with open('/dev/fb0', 'rb+') as buf:
		buf.write(frame_c)


cap = cv.VideoCapture(0)
while cap.isOpened():
	ret, frame = cap.read()
	show_frame(frame)
	# This monitor expects 16 bit color
	# frame = cv.cvtColor(frame, cv.COLOR_BGR2BGR565)
	# Try resize to full screen:
	# frame = cv.resize(frame, (1920, 1080), interpolation = cv.INTER_LINEAR)
	# import pdb
	# pdb.set_trace()

	# lineend = np.zeros(stride - 4*frame.shape[1])
	# with open('/dev/fb0', 'rb+') as buf:
		#buf.write(frame)
		#for row in frame:
		#	buf.write(row)
		#	buf.write(lineend)

cap.release()





