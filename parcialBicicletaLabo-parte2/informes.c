#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bicicleta.h"
#include "colores.h"
#include "tipo.h"
#include "funciones.h"
#include "trabajo.h"
#include "servicios.h"

int mostrarBicicletasColor(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int idColor;
    int flag=0;

    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamcol>0&&tipos!=NULL&&tamtip>0&&clientes!=NULL&&tamc>0)
    {
        mostrarColores(colores,tamcol);

        getNumero(&idColor,"\nIngrese el id del color que desea ver: ","Error, ",5000,5004,3);

        system("cls");
        printf("                    ***LISTA DE BICICLETAS***\n\n");
        printf("    Nombre          ID                     Marca                  Tipo                       Color         Rodado\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");


        for(int i=0; i<tamb; i++)
        {
            if(bicicletas[i].isEmpty==0 && bicicletas[i].idColor==idColor)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamtip,colores,tamcol,clientes,tamc);
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("\nNo hay bicicletas de este color ingresadas en el sistema\n");
        }
        system("pause");

        todoOk=1;

    }
    return todoOk;
}

int mostrarBicicletasTipo(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int idTipo;
    int flag=0;

    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamtip>0)
    {
        mostrarTipos(tipos,tamtip);

        getNumero(&idTipo,"\nIngrese el id del tipo que desea ver: ","Error, ",1000,1003,3);

        system("cls");
        printf("                    ***LISTA DE BICICLETAS***\n\n");
        printf("    Nombre          ID                     Marca                  Tipo                       Color         Rodado\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamb; i++)
        {
            if(bicicletas[i].isEmpty==0 && bicicletas[i].idTipo==idTipo)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamtip,colores,tamcol,clientes,tamc);
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("\nNo hay bicicletas de este tipo ingresadas en el sistema\n");
        }
        system("pause");


        todoOk=1;
    }
    return todoOk;
}

int mostrarBicicletasMenorRodado(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int flag=0;
    float rodadoMin=0;

    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamcol>0&&tipos!=NULL&&tamtip>0&&clientes!=NULL&&tamc>0)
    {
        system("cls");
        printf("                    ***LISTA DE BICICLETAS***\n\n");
        printf("    Nombre          ID                     Marca                  Tipo                       Color         Rodado\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamb; i++)
        {
            if(bicicletas[i].isEmpty==0 && (bicicletas[i].rodado<rodadoMin||rodadoMin==0))
            {
                rodadoMin=bicicletas[i].rodado;
            }
        }

        for(int i=0; i<tamb; i++)
        {
            if(bicicletas[i].isEmpty==0 && bicicletas[i].rodado==rodadoMin)
            {
                mostrarBicicleta(bicicletas[i],tipos,tamtip,colores,tamcol,clientes,tamc);
                flag=1;
            }
        }

        if(flag==0)
        {
            printf("\nNo hay bicicletas con este rodado ingresadas en el sistema\n");
        }
        system("pause");
        todoOk=1;
    }
    return todoOk;
}

int mostrarBicicletasPorTipo(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int flag;

    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamcol>0&&tipos!=NULL&&tamtip>0&&clientes!=NULL&&tamc>0)
    {
        system("cls");
        for(int i=0; i<tamtip; i++)
        {
            flag=0;
            printf("***TIPO: %s***\n",tipos[i].descripcion);
            printf("\n    Nombre          ID                     Marca                  Tipo                       Color         Rodado\n");
            printf("-----------------------------------------------------------------------------------------------------------------\n");
            for(int j=0; j<tamb; j++)
            {

                if(tipos[i].id==bicicletas[j].idTipo && bicicletas[j].isEmpty==0)
                {
                    mostrarBicicleta(bicicletas[j],tipos,tamtip,colores,tamcol,clientes,tamc);
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("\nNo hay bicicletas de este tipo\n\n");
            }
            printf("-------------------------------------------------------------------------------------------------------------------\n\n");
        }
        system("pause");
        todoOk=1;
    }
    return todoOk;
}

int cantBicisTipoColor(eBicicleta bicicletas[],int tamb,eColores colores[],int tamc, eTipo tipos[],int tamtip)
{
    int todoOk=0;
    int idColor;
    int idTipo;
    char descColor[10];
    char descTipo[10];
    int contador=0;

    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamtip>0)
    {
        system("cls");
        mostrarColores(colores,tamc);

        getNumero(&idColor,"\nIngrese el id del color: ","Error, ",5000,5004,3);

        system("cls");
        mostrarTipos(tipos,tamtip);

        getNumero(&idTipo,"\nIngrese el id del tipo: ","Error, ",1000,1003,3);

        system("cls");

        for(int i=0; i<tamb; i++)
        {
            if(bicicletas[i].isEmpty==0 && bicicletas[i].idTipo==idTipo && bicicletas[i].idColor==idColor)
            {
                contador++;
            }
        }

        cargarDescripcionColor(idColor,colores,tamc,descColor);
        cargarDescripcionTipo(idTipo,tipos,tamtip,descTipo);
        printf("\nHay %d bicicletas %s de color %s\n\n",contador,descTipo,descColor);
        system("pause");
        todoOk=1;
    }
    return todoOk;
}

int colorMasElegido(eBicicleta bicicletas[],int tamb,eColores colores[],int tamc, eTipo tipos[],int tamtip)
{
    int todoOk=0;
    int contador=0;
    int cantPorColor[tamc];
    int flagMasBicisDeColor=0;
    int masBicisColor=0;

    if(bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamtip>0)
    {
        for(int i=0; i<tamc; i++)
        {
            for(int j=0; j<tamb; j++)
            {
                if(bicicletas[j].isEmpty==0 && bicicletas[j].idColor==colores[i].id)
                {
                    contador++;
                }
            }
            cantPorColor[i]=contador;
            contador=0;
        }

        for(int i=0; i<tamc; i++)
        {
            if(flagMasBicisDeColor==0||cantPorColor[i]>masBicisColor)
            {
                masBicisColor=cantPorColor[i];
                flagMasBicisDeColor=1;
            }
        }

        for(int i=0; i<tamc; i++)
        {
            if(masBicisColor == cantPorColor[i])
            {
                printf("El color mas elegido es %s con %d bicicletas\n",colores[i].descripcion,masBicisColor);

            }
        }
        system("pause");
        todoOk=1;
    }
    return todoOk;
}

int trabajosUnaBicicleta(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int idBicicleta;
    int flag=0;

    if(trabajos!=NULL&&tamtra>0&&servicios!=NULL&&tams>0&&bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamcol>0&&tipos!=NULL&&tamtip>0&&clientes!=NULL&&tamc>0)
    {
        system("cls");
        mostrarBicicletas(bicicletas,tamb,tipos,tamtip,colores,tamcol,clientes,tamc);
        do
        {
            getNumero(&idBicicleta,"Ingrese id de la bicicleta que quiere ver los trabajos: ","Error, ",50000,51000,3);
        }
        while(buscarBicicleta(bicicletas,tamb,idBicicleta)==-1);

        system("cls");

        printf("TRABAJOS DE LA BICICLETA ID: %d\n\n",bicicletas[buscarBicicleta(bicicletas,tamb,idBicicleta)].id);
        printf("  ID Trabajo     ID Bicicleta        Servicio          Fecha\n");
        printf("-------------------------------------------------------------\n");

        for(int i=0; i<tamtra; i++)
        {
            if(trabajos[i].idBicicleta==idBicicleta&&trabajos[i].isEmpty==0)
            {
                mostrarTrabajo(trabajos[i],servicios,tams);
                flag=1;
            }

        }

        if(flag==0)
        {
            printf("Esta bicicleta no tiene ningun trabajo realizado\n");
        }

        printf("\n");

        system("pause");

        todoOk=1;
    }
    return todoOk;
}

int sumaImportesUnaBicicleta(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int idBicicleta;
    int flag=0;
    int importeTotal;

    if(trabajos!=NULL&&tamtra>0&&servicios!=NULL&&tams>0&&bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamcol>0&&tipos!=NULL&&tamtip>0&&clientes!=NULL&&tamc>0)
    {
        system("cls");
        mostrarBicicletas(bicicletas,tamb,tipos,tamtip,colores,tamcol,clientes,tamc);
        do
        {
            getNumero(&idBicicleta,"Ingrese id de la bicicleta que quiere ver los trabajos: ","Error, ",50000,51000,3);
        }
        while(buscarBicicleta(bicicletas,tamb,idBicicleta)==-1);

        for(int i=0; i<tamtra; i++)
        {
            if(trabajos[i].idBicicleta==idBicicleta&&trabajos[i].isEmpty==0)
            {
                for(int j=0; j<tams; j++)
                {
                    if(trabajos[i].idServicio==servicios[j].id)
                    {
                        importeTotal+=servicios[j].precio;
                        flag=1;
                    }
                }

            }

        }

        if(flag==1)
        {
            printf("\nLa bicicleta id %d tiene un total de importe de: $%d\n\n",bicicletas[buscarBicicleta(bicicletas,tamb,idBicicleta)].id,importeTotal);
        }
        else if(flag==0)
        {
            printf("Esta bicicleta no tiene ningun trabajo realizado\n");
        }
        system("pause");
        todoOk=1;
    }
    return todoOk;
}

int servicioYFecha(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc)
{
    int todoOk=0;
    int idServicio;
    char descServicio[10];
    int flag=0;

    if(trabajos!=NULL&&tamtra>0&&servicios!=NULL&&tams>0&&bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamcol>0&&tipos!=NULL&&tamtip>0&&clientes!=NULL&&tamc>0)
    {
        system("cls");
        mostrarServicios(servicios,tams);

        getNumero(&idServicio,"Ingrese id del servicio que quiere ver las bicicletas: ","Error, ",20000,20003,5);

        system("cls");
        cargarDescripcionServicio(idServicio,servicios,tams,descServicio);
        printf("El servicio %s se le realizo a las siguientes bicicletas: \n\n",descServicio);
        printf("   Nombre       ID                   Marca                    Tipo                           Color         Rodado\n");
        printf("------------------------------------------------------------------------------------------------------------------\n");

        for(int i=0; i<tamtra; i++)
        {
            if(trabajos[i].idServicio==idServicio)
            {
                for(int j=0;j<tamb;j++)
                {
                    if(trabajos[i].idBicicleta==bicicletas[j].id)
                    {
                        printf("%02d/%02d/%d\n",trabajos[i].fechaTrabajo.dia,
                       trabajos[i].fechaTrabajo.mes,trabajos[i].fechaTrabajo.anio);
                       mostrarBicicleta(bicicletas[j],tipos,tamtip,colores,tamcol,clientes,tamc);
                       flag=1;
                    }
                }


            }
        }

        if(flag==0)
        {
            printf("No hay bicicletas que se les haya realizado este servicio\n");
        }
        printf("\n\n");
        system("pause");
        todoOk=1;
    }
    return todoOk;

}

int serviciosEnUnaFecha(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamc, eTipo tipos[],int tamtip)
{
    int todoOk=0;
    fechas auxFecha;

    if(trabajos!=NULL&&tamtra>0&&servicios!=NULL&&tams>0&&bicicletas!=NULL&&tamb>0&&colores!=NULL&&tamc>0&&tipos!=NULL&&tamtip>0)
    {
        system("cls");
        printf("Ingrese fecha dd/mm/aaaa: ");
        scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);

        while(!(valFecha(auxFecha.dia,auxFecha.mes,auxFecha.anio)))
        {
            printf("Error, fecha invalida, ingrese fecha dd/mm/aaaa: ");
            scanf("%d/%d/%d",&auxFecha.dia,&auxFecha.mes,&auxFecha.anio);
        }

        printf("Los servicios realizados en esta fecha fueron: \n");
        printf("  ID Trabajo     ID Bicicleta        Servicio          Fecha\n");
        printf("-------------------------------------------------------------\n");

        for(int i=0;i<tamtra;i++)
        {
            if(compararFechas(auxFecha,trabajos[i].fechaTrabajo))
            {
                for(int j=0;j<tams;j++)
                {
                    if(servicios[j].id==trabajos[i].idServicio)
                    {
                        mostrarTrabajo(trabajos[i],servicios,tams);
                    }
                }
            }
        }

        printf("\n\n");
        system("pause");
        todoOk=1;
    }
    return todoOk;
}
