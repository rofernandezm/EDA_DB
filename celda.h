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

void eliminarCeldas(celda &celda);
//Elimina las celdas en una determinada columna
//Pre: celda != NULL

#endif