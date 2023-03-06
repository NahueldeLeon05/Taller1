#ifndef MIEMBROLISTA_H_INCLUDED
#define MIEMBROLISTA_H_INCLUDED

#include <stdio.h>

#include "MiembroABB.h"

typedef struct {
    MiembroABB m;
    boolean monarcaActual;
    boolean fueMonarca;
    boolean aspirante;
    boolean abdico;
    boolean fallecio;
    Fecha ascension;
    Fecha abdicacion;
    Fecha fallecimiento;
}   MiembroLista;

//Crea miembro de Lista
MiembroLista CrearMiembroLista(MiembroABB m, boolean monarcaActual);

//Despliega el miembro de la lista
void MostrarMiembroLista(MiembroLista ml);

//Devuelve si el miembro de la lista es rey o no
boolean EsRey(MiembroLista m);

//Devuelve si el miembro de la lista esta muerto o no
boolean Muerto(MiembroLista m);

//Devuelve si el miembro de la lista abdicó o no
boolean Abdico(MiembroLista m);

//Devuelve si el miembro de la lista es aspirante o no
boolean EsAspirante(MiembroLista m);

//Devuelve si el miembro de la lista es o no primogenito
boolean Primogenito(MiembroLista m);

//Devuelve si la fecha ascensión es 0/0/0
boolean fechaVacia(MiembroLista m);

//Muestra fecha de inicio y fin del reinado del miembro
void MostrarInicioFin(MiembroLista mL);

void MostrarAspirante(MiembroLista ml);

void MostrarMiembroListaHis(MiembroLista ml);

MiembroABB ObtenerMiembroABB(MiembroLista ml);

//Selectora obtiene si es monarca actual
boolean ObtenerMonarcaActual(MiembroLista mL);

//Selectora obtiene si fue monarca
boolean ObtenerFueMonarca(MiembroLista mL);

//Selectora obtiene si abdico
boolean ObtenerAbdico(MiembroLista mL);

//Selectora obtiene si fallecio
boolean ObtenerFallecio(MiembroLista mL);

//Selectora obtiene si es aspirante
boolean ObtenerAspirante(MiembroLista mL);

//Selectora obtener fecha de ascencion
Fecha ObtenerFechaAscencion(MiembroLista mL);

void CargarFechaAscension(MiembroLista &mL, Fecha f);

//Selectora obtener fecha de abdicacion
Fecha ObtenerFechaAbdicacion(MiembroLista mL);

void CargarFechaAbdicacion(MiembroLista &mL, Fecha f);

//Selectora obtener fecha de Fallecimiento
Fecha ObtenerFechaFallecimiento(MiembroLista mL);

void CargarFechaFallecimiento(MiembroLista &mL, Fecha f);

//Devuelve si el miembro de la lista esta vivo o no
boolean Vivo(MiembroLista m);

//Precondicion: el archivo debe venir abierto para escritura.
void GuardarMiembroLista(FILE* f, MiembroLista ml);

//Precondicion: el archivo debe venir abierto para lectura.
void CargarMiembroLista(FILE* f, MiembroLista &ml);

void LiberarMiembroLista(MiembroLista &ml);

#endif // MIEMBROLISTA_H_INCLUDED
