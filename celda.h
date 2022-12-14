// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// celda.h
// Modulo de Implementación de Base de Datos.

#ifndef CELDA_H
#define CELDA_H

#include "define.h"
#include "columna.h"

typedef struct nodo_celda * celda;

celda nuevaCelda(celda &cel);
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

celda insertInto_vacia(celda &cel);
//Crea una celda vacia

void printDataTable_celda(celda cel, TipoDatoCol tipo, int indice);
//Imprime el valor de una celda

void deleteFrom_celda(columna col, char *nombreCol, celda &cel, int &indice, TipoDatoCol tipo, char simbolo, char *condicion);
//Elimina las celdas que cumplan la condicion
//Pre: celda no es vacio

void borrarPorIndiceMenosUna_celda(celda &cel, int indiceABorrar);
//Borra la celda en la posicion indiceABorrar


#endif
