CC = g++
HEADER = dma.h
OBJS = main.o dma.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp $(HEADER)
	$(CC) -c $< -o $@
clean:
	rm -rf *.o