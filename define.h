#ifndef DEFINE_H
#define DEFINE_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// define.h
// Modulo de Definiciones Generales.

#define MAX_COMANDO 128
#define MAX_NOMBRE 20

enum _retorno{OK, ERROR, NO_IMPLEMENTADA};
typedef enum _retorno TipoRet;

enum _calificadorCol{PRIMARY_KEY, NOT_EMPTY, ANY};
typedef enum _calificadorCol Calificador;

enum _tipoDatoCol{STRING, INT};
typedef enum _tipoDatoCol TipoDatoCol;


#endif
