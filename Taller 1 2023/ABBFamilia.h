#ifndef ABBFAMILIA_H_INCLUDED
#define ABBFAMILIA_H_INCLUDED

#include "MiembroABB.h"

typedef struct nodoA {
	MiembroABB info;
	nodoA *hIzq;
	nodoA *hDer;
} nodoFamilia;

typedef nodoFamilia* ArbolFamilia;

//Inicializa ABB de familia
void InicializarArbolFamilia(ArbolFamilia &arbol);

//Verifica que el ABB tenga elementos
boolean ArbolTieneElementos(ArbolFamilia af);

//Crea miembro nuevo
MiembroABB CrearMiembroNuevo(String nom, String padre, Fecha nacimiento);

//Agrega elemento Miembro al ABB
void AgregarMiembroAlArbolFamilia(ArbolFamilia &arbol, MiembroABB m);

//Verifica si ese nombre existe en el ABB
boolean ExisteEnArbol(ArbolFamilia arbol, String nombre);

//Devuelve el ABB de familia
void MostrarABB(ArbolFamilia a);

//Precondicion: Archivo debe venir abierto para escritura.
//Guarda el arbol en un archivo
void GuardarABB(FILE* f, ArbolFamilia abb);

////Precondicion: Archivo debe venir abierto para lectura.
//Levanta ABB desde archivo
void LeerFamiliaABB(FILE* f, ArbolFamilia &abb);

//Libera el espacio de memoria ocupado por el ABB
void LiberarABBFamilia(ArbolFamilia &abb);

#endif // ABBFAMILIA_H_INCLUDED
