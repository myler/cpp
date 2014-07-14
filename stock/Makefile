CC = g++
HEADER = stock.h
OBJ = main.o stock.o

final:$(OBJ)
	$(CC) $^ -o final
%.o:%.cpp HEADER
	$(CC) -c $< -o $@
clean:
	rm -rf *.o