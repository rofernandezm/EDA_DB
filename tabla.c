// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tabla.c
// Modulo de Implementación de Base de Datos.

#include "tabla.h"
#include "columna.h"
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct nodo_tabla{
	char * nombre;
	columna col;
};

tabla crearTabla(char * nombreTabla){
	tabla t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	t->col = nuevaColumna();
	return t;
}

char * nombreTabla(tabla t){
	return t->nombre;
}

bool existeTablaNombre_Tabla(tabla t, char *nombreTabla){
	if(strcmp(t->nombre, nombreTabla)==0){
		return true;
	} else{
		return false;
	}
}

bool existenColumnas(tabla t){
	if(t->col==NULL){
		return false;
	}else{
		return true;
	}
}

bool existeColumnaNombre_Tabla(tabla t, char *NombreCol){
	if(existenColumnas(t)){
		return existeColumnaNombre(t->col, NombreCol);
	} else{
		return false;
	}
}

tabla getTableByName(tabla t, char *nombreTabla){
	if(strcmp(t->nombre, nombreTabla)==0){
		return t;
	} else {
		return NULL;
	}
}

/*
void imprimirTablas(tablas ts){
	if (!existenTablas(ts)){
		cout << " - No hay tablas" << endl;
	}else{
		cout << nombreTabla(ts->t) << endl;
	}
}
*/

/*
bool isEmptyColumn_Tabla(tabla t, char *NombreCol){
	if(existeColumnaNombre_Tabla(t, NombreCol)){
		return isEmptyColumn_Tabla(t->col, NombreCol);
	}
	//Ver error
}
*/

TipoRet addCol_tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoDato, Calificador calificadorCol){
	
	if(!existenColumnas(t)){ 
	//Verifica que no existan columnas en la tabla "currentTable"
		t->col = addCol(t->col, NombreCol, tipoDato, calificadorCol);
		return OK;

	}else if(existeColumnaNombre_Tabla(t, NombreCol)){
	//Verifica que no existan columnas con el mismo nombre
		cout << "Ya existe una columna con el nombre "<< NombreCol << endl;
		return ERROR; 
		
	}else if((existePrimaryKey_columna(t->col)) && calificadorCol == PRIMARY_KEY){
	//Verifica si ya existe alguna columna con primary key
		cout << "No puede haber mas de una primary key por tabla" << endl;
		return ERROR;
		
	}else if(existenTuplas(t->col) && calificadorCol != ANY){
		cout << "Ya existen datos en esta tabla, el calificador no puede ser distinto que ANY" << endl;
		return ERROR;
	}else{
		addCol(t->col, NombreCol, tipoDato, calificadorCol);
		return OK;
	}
}

void printMetaData_Tabla(tabla t, char *nombreTabla){
	//No se realiza iteracin sobre tablas porque hay una unica tabla
	cout << "Tabla " << t->nombre << endl;
	printMetaData_Column(t->col);
}



