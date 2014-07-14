CC = g++
CFLAG = --std=c++11
INCLUDE = vector.h
OBJS = vector.o randwalk.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp INCLUDE
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -rf *.o