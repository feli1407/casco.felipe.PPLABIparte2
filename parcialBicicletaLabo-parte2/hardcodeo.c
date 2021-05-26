#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bicicleta.h"
#include "trabajo.h"
#include "fechas.h"
#include "cliente.h"

char marcas[10][20]=
{
    "rider",
    "congo",
    "yeezy",
    "adidas",
    "raptor",
    "golfix",
    "rider",
    "rider",
    "negroni",
    "dollars"
};

int idTipo[10]= {1000,1003,1002,1001,1001,1003,1000,1003,1002,1000};

int idColor[10]= {5000,5003,5002,5001,5001,5004,5000,5004,5002,5000};

float rodado[10]= {20,27.5,20,20,29,26,29,26,27.5,20};

char nombres[10][20]=
{
    "Donato",
    "Alberto",
    "Carlos",
    "Vidal",
    "Susana",
    "Camila",
    "Marina",
    "Felipe",
    "Pascual",
    "Julia"
};

char sexos[10]= {'m','m','m','f','f','f','f','m','m','f'};

int idBicicletas[20]= {50000,50002,50001,50005,50006,50008,50009,50007,50000,50000,50002,50000,50002,50001,50005,50006,50008,50009,50007,50000};

int idServicios[20]= {20000,20002,20001,20003,20000,20003,20002,20003,20000,20001,20002,20000,20002,20001,20003,20000,20003,20002,20003,20000};

int idClientes[10]= {100,101,102,103,104,105,106,107,108,109};

fechas fechaTrabajos[]=
{
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {1,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {2,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {3,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021},
    {4,1,2021}
};

int hardcodearBicicletas(eBicicleta bicicletas[],int tam,int cant,int* pIdBicicleta)
{
    int todoOk=0;

    if(bicicletas!=NULL&&tam>0&&cant>0&&pIdBicicleta!=NULL)
    {
        for(int i=0;i<cant;i++)
        {
            bicicletas[i].id=*pIdBicicleta;
            (*pIdBicicleta)++;
            strcpy(bicicletas[i].marca,marcas[i]);
            bicicletas[i].idTipo=idTipo[i];
            bicicletas[i].idCliente=idClientes[i];
            bicicletas[i].idColor=idColor[i];
            bicicletas[i].rodado=rodado[i];
            bicicletas[i].isEmpty=0;
        }
        todoOk=1;
    }
    return todoOk;
}

int hardcodeoTrabajos(eTrabajos trabajos[],int tam,int cant,int* pIdTrabajo)
{
    int todoOk=0;
    if(trabajos!=NULL&&tam>0&&cant>0&&pIdTrabajo!=NULL)
    {
        for(int i=0;i<cant;i++)
        {
            trabajos[i].id=*pIdTrabajo;
            (*pIdTrabajo)++;
            trabajos[i].idBicicleta=idBicicletas[i];
            trabajos[i].idServicio=idServicios[i];
            trabajos[i].fechaTrabajo=fechaTrabajos[i];
            trabajos[i].isEmpty=0;
        }
        todoOk=1;
    }
    return todoOk;
}

int hardcodeoClientes(eClientes clientes[],int tam,int cant,int* pIdCliente)
{
    int todoOk=0;
    if(clientes!=NULL&&tam>0&&cant>0&&pIdCliente!=NULL)
    {
        for(int i=0;i<cant;i++)
        {
            clientes[i].id=*pIdCliente;
            (*pIdCliente)++;
            strcpy(clientes[i].nombre,nombres[i]);
            clientes[i].sexo=sexos[i];
            clientes[i].isEmpty=0;
        }
        todoOk=1;
    }
    return todoOk;
}
