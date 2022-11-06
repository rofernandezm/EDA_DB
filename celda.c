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
	bool hayDato = false;
	celda sig;
};

celda nuevaCelda(){
	return NULL;
}


void eliminarCeldas(celda &cel){
	if(cel->sig != NULL){
		eliminarCeldas(cel->sig);
	}
	delete cel;
}


celda insertInto_int(celda cel, int dato){

	if(cel == NULL){
		celda nueva_celda = new(nodo_celda);
		nueva_celda->datoInt = dato;
		nueva_celda->hayDato = true;
		nueva_celda->sig = NULL;
	}else{
		insertInto_int(cel->sig, dato);
	}
	
	return cel;
}


celda insertInto_char(celda cel, char * dato){
	
	if(cel == NULL){
		celda nueva_celda = new(nodo_celda);
		nueva_celda->datoStr = new char[MAX_NOMBRE];
		strcpy(nueva_celda->datoStr, dato);
		nueva_celda->hayDato = true;
		nueva_celda->sig = NULL;
		
		
	}else{
		insertInto_char(cel->sig, dato);
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









