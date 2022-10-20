// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tablas.c
// Modulo de Implementación de Base de Datos.

#include "tablas.h"
#include "tabla.h"
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_tablas{
	tabla t;
	tablas iz;
	tablas de;
};

tablas crearTablas(){
	return NULL;
}

TipoRet crearTabla_Tablas(tablas & ts, char * nombreTabla){
	if (!existenTablas(ts)){
		ts = new(nodo_tablas);
		ts->t = crearTabla(nombreTabla);
		return OK;
	}else{
		cout << "Imposible Crear Tabla, ya exite una creada y el sistema soporta solo una\n";
		return ERROR;
	}
}

void imprimirTablas(tablas ts){
	if (!existenTablas(ts)){
		cout << " - No hay tablas\n";
	}else{
		cout << nombreTabla(ts->t);
	}
}

boolean existenTablas(tablas ts){
	if(ts==NULL){
		return false;
	}else{
		return true;
	}
}

boolean existeTablaNombre_Tablas(tablas ts, char *nombreTabla){
	if(!existenTablas(ts)){
		return false;
	}else{
		return existeTablaNombre_Tabla(ts, char *nombreTabla);
	}
}

TipoRet addCol_tablas(tablas &ts, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	if(existenTablas(ts)){
		if(existeTablaNombre_Tablas(ts, nombreTabla)){
			return addCol_tabla(ts, nombreTabla, NombreCol, tipoCol, calificadorCol);
		} else{
			cout << " - No existe la tabla " << nombreTabla << endl;
			return ERROR;
		}
	} else {
		cout << " - No existen tablas\n";
		return ERROR;
	}
}







