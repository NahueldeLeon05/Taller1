#ifndef LISTADINASTIA_H_INCLUDED
#define LISTADINASTIA_H_INCLUDED

#include "MiembroLista.h"

typedef struct nodoH {
	MiembroLista info;
	nodoH *sig;
} nodoMiembro;

typedef nodoMiembro* ListaDinastia;

//Inicializa lista de la dinastia
void InicializarLista(ListaDinastia &ls);

//Agrega miembro a la lista de dinastia
void AgregarMiembroALista(ListaDinastia &ls, MiembroLista ml);

//Verifica que la lista tenga elementos
boolean ListaTieneElementos(ListaDinastia lf);

//Busca si existe un nombre en la lista
boolean BuscarNombreEnLista(ListaDinastia l, String nom);

//Obtiene miembro de la lista mediante el nombre
MiembroLista ObtenerMiembro(ListaDinastia l, String nom);

//Cargar fallecimiento de un miembro de la lista
void CargarFallecimiento(ListaDinastia &l, String nom, Fecha f);

//Pone en true el atributo "EsRey" de un miembro de la lista mediante el nombre
void CargarRey(ListaDinastia& l, String nom, boolean b);

//Carga la fecha de ascensión de un miembro de la lista mediante el nombre
void CargarFecha(ListaDinastia &l, String nom, Fecha f);

//Despliega por pantalla los elementos de la lista
void mostrarElementosLista(ListaDinastia ls);

//Carga fecha de abdicacion de un miembro de la lista mediante el nombre
void CargarFecha(ListaDinastia &ls, String nom, Fecha f);

//Despliega por pantalla a los monarcas pasados y al actual de la lista
void MostrarMonarcasLista(ListaDinastia a);

//Guarda lista en archivo
void GuardarLista(ListaDinastia ls, String nomArch);

//Levanta la lista desde archivo
void LeerLista(String nomArch, ListaDinastia &lf);

//Libera el espacio de memoria utilizado por la lista
void liberarListaDinastia(ListaDinastia &lf);

#endif // LISTAFAMILIA_H_INCLUDED
