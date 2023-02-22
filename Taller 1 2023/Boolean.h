#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>
typedef enum {FALSE, TRUE} boolean;

//Carga un valor booleano por teclado
void cargarBoolean(boolean &b);

//Muestra un valor booleano por pantalla
void desplegarBoolean(boolean b);

#endif // BOOLEAN_H_INCLUDED
