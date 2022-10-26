// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// columna.c
// Modulo de Implementación de Base de Datos.

#include "columna.h"
#include "celda.h"
#include <string.h>
#include <iostream>

using namespace std;

struct nodo_columna{
	char * nombreColumna;
	TipoDatoCol tipo;
	Calificador calif;
	celda dato;
	columna sig;
};

columna nuevaColumna(){
	return NULL;
}

char *getNombreColumna(columna col){
	return col->nombreColumna;
}

bool existeMasDeUnaColumna_col(columna col){
	if (col->sig != NULL) {
		return true;
	}
	else {
		return false;
	}
}

void deleteCellInColAndCol(columna col){
	if(col->sig == NULL){
		eliminarCeldas_col(col);
	}else{
		eliminarCeldas_col(col->sig);
	}
	delete col;
}

TipoDatoCol getTipoDato_col(columna col, char* NombreCol) {
	// Pre: Tiene que existir NombreCol
	if(strcmp(col->nombreColumna, NombreCol) == 0) {
		return col->tipo;
	}
	else {
		return getTipoDato_col(col-> sig, NombreCol);
	}
}

bool existeColumnaNombre(columna col, char *nombreCol){
	if(strcmp(col->nombreColumna , nombreCol)==0){
		return true;
	}else if(col->sig == NULL) {
		return false;
	} else {
		return existeColumnaNombre(col->sig, nombreCol);
	}
}

bool existePrimaryKey_columna(columna col){
	if(col == NULL)
		return false;
	else{
		if(col->calif == PRIMARY_KEY)
			return true;
		else
			return existePrimaryKey_columna(col->sig);
	}
}

Calificador getColumnCalif(columna col, char *NombreCol){
	if(strcmp(col->nombreColumna, NombreCol)==0){
		return col->calif;
	}else {
		return getColumnCalif(col->sig, NombreCol);
	}
}

columna addCol(columna col, char * nombreCol, TipoDatoCol tipoDato, Calificador calificador){
	
	if(col == NULL){
		columna nueva = new(nodo_columna);
		nueva->nombreColumna = new char[20];
		strcpy(nueva->nombreColumna, nombreCol);
		nueva->tipo = tipoDato;
		nueva->calif = calificador;
		nueva->dato = NULL; //llamar funcion crearCelda();
		nueva->sig = NULL;
		col = nueva;
	}else{
		col->sig = addCol(col->sig, nombreCol, tipoDato, calificador);
	}
	return col;
}

bool existenTuplas(columna col){
	if(col->dato == NULL)
		return false;
	else
		return true;
}

void printMetaData_Column(columna col){

	if(col != NULL){
		cout << " - Columna: " << "\n\tNombre: " << col->nombreColumna << "\n\tTipo: " << enumToTipo(col) << "\n\tCalificador: " << enumToCalificador(col)  << endl;
		printMetaData_Column(col->sig);
	}
}

char * enumToTipo(columna col){
	char * tipo = new(char[10]);
	if(col->tipo == 0)
		strcpy(tipo, "String");
	else
		strcpy(tipo, "Int");
	return tipo;
}

char * enumToCalificador(columna col){
	char * calif = new(char[15]);
	if(col->calif == 0)
		strcpy(calif, "Primary Key");
	else if(col->calif == 1)
		strcpy(calif, "Not Empty");
	else
		strcpy(calif, "Any");
	return calif;
}

void eliminarCeldas_col(columna col){
	if(existenTuplas(col)){
		eliminarCeldas(col->dato);
	}
}

void dropCol_col(columna &col, char *nombreCol){
	//To-Do crear funcion que elimine todos las celdas
	columna anter = NULL;
	columna iter = col;
	
	while(iter != NULL){
		if(strcmp(iter->nombreColumna, nombreCol) == 0){
		//estoy en el elemento que quiero borrar
			eliminarCeldas_col(iter);
			if(anter == NULL){
			//Si es el primer item de la lista
				col = col->sig;
				delete iter;
				iter = col;
			}else{
			//Si es un item del medio
				anter->sig = iter->sig;
				delete iter;
				iter = anter->sig;
			}
		}else{
		//No estoy en la columna que quiero borrar, itero
			anter = iter;
			iter = iter->sig;
		}
	}
}


void alterCol_col(columna &col, char *NombreCol, TipoDatoCol tipoColNuevo, Calificador calificadorColNuevo, char *nombreColNuevo) {





	/* CONSULTAR POR GUIA RAZONAMIENTO
	if (!existeTablaNombre_Tabla(t->nombre, nombreTabla)){
	//Si la tabla no exciste
		
		cout << "La tabla no exciste" << endl;
		
	}else if (!existeColumnaNombre(col->nombre,*nombreCol)){
	// Si la columna no exciste
		
		cout << "La columna no exciste" << endl;
	}else if (nombreCol->calif == PRIMARY_KEY && Col->sig != NULL){
	//Si nombreCol es PRIMARY_KEY y la tabla tiene más columnas.
		
		cout << "No se puede modificar la columna que es Primary Key si exciste al menos otra columna" << endl;
		
	}else // caso que modifica
	{
		strcpy(nombreColNuevo->nombreCol, nombreCol);
		strcpy(nombreCol->Col->tipoDato, tipoColNuevo);
		
	}
	

	*/
}

TipoRet insertInto_Columna(columna col, char * columna, char * dato){
	
	bool columnaEncontrada = false;
	
	while((columnaEncontrada == false) && (col->sig != NULL)){
		if(strcmp(col->nombreColumna, columna) != 0){
			//Si no es esta la columna, itero
			col = col->sig;
		}else{
			//Estoy en la columna en la que quiero agregar datos
			
			if(col->calif == PRIMARY_KEY){
				//Si la columna es primary key hay que verificar que no exista ese dato 
				
				if(col->tipo == INT){
					//Si la columna es tipo int, parsea a int
					int datoInsert;
					datoInsert = atoi(dato);
					if(existeDato_int(col->dato, datoInsert)){
						//Si el dato se repite, no lo inserta 
						cout << "No se puede ingresar el dato " << datoInsert << "en la columna " << columna << "porque ya existe y es primary key" << endl;
						return ERROR;
					}else{
						insertInto_int(col->dato, datoInsert);
						return OK;
					}
				}else{
					//Si el dato es tipo char, 
					if(existeDato_char(col->dato, dato)){
						//Si el dato se repite, no lo inserta 
						cout << "No se puede ingresar el dato " << dato << "en la columna " << columna << "porque ya existe y es primary key" << endl;
						return ERROR;
					}else{
						insertInto_char(col->dato, dato);
						return OK;
					}
				}	
			}else{
				//si la columna no es primary key
				if(col->tipo == INT){
					//Si la columna es tipo int, parsea a int
					int datoInsert;
					datoInsert = atoi(dato);
					insertInto_int(col->dato, datoInsert);
					return OK;
				}else{
					//Si el dato es tipo char, lo pasa
					insertInto_char(col->dato, dato);
					return OK;
				}
			}
			
			columnaEncontrada = true;
		}
	}
	
	if(!columnaEncontrada){
		cout << "No existe la columna " << columna << endl;
		return ERROR;
	}
}













