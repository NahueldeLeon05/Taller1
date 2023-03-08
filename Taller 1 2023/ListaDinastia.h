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

// Precondicion: El nodo existe.
//Devuelve el nodo de la lista dinastia
ListaDinastia ObtenerNodoListaDinastia(ListaDinastia ls, String nombre);

//Dado un padre devuelve el ultimo hijo
ListaDinastia UltimoHijo(ListaDinastia padre);

//Devuelve si una fecha es mayor a todas las de la lista
boolean FechaMayorATodas(ListaDinastia root, Fecha f);

//Verifica que la lista tenga elementos
boolean ListaTieneElementos(ListaDinastia lf);

//Despliega por pantalla los elementos de la lista
void MostrarElementosLista(ListaDinastia ls);

//Muestra listada la informacion requerida en la linea de sucesion (comando historial)
void MostrarLineaDeSucesion(ListaDinastia ld);

//Muestra listada la informacion requerida en el comando aspirantes (comando aspirantes)
void MostrarMiembrosAspirantes(ListaDinastia ld);

//Despliega por pantalla a los monarcas pasados y al actual de la lista
void MostrarMonarcasLista(ListaDinastia a);

//Guarda lista en archivo. Precondicion: Archivo debe venir abierto para escritura.
void GuardarListaDinastia(FILE* file, ListaDinastia ls);

//Levanta la lista desde archivo. Precondicion: Archivo debe venir abierto para escritura.
void CargarListaDinastia(FILE* file, ListaDinastia &lf);

//Libera el espacio de memoria utilizado por la lista
void LiberarListaDinastia(ListaDinastia &lf);

//Devuelve si el miembro de la lista es o no primogenito
boolean Primogenito(MiembroLista m, ListaDinastia ls);

//Devuelve si todos los miembros abdicaron o fallecieron
boolean TodosAbdicaronOFallecieron(ListaDinastia ls);

//Devuelve el siguiente monarca.
ListaDinastia SiguienteMonarca(ListaDinastia lista);

#endif // LISTAFAMILIA_H_INCLUDED
