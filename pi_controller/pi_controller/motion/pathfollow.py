from typing import Optional

from ..constants import Point, Tile
from ..path import Path
from .driver import MotionDriver
from ..custommap import to_tile

class PathFollower:

    def __init__(self,
                 motion_driver: MotionDriver,
                 path: Optional[Path] = None,
                 ):
        self.motion_driver = motion_driver
        self.motion_driver.subscribe_to_position(self._update_position)
        self._path = None
        if path:
            self.follow_path(path)

        self._last_tile: Optional[Tile] = None


    def follow_path(self, path: Path):
        """
        High-level call: give a path to follow; the MotionDriver will
        automatically pull from 
        """
    
        self._path = path

    def stop_following_path(self):
        """
        Stop path-following. Note that this probably won't stop any motion
        commands that have already been submitted.

        Blocks until the path-following loop has actualy stopped.
        """
        self._path = None  # _update_position callback will start no-op'ing
    
    def _update_position(self, current_position: Point) -> None:
        """
        Callback to receive updates from Klipper.

        This is called from the Klipper interface's websocket thread context,
        so we won't do much here, just put the update on a queue to hand off
        to our own worker thread context.
        """
        if self._path:
            current_tile = to_tile(current_position)
            
            if current_tile != self._last_tile:
                self._path.advance(current_tile)
