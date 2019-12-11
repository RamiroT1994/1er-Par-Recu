#include <stdio.h>
#include <stdlib.h>
#include "vuelos.h"

void hardcodeVuelos(eVuelo listaVuelos[],int numero)
{
    int i;

    int idVuelo[7] = {2001,2002,2003,2004,2005,2006,2007};
    int idDestino[7] = {2,3,8,4,5,1,5};
    int idPiloto[7] = {103,101,103,102,101,104,100};
    int partida[7] = {13,14,12,18,23,00,11};
    int llegada[7] = {15,18,14,22,05,19};

    int estadoVuelo[7] = {DEMORADO,CANCELADO,SUSPENDIDO,SUSPENDIDO,ACTIVO,ACTIVO,DEMORADO};

    for(i=0; i<numero; i++)
    {
        listaVuelos[i].idVuelo = idVuelo[i];
        listaVuelos[i].idDestino = idDestino[i];
        listaVuelos[i].idPiloto = idPiloto[i];
        listaVuelos[i].partida = partida[i];
        listaVuelos[i].llegada = llegada[i];

        listaVuelos[i].estado = estadoVuelo[i];
    }
}




int altaVuelo(eVuelo listaActores[],int tamv)
{
    int retorno = -1;
    int index;
    eVuelo auxVuelo;
    char respuesta;

    index = buscarLibre(listaActores,tamv);

    if(index != -1)
    {
        printf("Se ha encontrado lugar para cargar vuelo\n\n");

        auxVuelo = cargarActor(listaActores,tamv);

        printf("\n\nSe dara de alta al siguiente vuelo:");
        printf("\nID\tNOMBRE\tAPELLIDO\tSEXO\n");

        mostrarUnActor(auxVuelo);

        printf("\nDesea confirmar el alta del actor? S/N");
        fflush(stdin);
        respuesta = toupper(getch());

        while((respuesta != 'S') && (respuesta != 'N'))
        {
            printf("\n\nError. Reingrese una opcion valida.");
            fflush(stdin);
            respuesta = toupper(getch());
        }

        if(respuesta == 'S')
        {
            listaActores[index] = auxVuelo;
            printf("\n\nAlta realizada con exito\n\n");
            retorno = 1;
        }
        else if(respuesta == 'N')
        {
            printf("\n\nAlta de actor cancelada\n\n");
            retorno = 0;
        }

    }
    else
    {
        printf("\nNo se ha encontrado lugar para cargar actor\n\n");
    }


    return retorno;
}

int buscarLibre(eVuelo listaVuelos[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listaVuelos[i].estado != ACTIVO && listaVuelos[i].estado != SUSPENDIDO && listaVuelos[i].estado != DEMORADO && listaVuelos[i].estado != CANCELADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


eVuelo cargarVuelo(eVuelo listaVuelos[],int tamv,ePiloto listaPilotos[],int tamp, eDestino listaDestinos[],int tamd)
{
    eVuelo miVuelo;
    int auxId;

    miVuelo.idVuelo = generaId(listaVuelos,tamv);

    printf("Selecciona ID de destino\n\n");
    mostrarListadoDestinos(listaDestinos,tamd);

    scanf("%d",&auxId);


    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(miVuelo.apellido);

    printf("Identifique el sexo del actor\n\nIngrese H para hombre o M para mujer:");
    fflush(stdin);
    miVuelo.sexo = toupper(getch());

    while((miVuelo.sexo != 'H') && (miVuelo.sexo != 'M'))
    {
        printf("Error. Reingrese una opcion valida.\nIngrese H para hombre o M para mujer:");
        fflush(stdin);
        miVuelo.sexo = toupper(getche());
    }

   miVuelo.estado = OCUPADO;

    return miVuelo;
}


int generaId(eVuelo listaVuelos[],int tamv)
{
    int nuevoId;
    int i;
    int flag = 0;

    for(i=0;i<tamv;i++)
    {
        if(flag == 0 || listaVuelos[i].idVuelo > nuevoId)
        {
            flag = 1;
            nuevoId = listaVuelos[i].codigo;
        }
    }

    nuevoId++;
    return nuevoId;
}
