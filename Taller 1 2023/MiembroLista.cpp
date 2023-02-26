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

//Selectora: obtiene el nombre del miembro
void ObtenerNombreMiembroLista(MiembroLista mL, String &nom){
    ObtenerNombreMiembroABB(mL.m, nom);
}

//Selectora obtiene la fecha de nacimiento.
void ObtenerFechaNacMiembroLista(MiembroLista mL, String &fechaNac){
    ObtenerFechaNacimientoMiembroABB(mL.m, fechaNac);
}

//Selectora obtiene el nombre del progenitor
void ObtenerProgenitorMiembroLista(MiembroLista mL, String &progenitor){
    ObtenerNombreProgenitorMiembroABB(mL.m, progenitor);
}

//Selectora obtiene si es monarca actual
boolean ObtenerMonarcaActual(MiembroLista mL){
    return mL.monarcaActual;
}

//Selectora obtiene si fue monarca
boolean ObtenerFueMonarca(MiembroLista mL){
    return mL.fueMonarca;
}

//Selectora obtiene si es aspirante
boolean ObtenerAspirante(MiembroLista mL){
    return mL.aspirante;
}

//Selectora obtiene si abdico
boolean ObtenerAbdico(MiembroLista mL){
    return mL.abdico;
}

//Selectora obtiene si fallecio
Boolean ObtenerFallecio(MiembroLista mL){
    return mL.fallecio;
}

//Selectora obtener fecha de ascencion
Fecha ObtenerFechaAscencion(MiembroLista mL){
    return mL.ascension;
}

//Selectora obtener fecha de abdicacion
Fecha ObtenerFechaAbdicacion(MiembroLista mL){
    return mL.abdicacion;
}

//Selectora obtener fecha de Fallecimiento
Fecha ObtenerFechaFallecimiento(MiembroLista mL){
    return mL.fallecimiento;
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
