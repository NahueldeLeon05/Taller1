#include "MiembroLista.h"
#include "ListaDinastia.h"
#include <stdio.h>

MiembroLista crearMiembroLista(miembroABB m, boolean monarcaActual, boolean aspirante){
    /*MiembroABB m;
    strcrear(m.nombre);
    strcop(nom, m.nombre);
    strcrear(m.nombreProgenitor);
    strcop(padre, m.nombreProgenitor);
    */
}

//Despliega el miembro de la lista
void MostrarMiembroLista(MiembroLista ml){

}

boolean EsRey(MiembroLista m){
    return m.monarcaActual;
}

//Devuelve si el miembro de la lista esta muerto o no
boolean Muerto(MiembroLista m){
    return m.fallecio;
}

//Devuelve si el miembro de la lista abdicó o no
boolean Abdico(MiembroLista m){
    return m.abdico;
}

//Devuelve si el miembro de la lista es aspirante o no
boolean esAspirante(MiembroLista m){
    return m.aspirante;
}

//Devuelve si el miembro de la lista no es o fue monarca
boolean noEsOFueMonarca(MiembroLista m){
    return m.fueMonarca;
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

//Devuelve si la fecha ascensión es 0/0/0
boolean fechaVacia(MiembroLista m){
    return m.ascension.dia == 0 && m.ascension.mes == 0 && m.ascension.anio == 0 ? TRUE : FALSE;
}

//Muestra fecha de inicio y fin del reinado del miembro
void mostrarInicioFin(MiembroLista mL){
    if (mL.fallecio){
        print("/r/n%i",mL.m.nombre" desde el , %i" mL.ascension " hasta el , %i" mL.abdico "(fallecio)");
    else{
        print("/r/n%i",mL.m.nombre" desde el , %i" mL.ascension " hasta la actualidad");
    }
    //  EJEMPLO 1 - JORGE desde el 14/12/1895 hasta el 06/02/1952 (falleció)
    // EJEMPLO 2 - ISABEL desde el 06/02/1952 hasta la actualidad
}
