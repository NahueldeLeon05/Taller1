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

//Carga comandos a ListaString desde comandos.txt
void CargarComando(ListaString comandosDisponibles, Comando &cmd);

//Devuelve el inidice de la lista en el que se encuentra el comando ingresado
int IndiceComando(ListaString comandos, String input);

//Procesa el Id del comando para el manejo de los comandos
int ProcesarComandos(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString comandosDisponibles);

//Libera la ListaString de Comandos
void LiberarComando(Comando &cmd);

//Realiza las acciones correspondientes al comando Iniciar
void Iniciar(ArbolFamilia &arbol, ListaDinastia &dinastia, Comando comando);

//Realiza las acciones correspondientes al comando Nacimiento
void Nacimiento(ArbolFamilia &arbol, ListaDinastia &dinastia, Comando comando);

//Realiza las acciones correspondientes al comando Fallecimiento
void Fallecimiento(ListaDinastia dinastia, Comando comando);

//Realiza las acciones correspondientes al comando Abdicacion
void Abdicacion(ListaDinastia dinastia, Comando comando);

//Realiza las acciones correspondientes al comando Miembros
void Miembros(ArbolFamilia arbol, Comando comando);

//Realiza las acciones correspondientes al comando Monarcas
void Monarcas (ListaDinastia dinastia, Comando comando);

//Realiza las acciones correspondientes al comando Aspirantes
void Aspirantes(ListaDinastia ld, Comando comando);

//Realiza las acciones correspondientes al comando Historial
void Historial(ListaDinastia ld, Comando comando);

//Realiza las acciones correspondientes al comando Respaldar
void Respaldar(ListaDinastia ld, ArbolFamilia abb, Comando comando);

//Realiza las acciones correspondientes al comando Recuperar
void Recuperar(ListaDinastia &ld, ArbolFamilia &abb, Comando comando);

//Muestra ayuda al usuario
void Ayuda();

//Libera AbbFamilia, ListaString de comandos y ListaDinastia terminando el programa
void Salir(ListaDinastia &ld, ArbolFamilia &abb, Comando comando);

//Muestra banner Random de ayuda.
void MostrarBanner();

//Muestra la introduccion del software en Ayuda.
void MostrarIntroduccion();

//Muestra los comandos existentes.
void MostrarComandos();

#endif // COMANDO_H_INCLUDED
