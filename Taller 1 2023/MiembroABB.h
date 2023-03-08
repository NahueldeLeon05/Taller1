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

//Despliega por pantalla la informacion del miembro abb utilizada en historial
void MostrarMiembroABBHistorial(MiembroABB m);

//Selectora: devuelve el nombre del miembtoABB
void ObtenerNombreMiembroABB(MiembroABB m, String &nom);

//Selectora: devuelve la fecha de nacimiento del miembro abb
Fecha ObtenerFechaNacimientoMiembroABB(MiembroABB m);

//Selectora: devuelve el nombre del progenitor del miembro abb
void ObtenerNombreProgenitorMiembroABB(MiembroABB m, String &nom);

//Precondicion: Archivo debe venir abierto para escritura.
//Guarda el miembro abb en un archivo
void GuardarMiembroABB(FILE* f, MiembroABB m);

//Precondicion: Archivo debe venir abierto para lectura.
//Lee el miembro abb desde un archivo
void LevantarMiembroABB(FILE* f, MiembroABB &m);

//Libera la memoria utilizada por el miembro abb
void LiberarMiembroABB(MiembroABB &m);

//Setea el nombre del progenitor en null
void SetearNombreProgenitorNull(MiembroABB &m);

//Devuelve si el miembro abb tiene progenitor.
boolean TieneProgenitor(MiembroABB m);

#endif // MIEMBROABB_H_INCLUDED
