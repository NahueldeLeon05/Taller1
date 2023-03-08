#include "comando.h"

int main()
{
    ListaDinastia dinastia;
    InicializarLista(dinastia);

    ArbolFamilia arbol;
    InicializarArbolFamilia(arbol);

    ListaString comandosDisponibles = ObtenerComandosDisponibles();
    int ultimoComando = -1;
    while (ultimoComando != 12) {
        ultimoComando = ProcesarComandos(arbol, dinastia, comandosDisponibles);
    }

    return 0;
}
