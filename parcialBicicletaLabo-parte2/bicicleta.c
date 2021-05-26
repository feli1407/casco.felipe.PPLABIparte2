#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "bicicleta.h"
#include "tipo.h"
#include "colores.h"
#include "cliente.h"

int inicializarBiciletas(eBicicleta lista[], int tam)
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

int altaBicicleta(eBicicleta lista[], int tamb,eClientes clientes[],int tamc, int* punteroIdBici, int* punteroIdCliente)
{
    int todoOk=0;
    eBicicleta nuevaBicicleta;//variable auxuliar
    eClientes nuevoCliente;//variable auxuliar
    int errorValidacion=0;//1 si hay error y 0 si no hay

    system("cls");
    printf("      Alta Bicicleta\n\n");
    printf("\nId de la bicicleta: %d\n",*punteroIdBici);

    if(lista!=NULL &&tamb>0 && punteroIdBici!=NULL && punteroIdCliente!=NULL &&tamc>0)
    {
        if(buscarLibre(lista,tamb)!=-1)
        {
            do
            {
                fflush(stdin);
                if(!(getString(nuevoCliente.nombre,20,"Ingrese nombre del cliente: ","Error, ",3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    system("pause");
                    break;
                }

                fflush(stdin);
                if(!(pedirSexo(&nuevoCliente.sexo,"Ingrese sexo del cliente: ","Error, ",3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    system("pause");
                    break;
                }

                fflush(stdin);
                if(!(getString(nuevaBicicleta.marca,20,"Ingrese marca: ","Error, ",3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    system("pause");
                    break;
                }

                fflush(stdin);
                if(!(getNumero(&nuevaBicicleta.idTipo,"Ingrese id del tipo de bicicleta(1000/1003): ","Error, ",1000,1003,3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    system("pause");
                    break;
                }

                fflush(stdin);
                if(!(getNumero(&nuevaBicicleta.idColor,"Ingrese id del color de la bicicleta(5000/5004): ","Error, ",5000,5004,3)))
                {
                    printf(" ocurrio un error en la validacion\n");
                    errorValidacion=1;
                    system("pause");
                    break;
                }

                fflush(stdin);
                if(getNumeroFlotante(&nuevaBicicleta.rodado,"Ingrese rodado de la bicicleta(20/26/27.5/29): ","Error, ",20,29,3))
                {
                    if(nuevaBicicleta.rodado!=20 && nuevaBicicleta.rodado!=26 && nuevaBicicleta.rodado!= 27.5 && nuevaBicicleta.rodado!= 29)
                    {
                        printf(" ocurrio un error en la validacion\n");
                        errorValidacion=1;
                        system("pause");
                        break;
                    }
                }

            }
            while(errorValidacion!=0);

            if(errorValidacion==0)
            {
                if((agregarBicicleta(lista,tamb,*punteroIdBici,nuevaBicicleta.marca,nuevaBicicleta.idTipo
                    ,nuevaBicicleta.idColor,nuevaBicicleta.rodado,*punteroIdCliente))==0&&
                   (agregarCliente(clientes,tamc,*punteroIdCliente,nuevoCliente.nombre,nuevoCliente.sexo))==0)
                {
                    (*punteroIdBici)++;
                    (*punteroIdCliente)++;
                    todoOk=1;
                    printf("Alta exitosa\n");
                    system("pause");
                }
                else
                {
                    printf("Ocurrio un error al dar de alta la bicicleta\n");
                    system("pause");
                }

            }
        }
        else
        {
            printf("No hay lugar disponible para dar de alta empleados\n");
        }
    }
    return todoOk;
}

int agregarBicicleta(eBicicleta lista[], int tam, int id, char marca[],int idTipo,int idColor, float rodado,int idCliente)
{
    int todoOk=-1;
    int indice=-1;
    if(lista!=NULL&&tam>0&&marca!=NULL)
    {
        indice=buscarLibre(lista,tam);
        strcpy(lista[indice].marca,marca);
        lista[indice].id=id;
        lista[indice].isEmpty=0;
        lista[indice].idTipo=idTipo;
        lista[indice].idColor=idColor;
        lista[indice].rodado=rodado;
        lista[indice].idCliente=idCliente;
        todoOk=0;
    }
    return todoOk;
}

int buscarLibre(eBicicleta lista[], int tam)
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

int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[],int tamt, eColores colores[], int tamcol,eClientes clientes[],int tamc)
{
    int idModificar;
    int indice;
    char confirmacionModificar='n';
    char salirModificarMenu='n';
    int todoOk=0;



    if(lista!=NULL&&tam>0&&tipos!=NULL&&tamt>0&&colores!=NULL&&tamc>0)
    {
        mostrarBicicletas(lista,tam,tipos,tamt,colores,tamcol,clientes,tamc);

        do
        {
            getNumero(&idModificar,"\nIngrese id de la bicicleta: ","Opcion invalida!",50000,51000,3);
        }
        while(encontrarBicicletaConId(lista,tam,idModificar)==-1);

        indice=encontrarBicicletaConId(lista,tam,idModificar);

        printf("Esta seguro que desea modificar esta bicicleta?(s o n)\n");
        fflush(stdin);
        confirmacionModificar=getchar();

        if(confirmacionModificar=='s')
        {
            do
            {
                system("cls");
                printf("    ***MODIFICAR***\n\n");
                switch(menuModificar())
                {
                case 1:
                    fflush(stdin);
                    if(!(getNumeroFlotante(&lista[indice].rodado,"Ingrese nuevo rodado de la bicicleta(20/26/27.5/29): ","Error, ",20,29,3)))
                    {
                        printf(" ocurrio un error en la validacion\n");
                    }
                    else
                    {
                        printf("Rodado modificado correctamente\n");
                        system("pause");
                    }
                    break;
                case 2:
                    mostrarTipos(tipos,tamt);
                    fflush(stdin);
                    if(!(getNumero(&lista[indice].idTipo,"Ingrese nuevo id del tipo de bicicleta: ","Error, ",1000,1003,3)))
                    {
                        printf(" ocurrio un error en la validacion\n");
                    }
                    else
                    {
                        printf("id Tipo modificado correctamente\n");
                        system("pause");
                    }
                    break;
                case 3:
                    printf("Estas seguro que deseas volver al menu principal? (s o n)\n");
                    fflush(stdin);
                    salirModificarMenu = getchar();
                    break;
                default:
                    printf("Error, ingrese opcion valida");
                    break;
                }
            }
            while(salirModificarMenu=='n');
            todoOk=1;
        }
    }
    return todoOk;
}

int encontrarBicicletaConId(eBicicleta lista[], int tam,int id)
{
    int indiceDelId=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].id==id&&lista[i].isEmpty==0)
        {
            indiceDelId=i;
            break;
        }
    }
    return indiceDelId;
}

int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[],int tamt, eColores colores[], int tamcol,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int idDeLaBaja=0;
    char confirmacionDarBaja='n';
    int indice;

    system("cls");

    if(lista!=NULL&&tam>0&&tipos!=NULL&&tamt>0&&colores!=NULL&&tamc>0)
    {

    mostrarBicicletas(lista,tam,tipos,tamt,colores,tamcol,clientes,tamc);

    do
    {
        getNumero(&idDeLaBaja,"\nIngrese el id de la bicicleta que quiere dar de baja:","Error",50000,51000,3);
    }
    while(encontrarBicicletaConId(lista,tam,idDeLaBaja)==-1);

    printf("Esta seguro que desea dar de baja esta bicicleta?(s o n)\n");
    fflush(stdin);
    confirmacionDarBaja=getchar();
    indice=encontrarBicicletaConId(lista,tam,idDeLaBaja);

    if(confirmacionDarBaja=='s')
    {
        lista[indice].isEmpty=1;
        todoOk=1;
    }

    }
    return todoOk;

}

int mostrarBicicleta(eBicicleta unaBicicleta,eTipo tipos[],int tamt,eColores colores[], int tamcol,eClientes clientes[],int tamc)
{
    int todoOk=0;
    char descTipo[20];
    char descColor[20];
    char descCliente[20];

    if(tipos!=NULL&&tamt>0&&colores!=NULL&&tamcol>0)
    {
    if(cargarDescripcionTipo(unaBicicleta.idTipo,tipos,tamt,descTipo)&&
       cargarDescripcionColor(unaBicicleta.idColor,colores,tamcol,descColor)&&
       cargarDescripcionCliente(unaBicicleta.idCliente,clientes,tamc,descCliente))

    printf("%10s        %d   %20s   %20s         %20s         %.1f   "
           ,descCliente
           ,unaBicicleta.id
           ,unaBicicleta.marca
           ,descTipo
           ,descColor
           ,unaBicicleta.rodado);
    printf("\n");

    todoOk=1;
    }
    return todoOk;
}

int mostrarBicicletas(eBicicleta lista[], int tam,eTipo tipos[],int tamt,eColores colores[], int tamcol,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int flag=1;

    if(lista!=NULL&&tam>0&&tipos!=NULL&&tamt>0&&colores!=NULL&&tamcol>0)
    {
        ordenarBicicletas(lista,tam);
        system("cls");
        printf("                    ***LISTA DE BICICLETAS***\n\n");
        printf("    Nombre          ID                     Marca                  Tipo                       Color         Rodado\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");


        for(int i=0; i<tam; i++)
        {
            if(lista[i].isEmpty==0)
            {
                if(mostrarBicicleta(lista[i],tipos,tamt,colores,tamcol,clientes,tamc))
                {
                    flag=0;
                }
            }
        }
        if(flag==1)
        {
            printf("\n    No esta disponible mostrar clientes\n\n");
        }
        printf("\n\n");
        todoOk=1;
    }
    return todoOk;
}

int ordenarBicicletas(eBicicleta lista[], int tam)
{
    int todoOk=-1;
    eBicicleta auxBicicleta;

    if(lista!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(lista[i].idTipo>lista[j].idTipo||
                (lista[i].idTipo==lista[j].idTipo&&
                 lista[i].rodado>lista[j].rodado))
                {
                    auxBicicleta=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxBicicleta;
                }
            }
        }

        todoOk=0;
    }
    return todoOk;
}

int buscarBicicleta(eBicicleta lista[], int tam, int id)
{
    int indice=-1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].id==id)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
