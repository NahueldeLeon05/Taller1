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
MiembroABB crearMiembroNuevo(String nom, String padre, Fecha nacimiento);

//Despliega por pantalla el miembro del ABB
void MostrarMiembroABB(MiembroABB m);

#endif // MIEMBROABB_H_INCLUDED
