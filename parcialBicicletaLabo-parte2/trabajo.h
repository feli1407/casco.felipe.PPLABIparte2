#include "funciones.h"
#include "tipo.h"
#include "colores.h"
#include "servicios.h"
#include "bicicleta.h"
#include "fechas.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

struct
{
    int id;
    int idBicicleta;
    int idServicio;
    fechas fechaTrabajo;
    int isEmpty;
} typedef eTrabajos;

#endif // TRABAJO_H_INCLUDED

/** \brief Recorre el array de los trabajos poniendo isEmpty en 1 en todos los trabajos
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tam int tamaño del array
 * \return int Retorna 1 si pudo hacerlo y 0 si no
 *
 */
int inicializarTrabajos(eTrabajos trabajos[], int tam);

/** \brief Busca una estructura de trabajo que este libre(con isEmpty en 1)
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tam int tamaño del array
 * \return int retorna el indice del lugar libre o -1 si no hay
 *
 */
int buscarLibreTrabajo(eTrabajos trabajos[], int tam);

/** \brief muestra al usuario la lista de bicicletas y le pide al usuario ingresar que bicicleta
 *        y que servicio se le va a realizar.(actualiza el id de trabajo)
 * \param trabajos[] eTrabajos array de trabajos
 * \param tamt int tamaño del array de trabajos
 * \param colores[] eColores array de colores
 * \param tamcol int tamaño del array de colores
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array de bicicletas
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array de servicios
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño del array de tipos
 * \param pNextIdTrabajo int* Puntero al id de trabajo
 * \return Retorna 1 si pudo dar de alta el trabajo y 0 si no
 *
 */
int altaTrabajo(eTrabajos trabajos[], int tamt, eColores colores[],int tamcol ,eBicicleta bicicletas[], int tamb,
eServicio servicios[], int tams, eTipo tipos[],int tamtip, int* pNextIdTrabajo,eClientes clientes[],int tamc);

/** \brief Muestra 1 solo trabajo
 *
 * \param unTrabajo eTrabajos estructura de 1 solo trabajo
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array
 * \return int retorna 1 si pudo mostrarlo y 0 si no
 *
 */
int mostrarTrabajo(eTrabajos unTrabajo, eServicio servicios[], int tams);

/** \brief Muestra todos los trabajos
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tamt int tamaño del array de trabajos
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño del array servicios
 * \return int retorna 1 si pudo mostrarlos correctamente y 0 si no
 *
 */
int mostrarTrabajos(eTrabajos trabajos[], int tamt, eServicio servicios[], int tams);
