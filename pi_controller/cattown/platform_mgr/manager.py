from typing import Optional, Callable
from dataclasses import dataclass
from datetime import datetime

from ..core.physics import Position, Velocity, Acceleration
from ..core.types import MouseID, Trajectory
from ..core.exceptions import HardwareError


@dataclass
class PlatformState:
    timestamp: datetime  # when the PlatformState was observed
    
    active_mouse: Optional[MouseID]
    
    mouse_location: Position  # where the mouse is on the platform (in millimeters)
    mouse_velocity: Velocity  # how fast the mouse is moving (mm per second)
    mouse_acceleration: Acceleration  # mouse acceleration
    


class PlatformManager:

    def initialize_hardware(self):
        """
        Initialize the hardware platform however needed
        """
    
    def get_state(self) -> PlatformState:
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