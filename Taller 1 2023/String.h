#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "Boolean.h"
const int MAX = 80;
typedef char * String;

void strcrear(String &s);

int strlar(String s);

void strcop(String from, String &to);

void scan(String &s);

void strcon(String &s1, String s2);

void strswp(String &s1, String &s2);

void print(String s1);

boolean strmen(String s1, String s2);

boolean streq(String s1, String s2, boolean ignoreCase);

// Precondición: El archivo viene abierto para escritura.
void GuardarString(String s, FILE * f);

// Precondición: El archivo viene abierto para lectura.
void LeerString(String &s, FILE * f);

//Verifica que nombre sea alfabético
boolean NombreAlfabetico(String nom);

//Pasa a mayusculas el String
void PasarMayus(String &nombre);

//Verifica que el parametro sea "->"
boolean EsFlecha(String flecha);

//Libera el espacio de memoria usado por le string
void LiberarString(String &s);

void PrimerPalabra(String &input, String &palabra);

void Recortar(String &input);

void Substr(String &input, int from);

boolean StringVacio(String input);

#endif // STRING_H_INCLUDED
