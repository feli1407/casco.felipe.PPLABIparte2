#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

struct
{
    int id;
    char nombre[20];
    char sexo;
    int isEmpty;
} typedef eClientes;

#endif // CLIENTE_H_INCLUDED

/** \brief Inicializa todos los isEmpty de clientes en 1
 *
 * \param lista[] eClientes array de clientes
 * \param tam int tamaño del array
 * \return int retorna 1 si pudo hacerlo y 0 si no
 *
 */
int inicializarClientes(eClientes lista[], int tam);

/** \brief agrega un cliente con los datos validados al array de clientes
 *
 * \param lista[] eClientes array de clientes
 * \param tam int tamaño del array
 * \param id int id del cliente
 * \param nombre[] char nombre del cliente
 * \param sexo char sexo del cliente
 * \return int retorna -1 si no pudo hacerlo y 0 si pudo
 *
 */
int agregarCliente(eClientes lista[], int tam, int id, char nombre[],char sexo);

int buscarLibreCliente(eClientes lista[], int tam);

int cargarDescripcionCliente(int id, eClientes clientes[],int tam, char descripcion[]);
