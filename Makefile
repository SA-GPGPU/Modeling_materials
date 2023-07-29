all:	clean\
		compile\
		link\
		run

check:	clean\
		compile\
		link

compile:common.o\
		LZC.o\
		ram_i.o\
		stack.o\
		icache.o\
		Scheduler.o\
		Fetch.o\
		test.o

link:	
	gcc -o test *.o -g

clean:	
	rm -f *.o
	rm -f test
	rm -f run.log

run:
	./test > run.log
	vim run.log

%.o	: %.c
	gcc -c $*.c -g
