CC = g++
HEADER = coordin.h
OBJ = main.o func.o

final:$(OBJ)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) -c $< -o $@
clean:
	rm -rf *.o