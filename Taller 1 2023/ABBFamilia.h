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
void inicializarArbolFamilia(ArbolFamilia &arbol);

//Verifica que el ABB tenga elementos
boolean arbolTieneElementos(ArbolFamilia af);

//Crea miembro nuevo
miembroArbol crearMiembroNuevo(String nom, String padre, Fecha nacimiento);

//Agrega elemento Miembro al ABB
void agregarMiembroAlArbolFamilia(ArbolFamilia &arbol, miembroArbol m);

//Verifica si ese nombre existe en el ABB
boolean existeEnArbol(ArbolFamilia arbol, String nombre);

//Verifica que una fecha sea mayor a todas las existentes en el ABB
boolean fechaEsMayorATodas (ArbolFamilia arbol, fecha f);

//Devuelve el ABB de familia
void MostrarABB(ArbolFamilia a);

//Guarda ABB en archivo
void GuardarABB(ArbolFamilia abb, String nomArch);

//Levanta ABB desde archivo
void LeerFamiliaABB(String nomArch, ArbolFamilia &abb);

//Libera el espacio de memoria ocupado por el ABB
void liberarABBFamilia(ArbolFamilia &abb);

#endif // ABBFAMILIA_H_INCLUDED
