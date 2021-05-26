#include "tipo.h"
#include "colores.h"
#include "cliente.h"

#ifndef BICICLETA_H_INCLUDED
#define BICICLETA_H_INCLUDED

struct
{
    int id;
    int idCliente;
    char marca[20];
    int idTipo;
    int idColor;
    float rodado;
    int isEmpty;
} typedef eBicicleta;

#endif // BICICLETA_H_INCLUDED

/** \brief Recorre con un array todos los campos de bicicleta e inicializa isEmpty en 1
 *
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array
 * \return int Retorna 1 si pudo hacerlo y 0 si no
 *
 */
int inicializarBiciletas(eBicicleta lista[], int tam);

/** \brief Pasa los datos validados de bicicleta a un espacio libre del array de bicicletas
 *
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array
 * \param id int id de la bicicleta
 * \param marca[] char marca de la vicicleta
 * \param idTipo int id del tipo de bicicleta
 * \param idColor int id del color de bicicleta
 * \param rodado float rodado de la bicicleta
 * \return int retorna 1 si puso agregar la nueva bicicleta y 0 si no
 *
 */
int agregarBicicleta(eBicicleta lista[], int tam, int id, char marca[], int idTipo,int idColor, float rodado,int idCliente);

/** \brief Pide los datos para dar de alta una bicicleta y los valida, actualiza el id
 *
 * \param lista[] eBicicleta array de bicicleta
 * \param tam int tamaño del array
 * \param punteroId int* puntero al id de bicicleta
 * \return int retorna 1 si no hubo problemas con el alta y 0 si no pudo
 *
 */
int altaBicicleta(eBicicleta lista[], int tamb,eClientes clientes[],int tamc, int* punteroIdBici, int* punteroIdCliente);

/** \brief Busca el primer lugar de la lista que tenga isEmpty en 1
 *
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array
 * \return int devuelve -1 si no hay lugar libre y si hay el indice del lugar
 *
 */
int buscarLibre(eBicicleta lista[], int tam);

/** \brief compara un id con todas las bicicletas cargadas que no esten dadas de baja
 *         y si encuentra uno igual guarda el indice
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array
 * \param id int id a comparar
 * \return int Retorna el indice del id, y si no esta -1
 *
 */
int encontrarBicicletaConId(eBicicleta lista[], int tam,int id);

/** \brief Pide id de bicicleta al usuario y si existe permite modificar tipo y rodado
 *        (Muestra la lista de bicicletas para mejorar experiencia de usuario)
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamt int tamaño del array tipos
 * \param colores[] eColores array de colores
 * \param tamc int tamaño del array colores
 * \return int Retorna 1 si no hubo problemas y 0 si no se pudo modificar
 *
 */
int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[],int tamt, eColores colores[], int tamcol,eClientes clientes[],int tamc);

/** \brief pide al usuario el id de la bicicleta que quiere dar de baja y si existe cambia el
 *         campo isEmpty a 1. (Muestra la lista de bicicletas para mejorar experiencia de usuario)
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamt int tamaño del array tipos
 * \param colores[] eColores array de colores
 * \param tamc int tamaño del array colores
 * \return int retorna 1 si pudo hacer la baja y 0 si no
 *
 */
int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[],int tamt, eColores colores[], int tamcol,eClientes clientes[],int tamc);

/** \brief Muestra un listado de todas las bicicletas que estan con isEmpty en 0
 *
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array de bicicletas
 * \param tipos[] eTipo array de tipos
 * \param tamt int tamaño del array tipos
 * \param colores[] eColores array de colores
 * \param tamc int tamaño del array colores
 * \return int retorna 1 si se validaron bien los datos y 0 si no
 *
 */
int mostrarBicicletas(eBicicleta lista[], int tam,eTipo tipos[],int tamt,eColores colores[], int tamcol,eClientes clientes[],int tamc);

/** \brief Muestra una sola bicicleta
 *
 * \param unaBicicleta eBicicleta un solo espacio de la estructura bicicleta
 * \param tipos[] eTipo array de tipos
 * \param tamt int tamaño del array tipos
 * \param colores[] eColores array de colores
 * \param tamc int tamaño del array colores
 * \return int retorna 1 si se validaron bien los datos y 0 si no
 *
 */
int mostrarBicicleta(eBicicleta unaBicicleta,eTipo tipos[],int tamt,eColores colores[], int tamcol,eClientes clientes[],int tamc);

/** \brief Ordena las bicicletas por tipo y rodado
 *
 * \param lista[] eBicicleta una estructura de bicicletas
 * \param tam int tamaño del array
 * \return int retorna 1 si pudo ordenarlas y 0 si no
 *
 */
int ordenarBicicletas(eBicicleta lista[], int tam);

/** \brief Busca una bicicleta por el id
 *
 * \param lista[] eBicicleta array de bicicletas
 * \param tam int tamaño del array
 * \param id int id a buscar
 * \return int Retorna el indice si la encontro y -1 si no
 *
 */
int buscarBicicleta(eBicicleta lista[], int tam, int id);
