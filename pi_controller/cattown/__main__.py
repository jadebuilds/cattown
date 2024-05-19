"""Command-line interface."""
import click

from .motion_system import MotionController
from .cv import ComputerVisionSystem
from .personalities.canned_pattern import DoesCannedPattern


@click.command()
@click.version_option()
def main() -> None:
    """Does Cat Town!!!!"""

    platform_manager = MotionController()
    platform_manager.initialize_hardware()

    cv = ComputerVisionSystem()
    cv.initialize_hardware()
    
    personalities = [
        # todo how does gcode work??? add some real gcode moves.
        # (I see a text2gcodes() but not gcodes2text() in pygcode... does it only parse and not generate??????)
        DoesCannedPattern([])
    ]

    platform_manager.deploy_mouse(0)
    active_personality = PERSONALITIES[0]

    while True:
        active_personality.update_cat_state(cv.get_cat_state())
        platform_manager.execute_trajectory(active_personality.get_trajectory())


if __name__ == "__main__":
    main(prog_name="cattown")  # pragma: no cover
