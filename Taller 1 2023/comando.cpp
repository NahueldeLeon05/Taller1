#include "comando.h"

ListaString ObtenerComandosDisponibles() {
    FILE * f = fopen("comandos.txt", "rb");
    ListaString r = LeerListaString(f);
    fclose(f);

    return r;
}

Comando CrearComando() {
    Comando cmd;
    cmd.comandoID = -1;
    cmd.parametros = NULL;
    cmd.cantidadParametros = 0;

    return cmd;
}

void CargarComando(ListaString comandosDisponibles, Comando &cmd) {
    String input;
    while (cmd.comandoID == -1) {
        printf("Ingrese el comando: ");
        scan(input);

        cmd.comandoID = IndiceComando(comandosDisponibles, input);
        if (cmd.comandoID == -1) {
            printf("comando no existe\r\n");
        }
    }

    ListaString parametros = CmdEnLista(input);
    cmd.parametros = parametros->sig;

    parametros->sig = NULL;
    LiberarListaString(parametros);

    cmd.cantidadParametros = ContarElementosDeLista(cmd.parametros);

    LiberarString(input);
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
    Comando comando = CrearComando();
    CargarComando(comandosDisponibles, comando);

    switch (comando.comandoID) {
        case 0:
            Iniciar(arbol, dinastia, comando);
            break;

        case 1:
            Nacimiento(arbol, dinastia, comando);

        case 4:
            Miembros(arbol, comando);
            break;
    }

    LiberarComando(comando);
}

void LiberarComando(Comando &cmd) {
    LiberarListaString(cmd.parametros);
}

void Iniciar(ArbolFamilia &arbol, ListaDinastia &dinastia, Comando comando) {
    if (dinastia != NULL || arbol != NULL) {
        printf("[E]: La familia ya inicio.\r\n");
        return;
    }

    if (comando.cantidadParametros != 2) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    String fechaStr;
    AgarrarParam(comando.parametros, 0, fechaStr);

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
    AgarrarParam(comando.parametros, 1, nombre);
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

void Miembros(ArbolFamilia arbol , Comando comando) {
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    MostrarABB(arbol);
}
