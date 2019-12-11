#include <string.h>
#include "pilotos.h"

void hardcodePilotos(ePiloto listaPilotos[],int tam)
{
    int auxId[4] = {100,101,102,103};
    char auxNombre[4][30] = {"Juan Perez","Carlos Gomez","Miguel Santillan","Eduardo Cascante"};
    int i;

    for(i=0;i<tam;i++)
    {
        listaPilotos[i].idPiloto = auxId[i];
        strcpy(listaPilotos[i].nombre, auxNombre[i]);
    }
}
