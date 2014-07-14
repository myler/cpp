CC = g++
HEADER = tabtenn.h
OBJS = main.o tabtenn.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) -c $< -o $@
clean:
	rm -rf *.o