#include "ABBFamilia.h"

//Inicializa ABB de familia
void InicializarArbolFamilia(ArbolFamilia &arbol){
    arbol = NULL;
}

//Verifica que el ABB tenga elementos
boolean ArbolTieneElementos(ArbolFamilia af){
    return af == NULL ? FALSE : TRUE;
}

//Agrega elemento Miembro al ABB
void AgregarMiembroAlArbolFamilia(ArbolFamilia &arbol, MiembroABB m){
    if (arbol == NULL) {
        arbol = new nodoFamilia;
        arbol->hIzq = NULL;
        arbol->hDer = NULL;
        arbol->info = m;
   } else {
        String nom1, nom2;
        ObtenerNombreMiembroABB(arbol->info, nom1);
        ObtenerNombreMiembroABB(m, nom2);
        
        if (strmen(nom2, nom1) == TRUE){
            AgregarMiembroAlArbolFamilia(arbol->hIzq, m);
        } else {
            AgregarMiembroAlArbolFamilia(arbol->hDer, m);
        }

        LiberarString(nom1);
        LiberarString(nom2);
    }
}

//Verifica si ese nombre existe en el ABB
boolean ExisteEnArbol(ArbolFamilia arbol, String nombre){
    if (arbol == NULL) {
        return FALSE;
    } else {
        String nom1;
        ObtenerNombreMiembroABB(arbol->info, nom1);

        if(streq(nom1, nombre, TRUE)){
            LiberarString(nom1);
            return TRUE;
        } else {
            if(strmen(nom1, nombre)) {
                LiberarString(nom1);
                return ExisteEnArbol(arbol->hIzq, nombre);
            } else {
                LiberarString(nom1);
                return ExisteEnArbol(arbol->hDer, nombre);
            }
        }
    }
}

//Verifica que una fecha sea mayor a todas las existentes en el ABB
boolean FechaEsMayorATodas (ArbolFamilia arbol, MiembroABB m){
    boolean mayor = FALSE;
    String nom1, nom2;
    Fecha fA, fM;
    fM = ObtenerFechaNacimientoMiembroABB(m);
    ObtenerNombreMiembroABB(m, nom2);
    if(arbol != NULL){
        fA = ObtenerFechaNacimientoMiembroABB(arbol->info);
        if(FechaMayorIgual(fM, fA)){
            mayor = TRUE;
        }else{
            ObtenerNombreMiembroABB(arbol->info, nom1);
            fA = ObtenerFechaNacimientoMiembroABB(arbol->info);
            if(FechaMayorIgual(fM, fA)){
                if(strmen(nom2, nom1) == TRUE)
                    mayor = FechaEsMayorATodas(arbol->hIzq, m);
                else
                    mayor = FechaEsMayorATodas(arbol->hDer, m);
            LiberarString(nom1);
        }
    }
    LiberarString(nom2);
    return mayor;
    }
}

//Devuelve el ABB de familia
void MostrarABB(ArbolFamilia a){
    if (a != NULL) {
        MostrarABB(a->hIzq);
        MostrarMiembroABB(a->info);
        MostrarABB(a->hDer);
    }
}

void GuardarABB(FILE* f, ArbolFamilia abb){
    if (abb != NULL) {
        GuardarMiembroABB(f, abb->info);
        AuxGuardarABB(abb->hIzq, f);
        AuxGuardarABB(abb->hDer, f);
    }
}

//Levanta ABB desde archivo
void LeerFamiliaABB(FILE *f, ArbolFamilia &abb){
    MiembroABB buffer;
    InicializarArbolFamilia(abb);
    LevantarMiembroABB(f, buffer);

    while (!feof(f)) {
        AgregarMiembroAlArbolFamilia(abb, buffer);
        LevantarMiembroABB(f, buffer);
    }
}

//Libera el espacio de memoria ocupado por el ABB
void LiberarABBFamilia(ArbolFamilia &abb){
    if(abb != NULL){
        LiberarABBFamilia(abb->hIzq);
        LiberarABBFamilia(abb -> hDer);
        LiberarMiembroABB(abb -> info);

        delete abb;
        abb = NULL;
    }
}
