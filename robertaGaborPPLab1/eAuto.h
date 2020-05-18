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

int altaAuto (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
int modificarDatosAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
int buscarAutoId(int id,eAuto autos[],int tamAu);
void mostrarAuto(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
void bajaAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
void mostrarAutos (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
void ordenarAutos (eAuto autos[],int tamAu,eMarca marcas[],int tamMar);
int menuDeCambiosAuto(void);
int buscarPatenteAuto(char patente[],eAuto autos[],int tamAu);
int buscarLibre(eAuto autos[],int tamAu);
void inicializarAutos(eAuto autos[],int tamAu);

#endif // EAUTO_H_INCLUDED
