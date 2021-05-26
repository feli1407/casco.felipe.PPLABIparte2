#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

struct
{
    int id;
    char descripcion[20];
} typedef eTipo;

#endif // TIPO_H_INCLUDED

/** \brief carga la descripcion del tipo a una variable auxiliar para mostrarlo
 *
 * \param id int id del tipo
 * \param tipos[] eTipo array de tipos
 * \param tam int tamaño del array
 * \param descripcion[] char variable donde se va a cargar la descripcion
 * \return int Retorna 1 si pudo cargar la decripcion y 0 si no
 *
 */
int cargarDescripcionTipo(int id, eTipo tipos[],int tam, char descripcion[]);

/** \brief Muestra un solo tipo
 *
 * \param unTipo eTipo estructura de un tipo
 * \return int retorna 1 si pudo mostrarlo y 0 si no
 *
 */
int mostrarTipo(eTipo unTipo);

/** \brief Muestra todos los tipos cargados
 *
 * \param tipos[] eTipo array de tipos
 * \param tam int tamaño del array
 * \return int retorna 1 si pudo mostrarlos y 0 si no
 *
 */
int mostrarTipos(eTipo tipos[], int tam);
