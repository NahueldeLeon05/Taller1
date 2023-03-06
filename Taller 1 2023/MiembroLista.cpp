#include "MiembroLista.h"

//Crea miembro de Lista
MiembroLista CrearMiembroLista(MiembroABB m, boolean monarcaActual){
    MiembroLista mL;

    mL.m = m;

    mL.monarcaActual = monarcaActual;
    mL.aspirante = aspirante;
    mL.fueMonarca = FALSE;
    mL.abdico = FALSE;
    mL.fallecio = FALSE;
    if(monarcaActual == TRUE){
        mL.ascension = ObtenerFechaNacimientoMiembroABB(m);
        mL.aspirante = FALSE;
    }else{
        mL.aspirante = TRUE;
        mL.ascension = FechaDefecto();
    }
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
    printf("\n");
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

//Devuelve si la fecha ascensi�n es 0/0/0
// llevar a fecha.cpp
boolean fechaVacia(MiembroLista m){
    boolean t;
    int dia = ObtenerDiaFecha(m.ascension), mes = ObtenerMesFecha(m.ascension), anio = ObtenerAnioFecha(m.ascension);
    if(dia == 0 && mes == 0 && anio == 0)
        t = TRUE;
    else
        t = FALSE;

    return t;
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
        printf(" fallecio.\r\n");
    } else
           if(mL.abdico){
                printf(" hasta el ");
                MostrarFecha(mL.abdicacion);
                printf(" abdico.\r\n");
           }else {
        printf(" hasta la actualidad.\r\n");
    }
    // EJEMPLO 1 - JORGE desde el 14/12/1895 hasta el 06/02/1952 (falleci�)
    // EJEMPLO 2 - ISABEL desde el 06/02/1952 hasta la actualidad
}

void MostrarAspirante(MiembroLista ml){
    String nomMiembro, nomPadre;
    if(ml.aspirante == TRUE){
        ObtenerNombreMiembroABB(ml.m, nomMiembro);
        ObtenerNombreProgenitorMiembroABB(ml.m, nomPadre);
        print(nomMiembro);
        printf(" hijo de ");
        print(nomPadre);
        printf("\r\n");
        LiberarString(nomMiembro);
        LiberarString(nomPadre);
    }
}

void MostrarMiembroListaHis(MiembroLista ml){
    MostrarMiembroABBHistorial(ml.m);
    if(ml.monarcaActual == TRUE){
        MostrarFecha(ml.ascension);
        printf(" hasta la actualidad.");
        printf("\r\n");
    }
    if(ml.fueMonarca == TRUE){
        printf("fue monarca desde: ");
        MostrarFecha(ml.ascension);
        printf(" hasta");
        if (ml.fallecio){
            printf(" hasta el ");
            MostrarFecha(ml.fallecimiento);
            printf(" fallecio.\r\n");
    } else
           if(ml.abdico){
                printf(" hasta el ");
                MostrarFecha(ml.abdicacion);
                printf(" abdico.\r\n");
           }else {
        printf(" hasta la actualidad.\r\n");
        }
    }else{
        if(ml.aspirante == TRUE){
            printf(" es aspirante al trono.");
            printf("\r\n");
        }
        if (ml.fallecio){
            printf(" fallecio el ");
            MostrarFecha(ml.fallecimiento);
            printf("\r\n");
        } else
           if(ml.abdico){
                printf(" abdico el ");
                MostrarFecha(ml.abdicacion);
                printf("\r\n");
        }
    }

}
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

void CargarFechaAscension(MiembroLista &mL, Fecha f) {
    mL.ascension = f;
    mL.monarcaActual = TRUE;
}

//Selectora obtener fecha de abdicacion
Fecha ObtenerFechaAbdicacion(MiembroLista mL){
    return mL.abdicacion;
}

void CargarFechaAbdicacion(MiembroLista &mL, Fecha f) {
    mL.abdicacion = f;
    mL.abdico = TRUE;

    mL.fueMonarca = mL.monarcaActual;
    mL.monarcaActual = FALSE;
}

//Selectora obtener fecha de Fallecimiento
Fecha ObtenerFechaFallecimiento(MiembroLista mL){
    return mL.fallecimiento;
}

void CargarFechaFallecimiento(MiembroLista &mL, Fecha f) {
    mL.fallecimiento = f;
    mL.fallecio = TRUE;

    mL.fueMonarca = mL.monarcaActual;
    mL.monarcaActual = FALSE;
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
