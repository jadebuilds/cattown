"""
physics.py

Some basic data types in common dataclass representations to pass between modules
"""

from dataclasses import dataclass


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

