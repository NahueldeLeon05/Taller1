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

void ObtenerNombreMiembroABB(MiembroABB m, String &nom);

Fecha ObtenerFechaNacimientoMiembroABB(MiembroABB m);

void ObtenerNombreProgenitorMiembroABB(MiembroABB m, String &nom);

void GuardarMiembroABB(FILE* f, MiembroABB m);

void LevantarMiembroABB(FILE* f, MiembroABB &m);

void LiberarMiembroABB(MiembroABB &m);

#endif // MIEMBROABB_H_INCLUDED
