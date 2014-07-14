CC = g++
CFLAG = --std=c++11
INCLUDE = mytime2.h
OBJS = mytime2.o main.o

final:$(OBJS)
	$(CC) $^ -o final
%.o:%.cpp INCLUDE
	$(CC) $(CFLAG) -c $< -o $@
clean:
	rm -rf *.o