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
	int indice;
	columna col;
};

tabla crearTabla(char * nombreTabla){
	tabla t = new(nodo_tabla);
	t->nombre = new char[MAX_NOMBRE];
	strcpy(t->nombre, nombreTabla);
	t->indice = 0;
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

bool existeMasDeUnaColumna_tabla(tabla t) {
	//Pre: Existe al menos 1 columna
	return existeMasDeUnaColumna_col(t->col);
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


TipoRet addCol_tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoDato, Calificador calificadorCol){
	
	if(!existenColumnas(t)){ 
	//Verifica que no existan columnas en la tabla "currentTable"
		t->col = addCol(t->col, NombreCol, tipoDato, calificadorCol);
		return OK;

	}else if(existeColumnaNombre_Tabla(t, NombreCol)){
	//Verifica que no existan columnas con el mismo nombre
		cout << " - Ya existe una columna con el nombre '"<< NombreCol << "'" << endl;
		return ERROR; 
		
	}else if((existePrimaryKey_columna(t->col)) && calificadorCol == PRIMARY_KEY){
	//Verifica si ya existe alguna columna con primary key
		cout << " - No puede haber mas de una columna con calificador 'PRIMARY_KEY' por tabla" << endl;
		return ERROR;
		
	}else if(existenTuplas(t->col) && calificadorCol != ANY){
		cout << " - Ya existen datos en esta tabla, el calificador no puede ser distinto que ANY" << endl;
		return ERROR;
	}else{
		addCol(t->col, NombreCol, tipoDato, calificadorCol);
		return OK;
	}
}

void printMetaData_Tabla(tabla t, char *nombreTabla){
	//No se realiza iteracin sobre tablas porque hay una unica tabla
	cout << " - Tabla: " << t->nombre << endl;
	printMetaData_Column(t->col);
}

TipoRet dropCol_tabla(tabla &t, char *nombreCol){
	if(!existeColumnaNombre_Tabla(t, nombreCol)){
		cout << " - No existe la columna '" << nombreCol << "'" << endl;
		return ERROR;
	} else {
		dropCol_col(t->col, nombreCol);
		return OK;
	}
}

TipoRet dropTable_tabla(tabla t, char *nombreTabla){
	if(t->col != NULL){
		deleteCellInColAndCol(t->col);
	}
	delete t;
	return OK;
}

TipoRet alterCol_Tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoColNuevo, Calificador calificadorColNuevo, char *nombreColNuevo){
	
	/* TO-DO logica para encnotrar la tabla, revisar
	
	bool encontrada = false;
	
	//Encontrar la tabla correcta por su nombre
	while((t != NULL) && (encontrada == false)){
		if(strcmp(nombreTabla, t->nombre) != 0)
			t = t->sig; //itera
		else
			encontrada = true; //corta el while
	}*/
	

	if(!existeColumnaNombre_Tabla(t, NombreCol)){
		//Si no existe una columna con el nombre NombreCol
		cout << " - No existe la columna '" << NombreCol << "'" << endl;
		return ERROR;
	}else{
		if(existeMasDeUnaColumna_tabla(t) && (calificadorColNuevo == PRIMARY_KEY)) {
			cout << "No es posible agregar un 'PRIMARY_KEY' cuando hay mas de una columna" << endl;
			return ERROR;
			
		}else if(existePrimaryKey_columna(t->col) && calificadorColNuevo == PRIMARY_KEY) {
			cout << "Ya existe una columna con calificador 'PRIMARY_KEY'" << endl;
			return ERROR;
			
		}else{
			return alterCol_col(t->col, NombreCol, tipoColNuevo, calificadorColNuevo, nombreColNuevo);
		}
	}
}


TipoRet insertInto_Tabla(tabla &t, char *columnasTupla, char * valoresTupla){
	
	if(t->col == NULL){
		//La tabla no tiene columnas
		cout << "La tabla " << t->nombre << " no tiene columnas" << endl;
		return ERROR;
	}else{
		crearCeldas(t->col);
		//La tabla tiene columnas
		
		char columnas[200];
		strcpy(columnas, columnasTupla);
		char datos[200];
		strcpy(datos, valoresTupla);
		char *tokenCol, *col, *tokenDatos, *dat;
		col = &columnas[0];
		dat = &datos[0];
		
		tokenCol = strtok(columnas, " : ");
		tokenDatos = strtok(datos, " : ");
		
		while((tokenCol != NULL) && (tokenDatos != NULL)) {
		
			if(existeColumnaNombre(t->col, tokenCol)){
				//Si existe la columna, inserta los datos
				insertInto_Columna(t->col, tokenCol, tokenDatos);
			}
			col = &col[strlen(col) +1];
			dat = &dat[strlen(dat) +1];
			tokenCol = strtok(col, " : ");
			tokenDatos = strtok(dat, " : ");
		}
		
		t->indice++;

		return OK;
	}
}

TipoRet printDataTable_tabla(tabla t, char *nombreTabla){

		cout << "Tabla: " << nombreTabla << endl;
		printDataTable_col(t->col, t->indice);
		return OK;
	
}














