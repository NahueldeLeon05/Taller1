#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "Boolean.h"
const int MAX = 80;
typedef char * String;

//Verifica que nombre sea alfabético
boolean nombreAlfabetico(String nom);

//Pasa a mayusculas el String
void PasarMayus(String &nombre);

//Verifica que el parametro sea "->"
boolean esFlecha(String flecha);

//Libera el espacio de memoria usado por le string
void liberarString(String s);

#endif // STRING_H_INCLUDED
