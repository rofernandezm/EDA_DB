// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// bd.c
// Modulo de Implementación de Base de Datos.

#include <string.h>
#include <iostream>

using namespace std;

/*
//Definicion de Tipos de dato
tipoInt[3] = 'INT';
tipoStr[3] = 'STR';

//Definion de Calificador
califNotE = 'not empty';
califPrimKey
*/

struct columna{
	int indice;
	char * nombreColumna;
	char * tipo;
	char * datoStr;
	int datoInt;
	char * calif;
	columna sig;
};
/*
struct columnaString{
	int indice;
	char nombreColumna;
	char dato;
	columnaString sig;
	Calificador
};
*/

void addCol(tabla &t, char * nombreColumna, char tipoDato, char calificador){
	
	columna col = new(nodo_columna);
	//asigna el nombre a la columna
	col->nombreColumna = new char[20];
	strcpy(t->nombreColumna, nombreColumna); 
	//asigna el tipo
	col->tipo = new char[6];
	strcpy(t->tipo, tipoDato);
	//asigna el calificador
	
	//TO-DO revisar si los to-dos siguientes van aca o van en tabla.h
	//TO-DO validar si la tabla es vacia antes de asignar el calificador, si la tabla no es vacia no puede ser algo que no sea ANY
	//TO-DO validar si existe la tabla
	col->calif = new char[11];
	strcpy(t->calif, calificador);
};