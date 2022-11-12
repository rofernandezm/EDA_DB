// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// celda.c
// Modulo de Implementación de Base de Datos.

#include <string.h>
#include <iostream>
#include "celda.h"

using namespace std;

struct nodo_celda{
	char * datoStr;
	int datoInt;
	bool usada;
	bool hayDato;
	celda sig;
};

celda nuevaCelda(celda &cel){
	if(cel == NULL){
		celda nueva_celda = new(nodo_celda);
		nueva_celda->hayDato = false;
		nueva_celda->usada = true;
		nueva_celda->sig = NULL;
		cel = nueva_celda;
	}else{
		cel->sig = nuevaCelda(cel->sig);
	}
	return cel;
}

/*celda insertInto_vacia(celda &cel){

	if(cel == NULL){
		celda nueva_celda = nuevaCelda();
		nueva_celda->hayDato = false;
		nueva_celda->usada = true;
		nueva_celda->sig = NULL;
		cel = nueva_celda;
	}else{
		cel->sig = insertInto_vacia(cel->sig);
	}
	return cel;
}*/


void eliminarCeldas(celda &cel){
	if(cel->sig != NULL){
		eliminarCeldas(cel->sig);
	}
	delete cel;
}


celda insertInto_int(celda &cel, int dato){

	if(cel->sig == NULL){
		cel->datoInt = dato;
		cel->hayDato = true;
		cel->usada = true;
		cel->sig = NULL;
	}else{
		cel->sig = insertInto_int(cel->sig, dato);
	}
	return cel;
}


celda insertInto_char(celda &cel, char * dato){
	
	if(cel->sig == NULL){
		cel->datoStr = new char[MAX_NOMBRE];
		strcpy(cel->datoStr, dato);
		cel->hayDato = true;
		cel->usada = true;
		cel->sig = NULL;	
	}else{
		cel->sig = insertInto_char(cel->sig, dato);
	}
	return cel;
}


bool existeDato_int(celda cel, int dato){
	bool existe = false;
	
	while((cel != NULL) && (existe == false)){
		if(cel->datoInt == dato){
			//Si existe el dato cambia el bool
			existe = true;
		}
		cel = cel->sig;
	}
	
	return existe;
}


bool existeDato_char(celda cel, char * dato){
	bool existe = false;
	
	while((cel != NULL) && (existe == false)){
		if(strcmp(dato, cel->datoStr)==0){
			//Si existe el dato cambia el bool
			existe = true;
		}
		cel = cel->sig;
	}
	
	return existe;
}


bool hayCeldasVacias(celda cel){

	bool hayVacio = false;
	
	while((cel != NULL) && (hayVacio == false)){
		if(cel->hayDato == true)
			cel = cel->sig;
		else
			hayVacio = true;
	}
	
	return hayVacio;
}


void valoresAString(celda cel){

	while(cel != NULL){
		char string[MAX_NOMBRE];
		sprintf(string, "%d", cel->datoInt);
		cel = cel->sig;	
	}
}




void printDataTable_celda(celda cel, TipoDatoCol tipo, int indice){
	
	int i = 1;
	
	while((cel != NULL) && (i < indice)){
		cel = cel->sig;
		i++;
	}
	

	
	if((cel != NULL) && (cel->hayDato == true)){
		if(tipo == INT){
			cout << cel->datoInt << ":" ;
		}else{
			cout << cel->datoStr << ":" ;
		}
	}else if((cel != NULL) && (cel->hayDato == false)){
		cout << "vacio:" ;
	}
	
}


/*void insertVacios_celda(celda &cel, int indice){

	while((indice > 1) && (cel->sig != NULL)){
		cel = cel->sig;
		indice--;
	}
	
	if(indice > 1){
		celda nueva_celda = nuevaCelda();
		nueva_celda->hayDato = false;
		nueva_celda->usada = true;
		nueva_celda->sig = NULL;
		cel->sig = nueva_celda;
	}

	
	if((indice == 1) && (cel == NULL)){
		celda nueva_celda = nuevaCelda();
		nueva_celda->hayDato = false;
		nueva_celda->usada = true;
		nueva_celda->sig = NULL;
		cel = nueva_celda;
	}else if(indice>1){
		cel->sig = insertVacios_celda(cel->sig, indice-1);
	}
	
	return cel;
}*/















