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

columna nuevaColumna();
//Crea una columna nueva

columna addCol(columna col, char * nombreCol, TipoDatoCol tipoDato, Calificador calificador);
// Crea una columna de nombre "nombreCol"
// Pre: t creada previamente.

TipoRet dropCol(char *nombreTabla, char *nombreCol);
//Elimina la columna nombreCol si existe en la tabla nombreTabla

TipoRet alterCol (char *nombreTabla, char *nombreCol, char *tipoColNuevo, char nombreColNuevo);
//Modifica la tabla nombreTabla si esta existe

TipoRet insertInto (char *nombreTabla, char *columnasTupla, char *valoresTupla);
//Inserta en la tabla nombreTabla una tupla con los valores dados en valoresTupla para las columnas indicadas en columnasTupla

bool existeColumnaNombre(columna col, char *nombreCol);
// True si existe la columna de nombre "nombreCol"

bool existePrimaryKey_columna(columna col);
//Retorna true si existe una primary key entre las columnas o false en caso contrario

Calificador getColumnCalif(columna col, char *NombreCol);
//retorna el calificador de la columna "NombreCol"
//Pre: NombreCol debe existir.

bool existenTuplas(columna col);
//Retorna true si existe alguna tupla en la columna, false si no

void printMetaData_Column(columna col);
//Imprime los nombres de las columnas

char * enumToTipo(columna col);
//Recibe una columna y retorna un char con el tipo de dato

char * enumToCalificador(columna col);
//Recibe una columna y retorna un char con el calificador

void dropCol_col(columna &col, char *nombreCol);
//Elimina la columna nombreCol
//Pre: nombreCol tiene que existir

#endif
