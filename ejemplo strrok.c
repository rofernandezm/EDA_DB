/* Online C Compiler and Editor */
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main ()
{
    char columnas[80];
    strcpy(columnas, "Nombre:CI:Edad");
    char datos[80];
    strcpy(datos, "Mariana:1:diez");

//    const char s[2] = ":";

    char *tokenCol, *col;
    char *tokenDatos, *dat;
    dat = &datos[0];
    col = &columnas[0];

    /* get the first token */
    tokenCol = strtok(columnas, ":");
    tokenDatos = strtok(datos, ":");
    
    
            printf( "col=%s ", columnas);
        printf( "datos=%s \n", datos);

    /* walk through other tokens */
    while((tokenCol != NULL) && (tokenCol != NULL)) {
        printf( "%s = ", tokenCol);
        printf( "%s \n", tokenDatos);
        col = &col[strlen(col) +1];
        dat = &dat[strlen(dat) +1];
        tokenCol = strtok(col, ":");
        tokenDatos = strtok(dat, ":");
      //  sts

    }
 
}
