EXEC = secure_house
CC = g++
CFLAGS = -c -Wall

$(EXEC) : main.o
	$(CC) -o $(EXEC) main.o

main.o : main.h main.cpp
	$(CC) $(CFLAGS) main.cpp

clean :
	rm *.o
