CC = g++
HEADER = brass.h
OBJS = main.o brass.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) -c $< -o $@
clean:
	rm -rf *.o