final: main.o complex.o
	g++ -g -Wall main.o complex.o -o final -O
main.o: main.cpp
	g++ -g -Wall -c main.cpp -O
complex.o: complex.cpp complex.h
	g++ -g -Wall -c complex.cpp -O
clean:
	rm -rf *.o