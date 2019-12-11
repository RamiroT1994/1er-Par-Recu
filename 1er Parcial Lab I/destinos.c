#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destinos.h"

void hardcodeDestinos(eDestino listaDestinos[],int tamd)
{
    int auxId[8] = {1,2,3,4,5,6,7,8};
    char auxDescrip[4][50] = {"Cancun","Miami","Rio de Janeiro","Dominicana"};
    float precio[8] = {7500.50,18900.75,11550.99,9350.10,5575.12,7845.15,23125.15,13750.33};

    int i;

    for(i=0;i<tamd;i++)
    {
        listaDestinos[i].idDestino = auxId[i];
        strcpy(listaDestinos[i].descripcion,auxDescrip[i]);
        listaDestinos[i].precio = precio[i];
    }
}


void mostrarListadoDestinos(eDestino listaDestinos[], int tamd)
{
    int i;

    char auxTitulo1 [10] = "ID";
    char auxTitulo2 [15] = "DESCRIPCION";
    char auxTitulo3 [10] = "PRECIO";

    printf("%s%20s%16s\n",auxTitulo1,auxTitulo2,auxTitulo3);

    for(i=0; i<tamd; i++)
    {
        mostrarUnDestino(listaDestinos[i]);
    }
}

void mostrarUnDestino(eDestino destino)
{
    printf("%d %20s %15.2f\n",destino.idDestino,destino.descripcion,destino.precio);
}

