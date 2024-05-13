from typing import List
from ..core.types import CatState


class ComputerVisionSystem:

    def initialize_hardware():
        """
        Set up the camera.
        """
        raise NotImplementedError
    
    def get_cat_state(self) -> List[CatState]:
        """
        Tell us what the cat(s) are up to. Should return one CatState per identified cat.
        """
