#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input.h"

int getInt(char mensaje[], char msjError[], int menor, int mayor)
{
    int numero;

    printf(mensaje);
    scanf("%d",&numero);

       while( (isalpha(numero) == 0) && (numero < menor || numero > mayor))
        {
            printf(msjError);
            fflush(stdin);
            scanf("%d",&numero);
        }

    return numero;
}

float getFloat(char* mensaje, char* msjError,int menor, int mayor)
{
    float numFloat;

    printf(mensaje);
    scanf("%f",&numFloat);

    while(numFloat < menor || numFloat > mayor)
    {
        printf(msjError);
        fflush(stdin);
        scanf("%f",&numFloat);
    }

    return numFloat;
}

int isDigitOrPoint(char* cadena)
{
    int retorno;
    int i;

    if((cadena[0] >= 48 && cadena[0] <= 57) || (cadena[0] == 45) )
    {
        for(i=1; i<strlen(cadena); i++)
        {
            if((cadena[i] >= 48 && cadena[i] <= 57) || (cadena[i] == 44))
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
                break;
            }
        }
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


char getChar(char* mensaje)
{
    char letra;
    int aux;

    printf(mensaje);
    fflush(stdin);

    letra = getche();
    aux = isalpha(letra);

    if(aux != 0)
    {
        return letra;
    }
    else
    {
        return NULL;
    }

}


int validar_char(char caracter)
{
    int retorno = -1;
    char aux;

    aux = isalpha(caracter);

    /*Si retorno es distinto de 0(FALSO), porque es una letra...*/
    if(aux != 0)
    {
        retorno = 1;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


char* getString(char mensaje[], char msjError[])
{
    int auxInt;
    char* auxString = (char*)malloc(sizeof(char)*20);

    if(auxString != NULL)
    {
        printf(mensaje);
        fflush(stdin);
        gets(auxString);

        auxInt = validar_string(auxString);

        while(auxInt != 1)
        {
            printf(msjError);
            fflush(stdin);
            gets(auxString);

            auxInt = validar_string(auxString);
        }

        auxString = corregirMayus(auxString);
    }

    return auxString;
}


int validar_string(char* cadena)
{
    int i;
    int retorno = 1;

    for(i=0; i<strlen(cadena) ;i++)
    {
        if( (isalpha(cadena[i]) == 0) && (isspace(cadena[i]) == 0) )
        {
            retorno = -1;
            break;
        }
    }

    return retorno;
}

char* corregirMayus(char* cadena)
{
    int len;
    int i;
    char* auxString = NULL;

    len = strlen(cadena);

    if( cadena != NULL)
    {

        auxString = strlwr(cadena);

        for(i=0;i<len;i++)
        {
            if( i == 0)
            {
                auxString[0] = toupper(auxString[0]);
            }

            if( auxString[i] == 32) /*32 corresponde al espacio en el cod ASCII*/
            {
                auxString[i+1] = toupper(auxString[i+1]);
            }
        }
    }

    return auxString;
}

int menu(char mensaje[],char msjError[])
{
    int opcion;

    printf("1- Alta vuelo\n");
    printf("2- Baja vuelo\n");
    printf("3- Modificar estado vuelo\n");
    printf("4- Listar vuelos\n\n");
    printf("5- Salir\n\n");

    opcion = getInt(mensaje,msjError,1,5);

    return opcion;
}
