#include "ListaString.h"
#include "Boolean.h"
#include "Fecha.h"
#include "MiembroLista.h"

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

    String nombre, padre;
    printf("Ingrese nombre: ");
    scan(nombre);
    printf("Ingrese nombre del padre: ");
    scan(padre);
    Fecha f = CargarFecha(17, 12, 2001);
    MiembroABB m = CrearMiembroNuevo(nombre, padre, f);
    MiembroLista mL = CrearMiembroLista(m, FALSE, TRUE);
    MostrarMiembroLista(mL);

    return 0;
}
