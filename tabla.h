// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#ifndef TABLA_H
#define TABLA_H

typedef struct nodo_tabla * tabla;

tabla crearTabla(char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

TipoRet addCol_tabla(char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
//Agrega la columna a la tabla

#endif