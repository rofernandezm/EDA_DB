// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
<<<<<<< HEAD
=======
// tablas.c
>>>>>>> 2fc3065cabbca3120f4ea1a1c786d655052dadef
// Modulo de Implementación de Base de Datos.

#include "tablas.h"
#include "tabla.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_tablas{
	tabla t;
};

tablas crearTablas(){
	return NULL;
}

TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla){
	if (ts == NULL){
		ts = new(nodo_tablas);
		ts->t = crearTabla(nombreTabla);
		return OK;
	}else{
		cout << "Imposible Crear Tabla, ya exite una creada y el sistema soporta solo una\n";
		return ERROR;
	}
}

void imprimirTablas(tablas ts){
	if (ts == NULL){
		cout << " - No hay tablas\n";
	}else{
		cout << nombreTabla(ts->t);
	}
}

<<<<<<< HEAD
TipoRet addCol_tablas(char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	return addCol_tabla(nombreTabla, NombreCol, tipoCol, calificadorCol);
=======
TipoRet addCol_tablas(tablas & ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	return addCol_tabla(ts->t, nombreTabla, NombreCol, tipoCol, calificadorCol);
>>>>>>> 2fc3065cabbca3120f4ea1a1c786d655052dadef
}







