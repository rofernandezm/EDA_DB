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
	char datoStr;
	int datoInt;
	celda sig;
};

void eliminarCeldasCol(celda &celda){
	if(celda->sig == NULL){
		delete celda;
	} else{
		eliminarCeldasCol(celda->sig);
	}
}