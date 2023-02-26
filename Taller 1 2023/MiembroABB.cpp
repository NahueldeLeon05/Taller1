#include "MiembroABB.h"

MiembroABB CrearMiembroNuevo(String nom, String padre, Fecha nacimiento) {
    MiembroABB m;
    strcrear(m.nombre);
    strcop(nom, m.nombre);
    strcrear(m.nombreProgenitor);
    strcop(padre, m.nombreProgenitor);

    return m;
}
