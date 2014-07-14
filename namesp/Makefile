CC = g++
HEADER = namesp.h
OBJ = main.o namesp.o

final:$(OBJ)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) -c $< -o $@
clean:
	rm -rf *.o