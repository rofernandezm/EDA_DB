// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tablas.h
// Modulo de Implementación de Base de Datos.

#ifndef TABLAS_H
#define TABLAS_H

#include "define.h"

typedef struct nodo_tablas * tablas;

tablas crearTablas();
// Crea el conjunto de tablas vacio.

TipoRet crearTabla_Tablas(tablas & ts, char *nombreTabla);
// Crea la tabla de nombre "nombreTabla" en tablas.

void imprimirTablas(tablas ts);
// Imprime las tablas de manera ordenada.

TipoRet addCol_tablas(tablas &ts, char *nombreTabla, char *NombreCol, TipoDatoCol tipoCol, Calificador calificadorCol);
// Agrega la columna en la tabla

bool existenTablas(tablas ts);
// True si exitenTablas, False si no existen

bool existeTablaNombre_Tablas(tablas ts, char *nombreTabla);
// True si la tabla nombreTabla existe en ts

TipoRet printMetadata(tablas ts, char *nombreTabla);
//Imprime el esquema de la tabla nombreTabla

TipoRet dropCol_tablas(tablas ts, char *nombreTabla, char *nombreCol);
//Elimina la columna nombreColumna de la tabla nombreTabla
//Pre: nombreTabla tiene que existir.

TipoRet dropTable_Tablas(tablas ts, char *nombreTabla);
//Elimina la tabla nombreTabla y las tuplas en caso de existir
//Pre: nombreTabla tiene que existir;

#endif
