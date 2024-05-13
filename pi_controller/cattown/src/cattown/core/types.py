"""
types.py

Some other useful types to use across modules
"""

from typing import List, Optional
from dataclasses import dataclass
from pygcode import GCode

from .physics import Position, Velocity, Acceleration

"""
typedef for mouse ID (so we can change it later). 

Currently an unsigned integer, counting up, zero-indexed.
"""
MouseID = int  

"""
Representation of a trajectory for the mouse to follow, as gcode.

todo: consider vendoring pygdk and using them instead? It seems more trustworthy to me?
but I'm not really sure, I've literally looked at the readmes for like 30 seconds. Very
open to feedback here.
"""
class Trajectory:
    moves: List[GCode]


"""
Representation of cat state for a single cat.

todo: should velocity and acceleration be optional? (Zoda and Chris to decide)
"""
class CatState:
    position: Position
    velocity: Optional[Velocity]
    acceleration: Optional[Acceleration]

