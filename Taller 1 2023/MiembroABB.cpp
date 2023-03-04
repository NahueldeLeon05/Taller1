#include "MiembroABB.h"

MiembroABB CrearMiembroNuevo(String nom, String padre, Fecha nacimiento) {
    MiembroABB m;
    strcrear(m.nombre);
    strcop(nom, m.nombre);
    if (padre == NULL) {
        m.nombreProgenitor = NULL;
    } else {
        strcrear(m.nombreProgenitor);
        strcop(padre, m.nombreProgenitor);
    }
    m.fNac = nacimiento;

    return m;
}

void MostrarMiembroABB(MiembroABB m) {
    print(m.nombre);
    printf(" hijo/a de ");
    print(m.nombreProgenitor);
    printf(" nacio el ");
    MostrarFecha(m.fNac);
}

void ObtenerNombreMiembroABB(MiembroABB m, String &nom) {
    strcrear(nom);
    strcop(m.nombre, nom);
}

Fecha ObtenerFechaNacimientoMiembroABB(MiembroABB m) {
    return m.fNac;
}

void ObtenerNombreProgenitorMiembroABB(MiembroABB m, String &nom) {
    strcrear(nom);
    strcop(m.nombreProgenitor, nom);
}

void GuardarMiembroABB(FILE* f, MiembroABB m) {
    GuardarString(m.nombre, f);
    GuardarFecha(m.fNac, f);
    GuardarString(m.nombreProgenitor, f);
}

void LevantarMiembroABB(FILE* f, MiembroABB &m) {
    LeerString(m.nombre, f);
    LeerFecha(m.fNac, f);
    LeerString(m.nombreProgenitor, f);
}

void LiberarMiembroABB(MiembroABB &m) {
    LiberarString(m.nombre);
    LiberarString(m.nombreProgenitor);
}
