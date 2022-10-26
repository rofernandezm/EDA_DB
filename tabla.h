// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tabla.h
// Modulo de Implementación de Base de Datos.

#ifndef TABLA_H
#define TABLA_H

#include "define.h"
#include "columna.h"
#include <string.h>
#include <iostream>

typedef struct nodo_tabla * tabla;

tabla crearTabla(char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

bool existeTablaNombre_Tabla(tabla t, char *nombreTabla);
// True si existe la tabla de nombre "nombreTabla" en ts. Cualquier otro caso False

bool existeMasDeUnaColumna_tabla(tabla t);
// True si hay mas de una columna en la tabla, cualquier otro caso, false
// Pre: Existe al menos 1 columna

bool existenColumnas(tabla t);
// True si existen columnas en la tabla "t". Cualquier otro caso False

bool existeColumnaNombre_Tabla(tabla t, char *NombreCol);
// True si existe la columna de nombre "NombreCol" en la tabla "t". Cualquier otro caso False

tabla getTableByName(tabla t, char *nombreTabla);
// Retorna la tabla de nombre "nombreTabla"

TipoRet addCol_tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoCol, Calificador calificadorCol);
//Agrega la columna a la tabla

void printMetaData_Tabla(tabla t, char *nombreTabla);
//Imprime los cabezales de una tabla y sus columnas

TipoRet dropCol_tabla(tabla &t, char *nombreCol);
//Elimina la columna nombreCol de la tabla
//Pre: nombreCol tiene que existir

TipoRet dropTable_tabla(tabla t, char *nombreTabla);
//Elimina la tabla nombreTabla y las tuplas en caso de existir.
//Pre: nombreTabla tiene que existir

TipoRet alterCol_Tabla(tabla &t, char *NombreCol, TipoDatoCol tipoColNuevo, Calificador calificadorColNuevo, char *nombreColNuevo);
// Modifica la columna nombreCol de una tabla
// Pre: t tiene que existir 
#endif
