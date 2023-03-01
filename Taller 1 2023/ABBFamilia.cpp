#include "ABBFamilia.h"

//Inicializa ABB de familia
void InicializarArbolFamilia(ArbolFamilia &arbol){

}

//Verifica que el ABB tenga elementos
boolean ArbolTieneElementos(ArbolFamilia af){

}

//Agrega elemento Miembro al ABB
void AgregarMiembroAlArbolFamilia(ArbolFamilia &arbol, MiembroABB m){

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
        MostrarABB(a -> hIzq);
        MostrarMiembroABB(a -> info);
        MostrarABB(a -> hDer);
    }
}

//Guarda ABB en archivo
void GuardarABB(ArbolFamilia abb, FILE* f){
    if (abb != NULL) {
        GuardarABB(abb -> hIzq, f);
        GuardarABB(abb -> hDer, f);
        GuardarMiembroABB(f, abb -> info);
    }
}

//Levanta ABB desde archivo
void LeerFamiliaABB(FILE* f, ArbolFamilia &abb){
    MiembroABB buffer;
    abb = NULL;
    LevantarMiembroABB(f, buffer);

    while (!feof(f)) {
        AgregarMiembroAlArbolFamilia(abb, buffer);
        LevantarMiembroABB(f, buffer);
    }
}

//Libera el espacio de memoria ocupado por el ABB
void LiberarABBFamilia(ArbolFamilia &abb){
    if(abb != NULL){
        LiberarABBFamilia(abb -> hIzq);
        LiberarABBFamilia(abb -> hDer);
        LiberarMiembroABB(abb -> info);
    }
}
