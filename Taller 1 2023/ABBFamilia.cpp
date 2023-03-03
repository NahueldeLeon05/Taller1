#include "ABBFamilia.h"

//Inicializa ABB de familia
void InicializarArbolFamilia(ArbolFamilia &arbol){
    arbol = NULL;
}

//Verifica que el ABB tenga elementos
boolean ArbolTieneElementos(ArbolFamilia af){
    if(af == NULL)
        return FALSE;
    else
        return TRUE;
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
        if (strmen(nom2, nom1) == TRUE){
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
    String nom1;
    if (arbol == NULL)
        return FALSE;
    else{
        ObtenerNombreMiembroABB(arbol->info, nom1);
        if(streq(nom1, nombre, TRUE)){
            return TRUE;
        }else{
             if(strmen(nom1, nombre))
                 return ExisteEnArbol(arbol->hIzq, nombre);
             else
                 return ExisteEnArbol(arbol->hDer, nombre);
       }
        LiberarString(nom1);
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

//Guarda ABB en archivo Hacer auxiliar tendria que haber otra que abra el archivo y llame a esta
void AuxGuardarABB(ArbolFamilia abb, FILE* f){
    if (abb != NULL) {
        GuardarMiembroABB(f, abb->info);
        AuxGuardarABB(abb->hIzq, f);
        AuxGuardarABB(abb->hDer, f);
    }
}

void GuardarABB(String nomArch, ArbolFamilia abb){
    FILE* f;
    f = fopen (nomArch, "wb");
    AuxGuardarABB(abb, f);
    fclose(f);
}

//Levanta ABB desde archivo
void LeerFamiliaABB(String nomArch, ArbolFamilia &abb){
    MiembroABB buffer;
    InicializarArbolFamilia(abb);
    FILE *f;
    f = fopen(nomArch, "rb");
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
