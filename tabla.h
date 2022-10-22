// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tabla.h
// Modulo de Implementación de Base de Datos.

#ifndef TABLA_H
#define TABLA_H

#include "define.h"

typedef struct nodo_tabla * tabla;

tabla crearTabla(char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

bool existeTablaNombre_Tabla(tabla t, char *nombreTabla);
// True si existe la tabla de nombre "nombreTabla" en ts. Cualquier otro caso False

bool existenColumnas(tabla t);
// True si existen columnas en la tabla "t". Cualquier otro caso False

bool existeColumnaNombre_Tabla(tabla t, char *NombreCol);
// True si existe la columna de nombre "NombreCol" en la tabla "t". Cualquier otro caso False

tabla getTableByName(tabla t, char *nombreTabla);
// Retorna la tabla de nombre "nombreTabla"

TipoRet addCol_tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoCol, Calificador calificadorCol);
//Agrega la columna a la tabla

#endif