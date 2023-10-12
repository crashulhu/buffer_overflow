FLAGS=-fno-stack-protector -no-pie -m32 -z execstack
INFILE=challenge03


all: 
	gcc $(INFILE).c $(FLAGS) -o $(INFILE)

socat:
	./run_socat.sh

clean:
	rm $(INFILE)

