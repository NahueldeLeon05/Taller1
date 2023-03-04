#ifndef COMANDO_H_INCLUDED
#define COMANDO_H_INCLUDED

#include "ListaString.h"

#include "ListaDinastia.h"
#include "ABBFamilia.h"

ListaString ObtenerComandosDisponibles();

void ObtenerComando(String &input);

int IndiceComando(ListaString comandos, String input);

void ProcesarComandos(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString comandosDisponibles);

void Iniciar(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString params);

#endif // COMANDO_H_INCLUDED
