import threading


class ThreadSafeMonotonicCounter:
    """
    Generates monotonically increasing counter, useful for things like 
    attaching unique incrementing IDs to every interaction with the Klipper/
    Moonraker JSON RPC APIs.
    """

    def __init__(self) -> None:
        self.lock = threading.Lock()
        self.value = 0

    def get(self) -> int:
        with self.lock:
            to_return = self.value
            self.value += 1
            return to_return