from typing import Optional, List
import threading
import logging

from ..constants import Point, Tile
from ..toolhead_trajectory import ToolheadTrajectory
from .gcodes import UseAbsoluteCoordinates
from .driver import MotionDriver
from ..custommap import MapConfig, to_tile
from .styles import MotionStyle

logger = logging.getLogger(__name__)


class Toolhead:

    # How far ahead to buffer tiles in the move queue.
    MOVE_BUFFER_DEPTH_TILES = 50

    def __init__(self,
                 motion_driver: MotionDriver,
                 starting_motion_style: MotionStyle,
                 map_config: MapConfig,
                 path: Optional[ToolheadTrajectory] = None,
                 ):
        self.motion_driver = motion_driver
        self.motion_driver.subscribe_to_position(self._update_position)
        self.map_config = map_config

        self.path: Optional[ToolheadTrajectory] = None
        if path:
            self.follow_path(path)

        self.motion_style = starting_motion_style

        self.last_tile: Optional[Tile] = None

        self.paused_or_pausing = threading.Event()
        # self.on_path = threading.Event()  # will be set at startup once we hit the start of the path

        # Make sure we're using absolute coordinates
        self.motion_driver.enqueue_motion(UseAbsoluteCoordinates())  # todo this is syntactically awkward and I don't know where it belongs

        logger.info(f"Toolhead ready! Starting position: {self.get_current_tile()}")


    def get_current_tile(self) -> Tile:
        """
        Ask the MotionDriver where the mouse is currently.
        """
        return to_tile(self.motion_driver.get_current_position(), self.map_config)

    def follow_path(self, path: ToolheadTrajectory):
        """
        Start following the attached Path. Toolhead will take it 
        all the way to the last tile, at which point it'll wait for 
        more tiles to be added for the Path (which should then get consumed).
        """
        
        logger.info(f"Following path: {path}")
        self.path = path
        self.path.subscribe_to_extend(self._path_extended)
        if len(self.path) > 1:
            self._enqueue_motion(path[:self.MOVE_BUFFER_DEPTH_TILES])  # start us in motion!
            # Note that I'm submitting three units so that we have some buffer in 
            # the submitted queue.
        else:
            logger.info("Toolhead asked to follow an empty path; will start paused")
            
            if len(self.path) == 0:    
                current_tile = self.get_current_tile()
                logger.debug(f"Toolhead path is completely empty; pre-populating with where we are, {current_tile}")
                path.extend([current_tile])  # current tile is in the path...
                path.commit_to_movement(current_tile)  # ... and "committed to"
                # self.on_path.set()  # We're definitely on path
                self.paused_or_pausing.set()  # we'll set this after path.extend() so the callback doesn't try to start us again

    def set_motion_style(self, motion_style: MotionStyle):
        """
        Adjust the motion style. This will affect all motion that hasn't been
        committed to yet, as motion styles are applied "just in time" when
        motion is submitted to the MotionDriver.
        """

    def stop_following_path(self):
        """
        Stop path-following. Note that this probably won't stop any motion
        commands that have already been submitted.

        Blocks until the path-following loop has actualy stopped.
        """
        self.path = None  # _update_position callback will start no-op'ing
    
    def _update_position(self, current_position: Point) -> None:
        """
        Callback to receive updates from Klipper. Checks to see whether we've 
        moved into a new tile, and if we have, then tries to enqueue motion to
        the next tile down.
        """
        if self.path:
            current_tile = to_tile(current_position, map_config=self.map_config)
            
            if current_tile != self.last_tile:
                logger.debug(f"Entered new tile! {current_tile}")
                
                # if not self.on_path.is_set() and current_tile in self.path:
                #     # Consider ourselves on-path as soon as we encounter the path. Note that
                #     # this might have unexpected behavior if we translate across the path to get to 
                #     # the start of the path; let's just not do that please
                #     logger.info(f"Reached tile {current_tile}; toolhead is on-path!")
                #     self.on_path.set()

                if True: # self.on_path.is_set():

                    # Pop off the Trajectory to represent movement
                    try:
                        num_advanced = self.path.advance(current_tile)
                    except IndexError:
                        logger.debug("  > We're off-path again, so we won't advance the path for this one")
                        # self.on_path.clear()
                        return
                    
                    if num_advanced > 0:
                        self.last_tile = current_tile
                        next_tiles_up = self.path.first_n_uncommitted(num_advanced)

                        if next_tiles_up:
                            # Path segment needs to start at the first committed-to tile and go from there
                            tiles_to_move = [self.path.last_committed()] + next_tiles_up
                            self._enqueue_motion(tiles_to_move)
                            return
                
                        else:
                            # There's nothing uncommitted-to in the trajectory, so we'll consider ourselves "pausing"
                            if not self.paused_or_pausing.is_set():
                                logger.warning("No further tiles in the path! Toolhead will pause")
                                self.paused_or_pausing.set()

                
    def _enqueue_motion(self, path_segment: List[Tile]):
        """
        Given a path segment, convert it into motion!
        """
        self.path.commit_to_movement(path_segment[-1])  # tell the ToolheadTrajectory not to roll back this segment
        logger.debug(f"Enqueuing motion through {len(path_segment)} tiles: {path_segment}")
        motion = self.motion_style.generate_motion(path_segment)
        logger.debug(f"  > gcode moves: {motion}")
        self.motion_driver.enqueue_motion(motion)

    def _path_extended(self):
        """
        Toolhead does a "1-for-1" queue replacement, pushing another intertile
        move to the MotionDriver each time we arrive at a new tile (and thus complete a 
        previous intertile move). While it's going, Klipper provides the "heartbeat", 
        pushing us updates over websockets which trigger the _update_position() callback
        which in turn advances us forward in the ToolheadTrajectory object. Once we hit the end of a Path 
        object, though, this regular feedback cycle (ie incoming websocket updates triggering
        new outgoing gcode scripts) stops; we don't send a new motion request and so we stop
        getting motion_report updates back from Klipper.

        To restart this virtuous cycle when appropriate, we use this callback from Path
        to get notified when there's new juicy goodness in the Path that we can start traversing.
        If the cycle is already going then we're chill and don't need to do anything, but if
        we've hit the end of the ToolheadTrajectory and stopped already (which is tracked using self.paused)
        then we'll resume by 
        """
        if self.paused_or_pausing.is_set():
            logger.info("Resuming motion!")
            # Resume motion. Note that we have ceased to 
            
            # TODO track the actual outgoing buffer depth here (if we're mid-motion this will commit "too much")
            self._enqueue_motion(self.path.first_n_uncommitted(self.MOVE_BUFFER_DEPTH_TILES))
            self.paused_or_pausing.clear()  # Engine is going, alle ist gut
        else:
            logger.debug("Path extended; toolhead is already in motion; fuck it let's enqueue something anyway")
            if self.path and len(self.path) > 3:  # rule out None before we have a path object
                self._enqueue_motion(self.path.first_n_uncommitted(self.MOVE_BUFFER_DEPTH_TILES))
