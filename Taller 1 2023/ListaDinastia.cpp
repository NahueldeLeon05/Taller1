#include "ListaDinastia.h"

void InicializarLista(ListaDinastia &lista) {
    lista = NULL;
}

void AgregarMiembroALista(ListaDinastia &ls, MiembroLista ml) {
    ListaDinastia n = new nodoMiembro;
    n->info = ml;
    n->sig = NULL;

    if (ls == NULL) {
        ls = n;
    } else {
        boolean found = FALSE;
        String nombrePadre;
        ObtenerNombreProgenitorMiembroABB(ObtenerMiembroABB(ml), nombrePadre);
        ListaDinastia padre = ObtenerNodoPadre(ls, nombrePadre);

        ListaDinastia ultimoHijo = UltimoHijo(padre);
        if (ultimoHijo == NULL) {
            n->sig = padre->sig;
            padre->sig = n;
        } else {
            n->sig = ultimoHijo->sig;
            ultimoHijo->sig = n;
        }
    }
}

// Precondicion: El nodo existe.
ListaDinastia ObtenerNodoPadre(ListaDinastia ls, String nombre) {
    boolean found = FALSE;
    while (ls != NULL && found == FALSE) {
        String aux;
        ObtenerNombreMiembroABB(ObtenerMiembroABB(ls->info), aux);
        if (streq(aux, nombre, TRUE) == TRUE) {
            found = TRUE;
        } else {
            ls = ls->sig;
        }
    }

    return ls;
}

ListaDinastia UltimoHijo(ListaDinastia ls) {
    boolean diferente = FALSE;

    String nomPadre;
    ObtenerNombreProgenitorMiembroABB(ObtenerMiembroABB(ls->info), nomPadre);

    String aux;
    ls = ls->sig;
    while (ls != NULL && diferente == FALSE) {
        ObtenerNombreProgenitorMiembroABB(ObtenerMiembroABB(ls->info), aux);

        if (streq(aux, nomPadre, TRUE) == TRUE) {
            ls = ls->sig;
        } else {
            diferente = TRUE;
        }

        LiberarString(aux);
    }

    LiberarString(nomPadre);

    if (ls != NULL) {
        ls = UltimoHijo(ls);
    }

    return ls;
}

boolean FechaMayorATodas(ListaDinastia ls, Fecha f) {
    boolean b = TRUE;
    while (ls != NULL && b == TRUE) {
        MiembroABB mabb = ObtenerMiembroABB(ls->info);
        if (FechaMayorIgual(ObtenerFechaAbdicacion(ls->info), f) == TRUE ||
            FechaMayorIgual(ObtenerFechaAscencion(ls->info), f) == TRUE ||
            FechaMayorIgual(ObtenerFechaFallecimiento(ls->info), f) == TRUE ||
            FechaMayorIgual(ObtenerFechaNacimientoMiembroABB(mabb), f) == TRUE){
            b = FALSE;
        } else {
            ls = ls->sig;
        }
    }

    return b;
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
    MiembroLista buffer;
    ls = NULL;
    CargarMiembroLista(f, buffer);

    while(!feof(f)){
        AgregarMiembroALista(ls, buffer);
        CargarMiembroLista(f, buffer);
    }


    /*ListaDinastia aux = ls;
    while (aux != NULL) {
        CargarMiembroLista(f, aux->info);
        aux = aux->sig;
    }*/
}

void LiberarListaDinastia(ListaDinastia &ls) {
    if (ls != NULL) {
        LiberarListaDinastia(ls->sig);
        LiberarMiembroLista(ls->info);
        delete ls;
    }
}

//Devuelve si el miembro de la lista es o no primogenito
boolean Primogenito(MiembroLista m, ListaDinastia ls) { //REVISAR este es de ListaDinastia
    boolean es = FALSE;
    String nombre, nombre2;
    ObtenerNombreMiembroABB(ObtenerMiembroABB(ls->info), nombre);
    ObtenerNombreMiembroABB(ObtenerMiembroABB(m), nombre2);
    if (streq(nombre, nombre2, TRUE)){
        es = TRUE;
    }else{
        Primogenito(m, ls->sig);
    }
    LiberarString(nombre);
    LiberarString(nombre2);
    return es;
}


ListaDinastia Primogenito2(ListaDinastia padre) {
    boolean found = FALSE;

    String nomPadre;
    ObtenerNombreProgenitorMiembroABB(ObtenerMiembroABB(padre->info), nomPadre);

    while (padre != NULL && found == FALSE) {
        String aux;
        ObtenerNombreProgenitorMiembroABB(ObtenerMiembroABB(padre->info), aux);
        if (streq(aux, nomPadre, TRUE) == TRUE) {
            found = TRUE;
        } else {
            padre = padre->sig;
        }
        LiberarString(aux);
    }

    LiberarString(nomPadre);
    return padre;
}
