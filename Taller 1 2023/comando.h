#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include "ListaString.h"

#include "ListaDinastia.h"
#include "ABBFamilia.h"

typedef struct {
    int comandoID;
    ListaString parametros;
    int cantidadParametros;
} Comando;

ListaString ObtenerComandosDisponibles();

Comando CrearComando();

void CargarComando(ListaString comandosDisponibles, Comando &cmd);

int IndiceComando(ListaString comandos, String input);

void ProcesarComandos(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString comandosDisponibles);

void LiberarComando(Comando &cmd);

void Iniciar(ArbolFamilia &arbol, ListaDinastia &dinastia, Comando comando);


void Miembros(ArbolFamilia arbol , Comando comando);

#endif // COMANDO_H_INCLUDED
