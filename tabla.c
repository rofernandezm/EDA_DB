// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// bd.c
// Modulo de Implementación de Base de Datos.

#include "tabla.h"
#include "define.h"
#include <string.h>

struct nodo_tabla{
	char * nombre;
	columna * columna;
	//VER COLUMNAS!!!! HACER TAD
};

tabla crearTabla(char * nombreTabla){
	tabla t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	// VER COLUMNAS, ETC
	return t;
}

char * nombreTabla(tabla t){
	return t->nombre;
}
