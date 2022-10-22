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

TipoRet crearTabla_Tablas(tablas & ts, char *nombreTabla){

	if (!existenTablas(ts)){
		ts = new(nodo_tablas);
		ts->t = crearTabla(nombreTabla);
		ts->iz=crearTablas();
		ts->de=crearTablas();
		return OK;
	}else{
		cout << "Imposible Crear Tabla, ya exite una creada y el sistema soporta solo una" << endl;
		return ERROR;
	}
}

void imprimirTablas(tablas ts){
	if (!existenTablas(ts)){
		cout << " - No hay tablas" << endl;
	}else{
		cout << nombreTabla(ts->t) << endl;
	}
}

bool existenTablas(tablas ts){
	if(ts==NULL){
		return false;
	}else{
		return true;
	}
}

bool existeTablaNombre_Tablas(tablas ts, char *nombreTabla){
	if(!existenTablas(ts)){
		return false;
	}else{
		return existeTablaNombre_Tabla(ts->t, nombreTabla);
	}
}

TipoRet addCol_tablas(tablas &ts, char *nombreTabla, char *NombreCol, TipoDatoCol tipoCol, Calificador calificadorCol){
	if(existenTablas(ts)){
		if(existeTablaNombre_Tablas(ts, nombreTabla)){
			return addCol_tabla(ts->t, nombreTabla, NombreCol, tipoCol, calificadorCol);
		} else{
			cout << " - No existe la tabla " << nombreTabla << endl;
			return ERROR;
		}
	} else {
		cout << " - No existen tablas" << endl;
		return ERROR;
	}
}

TipoRet printMetadata(tablas ts, char *nombreTabla){
	if (!existenTablas(ts)){
		cout << " - No hay tablas" << endl;
		return ERROR;
	}else if(!existeTablaNombre_Tablas(ts, nombreTabla)){
		cout << "No existe ninguna tabla con ese nombre"<< endl;
		return ERROR;
	}else{
		printMetaData_Tabla(ts->t, nombreTabla);
		return OK;
	}
}
