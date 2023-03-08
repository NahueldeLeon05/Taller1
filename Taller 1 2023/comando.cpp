#include "comando.h"

ListaString ObtenerComandosDisponibles() {
    FILE * f = fopen("misc/comandos.fn", "rb");
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
            printf("[E]: Comando incorrecto.\r\n");
            printf("[E]: Utiliza ayuda para listar los comandos disponibles.\r\n");
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

int ProcesarComandos(ArbolFamilia &arbol, ListaDinastia &dinastia, ListaString comandosDisponibles) {
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

        case 6:
            Aspirantes(dinastia, comando);
            break;

        case 7:
            Historial(dinastia, comando);
            break;

        case 8:
            Respaldar(dinastia, arbol, comando);
            break;

        case 9:
            Recuperar(dinastia, arbol, comando);
            break;

        case 10:
            Ayuda();
            break;

        case 11:
            Salir(dinastia, arbol, comando);
            break;
    }

    LiberarComando(comando);
    return comando.comandoID;
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
    MiembroLista mList = CrearMiembroLista(mAbb, TRUE);

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

    if (ObtenerFallecio(ObtenerNodoListaDinastia(dinastia, progenitor)->info) == TRUE) {
        printf("[E]: ");
        print(progenitor);
        printf(" ya no esta entre nosotros :(\r\n");
        return;
    }

    MiembroABB mAbb = CrearMiembroNuevo(nombre, progenitor, fecha);
    AgregarMiembroAlArbolFamilia(arbol, mAbb);

    MiembroLista mList = CrearMiembroLista(mAbb, FALSE);
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

    if (ObtenerFallecio(ls->info) == TRUE) {
        printf("[E]: ");
        print(nombre);
        printf(" ya no esta entre nosotros :(\r\n");
        return;
    }

    boolean esRey = EsRey(ls->info);
    CargarFechaFallecimiento(ls->info, fecha);

    if (esRey) {
        ListaDinastia sigRey = SiguienteMonarca(dinastia);
        if (sigRey != NULL) {
            CargarFechaAscension(sigRey->info, fecha);
        }
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
        printf("[E]: ");
        print(nombre);
        printf(" ya no esta entre nosotros :(\r\n");
        return;
    }

    CargarFechaAbdicacion(ls->info, fecha);

    ListaDinastia sigRey = SiguienteMonarca(dinastia);
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

    if (arbol == NULL) {
        printf("[E]: La familia no fue iniciada.");
        return;
    }

    MostrarABB(arbol);
}

void Monarcas(ListaDinastia ld , Comando comando) {
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    if(ld == NULL){
        printf("[E]: La familia no fue iniciada.\r\n");
        return;
    }

    MostrarMonarcasLista(ld);
}

void Aspirantes(ListaDinastia ld, Comando comando){
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    if (ld == NULL) {
        printf("[E]: La familia no fue iniciada.");
        return;
    }

    MostrarMiembrosAspirantes(ld);
}

void Historial(ListaDinastia ld, Comando comando){
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    if (ld == NULL) {
        printf("[E]: La familia no fue iniciada.");
        return;
    }

    MostrarLineaDeSucesion(ld);
}

void Respaldar(ListaDinastia ld, ArbolFamilia abb, Comando comando){
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    if(ld == NULL || abb == NULL){
        printf("La familia no fue iniciada.\r\n");
        return;
    }

    FILE* f;
    f = fopen("datosArbol.txt", "wb");
    GuardarABB(f, abb);
    fclose(f);

    f = fopen("datosLista.txt", "wb");
    GuardarListaDinastia(f, ld);
    fclose(f);

    printf("[I]: Respaldo realizado correctamente.\r\n");
}

void Recuperar(ListaDinastia &ld, ArbolFamilia &abb, Comando comando){
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    if(ld != NULL || abb != NULL){
        printf("[E]: La familia ya fue iniciada.\r\n");
        return;
    }

    InicializarArbolFamilia(abb);
    FILE* f;
    f = fopen("datosArbol.txt", "rb");
    LeerFamiliaABB(f, abb);
    fclose(f);

    InicializarLista(ld);
    f = fopen("datosLista.txt", "rb");
    CargarListaDinastia(f, ld);
    fclose(f);

    printf("[I]: Recuperacion realizada correctamente.\r\n");

}

void Ayuda() {
    MostrarBanner();
    MostrarIntroduccion();
    MostrarComandos();

    printf("_.~\"~._.~\"~._.~\"~._.~\"~.__.~\"~._.~\"~._.~\"~._.~\"~._\r\n\r\n");
}

void Salir(ListaDinastia &ld, ArbolFamilia &abb, Comando comando){
    if (comando.cantidadParametros != 0) {
        printf("[E]: Cantidad de parametros incorrecta.\r\n");
        return;
    }

    LiberarABBFamilia(abb);
    LiberarListaDinastia(ld);
    LiberarComando(comando);
}

void MostrarBanner() {
    FILE* f = fopen("misc/banners/banners_list.fn", "rb");
    ListaString bannersFileNames = LeerListaString(f);
    fclose(f);

    int randomNum = rand() % (ContarElementosDeLista(bannersFileNames) - 1);
    String randomBannerFileName;
    AgarrarParam(bannersFileNames,
                 randomNum,
                 randomBannerFileName);
    LiberarListaString(bannersFileNames);

    f = fopen(randomBannerFileName, "rb");
    ListaString bannerLinesList = LeerListaString(f);
    fclose(f);
    LiberarString(randomBannerFileName);

    ListaString aux = bannerLinesList;
    while (aux != NULL) {
        print(aux->info);
        printf("\r\n");
        aux = aux->sig;
    }

    LiberarListaString(bannerLinesList);

    printf("FAMI-NET\r\n");
    printf("Desarrollado por Alejandro Barran, Nahuel de Leon y Nicolas Villar.\r\n\r\n");
    printf("_.~\"~._.~\"~._.~\"~._.~\"~.__.~\"~._.~\"~._.~\"~._.~\"~._\r\n\r\n");
}

void MostrarIntroduccion() {
    FILE* f = fopen("misc/introduccion.fn", "rb");
    ListaString intrLines = LeerListaString(f);
    fclose(f);

    ListaString aux = intrLines;
    while (aux != NULL) {
        print(aux->info);
        printf("\r\n");
        aux = aux->sig;
    }

    LiberarListaString(intrLines);
}

void MostrarComandos() {
    FILE* f = fopen("misc/ayuda.fn", "rb");
    ListaString intrLines = LeerListaString(f);
    fclose(f);

    ListaString aux = intrLines;
    while (aux != NULL) {
        print(aux->info);
        printf("\r\n");
        aux = aux->sig;
    }

    LiberarListaString(intrLines);
}
