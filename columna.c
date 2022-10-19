// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
<<<<<<< HEAD
=======
// columna.c
>>>>>>> 2fc3065cabbca3120f4ea1a1c786d655052dadef
// Modulo de Implementación de Base de Datos.

#include "tabla.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_columna{
	char * nombreColumna;
	TipoDatoCol * tipo;
	Calificador * calif;
	celda dato;
	columna sig;
};

columna addCol(tabla &t, char * nombreColumna, TipoDatoCol tipoDato, Calificador calificador){
	
	columna col = new(nodo_columna);
	
	//Asigna el nombre a la columna
	col->nombreColumna = new char[20]; 
	strcpy(t->nombreColumna, nombreColumna); 
	
	//Asigna el tipo
	col->tipo = new(TipoDatoCol);
	col->tipo = tipoDato;
	
	//Asigna el calificador
	col->calif = new(Calificador);
	col->calif = calificador;
};