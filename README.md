# cattown
Code for Cat Town Kickstarter project

# Poetry Environment Setup Instructions
-Make sure Python 3.12.3 exists on the system

-Install Poetry:

curl -sSL https://install.python-poetry.org/ | python3 -

May have to add this to path to run Poetry: `export PATH="/home/<YOUR USERNAME>/.local/bin:$PATH"`

The Poetry lock file and pyproject.toml should all be pulled from git.

You can now cd into `cattown/pi-controller` and run `poetry install` to make sure dependencies are installed.
