#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "String.h"
#include "boolean.h"

typedef struct {
    int dia;
    int mes;
    int anio;
} Fecha;

// Cargar la informacion de la fecha con los datos ingresados.
Fecha CargarFecha(int anio, int mes, int dia);

// Mostrar en pantalla la fecha ingresada.
void MostrarFecha(Fecha f);

// Obtener el dia de la fecha ingresada.
int ObtenerDiaFecha(Fecha f);

// Obtener el mes de la fecha ingresada.
int ObtenerMesFecha(Fecha f);

// Obtener el año de la fecha ingresada.
int ObtenerAnioFecha(Fecha f);

// Comparar dos fechas devolviendo TRUE si la
// primera es mayor estricto que la segunda.
// De lo contrario devuelve FALSE.
boolean FechaMayor(Fecha f1, Fecha f2);

// Comparar dos fechas devolviendo TRUE si la
// primera es mayor o igual que la segunda.
// De lo contrario devuelve FALSE.
boolean FechaMayorIgual(Fecha f1, Fecha f2);

// Guardar la información de la fecha en un archivo.
// Precondicion: EL archivo debe venir abierto para escritura.
void GuardarFecha(Fecha F, FILE* f);

// Cargar la información de la fecha desde un archivo.
// Precondicion: EL archivo debe venir abierto para lectura.
void LeerFecha(Fecha &F, FILE* f);

//Trasforma string a fecha
Fecha TransformarFecha(String input);

// Validar el formato de la fecha ingresada.
boolean ValidarFecha(Fecha f);

// Devolver la fecha por defecto (0/0/0).
Fecha FechaDefecto();

#endif // FECHA_H_INCLUDED
