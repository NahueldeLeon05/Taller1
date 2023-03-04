#ifndef LISTADINASTIA_H_INCLUDED
#define LISTADINASTIA_H_INCLUDED

#include "ListaString.h"
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

ListaDinastia ObtenerNodoListaDinastia(ListaDinastia ls, String nombre);

ListaDinastia UltimoHijo(ListaDinastia padre);

boolean FechaMayorATodas(ListaDinastia root, Fecha f);

//Verifica que la lista tenga elementos
boolean ListaTieneElementos(ListaDinastia lf);

//Despliega por pantalla los elementos de la lista
void MostrarElementosLista(ListaDinastia ls);

//Despliega por pantalla a los monarcas pasados y al actual de la lista
void MostrarMonarcasLista(ListaDinastia a);

//Guarda lista en archivo. Precondicion: Archivo debe venir abierto para escritura.
void GuardarListaDinastia(FILE* file, ListaDinastia ls);

//Levanta la lista desde archivo. Precondicion: Archivo debe venir abierto para escritura.
void CargarListaDinastia(FILE* file, ListaDinastia &lf);

//Libera el espacio de memoria utilizado por la lista
void LiberarListaDinastia(ListaDinastia &lf);

boolean Primogenito(MiembroLista m, ListaDinastia ls);

boolean TodosAbdicaronOFallecieron(ListaDinastia ls);

ListaDinastia SiguienteMonarca(ListaDinastia lista);

#endif // LISTAFAMILIA_H_INCLUDED
