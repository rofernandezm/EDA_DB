// Estructuras de Datos y Algoritmos - Curso 2022
// Tecnologo en Informatica FIng - DGETP - UTEC
//
// Trabajo Obligatorio
// main.h
// Consola para ingreso de datos.

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "bd.h"

using namespace std;

int main()
{
	bd bd = createBD();
	char * comando = new (char[MAX_COMANDO]);
	char * pch, * pch1, * pch2, *pch3, *pch4;
	TipoRet ret;
	bool ejecutado = false;

	bool salir = false;
	
	do{
		cout << "\tcreateTable(nombreTabla)\n";
		cout << "\tdropTable(nombreTabla)\n";
		cout << "\taddCol(nombreTabla, NombreCol, tipoCol, calificadorCol)\n";
		cout << "\tdropCol(nombreTabla, NombreCol)\n";
		cout << "\talterCol(nombreTabla, nombreCol, tipoColNuevo, calificadorColNuevo, nombreColNuevo)\n";
		cout << "\tinsertInto(nombreTabla, columnasTupla, valoresTupla)\n";
		cout << "\tdeleteFrom(nombreTabla, condicionEliminar)\n";
		cout << "\tupdate(nombreTabla, condicionModificar, columnaModificar, valorModificar)\n";
		cout << "\tselectWhere(nomTabla1, condicion, nomTabla2)\n";
		cout << "\tselect(nomTabla1, nomColumnas, nomTabla2)\n";
		cout << "\tjoin(nomTabla1, nomTabla2, nomTabla3)\n";
		cout << "\tunion(nombreTabla1, nombreTabla2, nombreTabla3)\n";
		cout << "\tintersec(nombreTabla1, nombreTabla2, nombreTabla3)\n";
		cout << "\tminus(nombreTabla1, nombreTabla2, nombreTabla3)\n";
		cout << "\tprintdatatable(NombreTabla)\n";
		cout << "\tprintTables()\n";
		cout << "\tprintMetadata(nombreTabla)\n";
		cout << "\tundo()\n";
		cout << "\tredo()\n";
		cout << "\tsalir()\n\n";
		cout << "> ";
		fflush( stdin );
		ejecutado = false;
		
		fgets (comando, MAX_COMANDO, stdin);

		pch = strtok (comando,"( ,)");

		if (strcasecmp (pch, "createTable") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret = createTable (bd, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "dropTable") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret = dropTable (bd, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "addCol") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						pch3 = strtok (NULL, "( ,)");
						if (pch3 != NULL){
							ret = addCol (bd, pch, pch1, pch2, pch3);
							ejecutado = true;
						}
						else
							cout << " - ERROR: Faltan Parametros.\n";
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "alterCol") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						pch3 = strtok (NULL, "( ,)");
						if (pch3 != NULL){
							pch4 = strtok (NULL, "( ,)");
							if (pch4 != NULL){
								ret = alterCol (bd, pch, pch1, pch2, pch3, pch4);
								ejecutado = true;
							}
							else
								cout << " - ERROR: Faltan Parametros.\n";
						}
						else
							cout << " - ERROR: Faltan Parametros.\n";
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}

		else if (strcasecmp (pch, "dropCol") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL)
			{
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					ret = dropCol (bd, pch, pch1);
					ejecutado = true;
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "insertInto") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						ret = insertInto (bd, pch, pch1, pch2);
						ejecutado = true;
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "deleteFrom") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					ret = deleteFrom (bd, pch, pch1);
					ejecutado = true;
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "update") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						pch3 = strtok (NULL, "( ,)");
						if (pch3 != NULL){
							ret = update (bd, pch, pch1, pch2, pch3);
							ejecutado = true;
						}
						else
							cout << " - ERROR: Faltan Parametros.\n";
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "selectWhere") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						ret = selectWhere (bd, pch, pch1, pch2);
						ejecutado = true;
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "select") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						ret = select (bd, pch, pch1, pch2);
						ejecutado = true;
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "join") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						ret = join (bd, pch, pch1, pch2);
						ejecutado = true;
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "union") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						ret = union_ (bd, pch, pch1, pch2);
						ejecutado = true;
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "intersec") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						ret = intersec (bd, pch, pch1, pch2);
						ejecutado = true;
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "minus") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				pch1 = strtok (NULL, "( ,)");
				if (pch1 != NULL){
					pch2 = strtok (NULL, "( ,)");
					if (pch2 != NULL){
						ret = minus_ (bd, pch, pch1, pch2);
						ejecutado = true;
					}
					else
						cout << " - ERROR: Faltan Parametros.\n";
				}
				else
					cout << " - ERROR: Faltan Parametros.\n";
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "printdatatable") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret =  printdatatable (bd, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "printTables") == 0){
				ret = printTables (bd);
				ejecutado = true;
		}
		else if (strcasecmp (pch, "printMetadata") == 0){
			pch = strtok (NULL, "( ,)");
			if (pch != NULL){
				ret =  printMetadata (bd, pch);
				ejecutado = true;
			}
			else
				cout << " - ERROR: Faltan Parametros.\n";
		}
		else if (strcasecmp (pch, "undo") == 0){
				ret = undo (bd);
				ejecutado = true;
		}
		else if (strcasecmp (pch, "redo") == 0){
				ret = redo (bd);
				ejecutado = true;
		}
		else if (strcasecmp (pch, "salir") == 0){
			salir = true;
		}
		else
			cout << " - Comando Incorrecto\n";
		if (ejecutado){
				if (ret == OK)
					cout << " - OK\n";
				else if (ret == ERROR)
					cout << " - ERROR\n";
				else
					cout << " - NO IMPLEMENTADA\n";
		}
	}while (!salir);
	cout << "\n\n - CHAUU!!!!\n";

	bd = destroyBD(bd);
	delete [] comando;
}
