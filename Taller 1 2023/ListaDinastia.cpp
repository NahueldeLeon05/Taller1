#include "ListaDinastia.h"

void InicializarLista(ListaDinastia &lista) {
    lista = NULL;
}

void AgregarMiembroALista(ListaDinastia &ls, MiembroLista ml) {
    /*ListaDinastia n = new nodoMiembro;
    n.info = ml;
    n.sig = NULL;

    if (ls == NULL) {
        ls = n;
    } else {
        boolean found = FALSE;
        ListaDinastia padre = ls;
        while (padre->sig != NULL && found == FALSE) {
            MiembroLista infoPadre = padre->info;
            if (streq(infoPadre.m.nombre, ml.m.nombreProgenitor)) {
                found = TRUE;
            }
        }
    }*/
}

boolean ListaTieneElementos(ListaDinastia lf) {
    return lf == NULL ? TRUE : FALSE;
}

boolean BuscarNombreEnLista(ListaDinastia ls, String nom) {
    boolean found = FALSE;
    while (ls != NULL && found == FALSE) {
        MiembroLista inf = ls->info;
        if (streq((ls->info).nombre, ml.m.nombreProgenitor)) {
            found = TRUE;
        }

        ls = ls->sig;
    }

    return found;
}

MiembroLista ObtenerMiembro(ListaDinastia l, String nom) {
    boolean found = FALSE;
    while (ls != NULL && found == FALSE) {
        MiembroLista inf = ls->info;
        if (streq((ls->info).nombre, ml.m.nombreProgenitor)) {
            found = TRUE;
        }

        ls = ls->sig;
    }

    return ls->info;
}

void CargarFallecimiento(ListaDinastia &l, String nom, Fecha f) {
    MiembroLista miembro = l.info;
    miembro.fallecimiento = f;
    miembro.fallecio = TRUE;
}
