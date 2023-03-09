#ifndef MIEMBROABB_H_INCLUDED
#define MIEMBROABB_H_INCLUDED

#include "String.h"
#include "Fecha.h"

typedef struct {
	String nombre;
	Fecha fNac;
	String nombreProgenitor;
} MiembroABB;

//Crea nuevo miembro
MiembroABB CrearMiembroNuevo(String nom, String padre, Fecha nacimiento);

//Despliega por pantalla el miembro del ABB
void MostrarMiembroABB(MiembroABB m);

void MostrarMiembroABBHistorial(MiembroABB m);

void ObtenerNombreMiembroABB(MiembroABB m, String &nom);

Fecha ObtenerFechaNacimientoMiembroABB(MiembroABB m);

void ObtenerNombreProgenitorMiembroABB(MiembroABB m, String &nom);

//Precondicion: Archivo debe venir abierto para escritura.
void GuardarMiembroABB(FILE* f, MiembroABB m);

//Precondicion: Archivo debe venir abierto para lectura.
void LevantarMiembroABB(FILE* f, MiembroABB &m);

void LiberarMiembroABB(MiembroABB &m);

void SetearNombreProgenitorNull(MiembroABB &m);

boolean TieneProgenitor(MiembroABB m);

#endif // MIEMBROABB_H_INCLUDED
