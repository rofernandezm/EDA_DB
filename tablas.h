// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tablas.h
// Mo

#ifndef TABLAS_H
#define TABLAS_H

#include "define.h"
#include "bd.h"

typedef struct nodo_tablas * tablas;

tablas crearTablas();
// Crea el conjunto de tablas vacio.

TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla);
// Crea la tabla de nombre "nombreTabla" en tablas.

void imprimirTablas(tablas ts);
// Imprime las tablas de manera ordenada.

TipoRet addCol_tablas(bd & bd, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
//Agrega columna de nombre "nombreCol" a la tabla de nombre "nombreTabla"

#endif