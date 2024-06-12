from typing import Optional, List
import threading
import logging

from ..constants import Point, Tile
from ..toolhead_trajectory import ToolheadTrajectory
from .driver import MotionDriver
from ..custommap import MapConfig, to_tile
from .styles import MotionStyle

logger = logging.getLogger(__name__)


class Toolhead:

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

        self.paused = threading.Event()


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
        
        self.path = path
        self.path.subscribe_to_extend(self._path_extended)
        self._enqueue_motion(path[:3])  # start us in motion!
        # Note that I'm submitting three units so that we have some buffer in 
        # the submitted queue.

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
        print("_update_position() called")
        if self.path:
            current_tile = to_tile(current_position, map_config=self.map_config)
            
            if current_tile != self.last_tile:
                self.path.advance(current_tile)
                
                last_tile_enqueued = self.path.last_committed()
                next_tile_up = self.path.first_uncommitted()
                if next_tile_up:
                    self._enqueue_motion([
                        last_tile_enqueued,
                        next_tile_up
                    ])
                else:
                    print("No further tiles in the path! Toolhead is pausing")
                    self.paused.set()

                
    def _enqueue_motion(self, path_segment: List[Tile]):
        """
        Given a path segment, convert it into motion!
        """
        self.path.commit_to_movement(path_segment[-1])  # tell the ToolheadTrajectory not to roll back this segment
        logger.debug(f"Enqueuing motion through {len(path_segment)} tiles: {path_segment}")
        self.motion_driver.enqueue_motion(
            self.motion_style.generate_motion(path_segment)
        )

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
        if self.paused.is_set():
            # Resume motion. Note that self.path.first_committed() should be valid here;
            # we really can't get into this state without having advanced down a ToolheadTrajectory already,
            # which means that self.path.last_committed() will have a value, and since we 
            # were extended already that means there are definitely fresh tiles to visit
            assert self.path.last_committed() == self.path[0], f"Expected to be paused at the first tile in the path, instead we're paused at {self.path.last_committed()} on path {self.path}???"
            self._enqueue_motion(self.path[:3])  # three tiles again to have some buffer

            self.paused.clear()  # Engine is going, alle ist gut
