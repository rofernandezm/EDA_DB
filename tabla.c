// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// Modulo de Implementación de Base de Datos.

#include "tabla.h"
#include "columna.h"
#include "define.h"
#include <string.h>

struct nodo_tabla{
	char * nombre;
	columna * columnaT;
};

tabla crearTabla(char * nombreTabla){
	tabla t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	t->columnaT = NULL;
	return t;
}

char * nombreTabla(tabla t){
	return t->nombre;
}

TipoRet addCol_tabla(char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	
	if(nombreTabla->columnaT == NULL){
		addCol(nombreTabla, NombreCol, tipoCol, calificadorCol); //si no hay ninguna columna creada en esa tabla, la crea 
		return OK;
	}else{
		//Si hay alguna columna creada, valida que no exista otra que tenga el mismo nombre
		columna iter = columnaT;
		bool colRepetida = false;
		while((colRepetida == false) && (iter != NULL)){
			if(iter->nombre == NombreCol){ //valida que no exista otra con el mismo nombre
				colRepetida = true;
			}else{
				iter = iter->sig;
			}
		}
		
		if(colRepetida == true){
			cout << 'Ya existe una tabla con este nombre';
			return ERROR; //si la columna ya existía retorna un error
		}else{ 
			//Validación del calificador
			if((nombreTabla->columnaT->datoStr != NULL) && (nombreTabla->columnaT->datoInt != NULL)){ //si las columnas no tienen ningún dato
				addCol(nombreTabla, NombreCol, tipoCol, calificadorCol);
				return OK;
			}else if(strcomp(calificadorCol, "ANY") == 0){ //Si la tabla tiene datos y el calificador de la nueva columna es "ANY", la crea
				addCol(nombreTabla, NombreCol, tipoCol, calificadorCol);
				return OK;
			}else{ //Si el calificador no es ANY, retorna un error
				cout << 'El calificador de esta columna no puede ser distinto que ANY';
				return ERROR;
			}
		}
	}
}

