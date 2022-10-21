// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// columna.c
// Modulo de Implementación de Base de Datos.

#include "columna.h"
#include "celda.h"
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
	if(strcmp(col->nombreColumna, nombreColumna)==0){
		return true;
	}else if(col->sig == NULL) {
		return false;
	} else {
		return existeColumnaNombre(col->sig, nombreColumna);
	}
}

Calificador getColumnCalif(columna col, char *NombreCol){
	if(strcmp(col->nombreColumna, NombreCol)==0){
		return col->calif;
	}else {
		return getColumnCalif(col->sig, nombreColumna);
	}
}

columna addCol(char * nombreColumna, TipoDatoCol tipoDato, Calificador calificador){
	
	columna col = new(nodo_columna);
	
	//Asigna el nombre a la columna
	col->nombreColumna = new char[20]; 
	strcpy(col->nombreColumna, nombreColumna); 
	
	//Asigna el tipo
	col->tipo = new(TipoDatoCol);
	col->tipo = tipoDato;
	
	//Asigna el calificador
	col->calif = new(Calificador);
	col->calif = calificador;

	col->celda = NULL; //llamar funcion crearCelda();
	col->sig = NULL;

	return col;
}