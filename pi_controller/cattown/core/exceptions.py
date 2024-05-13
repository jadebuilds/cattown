"""
exceptions.py

Specific exception types to raise and try/except against
"""


class HardwareError(Exception):
    """
    Generic hardware management error. I'm figuring we'll subclass this and then use it as a "platform fucked up" catch-all
    """
