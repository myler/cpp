CC = g++
HEADER = stock2.h
OBJ = main.o stock2.o

final:$(OBJ)
	$(CC) $^ -o final
%.o:%.cpp HEADER
	$(CC) -c $< -o $@
clean:
	rm -rf *.o