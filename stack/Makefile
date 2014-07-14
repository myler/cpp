CC = g++
HEADER = stack.h
OBJ = main.o stack.o

final:$(OBJ)
	$(CC) $^ -o final
%.o:%.cpp HEADER
	$(CC) -c $< -o $@
clean:
	rm -rf *.o