#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "colores.h"

int cargarDescripcionColor(int id, eColores colores[],int tam, char descripcion[])
{
    int todoOk=0;

    if(id>=5000 && id<=5004 && colores != NULL && tam >0 && descripcion!=NULL)//validaciones
    {
        for(int i=0; i<tam; i++) //recorro array de colores
        {
            if(colores[i].id==id)
            {
                strcpy(descripcion, colores[i].descripcion);//copio la descripcion de colores
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}

int mostrarColor(eColores unColor)
{
    int todoOk=1;

    printf("  %d       %15s   "
           ,unColor.id
           ,unColor.descripcion
          );
    printf("\n");

    return todoOk;
}

int mostrarColores(eColores colores[], int tam)
{
    int todoOk=0;
    int flag=1;

    if(colores!=NULL&&tam>0)
    {
        system("cls");
        printf("  ***LISTA DE COLORES***\n\n");
        printf("  ID               Descripcion\n");
        printf("-------------------------------\n");


        for(int i=0; i<tam; i++)
        {
            if(mostrarColor(colores[i]))
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
