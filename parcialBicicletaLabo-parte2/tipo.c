#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipo(int id, eTipo tipos[],int tam, char descripcion[])
{
    int todoOk=0;

    if(id>=1000 && id<=1003 && tipos != NULL && tam >0 && descripcion!=NULL)//validaciones
    {
        for(int i=0; i<tam; i++) //recorro array de tipos
        {
            if(tipos[i].id==id)
            {
                strcpy(descripcion, tipos[i].descripcion);//copio la descripcion de tipos
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}

int mostrarTipo(eTipo unTipo)
{
    int todoOk=1;

    printf("  %d       %15s   "
           ,unTipo.id
           ,unTipo.descripcion
          );
    printf("\n");

    return todoOk;
}

int mostrarTipos(eTipo tipos[], int tam)
{
    int todoOk=0;
    int flag=1;

    if(tipos!=NULL&&tam>0)
    {
        system("cls");
        printf("  ***LISTA DE TIPOS***\n\n");
        printf("  ID               Descripcion\n");
        printf("-------------------------------\n");


        for(int i=0; i<tam; i++)
        {
                if(mostrarTipo(tipos[i]))
                {
                    flag=0;
                }
        }
        if(flag==1)
        {
            printf("\n    No esta disponible mostrar tipos\n\n");
        }
        printf("\n\n");
        todoOk=1;


    }
    return todoOk;
}
