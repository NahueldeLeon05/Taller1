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

//Verifica que una fecha sea mayor a todas las existentes en el ABB
boolean FechaEsMayorATodas (ArbolFamilia arbol, Fecha f);

//Devuelve el ABB de familia
void MostrarABB(ArbolFamilia a);

//Precondicion: El archivo debe venir abierto para escritura
//Guarda ABB en archivo
void GuardarABB(ArbolFamilia abb, FILE *f);

//Precondicion: El archivo debe venir abierto para lectura
//Levanta ABB desde archivo
void LeerFamiliaABB(FILE *f, ArbolFamilia &abb);

//Libera el espacio de memoria ocupado por el ABB
void LiberarABBFamilia(ArbolFamilia &abb);

#endif // ABBFAMILIA_H_INCLUDED
