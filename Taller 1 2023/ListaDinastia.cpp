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

MiembroLista* ObtenerMiembro(ListaDinastia ls, String nom) {
    boolean found = FALSE;
    while (ls != NULL && found == FALSE) {
        MiembroLista inf = ls->info;

        String aux;
        ObtenerNombreMiembroABB(ObtenerMiembroABB(inf), aux);

        if (streq(nom, aux, TRUE)== TRUE) {
            found = TRUE;
        }

        ls = ls->sig;
    }

    return found == TRUE ? &ls->info : NULL;
}

void GuardarListaDinastia(FILE* f, ListaDinastia ls) {
    while (ls != NULL) {
        GuardarMiembroLista(f, ls->info);
        ls = ls->sig;
    }
}

void CargarListaDinastia(FILE* f, ListaDinastia &ls) {
   /* ListaDinastia aux = ls;
    while (aux != NULL) {
        CargarMiembroLista(f, aux->info);
        aux = aux->sig;
    }*/
}

void LiberarListaDinastia(ListaDinastia &ls) {
  /*  if (ls != NULL) {
        LiberarListaDinastia(ls->sig);
        LiberarMiembroLista(ls->info);
        delete ls;
    }*/
}
