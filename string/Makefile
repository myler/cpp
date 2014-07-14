CC = g++
HEADER = string.h
OBJS = main.o string.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) -c $< -o $@
clean:
	rm -rf *.o