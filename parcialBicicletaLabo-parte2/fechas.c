#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "fechas.h"

int compararFechas(fechas f1,fechas f2)
{
    int esIgual=0;
    if(f1.dia==f2.dia && f1.mes==f2.mes&&f1.anio==f2.anio)
    {
        esIgual=1;
    }
    return esIgual;
}
int valFecha( int dia, int mes, int anio)
{
    int todoOk = 0;

    if( mes >= 1 && mes <= 12 )
    {

        switch( mes )
        {

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if( dia >= 1 && dia <= 31 )
            {
                todoOk = 1;
            };
            break;


        case 4:
        case 6:
        case 9:
        case 11:
            if( dia >= 1 && dia <= 30 )
            {
                todoOk = 1;
            };
            break;


        case 2:
//Si el año es bisiesto +1 día.
            if( (anio%4 == 0)   &&  ( (anio%100 != 0)   ||   (anio%400 == 0) ))
            {
                if( dia >= 1 && dia <= 29 )
                {
                    todoOk = 1;
                };
            }
            else
            {
                if( dia >= 1 && dia <= 28 )
                {
                    todoOk = 1;
                };
            };
            break;

        };

    };

    return todoOk;
};
