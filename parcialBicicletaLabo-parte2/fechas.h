#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

//estructura fecha
typedef struct
{
    int dia;
    int mes;
    int anio;

} fechas;



#endif // FECHAS_H_INCLUDED

/** \brief Compara si dos fechas son iguales
 *
 * \param f1 fechas fecha 1 a comparar
 * \param f2 fechas fecha 2 a comparar
 * \return int Retorna 1 si son iguales y 0 si no
 *
 */
int compararFechas(fechas f1,fechas f2);

/** \brief Valida que sea una fecha ingresada existente
 *
 * \param dia int dia a validar
 * \param mes int mes a validar
 * \param anio int anio a validar
 * \return int retorna 1 si es valida y 0 si no
 *
 */
int valFecha(int dia,int mes,int anio );
