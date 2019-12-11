#include "destinos.h"

int menu(char mensaje[],char msjError[]);
int getInt(char* mensaje, char* msjError, int valorMenor, int valorMayor);


/** \brief Recibe un caracter.
 *
 * \param Recibe un string con mensaje.
 * \return Retorna el caracter en caso de ser valido.
 *         Retorna NULL en caso de no ser un caracter valido
 */
char getChar(char*);



/** \brief Valida que el caracter recibido sea un alpha
 *
 * \param El caracter a analizar.
 * \return Retorna 1 si es un caracter valido.
 * \return Retorna -1 si es no es un caracter valido.
 */
int validar_char(char);
char* getString(char[],char[]);
int validar_string(char*);
char* corregirMayus(char* cadena);
float getFloat(char* mensaje, char* msjError, int menor, int mayor);
