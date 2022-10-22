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
	TipoDatoCol tipo;
	Calificador calif;
	celda dato;
	columna sig;
};

columna nuevaColumna(){
	return NULL;
}

bool existeColumnaNombre(columna col, char *nombreCol){
	if(strcmp(col->nombreColumna , nombreCol)==0){
		return true;
	}else if(col->sig == NULL) {
		return false;
	} else {
		return existeColumnaNombre(col->sig, nombreCol);
	}
}

bool existePrimaryKey_columna(columna col){
	if(col == NULL)
		return false;
	else{
		if(col->calif == PRIMARY_KEY)
			return true;
		else
			return existePrimaryKey_columna(col->sig);
	}
}

Calificador getColumnCalif(columna col, char *NombreCol){
	if(strcmp(col->nombreColumna, NombreCol)==0){
		return col->calif;
	}else {
		return getColumnCalif(col->sig, NombreCol);
	}
}

columna addCol(columna col, char * nombreCol, TipoDatoCol tipoDato, Calificador calificador){
	
	if(col == NULL){
		columna nueva = new(nodo_columna);
		nueva->nombreColumna = new char[20];
		strcpy(nueva->nombreColumna, nombreCol);
		nueva->tipo = tipoDato;
		nueva->calif = calificador;
		nueva->dato = NULL; //llamar funcion crearCelda();
		nueva->sig = NULL;
		col = nueva;
	}else{
		col->sig = addCol(col->sig, nombreCol, tipoDato, calificador);
	}
	return col;
}

bool existenTuplas(columna col){
	if(col->dato == NULL)
		return false;
	else
		return true;
}

void printMetaData_Column(columna col){

	if(col != NULL){
		cout << "Columna " << col->nombreColumna << "\n\tTipo: " << enumToTipo(col) << "\n\tCalificador: " << enumToCalificador(col)  << endl;
		printMetaData_Column(col->sig);
	}
}

char * enumToTipo(columna col){
	char * tipo = new(char[10]);
	if(col->tipo == 0)
		strcpy(tipo, "String");
	else
		strcpy(tipo, "Int");
	return tipo;
}

char * enumToCalificador(columna col){
	char * calif = new(char[15]);
	if(col->calif == 0)
		strcpy(calif, "Primary Key");
	else if(col->calif == 1)
		strcpy(calif, "Not Empty");
	else
		strcpy(calif, "Any");
	return calif;
}




