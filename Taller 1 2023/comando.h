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

int ProcesarComandos(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString comandosDisponibles);

void LiberarComando(Comando &cmd);

void Iniciar(ArbolFamilia &arbol, ListaDinastia &dinastia, Comando comando);

void Nacimiento(ArbolFamilia &arbol, ListaDinastia &dinastia, Comando comando);

void Fallecimiento(ListaDinastia dinastia, Comando comando);

void Abdicacion(ListaDinastia dinastia, Comando comando);

void Miembros(ArbolFamilia arbol, Comando comando);

void Monarcas (ListaDinastia dinastia, Comando comando);

void Aspirantes(ListaDinastia ld, Comando comando);

void Historial(ListaDinastia ld, Comando comando);

void Respaldar(ListaDinastia ld, ArbolFamilia abb, Comando comando);

void Recuperar(ListaDinastia &ld, ArbolFamilia &abb, Comando comando);

void Ayuda();

void Salir(ListaDinastia &ld, ArbolFamilia &abb, Comando comando);

void MostrarBanner();

void MostrarIntroduccion();

void MostrarComandos();

#endif // COMANDO_H_INCLUDED
