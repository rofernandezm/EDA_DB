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

<<<<<<< HEAD
TipoRet addCol_tablas(char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
// Agrega la columna en la tabla
=======
TipoRet addCol_tablas(bd & bd, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
//Agrega columna de nombre "nombreCol" a la tabla de nombre "nombreTabla"
>>>>>>> 2fc3065cabbca3120f4ea1a1c786d655052dadef

#endif