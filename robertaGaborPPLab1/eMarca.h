#ifndef EMARCA_H_INCLUDED
#define EMARCA_H_INCLUDED


typedef struct{

int idMarca;
char descripcionMarca[20];

}eMarca;

int cargarDescripcionMarca(char descripcion[],int id,eMarca marcas[],int tamMar);
void mostrarMarcas (eMarca marca[],int tamMar);
void mostrarMarca(eMarca marcas);

#endif // EMARCA_H_INCLUDED
