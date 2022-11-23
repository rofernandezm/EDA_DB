// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// columna.h
// Modulo de Implementación de Base de Datos.

#ifndef COLUMNA_H
#define COLUMNA_H

#include "define.h"
#include "tabla.h"

typedef struct nodo_columna * columna;

columna nuevaColumna();
//Crea una columna nueva


char *getNombreColumna(columna col);
//Retorna el nomnbre de la columna col
//Pre: col tiene que existir

TipoDatoCol getTipoDato_col(columna col);
//Retorna el tipo de dato de la columna col

Calificador getCalificador_col(columna col);
//Retorna el calificador de la columna col

columna getColByIndice(columna col, int indice);
//Retorna la columna en la posicion indice


bool existeMasDeUnaColumna_col(columna col);
//Pre: existe una columna
// True si hay mas de 1 columna, cualquier otro caso false

void deleteCellInColAndCol(columna col);
//Elimina las celdas en la columna col y las siguientes luego se elimina la columna
//Pre: col tiene que existir


columna addCol(columna col, char * nombreCol, TipoDatoCol tipoDato, Calificador calificador);
// Crea una columna de nombre "nombreCol"
// Pre: t creada previamente.

TipoRet dropCol(char *nombreTabla, char *nombreCol);
//Elimina la columna nombreCol si existe en la tabla nombreTabla


TipoRet insertInto_Columna(columna col, char * columnaNombre, char * dato);
//Inserta en la tabla nombreTabla una tupla con los valores dados en valoresTupla para las columnas indicadas en columnasTupla

bool existeColumnaNombre(columna col, char *nombreCol);
// True si existe la columna de nombre "nombreCol"

bool existePrimaryKey_columna(columna col);
//Retorna true si existe una primary key entre las columnas o false en caso contrario


bool existenTuplas(columna col);
//Retorna true si existe alguna tupla en la columna, false si no

void printMetaData_Column(columna col);
//Imprime los nombres de las columnas

char * enumToTipo(columna col);
//Recibe una columna y retorna un char con el tipo de dato

char * enumToCalificador(columna col);
//Recibe una columna y retorna un char con el calificador

void dropCol_col(columna &col, char *nombreCol);
//Elimina la columna nombreCol
//Pre: nombreCol tiene que existir

void eliminarCeldas_col(columna col);
//Elimina las celdas en la columna col
//Pre: col tiene que existir

TipoRet alterCol_col(columna &col, char *NombreCol, TipoDatoCol tipoColNuevo, Calificador calificadorColNuevo, char *nombreColNuevo);
// Modifica el nombre, tipo y calificador de la Columna NombreCol

columna obtenerColumaPorNombre(columna col, char * nombreCol);
//Devuelve una columna a partir de su nombre;

TipoRet insertInto_Columna(columna col, char * columna, char * dato);
//Inserta el dato en la columna

void printDataTable_col(columna col, int indice);
//Imprime la informacion de una tabla

void crearCeldas(columna col);
//Crea todas las celdas de esa columna

TipoRet deleteFrom_col(columna col, int &indice, char *nombreCol, char simbolo, char *condicion);
//Elimina las tuplas que cumplan la condicion
//Pre: Existe la columna nombreCol

void borrarPorIndiceMenosUna_col(columna col, char *nombreCol, int indiceABorrar);
//Borra las celdas en la posicion indiceABorrar de todas las columnas, menos de nombreCol


/*void selectWhere_col(tabla tabla1, tabla nuevaT, columna col, char *nombreCol, char *condicion, char simbolo);
//Copia en nuevaT los datos de tabla1 que cumplan la condicion*/


#endif
