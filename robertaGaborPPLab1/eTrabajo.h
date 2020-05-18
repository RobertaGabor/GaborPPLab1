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

int altaTrabajo (int id,eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra);
int buscarLibreTrabajo(eTrabajo trabajos[],int tamTra);
void mostrartrabajos (eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamServ);
void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamServ);
void inicializarTrabajos(eTrabajo trabajos[],int tamTra);

#endif // ETRABAJO_H_INCLUDED
