CC = g++
CFLAG = --std=c++11
HEADER = queue.h
OBJS = main.o queue.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -rf *.o