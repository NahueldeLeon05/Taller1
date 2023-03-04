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
        ListaDinastia padre = ObtenerNodoListaDinastia(ls, nombrePadre);

        ListaDinastia ultimoHijo = UltimoHijo(padre);
        if (ultimoHijo == NULL) {
            n->sig = padre->sig;
            padre->sig = n;
        } else {
            n->sig = ultimoHijo->sig;
            ultimoHijo->sig = n;
        }

        LiberarString(nombrePadre);
    }
}

// Precondicion: El nodo existe.
ListaDinastia ObtenerNodoListaDinastia(ListaDinastia ls, String nombre) {
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
    ObtenerNombreMiembroABB(ObtenerMiembroABB(ls->info), nomPadre);

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
        MiembroLista mList = ls->info;
        MiembroABB mAbb = ObtenerMiembroABB(mList);
        if (FechaMayor(ObtenerFechaAbdicacion(mList), f) == TRUE ||
            FechaMayor(ObtenerFechaAscencion(mList), f) == TRUE ||
            FechaMayor(ObtenerFechaFallecimiento(mList), f) == TRUE ||
            FechaMayor(ObtenerFechaNacimientoMiembroABB(mAbb), f) == TRUE){
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

void GuardarListaDinastia(FILE* f, ListaDinastia ls) {
    while (ls != NULL) {
        GuardarMiembroLista(f, ls->info);
        ls = ls->sig;
    }
}

void MostrarElementosLista(ListaDinastia ls){
    while (ls != NULL){
        MostrarMiembroLista(ls->info);
        ls = ls -> sig;
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
void MostrarMonarcasLista(ListaDinastia ls){
    int cont = 1 ;
    while (ls != NULL){
        if (ObtenerFueMonarca(ls->info) == TRUE || ObtenerMonarcaActual(ls->info) == TRUE) {
            printf("%d-",cont);
            MostrarInicioFin(ls->info);
            cont++;
        }
        ls = ls -> sig;
    }
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

boolean TodosAbdicaronOFallecieron(ListaDinastia ls) {
    boolean found = FALSE;
    while (ls != NULL && found == FALSE) {
        MiembroLista miembro = ls->info;
        if (ObtenerAbdico(miembro) == FALSE || ObtenerFallecio(miembro) == FALSE) {
            found = TRUE;
        }
    }

    return found;
}

ListaDinastia SiguienteMonarca(ListaDinastia ls) {
    if (ls == NULL || ls->sig == NULL) {
        return NULL;
    }

    ls = ls->sig;
    boolean found = FALSE;
    while (ls != NULL && found == FALSE) {
        MiembroLista mList = ls->info;
        if (ObtenerFallecio(mList) == TRUE || ObtenerAbdico(mList) == TRUE) {
            ls = ls->sig;
        } else {
            found = TRUE;
        }
    }

    return found == TRUE ? ls : NULL;
}
