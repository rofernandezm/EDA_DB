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
	tabla sig; 
};

tabla crearTabla(tabla t, char * nombreTabla){
	if(t == NULL){
		tabla nueva_tabla = new(nodo_tabla);
		nueva_tabla->nombre = new char[MAX_NOMBRE];
		strcpy(nueva_tabla->nombre, nombreTabla);
		nueva_tabla->indice = 0;
		nueva_tabla->sig = NULL;
		t = nueva_tabla;
	}else{
		t->sig = crearTabla(t->sig, nombreTabla);
	}
	return t;
}

void nombreTabla(tabla t){
	while(t != NULL){
		cout << " - " << t->nombre << endl;
		t = t->sig;
	}
}

bool existeTablaNombre_Tabla(tabla t, char *nombreTabla){
	bool existe = false;
	while((t != NULL) && (existe == false)){
		if(strcmp(t->nombre, nombreTabla)==0){
			existe = true;
		}else{
			t = t->sig;
		}
	}
	
	return existe;
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


TipoRet addCol_tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoDato, Calificador calificadorCol){
	
	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}
	
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

	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}
	
	cout << " - Tabla: " << t->nombre << endl;
	printMetaData_Column(t->col);
	
}

TipoRet dropCol_tabla(tabla &t, char *nombreTabla, char *nombreCol){
	
	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}
	
	if(!existeColumnaNombre_Tabla(t, nombreCol)){
		cout << " - No existe la columna '" << nombreCol << "'" << endl;
		return ERROR;
	} else {
		dropCol_col(t->col, nombreCol);
		return OK;
	}
}

TipoRet dropTable_tabla(tabla t, char *nombreTabla){

	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}
	
	
	if(t->col != NULL){
		deleteCellInColAndCol(t->col);
	}
	delete t;
	return OK;
}

TipoRet alterCol_Tabla(tabla &t, char *nombreTabla, char *NombreCol, TipoDatoCol tipoColNuevo, Calificador calificadorColNuevo, char *nombreColNuevo){
	
	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}
	

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


TipoRet insertInto_Tabla(tabla &t, char *nombreTabla, char *columnasTupla, char * valoresTupla){

	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}
	
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

	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}

		cout << "Tabla: " << nombreTabla << endl;
		printDataTable_col(t->col, t->indice);
		return OK;
	
}

TipoRet deleteFrom_tabla(tabla t, char *nombreTabla, char *condicionEliminar){

	//Itero entre las tablas para llegar a la tabla nombreTabla
	while((t != NULL) && (strcmp(t->nombre, nombreTabla) != 0)){
		t = t->sig;
	}

	
	char str[100];
	char *columna1;
   	char simbolo;
   	char *condicion;
   	int i = 0;

   	strcpy(str, condicionEliminar);
   	
   	
   	//Obtener el simbolo
   	while((str[i] != '=') && (str[i] != '!') && (str[i] != '>') && (str[i] != '<')){
   		//Itera en el string hasta encontrar el simbolo
        	i++;
    	}
    	
    	simbolo = str[i];
    	
    	
    	//Obtener los datos de las columnas
    	columna1 = strtok(str, " = ! > < ");
    	condicion = strtok(NULL, " = ! > < ");
    	
    	
    	//Encontrar la tabla nombreTabla
    	bool tablaEncontrada = false;
    	
    	while((t != NULL) && tablaEncontrada == false){
    		if(strcmp(nombreTabla, t->nombre) == 0)
    			tablaEncontrada = true;
    		else
    			t = t->sig;
    	}
    	

    	//Se da por sentado que la tabla nombreTabla existe porque se controla en tablas.c
    	if(!existenColumnas(t)){
    		cout << "La tabla " << t->nombre << " no tiene columnas" << endl;
    		return ERROR;	
    	}else if(!existeColumnaNombre_Tabla(t, columna1)){
    		cout << "No existe columna con el nombre " << columna1 << " en la tabla " << t->nombre << endl; 
    		return ERROR;
    	}else{
    		return deleteFrom_col(t->col, t->indice, columna1, simbolo, condicion);
    	}
    	
    	
    	
}













