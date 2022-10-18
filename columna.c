// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// columna.c
// Modulo de Implementación de Base de Datos.

#include "tabla.h"
#include <string.h>
#include <iostream>

using namespace std;

struct columna{
	char * nombreColumna;
	TipoDatoCol * tipo;
	char * datoStr;
	int datoInt;
	Calificador * calif;
	columna sig;
};

tipoRet agregarCol(tabla &t, char * nombreColumna, TipoDatoCol tipoDato, Calificador calificador){
	
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