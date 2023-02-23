#include <stdio.h>
#include <cstdlib>

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

Fecha TransformarFecha(String fecha) {
    Fecha f;
    int pos = 0, idx = 0, j = 0;
    String aux = new String[5];
    while (fecha[idx] != '\0' && pos < 3) {
        if (fecha[idx] == '/') {
            int n = atoi(aux);
            if (pos == 0) {
                f.dia = n;
            } else if (pos == 1) {
                f.mes = n;
            } else {
                f.anio = n;
            }
            LiberarString(aux);
            pos++;

            j = 0;
        } else {
            aux[j] = fecha[idx];
            j++;
        }

        idx++;
    }
}

// Validar el formato de la fecha ingresada.
boolean ValidarFecha(Fecha f){
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

// Devolver la fecha por defecto (0/0/0).
Fecha FechaDefecto() {
    Fecha r;
    r.anio = 0;
    r.mes = 0;
    r.dia = 0;

    return r;
}
