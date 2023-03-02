#include "ABBFamilia.h"

//Inicializa ABB de familia
void InicializarArbolFamilia(ArbolFamilia &arbol){
    arbol = NULL;
}

//Verifica que el ABB tenga elementos
boolean ArbolTieneElementos(ArbolFamilia af){

}

//Agrega elemento Miembro al ABB
void AgregarMiembroAlArbolFamilia(ArbolFamilia &arbol, MiembroABB m){
    String nom1, nom2;
    if (arbol == NULL) {
        arbol = new nodoFamilia;
        arbol->hIzq = NULL;
        arbol->hDer = NULL;
        arbol->info = m;
   } else {
        ObtenerNombreMiembroABB(arbol->info, nom1);
        ObtenerNombreMiembroABB(m, nom2);
        if (strmen(nom1, nom2) == TRUE){
            AgregarMiembroAlArbolFamilia(arbol->hIzq, m);
       }else {
           AgregarMiembroAlArbolFamilia(arbol->hDer, m);
       }
       LiberarString(nom1);
       LiberarString(nom2);
    }
}

//Verifica si ese nombre existe en el ABB
boolean ExisteEnArbol(ArbolFamilia arbol, String nombre){

}

//Verifica que una fecha sea mayor a todas las existentes en el ABB
boolean FechaEsMayorATodas (ArbolFamilia arbol, Fecha f){

}

//Devuelve el ABB de familia
void MostrarABB(ArbolFamilia a){
    if (a != NULL) {
        MostrarABB(a->hIzq);
        MostrarMiembroABB(a->info);
        MostrarABB(a->hDer);
    }
}

//Guarda ABB en archivo Hacer auxiliar tendria que haber otra que abra el archivo y llame a esta
void GuardarABB(ArbolFamilia abb, FILE* f){
    if (abb != NULL) {
        GuardarMiembroABB(f, abb->info);
        GuardarABB(abb->hIzq, f);
        GuardarABB(abb->hDer, f);
    }
}

//Levanta ABB desde archivo
void LeerFamiliaABB(String nomArch, ArbolFamilia &abb){
    MiembroABB buffer;
    InicializarArbolFamilia(abb);
    FILE *f;
    f = fopen("nomArch", "rb");
    LevantarMiembroABB(f, buffer);

    while (!feof(f)) {
        AgregarMiembroAlArbolFamilia(abb, buffer);
        LevantarMiembroABB(f, buffer);
    }
    fclose(f);
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
