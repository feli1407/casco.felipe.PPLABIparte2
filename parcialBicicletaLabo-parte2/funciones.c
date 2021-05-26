#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int menu()
{
    int opcion;
    system("cls");
    printf("     ***BICICLETAS***\n\n");
    printf("1. ALTA BICICLETA\n");
    printf("2. MODIFICAR BICICLETA\n");
    printf("3. BAJA BICICLETA\n");
    printf("4. LISTAR BICICLETA\n");
    printf("5. LISTAR TIPOS\n");
    printf("6. LISTAR COLORES\n");
    printf("7. LISTAR SERVICIOS\n");
    printf("8. ALTA TRABAJO\n");
    printf("9. LISTAR TRABAJOS\n");
    printf("10. INFORMES\n");
    printf("11. SALIR\n");
    fflush(stdin);
    getNumero(&opcion,"\nIngrese opcion: ","Opcion invalida!",1,11,3);
    return opcion;
}

int menuInformes()
{
    int opcionI;
    system("cls");
    printf("***MENU INFORMES***\n");
    printf("1. Mostrar bicicletas del color selecionado por el usuario.\n");
    printf("2. Mostrar bicicletas del tipo selecionado por el usuario.\n");
    printf("3. Mostrar bicicletas con menor rodado.\n");
    printf("4. Mostrar bicicletas separadas por tipo.\n");
    printf("5. Mostrar cantidad de bicicletas de un tipo y color.\n");
    printf("6. Color mas elegido por los clientes.\n");
    printf("7. Trabajos que se le hicieron a una bicicleta.\n");
    printf("8. Suma de los importes de los servicios que se le hicieron a una bicicleta.\n");
    printf("9. Mostrar bicicleta a la que se le realizo el servicio y la fecha.\n");
    printf("10. Mostrar los servicios de una fecha.\n");
    printf("11. Salir.\n");
    fflush(stdin);
    getNumero(&opcionI,"\nIngrese opcion: ","Opcion invalida!",1,11,3);
    return opcionI;
}

int menuModificar()
{
    int opcionM;
    printf("1. Modificar el rodado.\n");
    printf("2. Modificar el tipo.\n");
    printf("3. Volver al menu principal\n");
    fflush(stdin);
    getNumero(&opcionM,"\nIngrese opcion: ","Opcion invalida!",1,3,3);
    return opcionM;
}

int myGets(char* cadena, int longitud)
{
    if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
    {
        fflush(stdin);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
        }
        return 1;
    }
    return 0;
}

int getInt(int* pResultado)
{
    int retorno=0;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==1 && esNumerica(buffer))
        {
            *pResultado = atoi(buffer);
            retorno = 1;
        }
    }
    return retorno;
}

int esNumerica(char* cadena)
{
    int i=0;
    int retorno = 1;
    if(cadena != NULL && strlen(cadena) > 0)
    {
        while(cadena[i] != '\0')
        {
            if(cadena[i] < '0' || cadena[i] > '9' )
            {
                retorno = 0;
                break;
            }
            i++;
        }
    }
    return retorno;
}

int getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt;
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getInt(&bufferInt) == 1)
        {
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *pResultado = bufferInt;
                retorno = 1;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int getString(char cadena[], int tam, char* mensaje, char* mensajeError,  int reintentos)
{
    char bufferChar[tam];
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(myGets(bufferChar,sizeof(bufferChar))==1)
        {
            if(tieneUnicamenteLetrasDelAlfabeto(bufferChar) && strlen(bufferChar) < tam)
            {
                strcpy(cadena,bufferChar);
                retorno = 1;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int tieneUnicamenteLetrasDelAlfabeto(char cadena[])
{
    int i = 0;
    while (cadena[i])
    {
        if (!isalpha(cadena[i]) && cadena[i] != ' ')
        {
            return 0;
        }
        i++;
    }
    return 1;
}

int getFloat(float* pResultado)
{
    int retorno=0;
    char buffer[64];
    if(pResultado != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==1 && esFlotante(buffer))
        {
            *pResultado = atof(buffer);
            retorno = 1;
        }
    }
    return retorno;
}

int getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float
                      maximo, int reintentos)
{
    float bufferFloat;
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getFloat(&bufferFloat) == 1)
        {
            if(bufferFloat >= minimo && bufferFloat <= maximo)
            {
                *pResultado = bufferFloat;
                retorno = 1;
                break;
            }
        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int esFlotante(char* cadena)
{
    int retorno=1;
    int contadorPuntos=0;
    if(cadena != NULL && strlen(cadena) > '0')
    {
        for(int i=0; cadena[i]!='\0'; i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]<'0'|| cadena[i]>'9')
            {
                if(cadena[i]=='.'&&contadorPuntos=='0')
                {
                    contadorPuntos++;
                }
                else
                {
                    retorno=0;
                    break;
                }
            }

        }
    }
    return retorno;
}

int esTelefono(char cadena[])
{
    int i=0;
    int contadorGuiones=0;

    while(cadena[i]!='\0')
    {
        if((cadena[i]!=' ')&&(cadena[i]!='-')&&(cadena[i]<'0' || cadena[i]>'9'))
        {
            return 0;
        }
        if(cadena[i]=='-')
        {
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones==1)//debe tener un guion
    {
        return 1;
    }
    return 0;
}

int getTelefono(char cadena[])
{
    int retorno=0;
    char buffer[64];
    if(cadena != NULL)
    {
        if(myGets(buffer,sizeof(buffer))==1 && esTelefono(buffer))
        {
            strcpy(cadena,buffer);
            retorno = 1;
        }
    }
    return retorno;
}

int pedirTelefono(char cadena[], char* mensaje, char* mensajeError, int reintentos)
{
    char buffer[23];
    int retorno = 0;
    while(reintentos>0)
    {
        reintentos--;
        printf("%s",mensaje);
        if(getTelefono(buffer) == 1)
        {
            strcpy(cadena,buffer);
            retorno = 1;
            break;

        }
        printf("%s",mensajeError);
    }
    return retorno;
}

int pedirSexo(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int retorno=0;
    char buffer;
    if(pResultado!=NULL&&mensaje!=NULL&&mensajeError!=NULL&&reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c",&buffer);
            if(buffer=='m'||buffer=='f')
            {
                *pResultado=buffer;
                retorno=1;
                break;
            }
            printf("%s",mensajeError);
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;
}
