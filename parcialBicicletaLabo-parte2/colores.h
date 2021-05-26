#ifndef COLORES_H_INCLUDED
#define COLORES_H_INCLUDED

struct
{
    int id;
    char descripcion[20];
} typedef eColores;

#endif // COLORES_H_INCLUDED

/** \brief carga la descripcion del color a una variable auxiliar para mostrarlo
 *
 * \param id int id del color
 * \param colores[] eColores array de colores
 * \param tam int tamaño del array
 * \param descripcion[] char variable donde se va a cargar la descripcion
 * \return int Retorna 1 si pudo cargar la decripcion y 0 si no
 *
 */
int cargarDescripcionColor(int id, eColores colores[],int tam, char descripcion[]);

/** \brief Muestra un solo color
 *
 * \param unColor eColores estructura de un color
 * \return int retorna 1 si pudo mostrarlo y 0 si no
 *
 */
int mostrarColor(eColores unColor);

/** \brief Muestra todos los colores cargados
 *
 * \param colores[] eColores array de colores
 * \param tam int tamaño del array
 * \return int retorna 1 si pudo mostrarlos y 0 si no
 *
 */
int mostrarColores(eColores colores[], int tam);
