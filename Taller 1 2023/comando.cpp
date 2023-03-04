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
            break;

        case 2:
            Fallecimiento(dinastia, comando);
            break;

        case 3:
            Abdicacion(dinastia, comando);
            break;

        case 4:
            Miembros(arbol, comando);
            break;

        case 5:
            Monarcas(dinastia, comando);
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

void Nacimiento(ArbolFamilia &arbol, ListaDinastia &dinastia, Comando comando){
    if (dinastia == NULL || arbol == NULL) {
        printf("[E]: La familia no fue iniciada.\r\n");
        return;
    }

    if (comando.cantidadParametros != 4) {
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

    String progenitor;
    AgarrarParam(comando.parametros, 1, progenitor);
    if (NombreAlfabetico(progenitor) == FALSE) {
        printf("[E]: El nombre del progenitor no es alfabetico.\r\n");
        return;
    }
    PasarMayus(progenitor);

    String flecha;
    AgarrarParam(comando.parametros, 2, flecha);
    if (EsFlecha(flecha) == FALSE) {
        printf("[E]: Entre los dos nombre debe de escribir '->'.\r\n");
        return;
    }

    String nombre;
    AgarrarParam(comando.parametros, 3, nombre);
    if (NombreAlfabetico(nombre) == FALSE) {
        printf("[E]: El nombre no es alfabetico.\r\n");
        return;
    }
    PasarMayus(nombre);

    if (ExisteEnArbol(arbol, nombre) == TRUE) {
        printf("[E]: Ya existe un miembro con este nombre.\r\n");
        return;
    }

    if (ExisteEnArbol(arbol, progenitor) == FALSE) {
        printf("[E]: No existe el nombre del progenitor.\r\n");
        return;
    }

    if (FechaMayorATodas(dinastia, fecha) == FALSE) {
        printf("[E]: La fecha ingresada debe ser mayor a todas las anteriores.\r\n");
        return;
    }

    MiembroABB mAbb = CrearMiembroNuevo(nombre, progenitor, fecha);
    AgregarMiembroAlArbolFamilia(arbol, mAbb);

    MiembroLista mList = CrearMiembroLista(mAbb, FALSE, FALSE);
    if (TodosAbdicaronOFallecieron(dinastia) == FALSE) {
        CargarFechaAscension(mList, fecha);
    }

    AgregarMiembroALista(dinastia, mList);

    LiberarString(fechaStr);
    LiberarString(progenitor);
    LiberarString(nombre);

    printf("[I]: Nacimiento registrado correctamente.\r\n");
}

void Fallecimiento(ListaDinastia dinastia, Comando comando) {
    if (dinastia == NULL) {
        printf("[E]: La familia no fue iniciada.\r\n");
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

    ListaDinastia ls = ObtenerNodoListaDinastia(dinastia, nombre);
    if (ls == NULL) {
        printf("[E]: El nombre no existe en la lista.\r\n");
        return;
    }

    if (ObtenerFallecio(ls->info) == FALSE) {
        boolean esRey = EsRey(ls->info);
        CargarFechaFallecimiento(ls->info, fecha);

        if (esRey) {
            ListaDinastia sigRey = SiguienteMonarca(ls);
            if (sigRey != NULL) {
                CargarFechaAscension(sigRey->info, fecha);
            }
        }
    } else {
        printf("[E]: El miembro ingresado no esta entre nosotros :(\r\n");
        return;
    }

    printf("[I]: Fallecimiento registrado correctamente.\r\n");
}

void Abdicacion(ListaDinastia dinastia, Comando comando) {
    if (dinastia == NULL) {
        printf("[E]: La familia no fue iniciada.\r\n");
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

    ListaDinastia ls = ObtenerNodoListaDinastia(dinastia, nombre);
    if (ls == NULL) {
        printf("[E]: El nombre no existe en la lista.\r\n");
        return;
    }

    if (EsRey(ls->info) == FALSE) {
        printf("[E]: El miembro ingresado no es el actual monarca.\r\n");
        return;
    }

    if (ObtenerFallecio(ls->info) == TRUE) {
        printf("[E]: El miembro ingresado no esta entre nosotros :(\r\n");
        return;
    }

    CargarFechaAbdicacion(ls->info, fecha);

    ListaDinastia sigRey = SiguienteMonarca(ls);
    if (sigRey != NULL) {
        CargarFechaAscension(sigRey->info, fecha);
    }

    printf("[I]: Abdicacion registrada correctamente.\r\n");
}

void Miembros(ArbolFamilia arbol , Comando comando) {
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    MostrarABB(arbol);
}

void Monarcas(ListaDinastia ld , Comando comando) {
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }
    MostrarMonarcasLista(ld);
}
