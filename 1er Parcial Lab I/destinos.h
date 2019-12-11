#include "pilotos.h"

typedef struct
{
    int idDestino;
    char descripcion[50];
    float precio;

}eDestino;

void hardcodeDestinos(eDestino[],int);
void mostrarListadoDestinos(eDestino[],int);
void mostrarUnDestino(eDestino);
