"""
types.py

Some other useful types to use across modules
"""

from typing import List, Optional
from dataclasses import dataclass
from pygcode import GCode


"""
Basic types for position, velocity, and acceleration
"""

@dataclass
class Position:
    x_mm: float
    y_mm: float

@dataclass
class Velocity:
    x_mm_s: float
    y_mm_s: float

@dataclass
class Acceleration:
    x_mm_s2: float
    y_mm_s2: float


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
    timestamp: datetime  # when the cat was observed

    position: Position
    velocity: Optional[Velocity]
    acceleration: Optional[Acceleration]


"""
Representation of mouse state for a single 
"""
@dataclass
class MouseState:
    timestamp: datetime  # when the mouse was observed
    
    active_mouse: Optional[MouseID]  # which mouse is active, if any
    
    mouse_location: Position  # where the mouse is on the platform (in millimeters)
    mouse_velocity: Velocity  # how fast the mouse is moving (mm per second)
    mouse_acceleration: Acceleration  # mouse acceleration
    
