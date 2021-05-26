#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicios.h"

int mostrarServicio(eServicio unServicio)
{
    int todoOk=1;

    printf("  %d       %15s         %d"
           ,unServicio.id
           ,unServicio.descripcion
           ,unServicio.precio
          );
    printf("\n");

    return todoOk;
}

int mostrarServicios(eServicio servicios[], int tam)
{
    int todoOk=0;
    int flag=1;

    if(servicios!=NULL&&tam>0)
    {
        system("cls");
        printf("          ***LISTA DE SERVICIOS***\n\n");
        printf("  ID               Descripcion       Precio\n");
        printf("--------------------------------------------\n");


        for(int i=0; i<tam; i++)
        {
                if(mostrarServicio(servicios[i]))
                {
                    flag=0;
                }
        }
        if(flag==1)
        {
            printf("\n    No esta disponible mostrar Colores\n\n");
        }
        printf("\n\n");
        todoOk=1;


    }
    return todoOk;
}
int validarIdServicio(int id, eServicio servicios[],int tam)
{
    int valido=0;

    if(servicios!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id==id)
            {
                valido=1;
                break;
            }
        }
    }
    return valido;
}

int cargarDescripcionServicio(int id, eServicio servicios[],int tam, char descripcion[])
{
    int todoOk=0;

    if(id>=20000 && id<=20003 && servicios != NULL && tam >0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id==id)
            {
                strcpy(descripcion, servicios[i].descripcion);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}
