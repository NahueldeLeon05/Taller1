#include "boolean.h"
#include <stdio.h>

//Carga un boolean
void CargarBoolean(boolean &b){
                int num;
                printf("Ingrese un valor: 0-False 1-True:\n");
                scanf("%d", &num);
                if(num==1)
                                b=TRUE;
                else
                                b=FALSE;
}

//muestra el boolean cargado
void MostrarBoolean(boolean b){
                if(b==TRUE)
                                printf("Es Verdadero");
                else
                                printf("Es Falso");
}
