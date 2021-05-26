#ifndef HARDCODEO_H_INCLUDED
#define HARDCODEO_H_INCLUDED



#endif // HARDCODEO_H_INCLUDED

/** \brief Hardcodea hasta 10 bicicletas
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tam int tamaño del array
 * \param cant int cantidad de bicicletas a hardcodear
 * \param PIdBicicleta int* puntero al id de bicicletas
 * \return int retorna 1 si pudo hardcodear y 0 si no
 *
 */
int hardcodearBicicletas(eBicicleta bicicletas[],int tam,int cant,int* PIdBicicleta);

/** \brief Hardcodea hasta 20 trabajos
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tam int tamaño del array
 * \param cant int cantidad de trabajos a hardcodear
 * \param pIdTrabajo int* puntero al id de trabajo
 * \return int retorna 1 si pudo hardcodear y 0 si no
 *
 */
int hardcodeoTrabajos(eTrabajos trabajos[],int tam,int cant,int* pIdTrabajo);

/** \brief Hardcodea hasta 10 clientes
 *
 * \param clientes[] eClientes array de clientes
 * \param tam int tamaño del array
 * \param cant int cantidad de clientes a hardcodear
 * \param pIdCliente int* puntero al id cliente
 * \return int retorna 1 si pudo hardcodearlos y 0 si no
 *
 */
int hardcodeoClientes(eClientes clientes[],int tam,int cant,int* pIdCliente);
