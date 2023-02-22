#include <stdio.h>

#include "Fecha.h"
#include "boolean.h"

// Cargar la informacion de la fecha por teclado.
void CargarFecha(Fecha &f, Fecha minima){
    boolean valida = FALSE;

    while (valida == FALSE) {
        printf("Día:\r\n");
        printf(">> ");
        scanf("%d", &f.dia);

        printf("Mes:\r\n");
        printf(">> ");
        scanf("%d", &f.mes);

        printf("Año:\r\n");
        printf(">> ");
        scanf("%d", &f.anio);

        if (FechaEsValida(f) == TRUE) {
            if (FechaMayorIgual(f, minima) == TRUE) {
                valida = TRUE;
            } else {
                printf("\r\n");
                printf("[E]: La fecha debe ser mayor a ");
                MostrarFecha(minima);
                printf("\r\n");
                printf("\r\n");
            }
        } else {
            printf("\r\n");
            printf("[E]: La fecha ingresada no es válida\r\n");
            printf("\r\n");
        }
    }
}

// Cargar la informacion de la fecha con los datos ingresados.
void CargarFecha(Fecha &f, int anio, int mes, int dia) {
    f.anio = anio;
    f.mes = mes;
    f.dia = dia;
}

// Devolver la fecha minima aceptada por el programa.
Fecha CargarFechaMinima() {
    Fecha min;
    CargarFecha(min, 1970, 1, 1);
    return min;
}

// Mostrar en pantalla la fecha ingresada.
void MostrarFecha(Fecha f){
    printf("%d/%d/%d", f.dia, f.mes, f.anio);
}

// Obtener el dia de la fecha ingresada.
int ObtenerDiaFecha(Fecha f){
    return f.dia;
}

// Obtener el mes de la fecha ingresada.
int ObtenerMesFecha(Fecha f) {
    return f.mes;
}

// Obtener el año de la fecha ingresada.
int ObtenerAnioFecha(Fecha f){
    return f.anio;
}

// Validar el formato de la fecha ingresada.
boolean FechaEsValida(Fecha f){
    int max;
    if (f.mes == 1 || f.mes == 3 || f.mes == 5 || f.mes == 7 || f.mes == 8 || f.mes == 10 || f.mes == 12)
        max = 31;
    else if (f.mes == 4 || f.mes == 6 || f.mes == 9 || f.mes == 11)
        max = 30;
    else if (f.anio % 4 == 0)
        max = 29;
    else
        max = 28;

    if (f.dia <= 0 || f.dia > max) {
        return FALSE;
    }

    if (f.mes <= 0 || f.mes > 12) {
        return FALSE;
    }

    return TRUE;
}

// Comparar dos fechas devolviendo TRUE si la
// primera es mayor estricto que la segunda.
// De lo contrario devuelve FALSE.
boolean FechaMasReciente(Fecha f1, Fecha f2){
    int f1Num = ObtenerAnioFecha(f1) * 10000 + ObtenerMesFecha(f1) * 100 + ObtenerDiaFecha(f1);
    int f2Num = ObtenerAnioFecha(f2) * 10000 + ObtenerMesFecha(f2) * 100 + ObtenerDiaFecha(f2);
    return f1Num > f2Num ? TRUE : FALSE;
}

// Comparar dos fechas devolviendo TRUE si la
// primera es mayor o igual que la segunda.
// De lo contrario devuelve FALSE.
boolean FechaMayorIgual(Fecha f1, Fecha f2) {
    int f1Num = ObtenerAnioFecha(f1) * 10000 + ObtenerMesFecha(f1) * 100 + ObtenerDiaFecha(f1);
    int f2Num = ObtenerAnioFecha(f2) * 10000 + ObtenerMesFecha(f2) * 100 + ObtenerDiaFecha(f2);
    return f1Num >= f2Num ? TRUE : FALSE;
}

// Guardar la información de la fecha en un archivo.
// Precondicion: EL archivo debe venir abierto para escritura.
void GuardarFecha(Fecha F, FILE * f){
    fwrite (&F, sizeof(Fecha), 1, f);
}

// Cargar la información de la fecha desde un archivo.
// Precondicion: EL archivo debe venir abierto para lectura.
void LeerFecha(Fecha &F, FILE * f){
    fread(&F, sizeof(Fecha), 1, f);
}

