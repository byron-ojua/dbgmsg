all:
	gcc --std=gnu99 -o output main.c util.c

clean: 
	rm output

test:
	clear
	make
	./output