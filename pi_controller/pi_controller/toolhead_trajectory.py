# toolhead_trajectory.py
# 
# A class for representing paths of motion along the play wall.
# This serves as a central hinge point for translating mapping
# into physical motion and back.
# 
# Named "Toolhead" because that's the term that Klipper uses
# to describe the thing the 3D printer is moving around (an extruder
# or whatever). In this case the tool is a magnet :)

from typing import List, Union, Optional, Callable
from dataclasses import dataclass
import threading
import copy
from .constants import Tile, Path
import logging


logger = logging.getLogger(__name__)


class ToolheadTrajectory:
    """
    A representation of the path for the mouse to follow. Kind of a custom 
    queue data structure, where the PathPlanner is adding tiles on the end / 
    redoing the path toward the end while Toolhead chews tiles off the front
    (tracking the progress of the physical mouse). Thread-safe (thorough
    lock use, not at all optimized) and should be conflict-free.

    Supports partial rollback with a construct of "commitment"; when we send G-Code
    to Klipper we can't undo it, so we submit motion one tile at a time and mark
    tiles that have had G-Code submitted for them as "committed" / not-rollback-able.

    There should only be one Path object, which describes the path of the toolhead itself.
    (We don't want to crash into mounting tabs, which are mostly flush for Open Sauce but
    some of them aren't quite; so we'll use path-planning to navigate the board even when 
    we don't have a toy attached, because it avoids obstacles and thus avoids mounting 
    tabs too.)

    This class serves as an interface between path planning and hardware, and
    so it takes on responsibility for thread safety.

    TODO support interjecting PickUpMouse / DropOffMouse actions into the path somehow
    """

    def __init__(self,
                 tiles: Optional[Path] = None
                 ):
        """
        """
        self._lock = threading.Lock()
        # List of tiles that the path goes through, in order
        self._tiles = tiles or []  # n.b. you can't say `tiles: Optional... = []` or else Weird Shit Happens
        # Segment of the Path that we've submitted to Klipper already (see commit_...() below)
        self._committed_destination: Optional[Tile] = None  
        self._extend_callbacks = []

    # --------------------------- Interface for MotionDriver --------------------------- #

    def advance(self, current_tile: Tile) -> int:
        """
        Advance along the path to the current position -- that is, 
        drop every Tile along the path that comes before the tile that
        we're currently on.

        Returns the number of tiles removed from the stack, so we can
        replace them in the correct number. (This will happen often when
        we do fast moves with lots of tiles crossed per websocket update!)

        Note that this method leaves current_tile in the Path object. 
        For example:

        ```
        >>> path = Path([(0, 1), (1, 1), (1, 2), (2, 2)])
        >>> path.advance((1, 2))
        >>> path
        Path([(1, 2), (2, 2)])
        
        ```

        I think this should work even for paths that cross themselves. Not that
        we're likely to encounter that? Idk why I'm so concerned about this edge case...

        Anyway this will be called by the motion platform to report where
        the stage is.

        Raises IndexError if the tile passed is not present in the path.
        """
        try:
            with self._lock:
                tile_index = self._tiles.index(current_tile)

                # TODO debugging code rm
                if tile_index != 0 and self._committed_destination in self._tiles[:tile_index]:
                    # This really shouldn't be happening but I believe that it is somehow?
                    logger.warn("Advancing path past self._committed_destination! wtf")
                    logger.warn(f"self: {self}")
                    logger.warn(f"self._committed_destination: {self._committed_destination}")
                    logger.warn(f"tile_index: {tile_index}")


                self._tiles = self._tiles[tile_index:]  # leaves current_tile in the list
                if tile_index != 1:
                    logger.debug(f"Advanced path by {tile_index}")
                return tile_index  # tile_index=0 means 0 tiles removed etc.
            
        except ValueError as e:
            raise IndexError(f"Tile {current_tile} is not in path {self}!") from e

    def commit_to_movement(self, target_tile: Tile):
        """
        Called when we submit motion to Klipper to limits the amount that other
        clients can truncate off the path.
        
        Raises IndexError if target_tile is not on the Path.

        Note that in practice the committed destination should never "go stale" and fall
        off the front end of the path; self_committed_destination should always be contained
        in self._tiles, because in order to actually move the toolhead to a different tile
        we would have to commit to moving there first. So we can assume that 
        self._committed_destination remains valid.
        """
        with self._lock:
            if not target_tile in self._tiles:
                raise IndexError(f"Tile {target_tile} is not in path {self}!")
            self._committed_destination = target_tile

    def subscribe_to_extend(self, callback: Callable):
        """
        Toolhead needs to know when the Path gets extended; this way it can
        "bottom out" at the end of a Path that hasn't gotten updated, stop, then resume
        when the Path is extended. (See Toolhead._path_extended() !)

        This method lets Toolhead install a callback that gets called when extend()
        is invoked. Callbacks have no arguments, it's assumed that 
        """
        with self._lock:
            if callback not in self._extend_callbacks:
                self._extend_callbacks.append(callback)

    # --------------------------- Interface for PathPlanner --------------------------- #        

    def extend(self, new_segment: Path):
        """
        Extend with another path segment.
        """
        with self._lock:
            self._tiles.extend(new_segment)

        logger.debug(f"Extended path by {len(new_segment)} tiles: {self}")

        for callback in self._extend_callbacks:
            callback()  # again, used by Toolhead to know that it's time to resume
        
    def clear(self) -> Optional[Tile]:
        """
        Attempt to drop as much of the upcoming path as we can.

        Return the last Tile that we are committed to moving to.

        If we haven't committed to any movement, drops all but the current
        tile and returns that tile.

        If the trajectory is totally empty, return None.
        """
        if len(self._tiles) > 0:
            return self.truncate_at(self[0])  # attempt to truncate at the starting position


    def truncate_at(self, end_tile: Tile) -> Tile:
        """
        Attempt to drop all Path beyond the indicated tile.

        Return either the requested Tile or the last Tile that we're
        committed to moving to, whichever is farther along the path.
        """
        if self._tiles:  # if self._tiles is still None then this should have no effect
            with self._lock:
                # We'll end either where we've committed to end or where we're 
                # trying to end, whichever is farther out (that's correct yea??)

                if end_tile not in self._tiles:
                    raise IndexError(f"Tile {end_tile} is not in path {self}!")
                
                # If we've committed to a destination, then we might only be able 
                # to truncate that far back
                if self._committed_destination:
                    truncate_end_index = max(
                        self._tiles.index(self._committed_destination),
                        self._tiles.index(end_tile)
                    )
                else:
                    truncate_end_index = self._tiles.index(end_tile)
                
                n_truncated = len(self._tiles) - truncate_end_index - 1
                self._tiles = self._tiles[:truncate_end_index + 1]  # keep the end_tile in the list
                
                logger.debug(f"Path truncated by {n_truncated}: {self}")
                return self._tiles[-1]
    
    # --------------------------- Utility functions for anyone --------------------------- #

    def get_tiles(self) -> Path:
        """
        Pull out the tiles contained within the Path object.

        Copies on access so that accessors don't inadvertently reach back in 
        / around the lock and mutate the internal list.
        """
        with self._lock:
            return copy.copy(self._tiles)  # shallow-copy so that we don't accidentally list mumble mutate

    def __len__(self):
        with self._lock:  # TODO is this needed?
            return len(self._tiles)

    def last_committed(self) -> Optional[Tile]:
        """
        The last tile we committed to.
        be
        """
        with self._lock:
            return self._committed_destination

    def first_n_uncommitted(self, n: int) -> Optional[List[Tile]]:
        """
        The next tile past that one... if there is such a tile. If we've already
        committed to the whole path, then this returns None.
        """
        with self._lock:
            if self._committed_destination:
                # Should never raise ValueError because we can't move away from the tile in
                # self._committed_destination without committing to a further tile first
                committed_index = self._tiles.index(self._committed_destination)
                try:
                    return self._tiles[committed_index + 1 : committed_index + 1 + n]
                except IndexError:
                    return None  # We've hit the end of the list


    def __getitem__(self, key: Union[int, slice]) -> Union[Tile, Path]:
        """
        Support integer index and slice access.

        For example, you can say:

        >>> path = Path((0,0), (0,1), (1,1), (1,2))
        >>> path[1]  # access by index
        (0, 1)
        >>> path[0:2]  # slice
        ((0, 0), (0, 1), (1, 1))

        This is low-key partly for backward compatibility, because
        I'm dropping this in to replace a `Path = List[Tile]` type alias.

        Raises an IndexError if the index/slice is out of bounds.

        Copies on access so that accessors don't inadvertently reach back in 
        / around the lock and mutate the internal list.
        """
        with self._lock:
                return self._tiles[key]

    def __contains__(self, tile: Tile):
        """
        Support `if tile in trajectory:` syntax 
        """
        with self._lock:
            return tile in self._tiles

    def __str__(self) -> str:
        # I keep trying to print(self) during critical sections in which
        # I already have the lock held, so I'm not going to access it here.
        # That exposes us to edge cases in which self._tiles gets mutated while
        # we're translating it to str, in which case............ idk! We'll
        # figure it out!
        return f"Path: {len(self._tiles)} tiles, {self._tiles}"