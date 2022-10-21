// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// tabla.c
// Modulo de Implementación de Base de Datos.

#include "tabla.h"
#include "columna.h"
#include <string.h>

struct nodo_tabla{
	char * nombre;
	columna * columna;
};

tabla crearTabla(char * nombreTabla){
	ts->t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	t->columna = NULL;
	return t;
}

char * nombreTabla(tabla t){
	return t->nombre;
}

boolean existeTablaNombre_Tabla(tabla t, char *nombreTabla){
	if(strcmp(t->nombre, nombreTabla)==0){
		return true;
	} else{
		return false;
	}
}

boolean existenColumnas(tabla t){
	if(t->columna==NULL){
		return false;
	}else{
		return true;
	}
}

boolean existeColumnaNombre_Tabla(tabla t, char *NombreCol){
	if(existenColumnas(t)){
		return existeColumnaNombre(t->columna, NombreCol);
	} else{
		return false;
	}
}

tabla getTableByName(tabla t, char *nombreTabla){
	if(strcmp(t->nombre, nombreTabla)==0){
		return t;
	}
}

/*
boolean isEmptyColumn_Tabla(tabla t, char *NombreCol){
	if(existeColumnaNombre_Tabla(t, NombreCol)){
		return isEmptyColumn_Tabla(t->columna, NombreCol);
	}
	//Ver error
}
*/

TipoRet addCol_tabla(tabla &t, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){
	
	if(!existenColumnas(t)){ //Verifica que no existan columnas en la tabla "currentTable"

		t->columna=addCol(t, NombreCol, tipoCol, calificadorCol);
		return OK;

	}else if(existeColumnaNombre_Tabla(t, NombreCol)){

		cout << 'Ya existe una tabla con este nombre';
		return ERROR; //si la columna ya existía retorna un error

	} else {

		

		//Existen columnas con distinto nombre
		//Validación del calificador
		//Se hace funcion para tener calificador?
		//Se hace funcion para ver si exite primarykey? o se modifca TAD indicando cuando ya lo tiene?



		/*
		if((nombreTabla->columnaT->datoStr != NULL) && (nombreTabla->columnaT->datoInt != NULL)){ //si las columnas no tienen ningún dato
			addCol(nombreTabla, NombreCol, tipoCol, calificadorCol);
			return OK;
		}else if(strcmp(calificadorCol, "ANY") == 0){ //Si la tabla tiene datos y el calificador de la nueva columna es "ANY", la crea
			addCol(nombreTabla, NombreCol, tipoCol, calificadorCol);
			return OK;
		}else{ //Si el calificador no es ANY, retorna un error
			cout << 'El calificador de esta columna no puede ser distinto que ANY';
			return ERROR;
		}*/
	}

	/*
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
			}else if(strcmp(calificadorCol, "ANY") == 0){ //Si la tabla tiene datos y el calificador de la nueva columna es "ANY", la crea
				addCol(nombreTabla, NombreCol, tipoCol, calificadorCol);
				return OK;
			}else{ //Si el calificador no es ANY, retorna un error
				cout << 'El calificador de esta columna no puede ser distinto que ANY';
				return ERROR;
			}
		}
	}
	*/
}