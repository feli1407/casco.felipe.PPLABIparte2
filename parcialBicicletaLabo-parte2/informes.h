#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

/** \brief Muestra las bicicletas del color seleccionado por el usuario
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int mostrarBicicletasColor(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc);

/** \brief Muestra las bicicletas del tipo seleccionado por el usuario
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int mostrarBicicletasTipo(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc);

/** \brief Muestra las bicicletas con menor rodado ingresadas en el sistema
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int mostrarBicicletasMenorRodado(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc);

/** \brief Muestra las bicicletas separadas por tipo
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int mostrarBicicletasPorTipo(eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc);

/** \brief Muestra las bicicletas que hay de un tipo y color elegido por el usuario
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int cantBicisTipoColor(eBicicleta bicicletas[],int tamb,eColores colores[],int tamc, eTipo tipos[],int tamtip);

/** \brief Muestra cual es el color mas elegido en las bicicletas
 *
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int colorMasElegido(eBicicleta bicicletas[],int tamb,eColores colores[],int tamc, eTipo tipos[],int tamtip);

/** \brief Pide una bicicleta y muestra todos los trabajos que se le realizaron
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tamtra int tamaño de array trabajo
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño array servicios
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int trabajosUnaBicicleta(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc);

/** \brief Pide una bicicleta al usuario y muestra la suma del costo de los servicios
 *         que se le realizaron
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tamtra int tamaño de array trabajo
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño array servicios
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int sumaImportesUnaBicicleta(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc);

/** \brief Pide un servicio y muestra las bicicletas que se le realizo y la fecha
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tamtra int tamaño de array trabajo
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño array servicios
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int servicioYFecha(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamcol, eTipo tipos[],int tamtip,eClientes clientes[],int tamc);

/** \brief Pide una fecha y muestra los servicios realizados en la misma
 *
 * \param trabajos[] eTrabajos array de trabajos
 * \param tamtra int tamaño de array trabajo
 * \param servicios[] eServicio array de servicios
 * \param tams int tamaño array servicios
 * \param bicicletas[] eBicicleta array de bicicletas
 * \param tamb int tamaño del array bicicletas
 * \param colores[] eColores array de colores
 * \param tamc int tamaño de array colores
 * \param tipos[] eTipo array de tipos
 * \param tamtip int tamaño array tipos
 * \return int Retorna 1 si pudo mostrar y 0 si no
 *
 */
int serviciosEnUnaFecha(eTrabajos trabajos[],int tamtra,eServicio servicios[],int tams,eBicicleta bicicletas[],int tamb,eColores colores[],int tamc, eTipo tipos[],int tamtip);
