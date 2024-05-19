from typing import Optional, Callable
from dataclasses import dataclass
from datetime import datetime

from ..core.types import Position, Velocity, Acceleration, MouseID, Trajectory
from ..core.exceptions import HardwareError


class MotionController:

    def initialize_hardware(self):
        """
        Initialize the hardware platform however needed
        """
    
    def get_size(self) -> Position:
        """
        Returns the size of the platform, as a Position describing the upper 
        rightmost point on the board (where the lower left is assumed to be 0,0)
        """
        raise NotImplementedError

    def get_state(self) -> MouseState:
        """
        Report the state of the platform.

        :raises: HardwareError (if can't get state)
        """
        raise NotImplementedError

    def execute_trajectory(self, Trajectory):
        """
        Execute a Trajectory synchronously.
        """
        raise NotImplementedError
    
    def register_error_callback(self, callback: Callable):
        """
        Register a callback to be invoked

        :param callback: A 
        """
        raise NotImplementedError
    
    def deploy_mouse(self, mouse: MouseID):
        """
        Tracks to the hard-coded X/Y coordinates of this particular mouse, then executes a canned routine to exit the mouse house.

        Will not put away any mouse that was previously engaged; will probably drop it against the side of the mouse house.
        """