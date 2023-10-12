#!/usr/bin/python3
from pwn import *

context(arch="i386", os="linux")

elf = context.binary = ELF("./binary_file")


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


