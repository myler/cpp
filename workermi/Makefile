CC = g++
HEADER = workermi.h
OBJS = main.o workermi.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) -c $< -o $@
clean:
	rm -rf *.o