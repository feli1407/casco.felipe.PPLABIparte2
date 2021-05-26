#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "trabajo.h"


int inicializarTrabajos(eTrabajos trabajos[], int tam)
{
    int todoOk=0;
    if(trabajos!=NULL&&tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            trabajos[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibreTrabajo(eTrabajos trabajos[], int tam)
{
    int lugarlibre=-1;

    for(int i=0; i<tam; i++)
    {
        if(trabajos[i].isEmpty==1)
        {
            lugarlibre=i;
            break;
        }
    }
    return lugarlibre;
}

int altaTrabajo(eTrabajos trabajos[], int tamt, eColores colores[],int tamcol,eBicicleta bicicletas[], int tamb,
                eServicio servicios[], int tams,eTipo tipos[],int tamtip, int* pNextIdTrabajo,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int indice;
    eTrabajos nuevoTrabajo;
    int idBicicleta;
    int idServicio;

    if(trabajos != NULL&&tipos!=NULL && bicicletas != NULL &&
            servicios != NULL && pNextIdTrabajo != NULL && tamt>0 && tamb>0 && tams>0&&tamtip>0)
    {
        printf("    ALTA TRABAJOS\n");
        indice=buscarLibreTrabajo(trabajos, tamt);
        if(indice==-1)
        {
            printf("No hay luagar para mas trabajos\n");
        }
        else
        {
            system("cls");
            mostrarBicicletas(bicicletas,tamb,tipos,tamtip,colores,tamcol,clientes,tamc);
            printf("Ingrese id de la bicicleta: ");
            scanf("%d", &idBicicleta);

            while(buscarBicicleta(bicicletas,tamb,idBicicleta)==-1)
            {
                printf("\nNo existe una bicicleta con este id. Reingrese id: ");
                scanf("%d", &idBicicleta);
            }

            nuevoTrabajo.idBicicleta=idBicicleta;

            system("cls");
            mostrarServicios(servicios,tams);

            printf("Ingrese id del servicio: ");
            scanf("%d", &idServicio);

            while(!(validarIdServicio(idServicio,servicios,tams)))
            {
                printf("Id invalido. Reingrese Id servicio: ");
                scanf("%d", &idServicio);
            }

            nuevoTrabajo.idServicio=idServicio;

            system("cls");
            printf("Ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d",&nuevoTrabajo.fechaTrabajo.dia,&nuevoTrabajo.fechaTrabajo.mes,
                  &nuevoTrabajo.fechaTrabajo.anio);

            while(!(valFecha(nuevoTrabajo.fechaTrabajo.dia,nuevoTrabajo.fechaTrabajo.mes,nuevoTrabajo.fechaTrabajo.anio)))
            {
                printf("Error, fecha invalida, ingrese fecha dd/mm/aaaa: ");
                scanf("%d/%d/%d",&nuevoTrabajo.fechaTrabajo.dia,&nuevoTrabajo.fechaTrabajo.mes,
                      &nuevoTrabajo.fechaTrabajo.anio);
            }

            nuevoTrabajo.id = *pNextIdTrabajo;
            (*pNextIdTrabajo)++;
            nuevoTrabajo.isEmpty = 0;
            trabajos[indice] = nuevoTrabajo;
            todoOk=1;
        }


    }

    return todoOk;

}

int mostrarTrabajo(eTrabajos unTrabajo, eServicio servicios[], int tams)
{

    int todoOk=0;
    char descServicio[20];



    if(servicios!=NULL&&tams>0)
    {
        if(cargarDescripcionServicio(unTrabajo.idServicio,servicios,tams,descServicio))
        {
            printf("      %d         %d      %15s        %02d/%02d/%d\n",unTrabajo.id,unTrabajo.idBicicleta,
                   descServicio, unTrabajo.fechaTrabajo.dia,
                   unTrabajo.fechaTrabajo.mes,unTrabajo.fechaTrabajo.anio);
        }
        todoOk=1;
    }

    return todoOk;

}

int mostrarTrabajos(eTrabajos trabajos[], int tamt, eServicio servicios[], int tams)
{
    int todoOk=0;
    if(trabajos!=NULL&&tamt>0&&servicios!=NULL&&tams>0)
    {
        int flag=1;
        system("cls");
        printf("                   ***LISTA DE TRABAJOS***\n");
        printf("  ID Trabajo     ID Bicicleta        Servicio          Fecha\n");
        printf("-------------------------------------------------------------\n");


        for(int i=0; i<tamt; i++)
        {
            if(!trabajos[i].isEmpty)//si el campo isEmpty no esta vacio, muestro la estructura
            {
                mostrarTrabajo(trabajos[i],servicios,tams);
                flag=0;
            }
        }
        if(flag==1)
        {
            printf("\n    No hay trabajos que mostrar\n\n");
        }
        printf("\n\n");

        system("pause");

        todoOk=1;
    }
    return todoOk;
}
