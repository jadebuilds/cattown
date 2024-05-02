# Not working yet, to test and iterate on RPi Zero 2 W
import cv2 as cv


cap = cv.VideoCapture(0)
while cap.is_Opened():
    ret, frame = cap.read()
    frame = cv.cvtColor(frame, cv.COLOR_BGR2BGRA)
    with open('/dev/fbdev2', 'rb+') as buf:
       buf.write(frame)
cap.release()





