
init: initt
	./init
initt: init.o
		g++ init.o -o init

init.o: init.cpp
		g++ -c -Wall -g init.cpp

clean:
	rm -rf *o init
