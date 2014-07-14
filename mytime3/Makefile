CC = g++
CFLAG = --std=c++11
INCLUDE = mytime3.h
OBJS = mytime3.o main.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp INCLUDE
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -rf *.o