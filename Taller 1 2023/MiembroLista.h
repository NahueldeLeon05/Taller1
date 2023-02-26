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

#endif // MIEMBROLISTA_H_INCLUDED
