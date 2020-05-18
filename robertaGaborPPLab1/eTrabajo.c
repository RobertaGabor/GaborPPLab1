#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMSERVICIOS 4
#define TAMCOLORES 5
#define TAMSMARCAS 5
#define TAMAUTOS 1000
#define TAMTRABAJOS 1000
#include "validaciones.h"
#include "eAuto.h"
#include "eColor.h"
#include "eMarca.h"
#include "eServicio.h"
#include "eTrabajo.h"

void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamServ)
{
    char descripcion[25];
    cargarDescripcionServicio(descripcion,trabajo.idServicio,servicios,tamServ);
    printf("\n%d    %10s    %d/%d/%d    %10s\n",trabajo.idTrabajo,trabajo.patente,trabajo.fecha,descripcion);
}

void mostrartrabajos (eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamServ)
{
    printf("**********Listado de Trabajos*********\n");
    printf(" ID        PATENTE    FECHA      SERVICIO\n");
    for(int i=0;i<tamTra;i++)
    {
        if(trabajos[i].isEmpty==0)
        {
            mostrarTrabajo(trabajos[i],servicios,tamServ);
        }

    }
}

int altaTrabajo (int id,eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra)
{
    int indice=buscarLibreTrabajo(trabajo,tamTra);
    int retorno=0;

    eTrabajo auxiliar;

    system("cls");
    printf("*****Alta de Trabajo*****\n");
    if(indice==-1)
    {
        printf("No hay lugar para agregar otro trabajo\n");
    }
    else
    {
        printf("*******Autos disponible*********\n\n");
        mostrarAutos(autos,tamAu,colores,tamCol,marcas,tamMar);
            if(getPatente(auxiliar.patente,20,"\nIngrese patente del auto: ","Error ingrese una cadena valida",1))
            {
                if(buscarPatenteAuto(auxiliar.patente,autos,tamAu)!=-1)
                {
                    mostrarServicios(servicio,tamServ);
                    if(getInt(&auxiliar.idServicio,"Ingrese ID del servicio","Error debe ser de 20000 a 20003",20000,20003,1))
                    {
                        printf("Ingrese fecha de ingreso dd/mm/aaa: ");
                        scanf("%d/%d/%d",&auxiliar.fecha.dia,&auxiliar.fecha.mes,&auxiliar.fecha.anio);

                        retorno=1;
                        auxiliar.isEmpty=0;
                        auxiliar.idTrabajo=id;
                        trabajo[indice]=auxiliar;

                    }
                }

            }
    }
    return retorno;


}


int buscarLibreTrabajo(eTrabajo trabajos[],int tamTra)
{
    int encontrado=-1;
    for(int i=0;i<tamTra;i++)
    {
        if(trabajos[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}
void inicializarTrabajos(eTrabajo trabajos[],int tamTra)
{
    for(int i=0;i<tamTra;i++)
    {
      trabajos[i].isEmpty=1;
    }
}
