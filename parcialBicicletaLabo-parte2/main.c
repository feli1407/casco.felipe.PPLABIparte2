#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "informes.h"
#include "hardcodeo.h"
#include "cliente.h"
#define TAMT 4
#define TAMCOL 5
#define TAMS 4
#define TAMBICI 1000
#define TAMCLIENTES 1000
#define TAMTRA 1000


int main()
{

    int idBicicleta=50000;
    int idTrabajo=10000;
    int idCliente=100;
    int flagAlta=0;//flag para validar si se dio de alta algun cliente
    char salirInformes='n';//Confirmacion para salir del menu informes
    char salir='n';//Confirmacion para salir del programa

    //hardcodeo tipo
    eTipo tipos[TAMT]=
    {
        {1000,"Rutera"},
        {1001,"Carrera"},
        {1002,"Mountain"},
        {1003,"BMX"}
    };

    //hardcodeo colores
    eColores colores[TAMCOL]=
    {
        {5000,"Gris"},
        {5001,"Negro"},
        {5002,"Blanco"},
        {5003,"Azul"},
        {5004,"Rojo"}
    };

    //hardcodeo Servicios
    eServicio servicios[TAMS]=
    {
        {20000,"Limpieza",250},
        {20001,"Parche",300},
        {20002,"Centrado",400},
        {20003,"Cadena",350}
    };

    eBicicleta bicicletas[TAMBICI];
    if(!(inicializarBiciletas(bicicletas,TAMBICI)))
    {
        printf("Ocurrio un error al inicializar bicicletas\n");
    }

    eTrabajos trabajos[TAMTRA];
    if(!(inicializarTrabajos(trabajos,TAMTRA)))
    {
        printf("Ocurrio un error al inicializar trabajos\n");
    }

    eClientes clientes[TAMCLIENTES];
    if(!(inicializarClientes(clientes,TAMCLIENTES)))
    {
        printf("Ocurrio un error al inicializar clientes\n");
    }

    hardcodearBicicletas(bicicletas,TAMBICI,10,&idBicicleta);
    hardcodeoTrabajos(trabajos,TAMTRA,20,&idTrabajo);
    hardcodeoClientes(clientes,TAMCLIENTES,10,&idCliente);

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            system("cls");
            printf("ALTA BICICLETA\n");
            if(altaBicicleta(bicicletas,TAMBICI,clientes,TAMCLIENTES,&idBicicleta,&idCliente))
            {
                flagAlta = 1;
            }
            else
            {
                printf("Ocurrio un problema con el alta\n");
            }
            break;
        case 2:
            if(flagAlta==1)
            {
                system("cls");
                printf("MODIFICAR BICICLETA\n");
                if(!(modificarBicicleta(bicicletas,TAMBICI,tipos,TAMT,colores,TAMCOL,clientes,TAMCLIENTES)))
                {
                    printf("Ocurrio un error al modificar al cliente\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta una bicicleta\n");
                system("pause");
            }
            break;
        case 3:
            if(flagAlta==1)
            {
                system("cls");
                printf("BAJA BICICLETA\n");
                if(!(bajaBicicleta(bicicletas,TAMBICI,tipos,TAMT,colores,TAMCOL,clientes,TAMCLIENTES)))
                {
                    printf("Hubo un error al dar de baja la bicicleta\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta una bicicleta\n");
                system("pause");
            }
            break;
        case 4:
            if(flagAlta==1)
            {
                system("cls");
                printf("LISTAR BICICLETA\n");
                if(!(mostrarBicicletas(bicicletas,TAMBICI,tipos,TAMT,colores,TAMCOL,clientes,TAMCLIENTES)))
                {
                    printf("Ocurrio un error al mostrar las bicicletas\n");
                }
                system("pause");
            }
            else
            {
                printf("Primero debe dar de alta una bicicleta\n");
                system("pause");
            }
            break;
        case 5:
            system("cls");
            printf("LISTAR TIPOS\n");
            if(!(mostrarTipos(tipos,TAMT)))
            {
                printf("Ocurrio un error al mostrar los tipos\n");
            }
            system("pause");
            break;
        case 6:
            printf("LISTAR COLORES\n");
            if(!(mostrarColores(colores,TAMCOL)))
            {
                printf("Ocurrio un error al mostrar los colores\n");
            }
            system("pause");
            break;
        case 7:
            printf("LISTAR SERVICIOS\n");
            if(!(mostrarServicios(servicios,TAMS)))
            {
                printf("Ocurrio un error al mostrar los servicios\n");
            }
            system("pause");
            break;
        case 8:
            if(flagAlta==1)
            {
                printf("ALTA TRABAJO\n");
                if(!(altaTrabajo(trabajos,TAMTRA,colores,TAMCOL,bicicletas,TAMBICI,servicios,TAMS,tipos,TAMT,&idTrabajo,clientes,TAMCLIENTES)))
                {
                    printf("Ocurrio un error al dar de alta el trabajo\n");
                }
            }
            else
            {
                printf("Primero debe dar de alta una bicicleta\n");
                system("pause");
            }

            break;
        case 9:
            printf("LISTAR TRABAJOS\n");
            if(!(mostrarTrabajos(trabajos,TAMTRA,servicios,TAMS)))
            {
                printf("Ocurrio un error al mostrar trabajos\n");
            }
            break;
        case 10:
            if(flagAlta==1)
            {
                do
                {
                    switch(menuInformes())
                    {
                    case 1:
                        if(!(mostrarBicicletasColor(bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT,clientes,TAMCLIENTES)))
                        {
                            printf("Ocurrio un error al mostrar bicicletas por color\n");
                        }
                        break;
                    case 2:
                        if(!(mostrarBicicletasTipo(bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT,clientes,TAMCLIENTES)))
                        {
                            printf("Ocurrio un error al mostrar bicicletas por tipo\n");
                        }
                        break;
                    case 3:
                        if(!(mostrarBicicletasMenorRodado(bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT,clientes,TAMCLIENTES)))
                        {
                            printf("Ocurrio un error al mostrar bicicletas de menor rodado\n");
                        }
                        break;
                    case 4:
                        if(!(mostrarBicicletasPorTipo(bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT,clientes,TAMCLIENTES)))
                        {
                            printf("Ocurrio un error al mostrar bicicletas por tipo\n");
                        }
                        break;
                    case 5:
                        if(!(cantBicisTipoColor(bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT)))
                        {
                            printf("Ocurrio un error al mostrar cantidad de bicis por tipo y color\n");
                        }
                        break;
                    case 6:
                        if(!(colorMasElegido(bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT)))
                        {
                            printf("Ocurrio un error al mostrar el color mas elegido\n");
                        }
                        break;
                    case 7:
                        if(!(trabajosUnaBicicleta(trabajos,TAMTRA,servicios,TAMS,bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT,clientes,TAMCLIENTES)))
                        {
                            printf("Ocurrio un error al mostrar los trabajos de una bicicleta\n");
                        }
                        break;
                    case 8:
                        if(!(sumaImportesUnaBicicleta(trabajos,TAMTRA,servicios,TAMS,bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT,clientes,TAMCLIENTES)))
                        {
                            printf("Ocurrio un error al mostrar los trabajos de una bicicleta\n");
                        }
                        break;
                    case 9:
                        if(!(servicioYFecha(trabajos,TAMTRA,servicios,TAMS,bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT,clientes,TAMCLIENTES)))
                        {
                            printf("Ocurrio un error al mostrar las bicicletas por servicio\n");
                        }
                        break;
                    case 10:
                        if(!(serviciosEnUnaFecha(trabajos,TAMTRA,servicios,TAMS,bicicletas,TAMBICI,colores,TAMCOL,tipos,TAMT)))
                        {
                            printf("Ocurrio un error al mostrar las bicicletas por servicio\n");
                        }
                        break;
                    case 11:
                        printf("SALIR\n");
                        printf("Estas seguro que deseas salir? (s o n)\n");
                        fflush(stdin);
                        salirInformes = getchar();
                        break;
                    }
                }
                while(salirInformes=='n');
                salirInformes='n';
            }
            else
            {
                printf("Primero debe dar de alta una bicicleta\n");
                system("pause");
            }

            break;
        case 11:
            printf("SALIR\n");
            printf("Estas seguro que deseas salir? (s o n)\n");
            fflush(stdin);
            salir = getchar();
            break;
        }

    }
    while(salir=='n');
    return 0;

}
