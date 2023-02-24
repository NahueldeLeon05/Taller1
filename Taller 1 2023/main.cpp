#include "ListaString.h"
#include "Boolean.h"
#include "Fecha.h"

/*void ProcesarComando(String cmd) {
    if (streq(cmd, "inicio", FALSE) == TRUE) {
        printf("Bien");
    } else {
        printf("Comando incorrecto");
    }
}*/

int main()
{
    String input;
    scan(input);
    ListaString lista = CmdEnLista(input);

    FILE * f;
    f = fopen ("comandos.txt","wb"); // Abre el archivo para escritura
    GuardarListaString(lista,f);
    fclose(f);

    ListaString lista1;
    f = fopen ("comandos.txt","rb"); // Abre el archivo para lectura
    LeerListaString(lista1,f);
    fclose(f);
     while (lista1 != NULL) {
        print(lista1->info);
        printf("\r\n");
        lista1 = lista1->sig;
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
    return 0;
}
