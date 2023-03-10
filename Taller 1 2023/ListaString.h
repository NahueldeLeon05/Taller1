#ifndef LISTASTRING_H_INCLUDED
#define LISTASTRING_H_INCLUDED

#include "String.h"

typedef struct _snode {
    String info;
	_snode* sig;
} snode;

typedef snode* ListaString;

//Guarda lo ingresado por el usuario en lista de string
ListaString CmdEnLista(String s);

//Agrega a la lista un string
void AgregarAListaString(ListaString &root, String s);

//Agarra un parametro de la lista de string
void AgarrarParam(ListaString ls, int pos, String& str);

//Cuenta elemetos de la lista de strings
int ContarElementosDeLista(ListaString root);

//Libera el espacio de memoria ocupado por la lista
void LiberarListaString(ListaString &ls);

//Guarda lista en archivo
//PRECONDICION: Archivo abierto en modo escritura
void GuardarListaString(ListaString L, FILE * f);

//Levanta lista desde archivo
//PRECONDICION: Archivo abierto en modo lectura
ListaString LeerListaString(FILE * f);

//Devuelve en que indice de la lista esta el string
int IndiceEnLista(ListaString root, String s);

//Despliega la lista string
void ImprimirLista(ListaString r);

#endif // LISTASTRING_H_INCLUDED
