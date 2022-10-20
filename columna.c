// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// columna.c
// Modulo de Implementación de Base de Datos.

#include "tabla.h"
#include "columna.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_columna{
	char * nombreColumna;
	TipoDatoCol * tipo;
	Calificador * calif;
	celda * dato;
	columna * sig;
};

boolean existeColumnaNombre(columna col, char *nombreColumna){
	if(strcmp(columna->nombreColumna, nombreColumna)==0){
		return true;
	}else if(columna->sig == NULL) {
		return false;
	} else {
		return existeColumnaNombre(columna->sig, nombreColumna);
	}
}

Calificador getColumnCalif(tabla t, char *NombreCol){
	columna col=t->columna;
	if(strcmp(col->nombreColumna, NombreCol)==0){
		return col->calif;
	}else {
		return getColumnCalif(columna->sig, nombreColumna);
	}
}

void addCol(tabla &t, char * nombreColumna, TipoDatoCol tipoDato, Calificador calificador){
	
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

	col->celda=NULL;
	col->sig=NULL;
}