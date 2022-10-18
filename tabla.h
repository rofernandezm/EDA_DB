// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tabla.h
// Modulo de Implementación de Base de Datos.

#ifndef TABLA_H
#define TABLA_H

typedef struct nodo_tabla * tabla;

tabla crearTabla(tablas ts, char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

TipoRet addCol_tabla(tablas ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);

#endif