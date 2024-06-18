# Cat computer vision module
# Motion track using background / foreground segmentation of moving objects and still objects that were moving
# Initially copy/pasted from cv_test_scripts/test_rpi_algo.py
# 
# Author: Chris

# TODO: Add FPS counter
import numpy as np
import cv2 as cv
from cv2 import aruco
import os
import time
from datetime import datetime
import threading

import logging


logger = logging.getLogger(__name__)


class CatVision():
	def __init__(self, board_width_mm=None, board_height_mm=None, display_annotated=True):

		if not board_width_mm:
			# TODO: Rough hardcoded values for now
			self.board_width_mm = 600 * 4  # 4x panels, each of which is 600mm (~23.6") wide
		if not board_height_mm:
			self.board_height_mm = 1180  # from CAD measurement

		self.cam_id = None
		self.display_annotated = display_annotated
		self.display_in_GUI = False
		self.display_slowmo_ms = 1 # wait this many ms between frames, 1 at minimum or bad things happen
		self.show_orientation = True
		self.show_contour = True
		self.show_bbox = True
		self.show_centroids = True

		# =================== Algorithm Parameters ===================
		self.detect_shadows = True # slower, but seems to be a lot more accurate

		# minimum and maximum object contour area to be tracked:
		# TODO: Calculate these after Aruco transform to put in real units (cm^2)
		# These will need updating regardless, just guesses based on original test camera and video
		self.min_cat_contour_area = 10000
		# self.min_cat_contour_area = 1000
		self.max_cat_contour_area = 250000

		self.min_mouse_contour_area = 250
		self.max_mouse_contour_area = 1000

		# maximum distance a cat might move between frames:
		self.max_same_cat_move_dist_pix = 50
		# We check if a moving cat's bounding box overlaps that of a previous still cat's, expanded by this factor,
		# to see if we should clear out the still cat
		self.restarted_cat_test_expand_bbox = 1.1
		# A cat must be moving but within the max frame-to-frame distance for this many frames before
		# 	it can be a candidate for being a still cat:
		self.min_frames_tracked_for_still = 4
		# clear memory of possible still cats after this many seconds:
		self.still_cat_clear_seconds = 18

		# Still cat settings
		# If the mean and stdev of each color channel is within 10% of what it was previously, there's still a cat there:
		# Caveat: watch out for poor lighting or when cat/board contrast is not high
		self.max_mean_diff_frac = 0.10
		self.max_stdev_diff_frac = 0.15
		# TODO: Apply some scaling with absolute pixel value so we don't get messed up by noise or quantization at low pixel values

		# For scaling displayed direction vector..
		self.maxvar_scaling = 0.02 # Since we don't divide x,y by their stdev, things get large


		# Calculated member vars
		self.back_sub = None 	# background subtractor object
		self.cap = None 		# cv VideoCapture object
		# 3x3 matrix for transforming image coordinates to board coordinates:
		self.transform_img_to_board = None
		# Rough guess for millimeters per pixel scale just using average of top and bottom board widths
		# (Actual scale will vary with position in image if there is any perspective "keystoning")
		self.rough_pix_to_mm = None

		self.cats = [] # Both moving and still cats
		self.mice = [] # Only moving mice
		self.prev_mcats = [] # previous frame's moving cats
		self.prev_scats = [] # previous frame's still cats

		self.is_running = False # used to control the run/update loop
		self.file_out = None # video output file stream


	@staticmethod
	def process_aruco_corners(frame, board_width_mm, board_height_mm):
		''' 
		Takes a single frame and extracts Aruco markers for the corners of the board,
		returns the 3x3 matrix for transforming img coordinate to board coordinates,
		also returns a rough estimate of image pixel scale (mm per pixel, NOT keystone corrected)

		Future feature: Once we have a variable number of "expansion panels" in the middle,
		we can look for Aruco markers on those as well to determine board with
			Caveat: if we miss one of the middle markers, we might not know, and we don't want to be
			way off.  So we could use the fixed board height to sanity check the aspect ratio
			we're seeing against what we think we'd get with the number of expansion panels we think we have?
		'''
		# TODO: Move these up to CCV init and pass in ArucoDetector as optimization?
		aruco_dict = aruco.getPredefinedDictionary(aruco.DICT_4X4_100)
		parms =  aruco.DetectorParameters()
		# Defaults for these are: min 3, max 23, step 10
		# This will need tweaking in the future, need to take images at min and max distances to board
		parms.adaptiveThreshWinSizeMin = 5
		parms.adaptiveThreshWinSizeMax = 15
		parms.adaptiveThreshWinSizeStep = 5  

		aruco_detector = aruco.ArucoDetector(aruco_dict, parms)

		markerCorners, markerIds, rejectedCandidates = aruco_detector.detectMarkers(frame)
		if (not all([i in markerIds.flatten() for i in range(4)])) or (not any(markerIds)):
			raise ValueError('Did not find all 4 corners of board.  TODO: Figure out how to propagate this error to user')

		# Uncomment for debug image:
		# frame_cp = frame.copy()
		# aruco.drawDetectedMarkers(frame_cp, markerCorners, markerIds)

		# plt.figure(figsize=(10,6));
		# plt.imshow(frame_cp)
		# plt.axis('off')

		# Get the outer corners of each of the 4 corners:
		# (Assumes ID = 0 is the upper left, and we go clockwise from there)
		
		id_idxs = np.argsort(markerIds.flatten())
		# Aruco corner coordinates are x, y, col, row NOT row, col , also start at top left and go clockwise
		# Just write out what they are as opposed to getting too "clever" to be readable here:
		markerCorners = [mc.astype(int) for mc in markerCorners]
		
		board_UL = markerCorners[id_idxs[0]][0][0]
		board_UR = markerCorners[id_idxs[1]][0][1]
		board_LR = markerCorners[id_idxs[2]][0][2]
		board_LL = markerCorners[id_idxs[3]][0][3]
		
		board_corners_img = np.array([board_UL, board_UR, board_LR, board_LL])

		# Assume lower left = (0,0) indexed coordinates for now, can change as needed
		board_corners_mm = np.array([(0, board_height_mm), (board_width_mm, board_height_mm), (board_width_mm, 0), (0,0)])
		
		# Perspective warp according to the 4 Aruco markers (OpenCV obnoxiously expects this to be in 32 bit floats)
		transform_img_to_board = cv.getPerspectiveTransform(board_corners_img.astype(np.float32), board_corners_mm.astype(np.float32))

		# Rough estimate of pixel scale based on averaging the length of top and bottom sides of board
		top_width_pix = board_width_mm/(board_UR[0] - board_UL[0])
		bot_width_pix = board_width_mm/(board_LR[0] - board_LL[0])
		rough_pix_to_mm = round( (top_width_pix + bot_width_pix)/2 )
		
		return transform_img_to_board, rough_pix_to_mm


	@staticmethod
	def im_x_y_to_board_x_y(im_coords, transform):
		''' Transform image coordinates (in col, row or x, y) to board coordinates (lower left is 0,0)'''
		# Mathematical definition: [t'x', t'y', t']' = transform * [x, y, 1]
		# Thus we tack on 1 to our original 2d coordinates to get a 3-vector, multiply the matrices, and divide the resulting x and y by the third (scaling) element
		result = np.matmul( transform, np.array([im_coords[0], im_coords[1], 1]).transpose())
		# Return properly scaled 2d coordinate
		return (result[0]/result[2], result[1]/result[2])


	@staticmethod
	def get_max_variance_vectors(contour, centroid):
		'''
		Essentially fit a line to the contour and get the line perpendicular to that,
		but using the trick of eigenvectors of the covariance

		TODO: Replace with cv.fitline?? might be faster, although it rules out calculating anisotropy
			(how much bigger axis of max variance is than the perpendicular axis)
		'''
		cr = np.reshape(contour, (contour.shape[0], 2))

		dcr = cr - centroid

		# The eigenvector of the covariance matrix with the larger eigenvalue is the direction of max variance
		covariance_mat = np.cov(dcr.T)
		eigenvalues, eigenvectors = np.linalg.eig(covariance_mat)

		# return the eigenvectors scaled by the eigenvalues (amount of variance along each axis)
		return [eigenvectors[:,i] * ev for i, ev in enumerate(eigenvalues)]


	@staticmethod
	def show_frame(frame, frame_buf=None):
		'''
		Directly dipslay annotated video on the frame buffer
		Useful for lightweight command line operation with no XWindows
		
		TODO: This is missing some steps to correctly stretch the output image or add the right amount of 
			emtpy space after each line in the frame buffer, but it kinda sorta works at some display resolutions.	
		'''
		if frame_buf is None:
			frame_buf = '/dev/fb0'
		frame_c = cv.cvtColor(frame, cv.COLOR_BGR2BGR565)
		with open(frame_buf, 'rb+') as buf:
			buf.write(frame_c)


	@staticmethod
	def open_live_capture(id):
		''' Making this its own method in case we want to do more handling later '''
		return cv.VideoCapture(id)


	@staticmethod
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


	@staticmethod
	def check_rect_intersect(rect1, rect2):
		'''
		Check for intersection of two bounding box rectangles
		Where they are given as tuples in the python OpenCV format of lowerleft_x, lowerleft_y, width, height)
		'''
		x1, y1, w1, h1 = rect1
		x2, y2, w2, h2 = rect2
		# Get centers
		cx1 = x1 + w1/2; cy1 = y1 + h1/2
		cx2 = x2 + w2/2; cy2 = y2 + h2/2
		# if x can be within bounds and y can be within bounds, they intersect
		return (abs(cx1-cx2) < 0.5*(w1+w2)) and (abs(cy1-cy2) < 0.5*(h1+h2))


	def start(self, cam_id=0, filename=None, frame_start=0, output_filename=None, display_in_GUI=False,
				display_slowmo_ms=1):
		'''
		Initialize and start detecting cats
			filename: Optional can load video from file using filename
			frame_start: Optionally jump ahead this many frames in the file before opening
			output_filename: If set, write annotated video to this filename
			display_in_GUI: If running in XWindows or other GUI, set this to True to display in
				an openCV window rather than attempt to display directly to the framebuffer as
				we do on command line.  If running from command line, set this to False.
			display_slowmo_ms: add a delay of this many milliseconds per frame when displaying
				only applies to GUI display, not framebuf, and needs to be a minimum of 1

		Currently this runs blocking forever, so needs to be in its own thread
		'''

		# Mixture of Gaussians backround/foreground segmentation algorithm:
		# Using default values except for detectShadows which we can change
		self.back_sub = cv.createBackgroundSubtractorMOG2(history = 500, varThreshold = 16,
														  detectShadows = self.detect_shadows)

		self.cam_id = cam_id
		self.display_in_GUI = display_in_GUI
		self.display_slowmo_ms = display_slowmo_ms

		if filename is not None:
			self.cap = cv.VideoCapture( filename )
			# Advance the capture to skip frames
			self.cap.set(cv.CAP_PROP_POS_FRAMES, frame_start)
		else:
			self.cap = self.open_live_capture(cam_id)
			# Uncomment to try this optimization for less latency:
			# cap.set(cv.CV_CAP_PROP_BUFFERSIZE, 3)

		# Open up the video stream for Aruco marker finding on first frame and size detection, then close it again
		if not self.cap.isOpened():
			raise ValueError(f'Could not open video stream')
		ret, frame = self.cap.read()
		if not ret:
			raise ValueError("Can't open first frame to read Aruco markers")

		# Configure output stream:
		frame_width = int(self.cap.get(3))
		frame_height = int(self.cap.get(4))
		if output_filename is not None:
			self.file_out = cv.VideoWriter(output_filename, 
								  cv.VideoWriter_fourcc('M','P','4','V'), 24, (frame_width,frame_height))
			
			if not self.file_out.isOpened():
				raise ValueError('VideoWriter failed to initialize')

		# Optimization: release the video stream and re-open later to avoid building up latency?
		self.cap.release()

		try:
			self.transform_img_to_board, self.rough_pix_to_mm = self.process_aruco_corners(frame,
																	self.board_width_mm, self.board_height_mm)
		except Exception as e:
			logger.error(f'Failed to detect all 4 Aruco markers with exception: {e}')


		# Optimization: reopen video stream after Aruco calculation, some copypasta:
		if filename is not None:
			self.cap = cv.VideoCapture( filename )
			# Advance the capture to skip frames
			self.cap.set(cv.CAP_PROP_POS_FRAMES, frame_start)
		else:
			self.cap = self.open_live_capture(cam_id)
			# Uncomment to try this optimization for less latency:
			# cap.set(cv.CV_CAP_PROP_BUFFERSIZE, 3)		
		if not self.cap.isOpened():
			raise ValueError(f'Could not open video stream')


		# Initialize or re-initialize cat and mouse lists
		self.cats = []
		self.mice = []
		self.prev_mcats = []
		self.prev_scats = []

		# Let the run loop know to keep running once we start it
		self.is_running = True 

		# ??? Do we spawn off run in its own thread now, or let that come from somewhere else?
		threading.Thread(target=self.run).start()
		# self.run()


	def run(self):
		while self.is_running:
			if not self.cap.isOpened():
				logger.error('Live camera capture failed to open, trying again...')
				self.cap = self.open_live_capture(self.read_livecam_id)
			
			# Capture frame-by-frame
			ret, frame = self.cap.read()
			if not ret:
				logger.warn("Can't receive frame (stream end?).  Trying again")
				# break # let the loop proceed for now, fix crashing issue?
				# TODO: Handle reading from files, right now we read forever
				continue	

			cats, mice = self.find_cats(frame)
			# TODO: Send protobuf message here with cat and mouse info?
			# TODO: Copy these into queue

		# If we're not running anymore, close up
		if self.cap is not None:
			self.cap.release()
		if self.file_out:
			self.file_out.release()


	def stop(self):
		''' Just set a variable to stop the update loop presumably running in its own thread '''
		self.is_running = False
		# Ugly hack, wait a little for loop running in start() thread to stop
		time.sleep(0.2)

		# Some redundancy here, though currently the loop in start can reopen these again if we don't wait long enough :(
		if self.cap is not None:
			self.cap.release()
		if self.file_out:
			self.file_out.release()


	def find_cats(self, frame):
		'''
		Does the actual cat finding and coordinate transforms
		For now just updates member vars and puts a timestamp for the latest calculation
		TODO: Send gcode messages on each frame update?
		'''

		# Apply background subtraction
		fg_mask = self.back_sub.apply(frame)

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
		cat_idxs = [i for i, a in enumerate(contour_areas) if a > self.min_cat_contour_area and a < self.max_cat_contour_area ]
		cat_contours = [contours[idx] for idx in cat_idxs]
		# Centroids (order should be column, row)
		cat_centroids = [ ( int(m['m10']/m['m00']), int(m['m01']/m['m00']) ) 
								 for m in [contour_moments[i] for i in cat_idxs] ]
		mouse_idxs = [i for i, a in enumerate(contour_areas) if a > self.min_mouse_contour_area and a < self.max_mouse_contour_area]
		mouse_contours = [contours[idx] for idx in mouse_idxs]
		mouse_centroids = [ ( int(m['m10']/m['m00']), int(m['m01']/m['m00']) ) 
								 for m in [contour_moments[i] for i in mouse_idxs] ]

		# Compare to previous frame's cats:
		# Store current moving cats, id is arbitrary but might be useful later if things get out of order:
		# TODO: Add linefit est. direction of facing and anisotropy of cat blob for mouse behavior
		cur_mcats = [{'id':n, 'contour':cont, 'centroid':cent, 'moving':True, 'frames_tracked':1, 'timestamp':0} 
						for n, cont, cent in zip(range(len(cat_contours)), cat_contours, cat_centroids)]
		# Only track moving mice for now:
		self.mice = [{'id':n, 'contour':cont, 'centroid':cent}
						for n, cont, cent in zip(range(len(mouse_contours)), mouse_contours, mouse_centroids)]

		# Compare to previous moving cats, identify cases where there is no moving cat nearby anymore
		#  This could mean the cat moved very far away, OR became still, in which case we still need to track them
		# TODO: Move this input parameter up, convert to mm:
		# TODO: This could be improved with knowledge of the cat's previous velocity?  Although cats can turn on a dime
		# We also cover the case where a previous still cat starts moving again
		
		possible_stopped_cats = [] # cats that became still this frame
		if any(self.prev_mcats):
			# Check for previously moving cats becoming still in this frame
			if not any(cur_mcats):
				# No moving cats detected, every previous moving cat becomes a stopped cat candidate:
				# NOTE: This may be yielding some false positives when things go out of frame,
				#   things change conformation and become smaller, etc...
				#   Maybe there's a better way to handle this
				possible_stopped_cats += self.prev_mcats
			else:
				# Try to match moving cats in this frame to moving cats in previous frame
				cur_cents = np.array( [cat['centroid'] for cat in cur_mcats] )
				
				for cat in self.prev_mcats:
					cent = np.array(cat['centroid'])
					dists = np.linalg.norm( cur_cents - cent, axis=1 )
		
					if dists.min() > self.max_same_cat_move_dist_pix:
						# We didn't find a previously moving cat close enough to call this the same cat,
						# And it's been tracked for a minimum number of frames
						# See if the previous moving cat became still
						if cat['frames_tracked'] >= self.min_frames_tracked_for_still:
							possible_stopped_cats.append(cat)
					else:
						# We found at least one moving cat close enough to be the same cat
						# Copy over the number of tracked frames from the prev cat and add one
						idx = np.argmin(dists)
						cur_mcats[idx]['frames_tracked'] = cat['frames_tracked'] + 1

		# Check for previously still cats that started moving, call these "restarted" cats
		# Stored as an index into the previous still cats list
		possible_restarted_cat_idxs = []
		if any(self.prev_scats) and any(cur_mcats):
			# Note bounding rect returns x,y, width, height
			cur_bboxes = [cv.boundingRect(cat['contour']) for cat in cur_mcats]

			for idx, cat in enumerate(self.prev_scats):
				# TODO optimization: only calculate previous still cat bbox once and cache it?
				prev_bbox = list(cv.boundingRect(cat['contour']))
				# Add some tolerance:
				# Scale up the bounding box (remember it's a list in order center_x, center_y, width, height)
				prev_bbox[2] = round(prev_bbox[2] * self.restarted_cat_test_expand_bbox)
				prev_bbox[3] = round(prev_bbox[3] * self.restarted_cat_test_expand_bbox)

				# Check if any moving cat bbox overlaps with the previous still cat bbox expanded by tolerance
				for bbox in cur_bboxes:
					if self.check_rect_intersect(prev_bbox, bbox):
						possible_restarted_cat_idxs.append(idx)
						break
					

		cur_scats = self.prev_scats # start out with same still cat list, drop if they restarted movement
		if possible_restarted_cat_idxs:
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
			means, stdevs = self.calc_area_stats(frame, cat['contour'])
			
			# Make the comparison
			mean_frac_diffs = [abs(mp - mc)/mc for mp, mc in zip(prev_means, means)]
			stdev_frac_diffs = [abs(sp - sc)/sc for sp, sc in zip(prev_stdevs, stdevs)]
			if max(mean_frac_diffs) < self.max_mean_diff_frac and min(stdev_frac_diffs) < self.max_stdev_diff_frac:
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
			means, stdevs = self.calc_area_stats(frame, cat['contour'])
			cat['means'] = means
			cat['stdevs'] = stdevs    

		# Clear out still cats that are beyond the time where we want to forget about them:
		cur_scats_culled = [cat for cat in cur_scats if (datetime.now().timestamp() - cat['timestamp']) < self.still_cat_clear_seconds]
		cur_scats = cur_scats_culled
		
		self.prev_mcats = cur_mcats
		self.prev_scats = cur_scats

		# Lists of all cats & moving mice in this frame:
		self.cats = cur_mcats + cur_scats

		# Generate board coordinates for all centroids:
		if self.transform_img_to_board is not None:
			logger.debug('Applying transform from image to board coordinates')
			for cat in self.cats:
				cat['centroid_board'] = self.im_x_y_to_board_x_y( cat['centroid'], self.transform_img_to_board )
			for mouse in self.mice:
				mouse['centroid_board'] = self.im_x_y_to_board_x_y( mouse['centroid'], self.transform_img_to_board )


		# We're done if we're not displaying an annotated image
		# TODO: We're skipping the direction vector calculation by exiting out here.  We may want to send that out.
		#       If so it's calculated below under show_orientation
		if not self.display_annotated:
			return self.cats, self.mice

		# initialize annotated frame:
		frame_ct = frame.copy()
		
		# Annotated frame:
		if self.show_contour:
			frame_ct = cv.drawContours(frame, [cat['contour'] for cat in cur_mcats], -1, (0, 255, 0), 2)
			frame_ct = cv.drawContours(frame, [cat['contour'] for cat in cur_scats], -1, (255, 255, 0), 2)
			frame_ct = cv.drawContours(frame, mouse_contours, -1, (255, 0, 0), 2)
		if self.show_bbox:
			for c in [cat['contour'] for cat in cur_mcats]:
				rect = cv.boundingRect(c)
				x,y,w,h = rect
				cv.rectangle(frame_ct, (x,y), (x+w,y+h), (0, 255, 0), 2)
			# Show still cats as cyan:
			for c in [cat['contour'] for cat in cur_scats]:
				rect = cv.boundingRect(c)
				x,y,w,h = rect
				cv.rectangle(frame_ct, (x,y), (x+w,y+h), (255, 255, 0), 2)
			for c in mouse_contours:
				rect = cv.boundingRect(c)
				x,y,w,h = rect
				cv.rectangle(frame_ct, (x,y), (x+w,y+h), (255, 0, 0), 2)

		# Draw centroids with extra markers if we're not using orientation markers:
		if not self.show_orientation and self.show_centroids:
			for c in cat_centroids:
				frame_ct = cv.drawMarker(frame_ct, c, (0, 0, 255), markerType=cv.MARKER_TILTED_CROSS, 
										 markerSize=15, thickness=2, line_type=cv.LINE_AA)
		elif self.show_orientation:
			# Draw eigenvectors of the covariance matrix scaled by eigenvalues
			# Gets across "direction" axis of variance, and if they're equally sized it's symmetric
			for c, cent in zip(cat_contours, cat_centroids):
				eigenvecs = self.get_max_variance_vectors(c, cent)
				for ev in eigenvecs:
					vary = round(self.maxvar_scaling*ev[0])
					varx = round(self.maxvar_scaling*ev[1])
					# Sign of max variance vector is arbitrary, so draw a line in both + and - directions from centroid
					frame_ct = cv.line( frame_ct, (cent[0]-vary, cent[1]-varx), (cent[0]+vary, cent[1]+varx), (0, 0, 255), 2 )
		
		# Display the resulting frame
		if self.display_in_GUI:
			# If running in XWindows or other GUI rather than command line
			cv.imshow('Frame_final', frame_ct)
			# Need this as well in order to display CV window properly in GUI
			if cv.waitKey(self.display_slowmo_ms) == ord('q'):
				return self.cats, self.mice
		else:
			# Command line frame buffer display:
			self.show_frame(frame_ct)

		if self.file_out is not None:
			# Write it to the video output file:
			# TODO: Writing file output is not necessarily thread safe
			self.file_out.write(frame_ct)

		return self.cats, self.mice



if __name__ == '__main__':
	# Test run
	run_for_seconds = 120
	print(f'Testing CatVision and intentionally stopping after {run_for_seconds} seconds:')
	ccv = CatVision()
	# Uncomment to play video file in cases where we can't access live camera feeed:
	ccv.start(filename=None, display_in_GUI=True)
	# ccv.start(filename='C:\\Chris\\cattown\\cat_chaos.mp4', display_in_GUI=True, display_slowmo_ms=50)
	# ccv.start()
	time.sleep(run_for_seconds)
	ccv.stop()