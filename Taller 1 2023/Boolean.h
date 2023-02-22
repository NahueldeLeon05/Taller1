#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#include <stdio.h>
typedef enum {FALSE, TRUE} boolean;

//Carga un boolean
void CargarBoolean(boolean &b);
//muestra el boolean cargado
void MostrarBoolean(boolean b);

#endif // BOOLEAN_H_INCLUDED
