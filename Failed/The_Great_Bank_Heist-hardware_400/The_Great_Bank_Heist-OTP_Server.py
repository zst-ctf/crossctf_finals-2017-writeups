#! /usr/bin/env python3
import socket
import re
from hashlib import sha256
from base64 import b16decode

s = socket.socket()
s.connect(('localhost', 1343))

KEY = b16decode("e5af6eb22bce17b27fd55ed32d72c6d4e1a79c7e9c83914acf8f33f512ae6907", casefold=True)

while True:
    s.settimeout(5.0)
    data = s.recv(4096).decode('ascii')
    if len(data) == 0:
        continue

    print(">", data, end="")

    if "Challenge issued" in data:
        number = re.search(r"Challenge issued: ([0-9]*)", data).group(1).strip()
        sha_digest = sha256(number.encode('ascii') + KEY).hexdigest()
        reply = sha_digest + "\n"
    if "Please enter the OTP:" in data:
        if reply is None or len(reply) == 0:
            reply = "???\n"
        print(reply, end="")
        s.send(reply.encode('ascii'))
        reply = None
