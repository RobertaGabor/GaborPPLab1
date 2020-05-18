#ifndef ECOLOR_H_INCLUDED
#define ECOLOR_H_INCLUDED


typedef struct{

int idColor;
char descripcionColor[20];
}eColor;

void mostrarColor(eColor colores);
void mostrarColores (eColor color[],int tamCol);
int cargarDescripcionColor(char descripcion[],int id,eColor colores[],int tamCol);

#endif // ECOLOR_H_INCLUDED
