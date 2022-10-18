// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// columna.h
// Modulo de Implementación de Base de Datos.

#ifndef COLUMNA_H
#define COLUMNA_H

#include "define.h"

typedef struct nodo_columna * columna;
//Crea una columna
 
columna addCol(tabla &t, char * nombreColumna, TipoDatoCol tipoDato, Calificador calificador);
// Crea una columna de nombre "nombreColumna"
// Pre: t creada previamente.

#endif