#ifndef MIEMBROLISTA_H_INCLUDED
#define MIEMBROLISTA_H_INCLUDED
#include "MiembroABB.h"

typedef struct {
                    MiembroABB m;
                    boolean monarcaActual;
                    boolean fueMonarca;
                    boolean aspirante;
                    boolean abdico;
                    boolean fallecio;
                    Fecha ascension;
                    Fecha abdicacion;
                    Fecha fallecimiento;
                }MiembroLista;

//Crea miembro de Lista
MiembroLista crearMiembroLista(MiembroABB m, boolean monarcaActual, boolean aspirante);

//Selectora: obtiene el nombre del miembro
void ObtenerNombreMiembroLista(MiembroLista mL, String &nom);

//Selectora obtiene la fecha de nacimiento.
void ObtenerFechaNacMiembroLista(MiembroLista mL, String &fechaNac);

//Selectora obtiene el nombre del progenitor
void ObtenerProgenitorMiembroLista(MiembroLista mL, String &progenitor);

//Selectora obtiene si es monarca actual
boolean ObtenerMonarcaActual(MiembroLista mL);

//Selectora obtiene si fue monarca
boolean ObtenerFueMonarca(MiembroLista mL);

//Selectora obtiene si es aspirante
boolean ObtenerAspirante(MiembroLista mL);

//Selectora obtiene si abdico
boolean ObtenerAbdico(MiembroLista mL);

//Selectora obtiene si fallecio
boolean ObtenerFallecio(MiembroLista mL);

//Selectora obtener fecha de ascencion
Fecha ObtenerFechaAscencion(MiembroLista mL);

//Selectora obtener fecha de abdicacion
Fecha ObtenerFechaAbdicacion(MiembroLista mL);

//Selectora obtener fecha de Fallecimiento
Fecha ObtenerFechaFallecimiento(MiembroLista mL);

//Devuelve si el miembro de la lista esta vivo o no
boolean Vivo(MiembroLista m);

//Devuelve si el miembro de la lista es rey o no
boolean EsRey(MiembroLista m);

//Devuelve si el miembro de la lista esta muerto o no
boolean Muerto(MiembroLista m);

//Devuelve si el miembro de la lista abdicó o no
boolean Abdico(MiembroLista m);

//Devuelve si el miembro de la lista es aspirante o no
boolean esAspirante(MiembroLista m);

//Devuelve si el miembro de la lista no es o fue monarca
boolean noEsOFueMonarca(MiembroLista m);

//Devuelve si el miembro de la lista es o no primogenito
boolean Primogenito(MiembroLista m);

//Devuelve si la fecha ascensión es 0/0/0
boolean fechaVacia(MiembroLista m, Fecha f);

//Despliega el miembro de la lista
void MostrarMiembroLista(MiembroLista ml);

//Muestra fecha de inicio y fin del reinado del miembro
void mostrarInicioFin(MiembroLista mL);

void GuardarMiembroLista(FILE* f, MiembroLista ml);

void CargarMiembroLista(FILE* f, MiembroLista &ml);

void LiberarMiembroLista(MiembroLista &ml);

#endif // MIEMBROLISTA_H_INCLUDED
