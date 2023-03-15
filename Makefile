all:
	gcc --std=gnu99 -o output main.c dbgmsg.c

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