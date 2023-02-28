#include "MiembroLista.h"
#include "ListaDinastia.h"
#include <stdio.h>

//Crea miembro de Lista
MiembroLista CrearMiembroLista(MiembroABB m, boolean monarcaActual, boolean aspirante){
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
    mL.ascension = FechaDefecto();
    mL.abdicacion = FechaDefecto();
    mL.fallecimiento = FechaDefecto();
    return mL;
}

//Despliega el miembro de la lista
void MostrarMiembroLista(MiembroLista mL){
    MostrarMiembroABB(mL.m);
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
    printf("\nFecha de ascencion: ");
    MostrarFecha(mL.ascension);
    printf("\nFecha de abdicacion: ");
    MostrarFecha(mL.abdicacion);
    printf("\nFecha de Fallecimiento: ");
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
boolean EsAspirante(MiembroLista m){
    return m.aspirante;
}

boolean NoFueMonarca(MiembroLista m){
    return m.fueMonarca;
}

//Devuelve si el miembro de la lista es o no primogenito
boolean Primogenito(MiembroLista m, ListaDinastia ls){ //REVISAR
    boolean es = FALSE;
    String nombre, nombre2;
    strcrear(nombre);
    strcrear(nombre2);
    ObtenerNombreMiembroABB(ObtenerMiembroABB(ls->info), nombre);
    ObtenerNombreMiembroABB(ObtenerMiembroABB(m), nombre2);
    while (ls ->sig != NULL){
        if (streq(nombre, nombre2, TRUE)){
            es = TRUE;
        }else{
            Primogenito(m, ls->sig);
        }
    }
    return es;
}

//Devuelve si la fecha ascensi�n es 0/0/0
boolean fechaVacia(MiembroLista m){
    return m.ascension.dia == 0 && m.ascension.mes == 0 && m.ascension.anio == 0 ? TRUE : FALSE;
}

//Muestra fecha de inicio y fin del reinado del miembro
void MostrarInicioFin(MiembroLista mL){
    MiembroABB miembroAbb = mL.m;

    String nombre;
    ObtenerNombreMiembroABB(miembroAbb, nombre);

    print(nombre);
    printf(" desde el ");
    MostrarFecha(mL.ascension);

    if (mL.fallecio){
        printf(" hasta el ");
        MostrarFecha(mL.fallecimiento);
        printf(" falleció.\r\n");
    } else {
        printf(" hasta la actualidad.\r\n");
    }
    // EJEMPLO 1 - JORGE desde el 14/12/1895 hasta el 06/02/1952 (falleci�)
    // EJEMPLO 2 - ISABEL desde el 06/02/1952 hasta la actualidad
}

MiembroABB ObtenerMiembroABB(MiembroLista ml) {
    return ml.m;
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
boolean ObtenerFallecio(MiembroLista mL){
    return mL.fallecio;
}

//Selectora obtiene si es aspirante
boolean ObtenerAspirante(MiembroLista mL) {
    return mL.aspirante;
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

void GuardarMiembroLista(FILE* f, MiembroLista ml){
    GuardarMiembroABB(f, ml.m);
    fwrite(&ml.monarcaActual, sizeof(int), 1, f);
    fwrite(&ml.fueMonarca, sizeof(int), 1, f);
    fwrite(&ml.aspirante, sizeof(int), 1, f);
    fwrite(&ml.abdico, sizeof(int), 1, f);
    fwrite(&ml.fallecio, sizeof(int), 1, f);
    GuardarFecha(ml.ascension, f);
    GuardarFecha(ml.abdicacion, f);
    GuardarFecha(ml.fallecimiento, f);
}

void CargarMiembroLista(FILE* f, MiembroLista &ml){
    LevantarMiembroABB(f, ml.m);
    fread(&ml.monarcaActual, sizeof(int), 1, f);
    fread(&ml.fueMonarca, sizeof(int), 1, f);
    fread(&ml.aspirante, sizeof(int), 1, f);
    fread(&ml.abdico, sizeof(int), 1, f);
    fread(&ml.fallecio, sizeof(int), 1, f);
    LeerFecha(ml.ascension, f);
    LeerFecha(ml.abdicacion, f);
    LeerFecha(ml.fallecimiento, f);
}

void LiberarMiembroLista(MiembroLista &ml){
    LiberarMiembroABB(ml.m);
}
