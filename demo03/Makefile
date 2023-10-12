FLAGS=-fno-stack-protector -no-pie -m32 -z execstack
INFILE=demo

all: 
	gcc $(INFILE).c $(FLAGS) -o $(INFILE)

shellcode:
	as ./shellcode.s -o ./shellcode.o -msyntax=intel --32
	objcopy -O binary -j .text ./shellcode.o ./shellcode.bin

clean:
	rm $(INFILE)

