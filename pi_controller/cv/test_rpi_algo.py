# TODO: Add FPS counter

import numpy as np
import cv2 as cv
import os
import time
from datetime import datetime

# import matplotlib.pyplot as plt

# Stored video file location
fdir = '/home/chris/cattown/'
# fdir = 'C:\\Chris\\cattown\\' # windows :(
fname = '2024-03-22 first trial.mov'

# TODO: Make these input arguments?
WRITE_OUTPUT = False
# setting READ_FILE to false means use live video from attached camera (USB or otherwise)
READ_FILE = False
read_livecam_id = 0
SHOW_ORIENTATION = False
SHOW_CONTOUR = False
SHOW_BBOX = True
SHOW_CENTROIDS = True



# Some helper functions to analyze the moving object contour
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

def open_live_capture(id):
	return cv.VideoCapture(id)

def calc_area_stats(im, contour):
	'''
	Takes an image and a contour
	Returns means and stdevs of the area within as lists in order of blue, green and red channels

	TODO: Look at Speed vs. Space (RAM) trade off here.  We could cache the mask for every cat
	contour, but since they're uint8 images the same size as the frame image, this takes up some RAM
	For now we are taking a CPU hit and regenerating the cat masks each frame

	If we don't expect that many still cats, perhaps we should rewrite to trade RAM for CPU?
	'''
	mask = np.zeros(im.shape[:2], dtype=np.uint8)
	# Per the internet, we abuse cv.drawContour to make a mask of pixel indices within the contour...
	mask = cv.drawContours(mask, [contour], contourIdx=0, color=255, thickness=-1)
	# idxs = cv.findNonZero(mask)
	#  Rather than actually look at image-to-image differences at the same pixel (color space distances),
	#  let's look at aggregate stats for speed:
	# These will be in Blue, Green, Red order:
	means, stdevs = cv.meanStdDev(im, mask = mask)
	means = means.flatten()
	stdevs = stdevs.flatten()

	return means, stdevs


# =================== Algorithm Parameters ===================
detect_shadows = True # slower, but seems to be a lot more accurate

# minimum and maximum object contour area to be tracked:
# TODO: Calculate these after Aruco transform to put in real units (cm^2)
# These will need updating regardless, just guesses based on original test camera and video
min_cat_contour_area = 2000
max_cat_contour_area = 15000

min_mouse_contour_area = 250
max_mouse_contour_area = 1000

max_same_cat_move_dist_pix = 50
# clear memory of possible still cats after 3 minutes:
still_cat_clear_seconds = 180 

# If the mean and stdev of each color channel is within 10% of what it was previously, there's still a cat there:
# Caveat: watch out for poor lighting or when cat/board contrast is not high
max_mean_diff_frac = 0.10
max_stdev_diff_frac = 0.15
# TODO: Apply some scaling with absolute pixel value so we don't get messed up by noise or quantization at low pixel values


# Leftover from reading test video file:
# Process only subset of video:
frame_start = 300
frames_to_proc = 450

# Amounts to scale direction vector..
# maxvar_scaling = 50 # old method
maxvar_scaling = 0.02 # Since we don't divide x,y by their stdev, things get large

# Motion track using background / foreground segmentation of moving objects
# These are the present default values except detect_shadows which we allow to change:
back_sub = cv.createBackgroundSubtractorMOG2(history = 500, varThreshold = 16, detectShadows = detect_shadows)

frame_end = frame_start + frames_to_proc
frame_num = 0

if READ_FILE:
	cap = cv.VideoCapture( os.path.join(fdir, fname))
	# Advance the capture to skip the first frames we don't want:
	cap.set(cv.CAP_PROP_POS_FRAMES, frame_start)
else:
	cap = open_live_capture(read_livecam_id)

# Configure output stream:
frame_width = int(cap.get(3))
frame_height = int(cap.get(4))
# out_fn = fname.replace('.mov', '_Annotated.mp4v')
out_fn = fname.replace('.mov', '_test2Annotated.avi')

# Initialize cat and mouse lists
cats = [] # Both moving and still cats
mice = [] # Only moving mice
prev_mcats = [] # previous frame's moving cats
prev_scats = [] # previous frame's still cats


if WRITE_OUTPUT:
	out = cv.VideoWriter(os.path.join(fdir, out_fn),
						  cv.VideoWriter_fourcc('M','P','4','V'), 24, (frame_width,frame_height))
	
	if not out.isOpened():
		raise ValueError('VideoWriter failed to initialize')

while True:
	if not cap.isOpened():
		print('Live camera capture failed to open, trying again...')
		cap = open_live_capture(read_livecam_id) 

	frame_num += 1
	
	if READ_FILE and frame_num > frame_end:
		break
	
	# Capture frame-by-frame
	ret, frame = cap.read()
	if not ret:
		print("Can't receive frame (stream end?).  Trying again")
		# break # let the loop proceed for now, fix crashing issue?
		continue
	
	# Apply background subtraction
	fg_mask = back_sub.apply(frame)

	# Background subtract only contains values of 255 = moving foreground, 127 = shadows
	# So apply threshold of 255 for foreground objects:
	fg_mask = cv.compare(fg_mask, 255, cv.CMP_EQ)

	# Binary erosion to remove small motion pixel groups
	# set the kernal
	kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))
	# Apply erosion
	fg_mask = cv.morphologyEx(fg_mask, cv.MORPH_OPEN, kernel)

	# Find contours
	contours, hierarchy = cv.findContours(fg_mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)    

	# Apply cat and mouse contour area filters to reject larger and smaller objects:
	# TODO: A mouse that's not where the mouse is supposed to be could still be part of a cat, like just the head moving
	#  We should test this and move it to the cat list if it's not where the mouse should be?
	# Optimization: get both centroid and area in one fell swoop from Moments:
	contour_moments = [cv.moments(c) for c in contours]
	contour_areas = [m['m00'] for m in contour_moments]

	# Some awkwardness to properly handle empty lists:
	cat_idxs = [i for i, a in enumerate(contour_areas) if a > min_cat_contour_area and a < max_cat_contour_area ]
	cat_contours = [contours[idx] for idx in cat_idxs]
	# Centroids (order should be column, row ? )
	cat_centroids = [ ( int(m['m10']/m['m00']), int(m['m01']/m['m00']) ) 
							 for m in [contour_moments[i] for i in cat_idxs] ]
	mouse_idxs = [i for i, a in enumerate(contour_areas) if a > min_mouse_contour_area and a < max_mouse_contour_area]
	mouse_contours = [contours[idx] for idx in mouse_idxs]
	mouse_centroids = [ ( int(m['m10']/m['m00']), int(m['m01']/m['m00']) ) 
							 for m in [contour_moments[i] for i in mouse_idxs] ]

	# Compare to previous frame's cats:
	# Store current moving cats, id is arbitrary but might be useful later if things get out of order:
	# TODO: Add linefit est. direction of facing and anisotropy of cat blob for mouse behavior
	cur_mcats = [{'id':n, 'contour':cont, 'centroid':cent, 'moving':True, 'timestamp':0} 
					for n, cont, cent in zip(range(len(cat_contours)), cat_contours, cat_centroids)]
	# Only track moving mice for now:
	mice = [{'id':n, 'contour':cont, 'centroid':cent}
					for n, cont, cent in zip(range(len(mouse_contours)), mouse_contours, mouse_centroids)]

	# Compare to previous moving cats, identify cases where there is no moving cat nearby anymore
	#  This could mean the cat moved very far away, OR became still, in which case we still need to track them
	# TODO: Move this input parameter up, convert to mm:
	# TODO: This could be improved with knowledge of the cat's previous velocity?  Although cats can turn on a dime
	# We also cover the case where a previous still cat starts moving again
	
	possible_stopped_cats = [] # cats that became still this frame
	if any(prev_mcats):
		# Check for previously moving cats becoming still in this frame
		if not any(cur_mcats):
			# No moving cats detected, every previous moving cat becomes a stopped cat candidate:
			possible_stopped_cats += prev_mcats
		else:
			# Try to match moving cats in this frame to moving cats in previous frame
			cur_cents = np.array( [cat['centroid'] for cat in cur_mcats] )
			
			for cat in prev_mcats:
				cent = np.array(cat['centroid'])
				dists = np.linalg.norm( cur_cents - cent, axis=1 )
	
				if dists.min() > max_same_cat_move_dist_pix:
					# We didn't find a previously moving cat close enough to call this the same cat
					# See if the previous moving cat became still
					possible_stopped_cats.append(cat)

	# Check for previously still cats that started moving, call these "restarted" cats
	# Stored as an index into the previous still cats list
	possible_restarted_cat_idxs = []
	if any(prev_scats) and any(cur_mcats):
		cur_cents = np.array( [cat['centroid'] for cat in cur_mcats] )

		for idx, cat in enumerate(prev_scats):
			cent = np.array(cat['centroid'])
			dists = np.linalg.norm( cur_cents - cent, axis=1 )
			if dists.min() < max_same_cat_move_dist_pix:
				# We found a moving cat close to the previously still cat, possibly a restarted cat
				possible_restarted_cat_idxs.append(idx)

	cur_scats = prev_scats # start out with same still cat list, drop if they restarted movement
	if any(possible_restarted_cat_idxs):
		# TODO: Test region similarity to see if still cat really restarted or other cat just passed close by still cat?
		# Such a test may falsely say there's still a cat where the still cat was if it moved enough to get on the moving
		#  cat list but only moved slightly...  So for now just call it restarted without this test
		culled_cur_scats = [cur_scats[idx] for idx in range(len(cur_scats)) if idx not in possible_restarted_cat_idxs]
		cur_scats = culled_cur_scats

	# Process possible stopped cats: Did they stop or just move away from that spot really fast?
	# check for region similarity where cat was previously moving last frame
	for cat in possible_stopped_cats:
		# Compare previously moving cat stats to stats for the same contour in the present frame to see if they're still there: 
		prev_means = cat['means']
		prev_stdevs = cat['stdevs']

		# Calculate current frame stats within the contour of the previously moving cat:
		means, stdevs = calc_area_stats(frame, cat['contour'])
		
		# Make the comparison
		mean_frac_diffs = [abs(mp - mc)/mc for mp, mc in zip(prev_means, means)]
		stdev_frac_diffs = [abs(sp - sc)/sc for sp, sc in zip(prev_stdevs, stdevs)]
		if max(mean_frac_diffs) < max_mean_diff_frac and min(stdev_frac_diffs) < max_stdev_diff_frac:
			# A moving cat from the previous frame not moving in this frame has been identified as a still cat
			# Update the cat's stats from this frame so they're more recent:
			cat['means'] = means
			cat['stdevs'] = stdevs
			# Give the still at a unique id in the still cat list:
			cat['id'] = len(cur_scats)
			cat['moving'] = False
			cat['timestamp'] = int( datetime.now().timestamp() )
			cur_scats.append(cat)


	# Calculate stats on each moving cat area to propagate to the next frame:
	# NOTE: we need to store the region stats for the previously moving cat in the previous frame...
	# Speed / space tradeoff: we could buffer the previous frame and only look at it if we need to (no moving cat within max distance of prev moving cat), 
	#   good for speed
	# Or we could calculate the stats within the contour for every moving cat on every frame, since any one could become still next frame,
	#   good for space
	# To see if still cats have started moving, we also need the region stats for all previous still cats
	# For now we're taking the hit to speed and saving space - calculate ROI stats for every moving cat every frame
	for cat in cur_mcats:
		means, stdevs = calc_area_stats(frame, cat['contour'])
		cat['means'] = means
		cat['stdevs'] = stdevs    

	# Clear out still cats that are beyond the time where we want to forget about them:
	cur_scats_culled = [cat for cat in cur_scats if (datetime.now().timestamp() - cat['timestamp']) < still_cat_clear_seconds]
	cur_scats = cur_scats_culled
	
	prev_mcats = cur_mcats
	prev_scats = cur_scats

	# Lists of all cats & moving mice in this frame:
	cats = cur_mcats + cur_scats

	# initialize annotated frame:
	frame_ct = frame.copy()
	
	# Annotated frame:
	if SHOW_CONTOUR:
		frame_ct = cv.drawContours(frame, [cat['contour'] for cat in cur_mcats], -1, (0, 255, 0), 2)
		frame_ct = cv.drawContours(frame, [cat['contour'] for cat in cur_scats], -1, (255, 255, 0), 2)
		frame_ct = cv.drawContours(frame, mouse_contours, -1, (255, 0, 0), 2)
	elif SHOW_BBOX:
		for c in [cat['contour'] for cat in cur_mcats]:
			rect = cv.boundingRect(c)
			x,y,w,h = rect
			cv.rectangle(frame_ct, (x,y), (x+w,y+h), (0, 255, 0), 2)
		# Show still cats as yellow:
		for c in [cat['contour'] for cat in cur_scats]:
			rect = cv.boundingRect(c)
			x,y,w,h = rect
			cv.rectangle(frame_ct, (x,y), (x+w,y+h), (255, 255, 0), 2)
		for c in mouse_contours:
			rect = cv.boundingRect(c)
			x,y,w,h = rect
			cv.rectangle(frame_ct, (x,y), (x+w,y+h), (255, 0, 0), 2)

	# Draw centroids with extra markers if we're not using orientation markers:
	if not SHOW_ORIENTATION and SHOW_CENTROIDS:
		for c in cat_centroids:
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
	cv.imshow('Frame_final', frame_ct)
	# show_frame(frame_ct)

	if WRITE_OUTPUT:
		# Write it to the video output file:
		out.write(frame_ct)
	
	if cv.waitKey(1) == ord('q'):
		break

cap.release()
if WRITE_OUTPUT:
	out.release()
