#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED

struct
{
    int id;
    char descripcion[25];
    int precio;
} typedef eServicio;

#endif // SERVICIOS_H_INCLUDED

/** \brief Muestra un solo servicio
 *
 * \param unServicio eServicio una estructura de servicios
 * \return int retorna 1 si pudo mostrarla y 0 si no
 *
 */
int mostrarServicio(eServicio unServicio);

/** \brief Muestra todos los servicios hardcodeados
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int tamaño del array
 * \return int retorna 1 si pudo mostrarlos y 0 si no
 *
 */
int mostrarServicios(eServicio servicios[], int tam);

/** \brief Valida que un id se servicio exista
 *
 * \param id int id a validar
 * \param servicios[] eServicio array de servicios
 * \param tam int tamaño del array
 * \return int retorna 1 si existe y 0 si no
 *
 */
int validarIdServicio(int id, eServicio servicios[],int tam);

/** \brief carga la descripcion del servicio a una variable auxiliar para mostrarlo
 *
 * \param id int id del servicio
 * \param servicios[] eServicio array de servicios
 * \param tam int tamaño del array
 * \param descripcion[] char variable donde se va a cargar la descripcion
 * \return int Retorna 1 si pudo cargar la decripcion y 0 si no
 *
 */
int cargarDescripcionServicio(int id, eServicio servicios[],int tam, char descripcion[]);
