#include <stdio.h>
#include "MiembroLista.h"

//Crea miembro de Lista
MiembroLista crearMiembroLista(MiembroABB m, boolean monarcaActual, boolean aspirante){
    MiembroLista mL;
    String nom, nomProg;
    Fecha f = ObtenerFechaNacimientoMiembroABB(m);
    ObtenerNombreMiembroABB(m, nom);
    ObtenerNombreProgenitorMiembroABB(m, nomProg);
    mL.m = CrearMiembroNuevo(nom, nomProg, f);
    mL.monarcaActual = monarcaActual;
    mL.aspirante = aspirante;
    mL.fueMonarca = FALSE;
    mL.abdico = FALSE;
    mL.fallecio = FALSE;
    mL.ascencion = FechaDefecto();
    mL.abdicacion = FechaDefecto();
    mL.fallecimiento = FechaDefecto();

    return mL;
}

//Devuelve si el miembro de la lista esta vivo o no
boolean Vivo(MiembroLista m){
}

//Devuelve si el miembro de la lista es rey o no
boolean EsRey(MiembroLista m){
}

//Devuelve si el miembro de la lista esta muerto o no
boolean Muerto(MiembroLista m){
}

//Devuelve si el miembro de la lista abdicó o no
boolean Abdico(MiembroLista m){
}

//Devuelve si el miembro de la lista es aspirante o no
boolean esAspirante(MiembroLista m){
}

//Devuelve si el miembro de la lista no es o fue monarca
boolean noEsOFueMonarca(MiembroLista m){
}

//Devuelve si el miembro de la lista es o no primogenito
boolean Primogenito(MiembroLista m){
}

//Devuelve si la fecha ascensión es 0/0/0
boolean fechaVacia(MiembroLista m, Fecha f){
}

//Despliega el miembro de la lista
void MostrarMiembroLista(MiembroLista ml){
    MostrarMiembroABB(ml.m);
    printf("\nMonarca actual: ");
    MostrarBoolean(mL.monarcaActual);
    printf("\nFue monarca: ");
    MostrarBoolean(mL.fueMonarca);
    printf("\nEs aspirante: ");
    MostrarBoolean(mL.aspirante);
    printf("\nAbdico: ");
    MostrarBoolean(mL.abdico);
    printf("\nFallecio: ");
    MostrarBoolean(mL.fallecio);
    printf("Fecha de ascencion: ");
    MostrarFecha(mL.ascencion);
    printf("Fecha de abdicacion: ");
    MostrarFecha(mL.abdicacion);
    printf("Fecha de Fallecimiento: ");
    MostrarFecha(mL.fallecimiento);
}

//Muestra fecha de inicio y fin del reinado del miembro
void mostrarInicioFin(MiembroLista mL){
}
