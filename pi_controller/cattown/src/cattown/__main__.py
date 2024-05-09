"""Command-line interface."""
import click


@click.command()
@click.version_option()
def main() -> None:
    """Cat Town."""


if __name__ == "__main__":
    main(prog_name="cattown")  # pragma: no cover
