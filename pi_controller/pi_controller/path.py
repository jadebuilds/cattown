# path.py
# 
# A class for representing paths of motion along the play wall.
# This serves as a central hinge point for translating mapping
# into physical motion and back.

from typing import List, Union, Optional
import threading
import copy
from .constants import Tile


class Path:
    """
    A representation of the path for the mouse to follow.

    TODO what happens when we switch mice? Do we instantiate a new path 
    or update the old one? I'm assuming we'll have one fixed Path which is
    kind of the "path for the toolhead" rather than the path for any individual
    mouse, and it will just happen to include stops to pick up and drop off
    mice along the way. I think that's simpler than trying to maintain separate
    state per mouse and swap back and forth. But let's discuss 🙏

    This class serves as an interface between path planning and hardware, and
    so it takes on responsibility for thread safety.
    """

    def __init__(self,
                 tiles: Optional[List[Tile]] = None
                 ):
        """
        """
        self._lock = threading.Lock()
        # List of tiles that the path goes through, in order
        self._tiles = tiles or []  # n.b. you can't say `tiles: Optional... = []` or else Weird Shit Happens
        # Segment of the Path that we've submitted to Klipper already (see commit_...() below)
        self._committed_destination: Optional[Tile] = None  

    def advance(self, current_tile: Tile):
        """
        Advance along the path to the current position -- that is, 
        drop every Tile along the path that comes before the tile that
        we're currently on.

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
                self._tiles = self._tiles[tile_index:]  # leaves current_tile in the list
        except ValueError:
            raise IndexError(f"Tile {current_tile} is not in path {self}!")

    def commit_to_movement(self, target_tile: Tile):
        """
        Call me when we submit motion to Klipper to limits the amount that other
        clients can truncate off the path.
        
        Raises IndexError if target_tile
        """
        with self._lock:
            if not target_tile in self._tiles:
                raise IndexError(f"Tile {target_tile} is not in path {self}!")
            self._committed_destination = target_tile
        

    def extend(self, new_segment: 'Path'):            
        """
        Extend with another path segment.
        """
        with self._lock:
            self._tiles.extend(new_segment._tiles)

    def clear(self) -> Tile:
        """
        Attempt to drop as much of the upcoming path as we can.

        Return the last Tile that we are committed to moving to.

        If we haven't committed to any movement, drops all but the current
        tile and returns that tile.
        """
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
                    truncate_end = max(
                        self._tiles.index(self._committed_destination),
                        self._tiles.index(end_tile)
                    )
                else:
                    truncate_end_index = self._tiles.index(end_tile)
                    
                self._tiles = self._tiles[:truncate_end_index + 1]  # keep the end_tile in the list
                
                return self._tiles[-1]
    
    def get_tiles(self) -> List[Tile]:
        """
        Pull out the tiles contained within the Path object.

        Copies on access so that accessors don't inadvertently reach back in 
        / around the lock and mutate the internal list.
        """
        with self._lock:
            return copy.copy(self._tiles)  # shallow-copy so that we don't accidentally list mumble mutate

    def __getitem__(self, key: Union[int, slice]) -> Union[Tile, List[Tile]]:
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
            return copy.copy(self._tiles[key])

    def __str__(self) -> str:
        # I keep trying to print(self) during critical sections in which
        # I already have the lock held, so I'm not going to access it here.
        # That exposes us to edge cases in which self._tiles gets mutated while
        # we're translating it to str, in which case............ idk! We'll
        # figure it out!
        return f"Path: {self._tiles}"