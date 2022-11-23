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

tabla crearTabla(tabla t, char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

void nombreTabla(tabla t);
// Imprime los nombres de todas las tablas
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

TipoRet addCol_tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoCol, Calificador calificadorCol);
//Agrega la columna a la tabla
//Pre: La tabla nombreTabla debe existir

void printMetaData_Tabla(tabla t, char *nombreTabla);
//Imprime los cabezales de una tabla y sus columnas
//Pre: La tabla nombreTabla debe existir

TipoRet dropCol_tabla(tabla &t, char *nombreTabla, char *nombreCol);
//Elimina la columna nombreCol de la tabla
//Pre: La tabla nombreTabla debe existir

TipoRet dropTable_tabla(tabla t, char *nombreTabla);
//Elimina la tabla nombreTabla y las tuplas en caso de existir.
//Pre: La tabla nombreTabla debe existir

TipoRet alterCol_Tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoColNuevo, Calificador calificadorColNuevo, char *nombreColNuevo);
// Modifica la columna nombreCol de una tabla
//Pre: La tabla nombreTabla debe existir

TipoRet insertInto_Tabla(tabla &t, char *nombreTabla, char *columnasTupla, char * valoresTupla);
//Inserta los valoresTupla en las columnasTupla
//Pre: La tabla nombreTabla debe existir

TipoRet printDataTable_tabla(tabla t, char *nombreTabla);
//Imprime la informacion de una tabla
//Pre: La tabla nombreTabla debe existir

TipoRet deleteFrom_tabla(tabla t, char *nombreTabla, char *condicionEliminar);
//Elimina las tuplas que cumplan la condicion
//Pre: La tabla nombreTabla debe existir

TipoRet selectWhere_tabla(tabla t, char *tabla1, char *condicionCopiar, char *tabla2);
//Crea la tabla dos a partir de las tuplas de la tabla1 que cumplan la condicion
//Pre: la tabla1 debe existir
//Pre: la tabla2 no debe existir

#endif
