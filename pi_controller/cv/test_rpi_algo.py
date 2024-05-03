# TODO: Add FPS counter

import numpy as np
import cv2 as cv
import os
# import matplotlib.pyplot as plt
# %matplotlib widget

# Stored video file location
fdir = '/home/chris/cattown/'
fname = '2024-03-22 first trial.mov'

# TODO: Make these input arguments
WRITE_OUTPUT = False
READ_FILE = False
read_livecam_id = 0
SHOW_ORIENTATION = True
SHOW_CONTOUR = False
SHOW_BBOX = True
SHOW_CENTROIDS = True



# Some helper functions to analyze the moving object contour

def get_centroid(contour):
	''' Get centroid of an openCV 2d contour '''
	row = int( np.round( contour[:,0,0].mean() ) )
	col = int( np.round( contour[:,0,1].mean() ) )
	return (row, col)

def get_2ndmoments(contour, centroid):
	''' Get moments of inertia along x and y, return vector - NOT CURRENTLY USED '''
	cr = np.reshape(contour, (contour.shape[0], 2))

	dcr = cr - centroid
	Iy = np.sum( (dcr[:,0]**2) / dcr.shape[0] )
	Ix = np.sum( (dcr[:,1]**2) / dcr.shape[0] )

	return (round(Iy), round(Ix)) # row, col    

def get_max_variance_vectors(contour, centroid):
	cr = np.reshape(contour, (contour.shape[0], 2))

	dcr = cr - centroid

	# The eigenvector of the covariance matrix with the larger eigenvalue is the direction of max variance
	covariance_mat = np.cov(dcr.T)
	eigenvalues, eigenvectors = np.linalg.eig(covariance_mat)

	# return the eigenvectors scaled by the eigenvalues (amount of variance along each axis)
	return [eigenvectors[:,i] * ev for i, ev in enumerate(eigenvalues)]

# Command line video output on RPi by writing to frame buf:
def show_frame(frame):
	frame_c = cv.cvtColor(frame, cv.COLOR_BGR2BGR565)
	with open('/dev/fb0', 'rb+') as buf:
		buf.write(frame_c)


# Magic numbers:
# minimum and maximum object contour area to be tracked:
# TODO: Calculate these after Aruco transform to put in real units (cm^2)
min_contour_area = 2000
max_contour_area = 10000


backsub_thresh = 180 # Threshold for movement in background subtracted image

# Process only subset of video:
frame_start = 300
frames_to_proc = 450

# Amounts to scale direction vector..
# maxvar_scaling = 50 # old method
maxvar_scaling = 0.02 # Since we don't divide x,y by their stdev, things get large

# Attempt manual mtion tracking method - background subtraction and contours:
back_sub = cv.createBackgroundSubtractorMOG2()

frame_end = frame_start + frames_to_proc
frame_num = 0

if READ_FILE:
	cap = cv.VideoCapture( os.path.join(fdir, fname))
	# Advance the capture to skip the first frames we don't want:
	cap.set(cv.CAP_PROP_POS_FRAMES, frame_start)
else:
	frames_to_proc = np.inf
	cap = cv.VideoCapture(read_livecam_id)

# Configure output stream:
frame_width = int(cap.get(3))
frame_height = int(cap.get(4))
# out_fn = fname.replace('.mov', '_Annotated.mp4v')
out_fn = fname.replace('.mov', '_test2Annotated.avi')

if WRITE_OUTPUT:
	out = cv.VideoWriter(os.path.join(fdir, out_fn),
						  cv.VideoWriter_fourcc('M','P','4','V'), 24, (frame_width,frame_height))
	
	if not out.isOpened():
		raise ValueError('VideoWriter failed to initialize')

while cap.isOpened():
	frame_num += 1
	
	if frame_num > frame_end:
		break
	
	# Capture frame-by-frame
	ret, frame = cap.read()
	if not ret:
		print("Can't receive frame (stream end?). Exiting ...")
		break
	
	# Apply background subtraction
	fg_mask = back_sub.apply(frame)

	# apply global threshold to remove shadows
	retval, mask_thresh = cv.threshold( fg_mask, backsub_thresh, 255, cv.THRESH_BINARY)

	# Binary erosion to remove small motion pixel groups
	# set the kernal
	kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))
	# Apply erosion
	mask_eroded = cv.morphologyEx(mask_thresh, cv.MORPH_OPEN, kernel)

	# Find contours
	contours, hierarchy = cv.findContours(mask_eroded, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)    
 
	# Filter contours to allow only larger objects:
	contour_areas = [cv.contourArea(c) for c in contours]
	large_contours = [cnt for cnt, a in zip(contours,contour_areas) if a > min_contour_area and a < max_contour_area ]    centroids = [get_centroid(c) for c in large_contours]

	# initialize annoated frame:
	frame_ct = frame.copy()
	
	# Annotated frame:
	if SHOW_CONTOUR:
		frame_ct = cv.drawContours(frame, large_contours, -1, (0, 255, 0), 2)
	elif SHOW_BBOX:
		for c in large_contours:
			rect = cv.boundingRect(c)
			x,y,w,h = rect
			cv.rectangle(frame_ct, (x,y), (x+w,y+h), (0, 255, 0), 2)
		
	# Draw centroids with extra markers if we're not using orientation markers:
	if not SHOW_ORIENTATION and SHOW_CENTROIDS:
		for c in centroids:
			frame_ct = cv.drawMarker(frame_ct, c, (0, 0, 255), markerType=cv.MARKER_TILTED_CROSS, 
									 markerSize=15, thickness=2, line_type=cv.LINE_AA)
	elif SHOW_ORIENTATION:
		# Draw eigenvectors of the covariance matrix scaled by eigenvalues
		# Gets across "direction" axis of variance, and if they're equally sized it's symmetric
		for c, cent in zip(large_contours, centroids):
			eigenvecs = get_max_variance_vectors(c, cent)
			for ev in eigenvecs:
				vary = round(maxvar_scaling*ev[0])
				varx = round(maxvar_scaling*ev[1])
				# Sign of max variance vector is arbitrary, so draw a line in both + and - directions from centroid
				frame_ct = cv.line( frame_ct, (cent[0]-vary, cent[1]-varx), (cent[0]+vary, cent[1]+varx), (0, 0, 255), 2 )
	
	# Display the resulting frame
	# cv.imshow('Frame_final', frame_ct)
	show_frame(frame_ct)

	if WRITE_OUTPUT:
		# Write it to the video output file:
		out.write(frame_ct)
	
	if cv.waitKey(1) == ord('q'):
		break

cap.release()
if WRITE_OUTPUT:
	out.release()