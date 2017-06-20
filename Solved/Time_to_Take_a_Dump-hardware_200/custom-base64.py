#http://www.overclock.net/t/1475505/python-base64-encoding-with-a-non-standard-alphabet
import string
import base64

STANDARD_ALPHABET = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
CUSTOM_ALPHABET = '/+9876543210zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA'
ENCODE_TRANS = string.maketrans(STANDARD_ALPHABET, CUSTOM_ALPHABET)
DECODE_TRANS = string.maketrans(CUSTOM_ALPHABET, STANDARD_ALPHABET)

def encode(input):
  return base64.b64encode(input).translate(ENCODE_TRANS)

def decode(input):
  return base64.b64decode(input.translate(DECODE_TRANS))


IN = "vI2QjIy8q7mEvZ6MzMnLoM6FoJeejZuC9f/="
print decode(IN)
print decode(IN).encode("hex")