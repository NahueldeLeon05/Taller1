#include "MiembroLista.h"
#include "ListaDinastia.h"
#include <stdio.h>

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
boolean EsRey(MiembroLista m){
    return m.monarcaActual;
}
//Devuelve si el miembro de la lista esta muerto o no
boolean Muerto(MiembroLista m){
    return m.fallecio;
}
//Devuelve si el miembro de la lista abdic� o no
boolean Abdico(MiembroLista m){
    return m.abdico;
}
//Devuelve si el miembro de la lista es aspirante o no
boolean esAspirante(MiembroLista m){
    return m.aspirante;
}
boolean noFueMonarca(MiembroLista m){
    return m.fueMonarca;
}
//Devuelve si el miembro de la lista es o no primogenito
boolean Primogenito(MiembroLista m, ListaDinastia ls){ //REVISAR
    bool es = false;
    while (ls ->sig != NULL){
        if (streq(ls->info.m.nombre, m.nombre)){
            es = true;
        }else{
            Primogenito(m, ls->sig)
        }
    }
    return es;
}
//Devuelve si la fecha ascensi�n es 0/0/0
boolean fechaVacia(MiembroLista m){
    return m.ascension.dia == 0 && m.ascension.mes == 0 && m.ascension.anio == 0 ? TRUE : FALSE;
}
//Muestra fecha de inicio y fin del reinado del miembro
void mostrarInicioFin(MiembroLista mL){
    if (mL.fallecio){
        print("/r/n%i",mL.m.nombre" desde el , %i" mL.ascension " hasta el , %i" mL.abdico "(fallecio)");
    }else{
        print("/r/n%i",mL.m.nombre" desde el , %i" mL.ascension " hasta la actualidad");
    }
    //  EJEMPLO 1 - JORGE desde el 14/12/1895 hasta el 06/02/1952 (falleci�)
    // EJEMPLO 2 - ISABEL desde el 06/02/1952 hasta la actualidad
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
