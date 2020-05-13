#ifndef ETRABAJO_H_INCLUDED
#define ETRABAJO_H_INCLUDED
typedef struct{

int dia;
int mes;
int anio;

}eFecha;
typedef struct{

int idTrabajo;
int patente;
int idServicio;
eFecha fecha;
int isEmpty;

}eTrabajo;

#endif // ETRABAJO_H_INCLUDED
