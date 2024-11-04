import logging
import colorlog
import sys
import traceback
from .backend import Game


def main():
    try:
        logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)
        logging.getLogger().handlers[0].setFormatter(
            colorlog.ColoredFormatter(
                "%(asctime)s %(log_color)s[%(levelname)s] %(module)s: %(message)s"
            )
        )
        game = Game()
        game.run()
    except Exception:
        traceback.print_exc()


if __name__ == "__main__":
    main()
