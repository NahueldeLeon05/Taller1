#include "comando.h"

ListaString ObtenerComandosDisponibles() {
    FILE * f = fopen("comandos.txt", "rb");
    ListaString r = LeerListaString(f);
    fclose(f);

    return r;
}

void ObtenerComando(String &input) {
    printf("Escriba el comando: ");
    scan(input);
}

int IndiceComando(ListaString comandos, String input) {
    ListaString params = CmdEnLista(input);

    String cmd;
    strcrear(cmd);
    AgarrarParam(params, 0, cmd);

    int idx = IndiceEnLista(comandos, cmd);
    LiberarString(cmd);
    LiberarListaString(params);

    return idx;
}

void ProcesarComandos(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString comandosDisponibles) {
    int comando = -1;

    String input;
    while (comando == -1) {
        ObtenerComando(input);
        comando = IndiceComando(comandosDisponibles, input);
        if (comando == -1) {
            printf("comando no existe\r\n");
        }
    }

    ListaString params = CmdEnLista(input);
    switch (comando) {
        case 0:
            Iniciar(arbol, dinastia, params);
            break;
    }

    LiberarString(input);
    LiberarListaString(params);
}

void Iniciar(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString params) {
    if (dinastia != NULL) {
        printf("[E]: La familia ya inicio.\r\n");
        return;
    }

    if (arbol != NULL) {
        printf("[E]: La familia ya inicio.\r\n");
        return;
    }

    if (ContarElementosDeLista(params) != 3) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    String fechaStr;
    AgarrarParam(params, 1, fechaStr);

    if (ValidarFormato(fechaStr) == FALSE) {
        printf("[E]: Formato de fecha incorrecto.\r\n");
        return;
    }

    Fecha fecha = TransformarFecha(fechaStr);
    if (ValidarFecha(fecha) == FALSE) {
        printf("[E]: Fecha incorrecta.\r\n");
        return;
    }

    String nombre;
    AgarrarParam(params, 2, nombre);
    if (NombreAlfabetico(nombre) == FALSE) {
        printf("[E]: El nombre no es alfabetico.\r\n");
        return;
    }

    PasarMayus(nombre);
    MiembroABB mAbb = CrearMiembroNuevo(nombre, NULL, fecha);
    MiembroLista mList = CrearMiembroLista(mAbb, TRUE, FALSE);

    AgregarMiembroALista(dinastia, mList);
    AgregarMiembroAlArbolFamilia(arbol, mAbb);

    LiberarString(fechaStr);
    LiberarString(nombre);

    printf("[I]: Dinastia iniciada correctamente.\r\n");
}
