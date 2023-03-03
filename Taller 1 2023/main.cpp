#include "ListaString.h"
#include "Boolean.h"
#include "Fecha.h"
#include "MiembroLista.h"
#include "ABBFamilia.h"

int main()
{
      //FILE * f;
    /*String input;
    scan(input);
    ListaString lista = CmdEnLista(input);

    f = fopen ("comandos.txt","wb"); // Abre el archivo para escritura
    GuardarListaString(lista,f);
    fclose(f);*/

   /* ListaString comandos;
    f = fopen ("comandos.txt","rb"); // Abre el archivo para lectura
    LeerListaString(comandos,f);
    fclose(f);
    /*while (lista1 != NULL) {
        print(lista1->info);
        printf("\r\n");
        lista1 = lista1->sig;
    }*/

   /* ListaString params;
    int id = -1;
    while (id == -1) {
        String input;
        printf("Ingrese comando: ");
        scan(input);

        params = CmdEnLista(input);

        String cmd;
        strcrear(cmd);
        AgarrarParam(params, 0, cmd);

        id = IndiceEnLista(comandos, cmd);
        if (id == -1) {
            printf("El comando no existe.\r\n");
            LiberarString(cmd);
            LiberarListaString(params);
        }
    }

    for (int i = 0; i < ContarElementosDeLista(params); i++) {
        String p;
        AgarrarParam(params, i, p);
        printf("%d> ", i);
        print(p);
        printf("\r\n");
        LiberarString(p);
    }

    switch(id) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
    }

    /*String s;
    while(true) {
        printf("Ingresa una fecha: \r\n");
        scan(s);
        printf(ValidarFormato(s) ? "Formato es valido" : "Formato no es valido");
        printf("\r\n");

        Fecha f = TransformarFecha(s);
        MostrarFecha(f);
        printf("\r\n");

        printf(ValidarFecha(f) ? "Fecha es valida" : "Fecha no es valida");
        printf("\r\n");

        printf("=============================\r\n");

        LiberarString(s);
    }*/
   /* String input;
    scan(input);
    FILE * f;
    f = fopen ("comandos.txt","wb"); // Abre el archivo para lectura
    GuardarString(input,f);
    fclose(f);
    LiberarString(input);
    strcrear(input);
    f = fopen ("comandos.txt","rb"); // Abre el archivo para lectura
    LeerString(input,f);
    fclose(f);
    print(input);

    ListaString lista = CmdEnLista(input);
    while (lista != NULL) {
        print(lista->info);
        if (EsFlecha(lista->info)) {
            printf(" - Es flecha");
        }
        printf("\r\n");
        lista = lista->sig;
    }

    String cmd;
    AgarrarParam(lista, 0, cmd);
    ProcesarComando(cmd);*/
    //inicia prueba mostrar, crear, guardar y leer de miembroLista
    /*FILE* f;
    String nombre, padre;
    printf("Ingrese nombre: ");
    scan(nombre);
    printf("Ingrese nombre del padre: ");
    scan(padre);
    Fecha j = CargarFecha(17, 12, 2001);
    MiembroABB m = CrearMiembroNuevo(nombre, padre, j);
    MiembroLista mL = CrearMiembroLista(m, FALSE, TRUE);
    f = fopen ("prueba.txt","wb");
    GuardarMiembroLista(f, mL);
    fclose(f);
    f = fopen ("prueba.txt","rb");
    CargarMiembroLista(f, mL);
    fclose(f);
    MostrarMiembroLista(mL);*/
    //finaliza prueba mostrar, crear, guardar y leer de miembroLista

    //FILE* f;
    String nombre, padre, nom, pad;
    printf("Ingrese nombre: ");
    scan(nombre);
    printf("Ingrese nombre del padre: ");
    scan(padre);
    printf("Ingrese nombre: ");
    //scan(nom);
    //printf("Ingrese nombre del padre: ");
    scan(pad);
    Fecha j = CargarFecha(17, 12, 2001), k=CargarFecha(4, 12, 2002);
    MiembroABB m = CrearMiembroNuevo(nombre, padre, j);
    //MiembroABB l = CrearMiembroNuevo(nom, pad, k);
    ArbolFamilia abb;
    InicializarArbolFamilia(abb);
    /*MiembroLista mL = CrearMiembroLista(m, FALSE, TRUE);
    MostrarInicioFin(mL);*/
    //MostrarBoolean(strmen(nombre, padre));*/
    AgregarMiembroAlArbolFamilia(abb, m);
    //AgregarMiembroAlArbolFamilia(abb, l);
    //MostrarABB(abb);
    //GuardarABB("prueba.txt", abb);
    //LeerFamiliaABB("prueba.txt", abb);
    //MostrarABB(abb);
    boolean b = ExisteEnArbol(abb, nom);
    MostrarBoolean(b);
    return 0;
}
