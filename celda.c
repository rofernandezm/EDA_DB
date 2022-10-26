// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// celda.c
// Modulo de Implementación de Base de Datos.

#include <string.h>
#include <iostream>
#include "celda.h"

using namespace std;

struct nodo_celda{
	char * datoStr;
	int datoInt;
	celda sig;
};

void eliminarCeldas(celda &celda){
	if(celda->sig == NULL){
		delete celda;
	} else{
		eliminarCeldas(celda->sig);
	}
}

void insertInto_int(celda celda, int dato){
	
	while(celda != NULL){
		//Si la celda no esta vacia, itero
		celda = celda->sig;
	}

	//Estoy en la celda en la que quiero insertar
	celda->datoInt = dato;
	
	
}

void insertInto_char(celda celda, char * dato){
	
	while(celda != NULL){
		//Si la celda no est vaca, itero
		celda = celda->sig;
	}
	
	//Estoy en la celda en la que quiero insertar
	strcpy(celda->datoStr, dato);
}

bool existeDato_int(celda celda, int dato){
	bool existe = false;
	
	while((celda != NULL) && (existe == false)){
		if(celda->datoInt == dato){
			//Si existe el dato cambia el bool
			existe = true;
		}
		celda = celda->sig;
	}
	
	return existe;
}

bool existeDato_char(celda celda, char * dato){
	bool existe = false;
	
	while((celda != NULL) && (existe == false)){
		if(strcmp(dato, celda->datoStr)==0){
			//Si existe el dato cambia el bool
			existe = true;
		}
		celda = celda->sig;
	}
	
	return existe;
}
