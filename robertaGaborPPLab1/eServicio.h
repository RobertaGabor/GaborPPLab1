#ifndef ESERVICIO_H_INCLUDED
#define ESERVICIO_H_INCLUDED


typedef struct{

int idServicio;
char descripcionServicio[25];
float precio;

}eServicio;

void mostrarServicio(eServicio servicios);
void mostrarServicios (eServicio servicios[],int tamServ);
int cargarDescripcionServicio(char descripcion[],int id,eServicio servicio[],int tamSer);

#endif // ESERVICIO_H_INCLUDED
