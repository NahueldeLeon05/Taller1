#include "Fecha.h"

int main()
{
    String s;
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

        LiberarString(s);
    }
    return 0;
}
