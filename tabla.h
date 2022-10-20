// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tabla.h
// Modulo de Implementación de Base de Datos.

#ifndef TABLA_H
#define TABLA_H

typedef struct nodo_tabla * tabla;

tabla crearTabla(tablas & ts, char * nombreTabla);
// Crea una tabla de nombre "nombreTabla".

char * nombreTabla(tabla t);
// Retorna el nombre de t.
// Pre: t creada previamente.

boolean existeTablaNombre_Tabla(tablas ts, char *nombreTabla);
// True si existe la tabla de nombre "nombreTabla" en ts. Cualquier otro caso False

boolean existenColumnas(tabla t);
// True si existen columnas en la tabla "t". Cualquier otro caso False

boolean existeColumnaNombre_Tabla(tabla t, char *NombreCol);
// True si existe la columna de nombre "NombreCol" en la tabla "t". Cualquier otro caso False

tabla getTableByName(tablas &ts, char *nombreTabla);
// Retorna la tabla de nombre "nombreTabla"

TipoRet addCol_tabla(tablas &ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
//Agrega la columna a la tabla

#endif