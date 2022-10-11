#ifndef BD_H
#define BD_H

// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// bd.h
// Modulo de Definición de Base de Datos.

#include "define.h"

typedef struct nodo_bd * bd;

bd createBD();
// Crea la base de datos vacía.

TipoRet createTable (bd & bd, char *nombreTabla);
// Crea una nueva tabla vacía (sin columnas ni tuplas) en la base de datos
// con nombre nombreTabla, siempre que no exista ya una tabla con dicho nombre.

TipoRet dropTable (bd & bd, char *nombreTabla);
// Elimina de la base de datos la tabla de nombre nombreTabla, y las tuplas
// que la misma posee, si nombreTabla existe.

TipoRet addCol (bd & bd, char *nombreTabla, char *NombreCol, char *tipoCol, char *calificadorCol);
// Agrega a la tabla de nombre nombreTabla, si ésta existe, una nueva columna al final de nombre nombreCol,
// si ésta no existe. Si la tabla tiene tuplas el nuevo campo tendrá el valor EMPTY en cada tupla. Por lo
// tanto, en el caso de que la tabla tenga tuplas, no es válido que se agregue un calificador distinto de ANY.
// Tampoco es válido que calificadorCol sea PRIMARY KEY si existe ya una columna con dicho calificador en la
// tabla nombreTabla.

TipoRet dropCol (bd & bd, char *nombreTabla, char *NombreCol);
// Elimina de la tabla de nombre nombreTabla, si ésta existe, la columna de nombre
// nombreCol, si ésta existe. Si la tabla tiene tuplas, entonces se eliminará de éstas
// el campo correspondiente a la columna eliminada. Si la tabla posee una única columna
// de nombre nombreColentonces quedará como tabla vacía. Si la columna a eliminar es la
// PRIMARY KEY, la operación resultará inválida, salvo que ésta sea la única columna de
// la tabla, en cuyo caso quedará como tabla vacía, como se describió previamente.

TipoRet alterCol (bd & bd, char * nombreTabla, char * nombreCol, char *tipoColNuevo, char *calificadorColNuevo, char *nombreColNuevo);
// Modifica de la tabla de nombre nombreTabla, si ésta existe, la columna de nombre nombreCol,
// si ésta existe, quedando ésta columna con el nuevo tipo de datos tipoColNuevo, calificador
// calificadorColNuevo y nombre nombreColNuevo, si éste último no es el nombre de otra columna
// de la tabla. Si la tabla tiene tuplas, los valores de la columna modificada deberán satisfacer
// las nuevas características (tipo de dato y calificador). El tipo de datos sólo puede cambiar de
// integer a string y en este caso se deberá realizar la conversión de tipo de la columna especificada
// en todas las tuplas de la tabla.

TipoRet insertInto (bd & bd, char *nombreTabla, char *columnasTupla, char *valoresTupla);
// Inserta en la tabla de nombre nombreTabla, si ésta existe, una tupla con los valores
// dados en valoresTupla para las columnas indicadas en columnasTupla, si los nombres de las
// columnas existen, los valores son del tipo adecuado y satisfacen los calificadores correspondientes
// a cada columna. Si no se indican todas las columnas se inserta EMPTY en las otras. Por lo tanto,
// la operación se permite sólo si las columnas que no se indican tienen el calificador ANY. Los nombres
// de las columnas en columnasTupla y los valores de valoresTupla se separan con el uso del caracter
// dos puntos (:) y deben corresponderse uno a uno. Esto es, el nombre de columna i en columnasTupla con
// el valor en la posición i de valoresTupla. Si la tupla a insertar pertenece a la tabla,
// la operación no tendrá efecto.

TipoRet deleteFrom (bd & bd, char *nombreTabla, char *condicionEliminar);
// Elimina de la tabla de nombre nombreTabla, si éste existe, todas las tuplas que cumplen
// la condición condiciónEliminar. En caso de que la condición sea “”, se eliminan todas
// las tuplas de la tabla. Si ninguna tupla cumple la condición, la operación no tendrá
// efecto. El formato de las condiciones es: columna operador valor (sin espacios en blanco
// intermedios). Los operadores a utilizar son: = “igual”, ! “Distinto”, > “Mayor” , < “Menor”
// y * “Igual Prefijo”

TipoRet update(bd & bd, char * nombreTabla, char * condicionModificar, char * columnaModificar, char * valorModificar);
// Modifica en la tabla de nombre nombreTabla, si éste existe, el valor de las tuplas en la
// columna de nombre columnaModificar, si éste existe, que cumplen la condición condiciónModificar.
// En la columna especificada de las tuplas que cumplen la condición se asigna el valor valorModificar,
// siempre que este valor sea del tipo adecuado y satisfaga el calificador de la columna especificada.
// La condición respeta el formato descrito para condiciones.

TipoRet selectWhere (bd & bd,char * nomTabla1, char * condicion, char * nomTabla2);
// Dado un nombre de tabla nombreTabla1 y una condición, genera una nueva tabla en la base de datos de
// nombre nombreTabla2, si nombreTabla1 existe y nombreTabla2 no existe, con las tuplas de la tabla nombreTabla1
// que cumplan la condición. En caso de que la condición sea “”, la operación tiene aplicación sobre todas las
// tuplas de la tabla. La condición respeta el formato descripto anteriormente para condiciones (ver operación delete).

TipoRet select (bd & bd, char * nomTabla1, char * nomColumnas, char * nomTabla2);
// Dado un nombre de tabla nombreTabla1 y uno o más nombres de columnas de dicha tabla especificados en el
// parámetro columnas, genera una nueva tabla en la base de datos de nombre nombreTabla2, si nombreTabla1
// existe, nombreTabla2 no existe y si todas las columnas especificadas pertenecen a la tabla de nombre
// nombreTabla1. La tabla nombreTabla2 tendrá las tuplas de la tabla nombreTabla1 sólo con las columnas
// especificadas, manteniendo el orden establecido en el parámetro columnas. Los nombres de las columnas
// se separan con el uso del caracter dos puntos (:).

TipoRet join (bd & bd, char * nomTabla1, char * nomTabla2, char * nomTabla3);
// Dadas dos tablas de nombres nombreTabla1 y nombreTabla2, tales que ambas tengan exactamente una única columna
// en común con el mismo nombre, calificada como PRIMARY KEY, genera una nueva tabla en la base de datos de nombre
// nombreTabla3, si nombreTabla1 y nombreTabla2 existen y nombreTabla3 no existe. La nueva tabla nombreTabla3 tendrá
// todas las columnas de la tabla nombreTabla1 y las columnas de nombreTabla2, en ese orden, excepto la que esté
// calificada como PRIMARY KEY en nombreTabla2 (de modo de no repetirla). Asimismo, la tabla nombreTabla3 tendrá
// exclusivamente las tuplas que satisfagan la igualdad de las claves de ambas tablas.

TipoRet union_(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3);
// Dadas dos tablas de nombres nombreTabla1 y nombreTabla2 con igual esquema (nombres de columnas, tipos
// de datos y calificadores), genera una nueva tabla en la base de datos de nombre nombreTabla3, si nombreTabla1
// y nombreTabla2 existen y nombreTabla3 no existe. La nueva tabla nombreTabla3 tendrá el mismo esquema que las
// otras tablas y las tuplas de ambas. 

TipoRet intersec(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3);
// Idem a la descripción de la operación unión pero para la intersección. Es decir, la tabla resultante
// nombreTabla3 contiene sólo las tuplas comunes a nombreTabla1 y nombreTabla2.

TipoRet minus_(bd & bd, char * nombreTabla1, char * nombreTabla2, char * nombreTabla3);
// Idem a las operaciones anteriores pero para la diferencia de la tabla nombreTabla1 con la tabla
// nombreTabla2. Es decir, la tabla resultante nombreTabla3 tiene las tuplas que están en nombreTabla1
// pero no en nombreTabla2.

TipoRet printdatatable (bd bd, char *NombreTabla);
// Imprime las tuplas de la tabla de nombre nombreTabla, si ésta existe. Los nombres y los valores
// de las columnas se expresan en el formato columna1:columna2: … :columnan. Las tuplas se muestran
// ordenadas ascendentemente por la PRIMARY KEY. Primero se imprime el nombre de la tabla, luego los
// nombres de las columnas, separados con (:), y por último las tuplas, cuyos campos se separan
// también con (:).

TipoRet printTables(bd bd);
// Imprime los nombres de las tablas de la base de datos del sistema, ordenados alfabéticamente de menor a mayor.

TipoRet printMetadata(bd bd, char *nombreTabla);
// Imprime el esquema de la tabla de nombre nombreTabla, si éste existe. Es decir, imprime el nombre
// de la Tabla, los nombres de sus columnas en el orden correspondiente, indicando para cada columna su
// tipo de datos y calificador si lo tuviera.

TipoRet undo(bd & bd);
// Deshace el efecto de la última operación ejecutada que modifica el estado de la base de datos.
// En particular, las operaciones de impresión de datos resultan transparentes al sistema ya que no
// modifican el estado de la base de datos. Si no hay operaciones previas que modifiquen el estado de
// la base de datos, la operación undo no tiene efecto. Una operación undo no deshace el efecto de una
// operación undo inmediatamente anterior a ella, sino que refiere a la operación previa a la operación
// cuyo efecto se deshace con la ejecución del primer undo.

TipoRet redo(bd & bd);
// Rehace el efecto de la operación deshecha inmediatamente antes. La operación redo no tiene efecto
// si no hay una operación undo ejecutada inmediatamente antes que provoque un cambio de estado en la
// base de datos. Al igual que para el comando undo, asumimos que en particular las operaciones de
// impresión de datos resultan transparentes al sistema (no deberían tenerse en cuenta en el proceso undo-redo).

bd destroyBD(bd & bd);
// Destruye bd y libera la memoria asociada.

#endif

