CC = g++
CFLAG = --std=c++11
INCLUDE = mytime0.h
OBJS = mytime0.o usetime0.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp INCLUDE
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -rf *.o