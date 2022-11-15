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
	if(nombreTabla==NULL){
		cout << " - No se especifico el nombre de la tabla a crear." << endl;
		return ERROR;
	}else if (!existenTablas(ts)){
		ts = new(nodo_tablas);
		ts->t = crearTabla(nombreTabla);
		ts->iz=crearTablas();
		ts->de=crearTablas();
		return OK;
	}else{
		cout << " - Imposible crear tabla '" << nombreTabla << "', ya exite una creada y el sistema soporta solo una" << endl;
		return ERROR;
	}
}

void imprimirTablas(tablas ts){
	if (!existenTablas(ts)){
		cout << "No existe ninguna tabla creada" << endl;
	}else{
		cout << " - " << nombreTabla(ts->t) << endl;
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
			cout << " - No existe la tabla '" << nombreTabla << "'" << endl;
			return ERROR;
		}
	} else {
		cout << "No existe ninguna tabla creada" << endl;
		return ERROR;
	}
}

TipoRet printMetadata(tablas ts, char *nombreTabla){
	if (!existenTablas(ts)){
		cout << "No existe ninguna tabla creada" << endl;
		return ERROR;
	}else if(!existeTablaNombre_Tablas(ts, nombreTabla)){
		cout << " - No existe la tabla '" << nombreTabla << "'" << endl;
		return ERROR;
	}else{
		printMetaData_Tabla(ts->t, nombreTabla);
		return OK;
	}
}

TipoRet dropCol_tablas(tablas ts, char *nombreTabla, char *nombreCol){
	if(ts->t == NULL){
		cout << "No existe ninguna tabla creada" << endl;
		return ERROR;
	}else if(!existeTablaNombre_Tablas(ts, nombreTabla)){
		//Si no existe la tabla nombreTabla
		cout << " - No existe la tabla '" << nombreTabla << "'" << endl;
		return ERROR;
	}else{
		return dropCol_tabla(ts->t, nombreCol);
	}

}

TipoRet dropTable_Tablas(tablas &ts, char *nombreTabla){
	if(ts->t == NULL){
		cout << "No existe ninguna tabla creada" << endl;
		return ERROR;
	}else if(!existeTablaNombre_Tablas(ts, nombreTabla)){
		//Si no existe la tabla nombreTabla
		cout << " - No existe la tabla '" << nombreTabla << "'" << endl;
		return ERROR;
	}else{
		dropTable_tabla(ts->t, nombreTabla);
		ts=NULL;
		return OK;
	}
}

TipoRet alterCol_Tablas(tablas &ts, char *nombreTabla, char *nombreCol, TipoDatoCol tipoColNuevo, Calificador calificadorColNuevo, char *nombreColNuevo){
	if(existenTablas(ts)){
		if(existeTablaNombre_Tablas(ts, nombreTabla)){
			//Si existe una tabla con ese nombre
			return alterCol_Tabla(ts->t, nombreTabla, nombreCol, tipoColNuevo, calificadorColNuevo, nombreColNuevo);
		} else{
			cout << " - No existe la tabla '" << nombreTabla << "'" << endl;
			return ERROR;
		}
	} else {
		cout << "No existe ninguna tabla creada" << endl;
		return ERROR;
	}
}

TipoRet insertInto_Tablas(tablas &ts, char *nombreTabla, char *columnasTupla, char *valoresTupla){
	if(existeTablaNombre_Tablas(ts, nombreTabla)){
		return insertInto_Tabla(ts->t, columnasTupla, valoresTupla);
	} else{
		cout << " - No existe la tabla con el nombre: " << nombreTabla << endl;
		return ERROR;
	}
}

TipoRet printDataTable_tablas(tablas ts, char *nombreTabla){
	if(ts->t == NULL){
		cout << "No existe ninguna tabla creada" << endl;
		return ERROR;
	}else if(!existeTablaNombre_Tablas(ts, nombreTabla)){
		cout << "No existe la tabla " << nombreTabla << endl; 
		return ERROR;
	}else{ 
		//TO-DO logica para encontrar la tabla
		return printDataTable_tabla(ts->t, nombreTabla);
	}
}

TipoRet deleteFrom_tablas(tablas ts, char *nombreTabla, char *condicionEliminar){

	if(ts->t == NULL){
		cout << "No existe ninguna tabla creada" << endl;
		return ERROR;
	}else if(!existeTablaNombre_Tablas(ts, nombreTabla)){
		cout << " - No existe la tabla '" << nombreTabla << "'" << endl;
		return ERROR;
	}else{
		return deleteFrom_tabla(ts->t, nombreTabla, condicionEliminar);
	}
}














