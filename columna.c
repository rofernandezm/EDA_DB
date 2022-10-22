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

columna iniColumna(){
	return NULL;
}

bool existeColumnaNombre(columna *col, char *nombreCol){
	if(strcmp(col->nombreColumna, nombreCol)==0){
		return true;
	}else if(col->sig == NULL) {
		return false;
	} else {
		return existeColumnaNombre(col->sig, nombreCol);
	}
}

Calificador getColumnCalif(columna col, char *NombreCol){
	if(strcmp(col->nombreColumna, NombreCol)==0){
		return col->calif;
	}else {
		return getColumnCalif(col->sig, NombreCol);
	}
}

columna * addCol(char * nombreCol, TipoDatoCol tipoDato, Calificador calificador){
	
	columna * col = new(nodo_columna);
	
	//Asigna el nombre a la columna
	col->nombreColumna = new char[20]; 
	strcpy(col->nombreColumna, nombreCol); 
	
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