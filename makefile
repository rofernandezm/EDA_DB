todo: main.o bd.o tablas.o tabla.o
	g++ -Wall -o main bd.o main.o tablas.o tabla.o
main.o: bd.o main.c
	g++ -Wall -c main.c
bd.o: bd.c bd.h
	g++ -Wall -c bd.c
tablas.o: tablas.c tablas.h
	g++ -Wall -c tablas.c
tabla.o: tabla.c tabla.h
	g++ -Wall -c tabla.c
clean:
	rm -f *.o
	rm -f main

