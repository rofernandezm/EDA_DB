// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// bd.c
// Modulo de Implementación de Base de Datos.

#include <iostream>
#include <string.h>
#include "bd.h"
#include "tablas.h"

using namespace std;

struct nodo_bd{
	tablas ts;
};


bd createBD(){
	bd bd = new(nodo_bd);
	bd->ts = crearTablas();
	return bd;
}


TipoRet createTable(bd & bd, char *nombreTabla){
	
	return crearTabla_Tablas(bd->ts, nombreTabla);
}


TipoRet dropTable(bd & bd, char *nombreTabla){

	if(bd->ts == NULL){
		cout << " - Base de datos vacia" << endl;
        	return ERROR;
	} else {
		return dropTable_Tablas(bd->ts, nombreTabla);
	}
}


TipoRet addCol(bd & bd, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol){

	if(bd->ts == NULL){
		cout << " - Base de datos vacia" << endl;
        	return ERROR;
        }else{
		TipoDatoCol tipo;
		Calificador cal;

		//Valida que el tipo de dato sea correcto
		if (strcasecmp(tipoCol, "string") == 0){
		tipo = STRING;
		} else if (strcasecmp(tipoCol, "int") == 0){
		tipo = INT;
	    }else{
			cout << " - Tipo de columna ingresado es incorrecto" << endl;
		return ERROR;
	    }
		
		//Valida que el calificador sea correcto
		if (strcasecmp(calificadorCol, "ANY") == 0){
			cal = ANY;
		} else if (strcasecmp(calificadorCol, "NOT_EMPTY") == 0){
			cal = NOT_EMPTY;
		} else if (strcasecmp(calificadorCol, "PRIMARY_KEY") == 0){
		   	cal = PRIMARY_KEY;
	    	}else{
			cout << " - Calificador ingresado es incorrecto" << endl;
		return ERROR;
	    }

		return addCol_tablas(bd->ts, nombreTabla, NombreCol, tipo, cal);
	}
}


TipoRet dropCol (bd & bd, char *nombreTabla, char *NombreCol){

	if (bd->ts == NULL){
		cout << " - Base de datos vacia" << endl;
        	return ERROR;
	}else{
		return dropCol_tablas(bd->ts, nombreTabla, NombreCol);
	}
}


TipoRet alterCol (bd & bd, char * nombreTabla, char * nombreCol, char *tipoColNuevo, char *calificadorColNuevo, char *nombreColNuevo){
	if(bd->ts == NULL){
		cout << " - Base de datos vacia" << endl;
        	return ERROR;
        }else{
		TipoDatoCol tipo;
		Calificador cal;

		//Valida que el tipo de dato sea correcto
		if (strcasecmp(tipoColNuevo, "string") == 0){
			tipo = STRING;
		} else if (strcasecmp(tipoColNuevo, "int") == 0){
			tipo = INT;
		}else{
			cout << " - Tipo de columna ingresado es incorrecto" << endl;
			return ERROR;
		}
		
		//Valida que el calificador sea correcto
		if (strcasecmp(calificadorColNuevo, "ANY") == 0){
			cal = ANY;
		}else if (strcasecmp(calificadorColNuevo, "NOT_EMPTY") == 0){
			cal = NOT_EMPTY;
		}else if (strcasecmp(calificadorColNuevo, "PRIMARY_KEY") == 0){
		   	cal = PRIMARY_KEY;
	    	}else{
			cout << " - Calificador ingresado es incorrecto" << endl;
			return ERROR;
		}

		return alterCol_Tablas(bd->ts, nombreTabla, nombreCol, tipo, cal, nombreColNuevo);
	}
}


TipoRet insertInto (bd & bd, char *nombreTabla, char *columnasTupla, char *valoresTupla){
	if(bd->ts == NULL){
		cout << " - Base de datos vacia" << endl;
        	return ERROR;
        }else
		return insertInto_Tablas(bd->ts, nombreTabla, columnasTupla, valoresTupla);
}


TipoRet deleteFrom (bd & bd, char *nombreTabla, char *condicionEliminar){
	
	if(bd->ts == NULL){
		cout << " - Base de datos vacia" << endl;
        	return ERROR;
        }else
		return deleteFrom_tablas(bd->ts, nombreTabla, condicionEliminar);
}


TipoRet update(bd & bd, char * nombreTabla, char * condicionModificar, char * columnaModificar, char * valorModificar){
	//cout << " - update " << nombreTabla << " " << condicionModificar << " " << columnaModificar << " " << valorModificar << endl;
	return NO_IMPLEMENTADA;
}


TipoRet selectWhere (bd & bd,char * nomTabla1, char * condicion, char * nomTabla2){
	//cout << " - selectWhere " << nomTabla1 << " " << condicion << " " << nomTabla2 << endl;
	return NO_IMPLEMENTADA;
}


TipoRet select (bd & bd, char * nomTabla1, char * nomColumnas, char * nomTabla2){
	//cout << " - select " << nomTabla1 << " " << nomColumnas << " " << nomTabla2 << endl;
	return NO_IMPLEMENTADA;
}


TipoRet join (bd & bd, char * nomTabla1, char * nomTabla2, char * nomTabla3){
	//cout << " - join " << nomTabla1 << " " << nomTabla2 << " " << nomTabla3 << endl;
	return NO_IMPLEMENTADA;
}


TipoRet union_(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3){
	//cout << " - union_ " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}


TipoRet intersec(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3){
	//cout << " - intersec " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}


TipoRet minus_(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3){
	//cout << " - minus_ " << nombreTabla1 << " " << nombreTabla2 << " " << nombreTabla3 << endl;
	return NO_IMPLEMENTADA;
}


TipoRet printdatatable (bd bd, char *NombreTabla){

	return printDataTable_tablas(bd->ts, NombreTabla);

}


TipoRet printTables(bd bd){

	imprimirTablas(bd->ts);
	return OK;
}


TipoRet printMetadata(bd bd, char *nombreTabla){
	//cout << " - printMetadata " << nombreTabla << endl;
	return printMetadata(bd->ts, nombreTabla);
}


TipoRet undo(bd & bd){
	//cout << " - undo" << endl;
	return NO_IMPLEMENTADA;
}


TipoRet redo(bd & bd){
	//cout << " - redo" << endl;
	return NO_IMPLEMENTADA;
}


bd destroyBD(bd & bd){
	//
	return NULL;
}

