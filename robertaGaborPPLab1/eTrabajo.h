#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED


typedef struct{

int dia;
int mes;
int anio;

}eFecha;
typedef struct{

int idTrabajo;
char patente[20];
int idServicio;
eFecha fecha;
int isEmpty;

}eTrabajo;

/** \brief Carga un array de tipo eTrabajo en un indice
 *
 * \param Id autoincremental pasado por referencia desde main, solo se incrementa si se logra dar un trabajo de alta
 * \param vector de tipo eAuto
 * \param tama�o de vector de tipo eAuto
 * \param vector de tipo eColor
 * \param tama�o de vecto Colores
 * \param vector de tipo eMarca
 * \param tama�o de verctor marcas
 * \param vector de tipo eServicio
 * \param tama�o de vector servicios
 * \param vector a cargar eTrabajo
 * \param  tama�o de vector ttrabajos
 * \return devuelve 1 si se pudo dar de alta sino 0
 *
 */
int altaTrabajo (int id,eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra);
/** \brief Analiza un array de tipo eTrabajo y busca el primer indice con isEmpty=1
 *
 * \param trabajos[] eTrabajo vector a analizar
 * \param tamTra int tama�o de vector
 * \return int devuelve -1 si no encontr�, sino devuelve el indice
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[],int tamTra);
/** \brief Muestra una lista de todos los trabajos realizados
 *
 * \param vector de tipo eTrabajo a analizar
 * \param tama�o del vector trabajos
 * \param vector de tipo eServicio
 * \param tama�o de vector servicios
 * \return void
 *
 */
void mostrartrabajos (eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamServ);
/** \brief Muestra los datos de un vectir eTrabajo en un solo indice
 *
 * \param trabajo eTrabajo variable eTrabajo
 * \param servicios[] eServicio vector de tipo eServicio
 * \param tamServ int tama�o de vector servicios
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamServ);
/** \brief Inicializa todo un vector de tipo eTrabajo en la celda isEmpty en 1
 *
 * \param trabajos[] eTrabajo vector eTrabajo a inicializar
 * \param tamTra int tama�o del vector
 * \return void
 *
 */
void inicializarTrabajos(eTrabajo trabajos[],int tamTra);

#endif // ETRABAJO_H_INCLUDED
