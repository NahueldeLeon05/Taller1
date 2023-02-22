#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "Boolean.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

//Valida formato de fecha
boolean ValidarFormato(String fecha);

//Trasforma string a fecha
Fecha transformarFecha(String input);

//Valida fecha
boolean validarFecha(Fecha f);

#endif // FECHA_H_INCLUDED
