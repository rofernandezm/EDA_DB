// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// celda.c
// Modulo de Implementación de Base de Datos.

#include <string.h>
#include <iostream>
#include "celda.h"
#include "columna.h"

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


void deleteFrom_celda(columna col, char *nombreCol, celda &cel, int &indice, TipoDatoCol tipo, char simbolo, char *condicion){
	celda anter = NULL;
	celda iter = cel;
	int indiceBorrado = 1;
	
		if(tipo == INT){
			//La celda es de tipo INT
			int dato;
			dato = atoi(condicion);
			
			if(simbolo == '='){
				while(iter != NULL){
					if((iter->hayDato == true) && (iter->datoInt == dato)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
							indice--;
						}
					}else{
						anter = iter;
						iter = anter->sig;
						indiceBorrado++;
					}
				}
			}else if(simbolo == '!'){
				while(iter != NULL){
					if((iter->hayDato == true) && (iter->datoInt != dato)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							indice--;
						}
						borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
					}else{
						anter = iter;
						iter = anter->sig;
						indiceBorrado++;
					}
				}
			
			}else if(simbolo == '>'){
				while(iter != NULL){
					if((iter->hayDato == true) && (iter->datoInt > dato)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							indice--;
						}
						borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
					}else{
						anter = iter;
						iter = anter->sig;
						indiceBorrado++;
					}
				}
				
			}else if(simbolo == '<'){
				while(iter != NULL){
					if((iter->hayDato == true) && (iter->datoInt < dato)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							indice--;
						}
						borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
					}else{
						anter = iter;
						iter = iter->sig;
						indiceBorrado++;
					}
			}
		}
			
		}else{
			//La celda es de tipo string
			if(simbolo == '='){
				while(iter != NULL){
					if((iter->hayDato == true) && (strcmp(iter->datoStr, condicion) == 0)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							indice--;
						}
						borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
					}else{
						anter = iter;
						iter = iter->sig;
						indiceBorrado++;
					}
				}
			
			}else if(simbolo == '!'){
				while(iter != NULL){
					if((iter->hayDato == true) && (strcmp(iter->datoStr, condicion) != 0)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							indice--;
						}
						borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
					}else{
						anter = iter;
						iter = iter->sig;
						indiceBorrado++;
					}
				}
			
			}else if(simbolo == '>'){
				while(iter != NULL){
					if((iter->hayDato == true) && (strcmp(iter->datoStr, condicion) > 0)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							indice--;
						}
						borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
					}else{
						anter = iter;
						iter = iter->sig;
						indiceBorrado++;
					}
				}
				
			}else if(simbolo == '<'){
				while(iter != NULL){
					if((iter->hayDato == true) && (strcmp(iter->datoStr, condicion) < 0)){
						//Quiero borrar
						if(anter == NULL){
							//Estoy en el primer elemento
							cel = cel->sig;
							delete iter;
							iter = cel;
							indice--;
						}else{
							anter->sig = iter->sig;
							delete iter;
							iter = anter->sig;
							indice--;
						}
						borrarPorIndiceMenosUna_col(col, nombreCol, indiceBorrado);
					}else{
						anter = iter;
						iter = iter->sig;
						indiceBorrado++;
					}
				}
			}
		}
	
}



void borrarPorIndiceMenosUna_celda(celda &cel, int indiceABorrar){

	celda anter = NULL;
	celda iter = cel;
	
	while((iter != NULL) && (indiceABorrar > 1)){
		anter = cel;
		iter = iter->sig;
		indiceABorrar--;
	}
	
	if(anter == NULL){
		//Estoy en el primer elemento
		cel = cel->sig;
		delete iter;
		iter = cel;
	}else{
		anter->sig = iter->sig; 
		delete iter;
		iter = anter->sig;
	}

}













