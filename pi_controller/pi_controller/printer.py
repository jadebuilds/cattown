#!/usr/bin/env python3
# 
# 
# 
# Copyright (C) 2024 Jack "Jade" Weinstein
#
# Adapted from whconsole.py by Kevin O'Connor <kevin@koconnor.net> (# Copyright (C) 2020  )
#
# This file may be distributed under the terms of the GNU GPLv3 license.


import sys, socket, select, errno, time, json
import threading

from .motion import MotionCommand


def webhook_socket_create(uds_filename):
    sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)
    sock.setblocking(0)
    sys.stderr.write("Waiting for connect to %s\n" % (uds_filename,))
    while 1:
        try:
            sock.connect(uds_filename)
        except socket.error as e:
            if e.errno == errno.ECONNREFUSED:
                time.sleep(0.1)
                continue
            sys.stderr.write("Unable to connect socket %s [%d,%s]\n"
                             % (uds_filename, e.errno,
                                errno.errorcode[e.errno]))
            sys.exit(-1)
        break
    sys.stderr.write("Connection.\n")
    return sock


class KlipperSocket:

    def __init__(self, socket_path: str):
        """
        socket_path: The full filename of the Unix domain socket.

        socket_path can be found by running systemctl status | grep klipper ;
        it's passed to the Klipper executable using the -a flag,.
        """
        self.webhook_socket = webhook_socket_create(socket_path)
        self.poll = select.poll()
        self.poll.register(self.webhook_socket, select.POLLIN | select.POLLHUP)
        self.socket_data = b""
        self.thread = threading.Thread(target=self._thread_run, daemon=True)
        self.should_close = threading.Event()  # set() to stop the thread from running
        self.thread.start()

    def enqueue_motion(self, motion: MotionCommand):
        """
        Send a Gcode
        """
        cmd = json.dumps({
            "id": 123, 
            "method": "gcode/script", 
            "params": {"script": " ".join(gcode.to_str() for gcode in motion.to_g_code())}
        }, separators=(',', ':')
        )
        print(f"Sending: {cmd}")
        self.webhook_socket.send(cmd.encode('ascii') + b"\x03")

    def _process_socket(self):
        data = self.webhook_socket.recv(4096)
        if not data:
            sys.stderr.write("Socket closed\n")
            sys.exit(0)
        parts = data.split(b'\x03')
        parts[0] = self.socket_data + parts[0]
        self.socket_data = parts.pop()  # what does this do?? I'm confused
        for line in parts:
            print(f"Got from socket: {line}")

    def _thread_run(self):
        while not self.should_close.is_set():
            events = self.poll.poll(1000.)  # indicates receive ready (is this necessary?)
            if events:
                self._process_socket()
            else:
                print("no events")

    def stop(self):
        self.should_close.set()
