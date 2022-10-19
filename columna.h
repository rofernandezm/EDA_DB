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
 
columna addCol(tabla &t, char * nombreColumna, TipoDatoCol tipoDato, Calificador calificador);
// Crea una columna de nombre "nombreColumna"
// Pre: t creada previamente.

TipoRet dropCol( char *nombreTabla, char *nombreCol);
//Elimina la columna nombreCol si existe en la tabla nombreTabla

TipoRet alterCol (char *nombreTabla, char *nombreCol, char *tipoColNuevo, char nombreColNuevo);
//Modifica la tabla nombreTabla si esta existe

TipoRet insertInto (char *nombreTabla, char *columnasTupla, char *valoresTupla);
//Inserta en la tabla nombreTabla una tupla con los valores dados en valoresTupla para las columnas indicadas en columnasTupla

#endif