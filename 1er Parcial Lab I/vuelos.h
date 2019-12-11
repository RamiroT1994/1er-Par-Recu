#define ACTIVO 1
#define SUSPENDIDO 2
#define DEMORADO 3
#define CANCELADO 4


typedef struct
{
    int idVuelo;
    int idDestino;
    int idPiloto;
    int partida;
    int llegada;

    int estado;

}eVuelo;

void hardcodeVuelos(eVuelo listaVuelos[],int numero);
