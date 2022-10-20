todo: main.o bd.o tablas.o tabla.o columna.o celda.o
	g++ -Wall -o main bd.o main.o tablas.o tabla.o columna.o celda.o
main.o: bd.o main.c
	g++ -Wall -c main.c
bd.o: bd.c bd.h tablas.o
	g++ -Wall -c bd.c
tablas.o: tablas.c tablas.h tabla.o
	g++ -Wall -c tablas.c
tabla.o: tabla.c tabla.h columna.o
	g++ -Wall -c tabla.c
columna.o: columna.c columna.h celda.o
	g++ -Wall -c columna.c
celda.o: celda.c celda.h
	g++ -Wall -c celda.c
clean:
	rm -f *.o
	rm -f main