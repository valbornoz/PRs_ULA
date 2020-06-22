CC=g++
CFLAGS=-g

main:  inventario.o main.o
	$(CC) $(CFLAGS) main.o inventario.o -o inventario

main.o: main.cpp
	$(CC) $(CFLAGS) -c -I. main.cpp

inventario.o: inventario.cpp
	$(CC) $(CFLAGS) -c -I. inventario.cpp

clean:
	rm -f *.o
	rm -f *~
