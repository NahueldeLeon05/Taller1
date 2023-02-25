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

void AgregarAListaString(ListaString &root, String s);

//Agarra un parametro de la lista de string
void AgarrarParam(ListaString ls, int pos, String& str);

//Valida que sea un parámetro valido
boolean ValidarComando(String s);

//Cuenta elemetos de la lista de strings
int contarElementosDeLista(ListaString ls);

//Libera el espacio de memoria ocupado por la lista
void LiberarListaString(ListaString &ls);

//Guarda lista en archivo
//PRECONDICION: Archivo abierto en modo escritura
void GuardarListaString(ListaString L, FILE * f);

//Levanta lista desde archivo
//PRECONDICION: Archivo abierto en modo lectura
void LeerListaString(ListaString &root, FILE * f);

int IndiceEnLista(ListaString root, String s);

#endif // LISTASTRING_H_INCLUDED
