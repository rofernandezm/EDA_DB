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

bool existeDato_char(celda cel, char * dato);
//Devuelve true si en una columna de tipo char existe el dato

bool existeDato_int(celda cel, int dato);
//Devuelve true si en una columna de tipo int existe el dato

celda insertInto_char(celda &cel, char * dato);
//Inserta en una columna tipo char

celda insertInto_int(celda &cel, int dato);
//Inserta en una columna tipo int

bool hayCeldasVacias(celda cel);
//Returna true si hay algun valor vacio en la columna, o false si no lo hay

void valoresAString(celda cel);
//Pasa todos los valores de una columna a int

void completarVacios_celda(celda cel, int indice);
//Completa una tabla con vacios

void printDataTable_celda(celda cel, TipoDatoCol tipo, int indice);
//Imprime el valor de una celda

#endif
