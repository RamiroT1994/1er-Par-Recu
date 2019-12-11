#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <string.h>

#define TAMP 4
#define TAMV 10
#define TAMD 8

int main()
{
    eDestino listaDestinos[TAMD];
    ePiloto listaPilotos[TAMP];
    /* HARDCODE */

    hardcodeDestinos(listaDestinos,8);
    hardcodePilotos(listaPilotos,4);

    int opcion;

    do
    {
        system("cls");
        opcion = menu("Seleccione una opcion: ","Error. Reingrese opcion valida: ");

        switch(opcion)
        {
            case 1:
                system("cls");

                system("pause");
                break;
            case 2:
                printf("BAJA");
                break;
            case 3:
                printf("MODIFICAR");
                break;
            case 4:
                printf("LISTADO");
                break;
            case 5:
                printf("SALIR");
                break;
        }

    }while(opcion != 5);

    return 0;
}

