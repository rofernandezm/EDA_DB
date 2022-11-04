// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// celda.h
// Modulo de Implementación de Base de Datos.

#ifndef CELDA_H
#define CELDA_H

#include "define.h"

typedef struct nodo_celda * celda;

celda nuevaCelda();
//Crea una nueva celda

void eliminarCeldas(celda &celda);
//Elimina las celdas en una determinada columna
//Pre: celda != NULL

bool existeDato_char(celda celda, char * dato);
//Devuelve true si en una columna de tipo char existe el dato

bool existeDato_int(celda celda, int dato);
//Devuelve true si en una columna de tipo int existe el dato

celda insertInto_char(celda celda, char * dato);
//Inserta en una columna tipo char

celda insertInto_int(celda celda, int dato);
//Inserta en una columna tipo int

bool hayCeldasVacias(celda celda);
//Returna true si hay algun valor vacio en la columna, o false si no lo hay

void valoresAString(celda celda);
//Pasa todos los valores de una columna a int

#endif
