CC=g++
CFLAGS=-g

main:  temp.o main.o
	$(CC) $(CFLAGS) main.o temp.o -o temp

main.o: main.cpp
	$(CC) $(CFLAGS) -c -I. main.cpp

temp.o: temp.cpp
	$(CC) $(CFLAGS) -c -I. temp.cpp

clean:
	rm -f *.o
	rm -f *~
