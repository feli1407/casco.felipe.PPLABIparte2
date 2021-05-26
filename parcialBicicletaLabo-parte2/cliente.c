#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"

int inicializarClientes(eClientes lista[], int tam)
{
    int todoOk=0;
    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int agregarCliente(eClientes lista[], int tam, int id, char nombre[],char sexo)
{
    int todoOk=-1;
    int indice=-1;
    if(lista!=NULL&&tam>0&&nombre!=NULL)
    {
        indice=buscarLibreCliente(lista,tam);
        strcpy(lista[indice].nombre,nombre);
        lista[indice].id=id;
        lista[indice].isEmpty=0;
        lista[indice].sexo=sexo;
        todoOk=0;
    }
    return todoOk;
}

int buscarLibreCliente(eClientes lista[], int tam)
{
    int lugarlibre=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty==1)
        {
            lugarlibre=i;
            break;
        }
    }
    return lugarlibre;
}

int cargarDescripcionCliente(int id, eClientes clientes[],int tam, char descripcion[])
{
    int todoOk=0;

    if(id>=100 && id<=1100 && clientes != NULL && tam >0 && descripcion!=NULL)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].id==id)
            {
                strcpy(descripcion, clientes[i].nombre);
                todoOk=1;
                break;
            }
        }
    }

    return todoOk;
}
