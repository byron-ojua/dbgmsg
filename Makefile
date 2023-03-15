all:
	gcc --std=gnu99 -o output example.c dbgmsg.c

clean: 
	rm output

test:
	clear
	make
	./output

redirect-test:
	clear
	make
	./output > error.txt