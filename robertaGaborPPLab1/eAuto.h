#ifndef EAUTO_H_INCLUDED
#define EAUTO_H_INCLUDED
#include "eColor.h"
#include "eMarca.h"

typedef struct{

int idAuto;
char patente[20];
int idMarca;
int idColor;
int modelo;
int isEmpty;

}eAuto;

/** \brief Carga un array de tipo estructura auto en un indice
*
* \param vector de autos
* \param tamaño vector de autos
* \param vector de colores con estructura color
* \param tamaño vector de colores
* \param vector de marcas con estructura marcas
* \param tamaño vector de marcas
* \return 1 si se pudo dar de alta sino 0
 *
 */
int altaAuto (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
/** \brief Se elige si modificar color o modelo de un indice del vector de autos (de un auto)
 *
 * \param autos[] eAuto vector que se carga
 * \param tamAu int tamaño del vector autos
 * \param colores[] eColor vector de colores
 * \param tamCol int tamaño vector de colores
 * \param marcas[] eMarca vector de marcas
 * \param tamMar int tamaño vector de marcas
 * \return int devuelve 1 si se pudo modificar sino 0
 *
 */
int modificarDatosAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
/** \brief Busca el ID de auto en un vector y si lo encuentra devuelve el indice
 *
 * \param id int Id buscado
 * \param autos[] eAuto vector de autos a analizar
 * \param tamAu int tamaño de vector autos
 * \return int devuelve -1 si no lo encontro sino devuelve el indice
 *
 */
int buscarAutoId(int id,eAuto autos[],int tamAu);
/** \brief muestra los datos dde un solo auto(1 indice del vector)
 *
 * \param autos eAuto variable de tipo eAuto
 * \param colores[] eColor vector de colores tipo eColor
 * \param tamCol int tamaño de vector colores
 * \param marcas[] eMarca vector de marcas de tipo eMarcas
 * \param tamMar int tamaño de vector marcas
 * \return void
 *
 */
void mostrarAuto(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
/** \brief Baja logica de un auto, pide patente y si la encuentra convierte el isEmpty en 1
 *
 * \param autos[] eAuto vector autos
 * \param tamAu int tamañod e vector autos
 * \param colores[] eColor vector de color
 * \param tamCol int tamaño de vector color
 * \param marcas[] eMarca vector marca
 * \param tamMar int taaño vector marca
 * \return void
 *
 */
void bajaAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
/** \brief Muestra los datos de todos los autos disponibles con isEmpty en 0
 *
 * \param vector tipo eAuto de autos
 * \param tamaño de vector autos
 * \param vector tipo eColor de colores
 * \param tamaño de vector colores
 * \param vector tipo eMarca de marcas
 * \param tamaño vector marcas
 * \return void
 *
 */
void mostrarAutos (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
/** \brief ordena el vector autos por marca y por patente
 *
 * \param vector autos de estructura eAuto
 * \param tamaño de vector autos
 * \param vector de marcas tipo estructura eMarcas
 * \param tamaño de vector marcas
 * \return
 *
 */
void ordenarAutos (eAuto autos[],int tamAu,eMarca marcas[],int tamMar);
/** \brief Menu del case modificarDatosAuto
 *
 * \param void
 * \return int devuelve el case elegido
 *
 */
int menuDeCambiosAuto(void);
/** \brief pide una patente y bsuca si se encuentra, si la encuentra devuelve el indice
 *
 * \param patente[] char patente buscada
 * \param autos[] eAuto vector tipo struct eAuto a analizar
 * \param tamAu int tamaño de vector auto
 * \return int devuelve -1 si no lo encontro sino el indice
 *
 */
int buscarPatenteAuto(char patente[],eAuto autos[],int tamAu);
/** \brief busca un espacio libre en el array de autos en la celda isEmpty=1
 *
 * \param autos[] eAuto vector autos a analizar
 * \param tamAu int tamaño de vector autos
 * \return int devuelve el indice si encuentra libre, sino -1
 *
 */
int buscarLibre(eAuto autos[],int tamAu);
/** \brief inicializa un array de tipo eAuto en la celda isEmpty en 1
 *
 * \param autos[] eAuto array a inicializar
 * \param tamAu int tamaño del array
 * \return void
 *
 */
void inicializarAutos(eAuto autos[],int tamAu);

#endif // EAUTO_H_INCLUDED
