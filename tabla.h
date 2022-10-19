// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
<<<<<<< HEAD
=======
// tabla.h
>>>>>>> 2fc3065cabbca3120f4ea1a1c786d655052dadef
// Modulo de Implementación de Base de Datos.

#ifndef TABLA_H
#define TABLA_H

typedef struct nodo_tabla * tabla;

tabla crearTabla(tablas ts, char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

<<<<<<< HEAD
TipoRet addCol_tabla(char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
//Agrega la columna a la tabla
=======
TipoRet addCol_tabla(tablas ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
>>>>>>> 2fc3065cabbca3120f4ea1a1c786d655052dadef

#endif