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

void inicializarTrabajos(eTrabajo trabajos[],int tamTra);
void inicializarAutos(eAuto autos[],int tamAu);
int altaAuto (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
int menu(void);
int buscarLibre(eAuto autos[],int tamAu);
void mostrarMarca(eMarca marcas);
void mostrarColor(eColor colores);
void mostrarColores (eColor color[],int tamCol);
void mostrarMarcas (eMarca marca[],int tamMar);
int modificarDatosAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
int menuDeCambiosAuto(void);
int buscarAutoId(int id,eAuto autos[],int tamAu);
void mostrarAuto(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
int cargarDescripcionColor(char descripcion[],int id,eColor colores[],int tamCol);
int cargarDescripcionMarca(char descripcion[],int id,eMarca marcas[],int tamMar);
void bajaAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
void mostrarAutos (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar);
void ordenarAutos (eAuto autos[],int tamAu,eMarca marcas[],int tamMar);
int buscarPatenteAuto(char patente[],eAuto autos[],int tamAu);
void mostrarServicio(eServicio servicios);
void mostrarServicios (eServicio servicios[],int tamServ);
int cargarDescripcionServicio(char descripcion[],int id,eServicio servicio[],int tamSer);
int altaTrabajo (int id,eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar,eServicio servicio[],int tamServ,eTrabajo trabajo[], int tamTra);
int buscarLibreTrabajo(eTrabajo trabajos[],int tamTra);

int main()
{
    eServicio servicios[TAMSERVICIOS]={{20000,"Lavado",250},{20001,"Pulido",300},{20002,"Encerado",400},{20003,"Completo",600}};
    eMarca marcas[TAMSMARCAS]={{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
    eColor colores[TAMCOLORES]={{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
    eAuto autos[TAMAUTOS];
    eTrabajo trabajos[TAMTRABAJOS];

    char seguir='s';
    int opcionMenuMain;
    int proximoIdTrabajo=10;
    int flag=0;

    inicializarAutos(autos,TAMAUTOS);
    inicializarTrabajos(trabajos,TAMTRABAJOS);


    do
    {
        opcionMenuMain=menu();
        switch(opcionMenuMain)
        {
        case 1:
            if(altaAuto(autos,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS))
            {
                printf("\n****Dado de alta exitosamente\n");
                flag=1;
            }
            else
            {
                printf("\n****No se pudo dar de alta****\n");
            }
            break;
        case 2:
            if(flag==1)
            {
                modificarDatosAuto(autos,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS);
            }
            else
            {
                printf("Primero ingrese al menos un auto\n");
            }


            break;
        case 3:
            if(flag==1)
            {
               bajaAuto(autos,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS);
            }
            else
            {
                printf("Primero ingrese al menos un auto\n");
            }
            break;
        case 4:
            if(flag==1)
            {
                    ordenarAutos(autos,TAMAUTOS,marcas,TAMSMARCAS);
                    mostrarAutos(autos,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS);

            }
            else
            {
                printf("Primero ingrese al menos un auto\n");
            }

            break;
        case 5:
            mostrarMarcas(marcas,TAMSMARCAS);
            break;
        case 6:
            mostrarColores(colores,TAMCOLORES);
            break;
        case 7:
            mostrarServicios(servicios,TAMSERVICIOS);
            break;
        case 8:
            if(flag==1&&altaTrabajo(proximoIdTrabajo,autos,TAMAUTOS,colores,TAMCOLORES,marcas,TAMSMARCAS,servicios,TAMSERVICIOS,trabajos,TAMTRABAJOS))
            {
                printf("\n****Dado de alta exitosamente\n");
                proximoIdTrabajo++;
                flag=2;
            }
            else
            {
                printf("\n****No se pudo dar de alta****\n");
            }
            break;
        case 9:
            if(flag==2)
            {

            }
            break;
        case 0:
            seguir='n';
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        system("pause");
    }while(seguir=='s');

    return 0;

}

int menu(void)
{

    int opcion;
    system("cls");
    printf("********Menu de opciones**********\n");

    printf("1-Alta de auto\n");
    printf("2-Modificar Auto\n");
    printf("3-Baja de auto\n");
    printf("4-Listar autos\n");
    printf("5-Listar marcas\n");
    printf("6-Listar colores\n");
    printf("7-Listar servicios\n");
    printf("8-Alta trabajo\n");
    printf("9-Listar trabajos\n");
    printf("0-salir\n");
    printf("Ingrese la opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

void inicializarTrabajos(eTrabajo trabajos[],int tamTra)
{
    for(int i=0;i<tamTra;i++)
    {
      trabajos[i].isEmpty=1;
    }
}

void inicializarAutos(eAuto autos[],int tamAu)
{
    for(int i=0;i<tamAu;i++)
    {
      autos[i].isEmpty=1;
    }
}

int altaAuto (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar)
{
    int indice=buscarLibre(autos,tamAu);

    int retorno=0;

    eAuto auxiliar;

    system("cls");
    printf("*****Alta de Auto*****\n");
    if(indice==-1)
    {
        printf("No hay lugar para agregar otro auto\n");
    }
    else
    {
            if(getInt(&auxiliar.idAuto,"Ingrese ID(de 0 a 10000): ","Error",0,10000,1)
               &&getString(auxiliar.patente,20,"Ingrese patente: ","Error",1)
               &&getInt(&auxiliar.modelo,"Ingrese anio de fabricacion: ","Error",1000,2020,1))
            {
                {
                    mostrarColores(colores,tamCol);
                    if(getInt(&auxiliar.idColor,"Ingrese color: ","Error. debe ser numerico",5000,5004,1))
                    {   mostrarMarcas(marcas,tamMar);
                        if(getInt(&auxiliar.idMarca,"Ingrese marca: ","Error. debe ser numerico",1000,1004,1))
                        {
                            auxiliar.isEmpty=0;
                            autos[indice]=auxiliar;
                            retorno=1;
                        }

                    }
                }
            }
    }
    return retorno;


}

int buscarLibre(eAuto autos[],int tamAu)
{
    int encontrado=-1;
    for(int i=0;i<tamAu;i++)
    {
        if(autos[i].isEmpty==1)
        {
            encontrado=i;
            break;
        }
    }

    return encontrado;
}

void mostrarMarca(eMarca marcas)
{
    printf("\n%d    %10s\n",marcas.idMarca,marcas.descripcionMarca);

}



void mostrarColor(eColor colores)
{
    printf("\n%d    %10s\n",colores.idColor,colores.descripcionColor);
}

void mostrarColores (eColor color[],int tamCol)
{
    printf("**********Listado de Colores*********\n");
    printf(" ID         COLOR\n");
    for(int i=0;i<tamCol;i++)
    {
            mostrarColor(color[i]);
    }
}

void mostrarMarcas (eMarca marca[],int tamMar)
{
    printf("**********Listado de Marcas*********\n");
    printf(" ID         MARCA\n");
    for(int i=0;i<tamMar;i++)
    {
            mostrarMarca(marca[i]);
    }
}

int modificarDatosAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar)
{
    int id;
    int retorno=0;

    int indice;
    int opcionCambio;
    int flag;

    eAuto auxiliar;

    system("cls");
    if(autos!=NULL&&tamAu>0)
    {
        retorno=1;
        printf("\n*****Modificar datos de un auto*****\n");

        if(getInt(&id,"\nIngrese ID del auto: ","Error. Ingrese ID(de 0 a 10000): ",0,10000,0))
        {
            indice=buscarAutoId(id,autos,tamAu);
            if(indice==-1)
            {
                printf("\n*****No se encontro este ID en la base de datos*****\n\n");
            }
            else
            {
            	flag=0;

                do
                {

                    system("cls");
                    printf("*****Auto seleccionado*****\n");
                    printf("ID   COLOR   MARCA   MODELO   PATENTE\n\n");
                    mostrarAuto(autos[indice],colores,tamCol,marcas,tamMar);

                    printf("\n\n");
                    system("pause");
                    system("cls");

                    opcionCambio=menuDeCambiosAuto();

                    switch(opcionCambio)
                    {
                    case 1:
                        mostrarColores(colores,tamCol);
                        if(getInt(&auxiliar.idColor,"Ingrese color: ","Error. debe ser numerico",5000,5004,1))
                        {
                            autos[indice].idColor=auxiliar.idColor;
                            flag=1;
                        }
                        break;
                    case 2:
                        if(getInt(&auxiliar.modelo,"Ingrese anio de fabricacion: ","Error",1000,2020,1))
                        {
                            autos[indice].modelo=auxiliar.modelo;
                        }
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n*****Error. Ingrese una opcion valida*****\n\n");
                        system("pause");
                        break;
                    }

                    system("cls");
                }while(opcionCambio!=3);

                if(flag==1)
                {
                    printf("\n******Los cambios se han cargado con exito!!!****\n");
                    system("pause");
                }
            }
        }
    }
    return retorno;
}

int menuDeCambiosAuto(void)
{
    int opcion;
    printf("******Eleccion de dato a modificar*******\n");
    printf("1-Color\n");
    printf("2-Modelo\n");
    printf("3-Salir\n");

    printf("\nQue dato desea cambiar?: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

int buscarAutoId(int id,eAuto autos[],int tamAu)
{
    int indice=-1;
    for(int i=0;i<tamAu;i++)
    {
        if(autos[i].idAuto==id&&autos[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void mostrarAuto(eAuto autos,eColor colores[],int tamCol,eMarca marcas[],int tamMar)
{
    char marca[20];
    char color[20];
    cargarDescripcionColor(color,autos.idColor,colores,tamCol);
    cargarDescripcionMarca(marca,autos.idMarca,marcas,tamMar);

    printf("\n%d    %10s   %10s   %d   %10s\n\n",autos.idAuto,autos.idColor,autos.idMarca,autos.modelo,autos.patente);
}

int cargarDescripcionColor(char descripcion[],int id,eColor colores[],int tamCol)
{
    int retorno=0;

    for(int i=0;i<tamCol;i++)
    {
        if(colores[i].idColor==id)
        {
            strcpy(descripcion,colores[i].descripcionColor);
            retorno=1;
        }
    }

    return retorno;
}

int cargarDescripcionMarca(char descripcion[],int id,eMarca marcas[],int tamMar)
{
    int retorno=0;

    for(int i=0;i<tamMar;i++)
    {
        if(marcas[i].idMarca==id)
        {
            strcpy(descripcion,marcas[i].descripcionMarca);
            retorno=1;
        }
    }

    return retorno;
}

void bajaAuto(eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar)
{
    int indiceID;
    char patente[10];
    char confirmacion='s';

    system("cls");
    printf("*********Baja de Auto********\n");

    if(getString(patente,10,"Ingrese patente: ","Error",1))
    {
        indiceID=buscarPatenteAuto(patente,autos,tamAu);
        if(indiceID==-1)
        {
            printf("No se encontro la patente o está dado de baja\n");
        }
        else
        {
            printf("ID   COLOR   MARCA   MODELO   PATENTE\n\n");
            mostrarAuto(autos[indiceID],colores,tamCol,marcas,tamMar);
            printf("\n\nDesea comfirmar baja?: \n");
            printf("s - para confirmar\n");
            fflush(stdin);
            scanf("%c",&confirmacion);

            if(confirmacion=='s')
            {
                autos[indiceID].isEmpty=1;
                printf("\n\n****Removido exitosamente***\n");
            }
            else
            {
                printf("\nOperacion cancelada\n");
            }
        }
    }

}

void mostrarAutos (eAuto autos[],int tamAu,eColor colores[],int tamCol,eMarca marcas[],int tamMar)
{
    printf("**********Listado de Autos*********\n");
    printf("ID   COLOR   MARCA   MODELO   PATENTE\n");
    for(int i=0;i<tamAu;i++)
    {
        if(autos[i].isEmpty==0)
        {
             mostrarAuto(autos[i],colores,tamCol,marcas,tamMar);
        }

    }
}

void ordenarAutos (eAuto autos[],int tamAu,eMarca marcas[],int tamMar)
{
    eAuto auxiliar;
    char marcaI[20];
    char marcaJ[20];

    for(int i=0;i<tamAu-1;i++)
    {
        cargarDescripcionMarca(marcaI,autos[i].idMarca,marcas,tamMar);
        for(int j=i+1;j<tamAu;j++)
        {
            cargarDescripcionMarca(marcaJ,autos[j].idMarca,marcas,tamMar);
            if(strcmp(marcaI,marcaJ)<0)
            {
                auxiliar=autos[i];
                autos[i]=autos[j];
                autos[j]=auxiliar;
            }
            else
            {
                 if((strcmp(marcaI,marcaJ)==0)&&(strcmp(auxiliar[i].patente,auxiliar[j].patente)<0))
                {
                    auxiliar=autos[i];
                    autos[i]=autos[j];
                    autos[j]=auxiliar;
                }
            }
        }
    }
}

int buscarPatenteAuto(char patente[],eAuto autos[],int tamAu)
{
    int indice=-1;
    for(int i=0;i<tamAu;i++)
    {
        if((strcmp(autos[i].patente,patente)==0)&&autos[i].isEmpty==0)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void mostrarServicio(eServicio servicios)
{
    printf("\n%d    %10s   %2.f\n",servicios.idServicio,servicios,servicios.precio);
}

void mostrarServicios (eServicio servicios[],int tamServ)
{
    printf("**********Listado de Servicios*********\n");
    printf(" ID         SERVICIO   PRECIO\n");
    for(int i=0;i<tamServ;i++)
    {
            mostrarServicio(servicios[i]);
    }
}

void mostrarTrabajo(eTrabajo trabajo,eServicio servicios[],int tamServ)
{
    char descripcion[25];
    cargarDescripcionServicio(descripcion,trabajo.idServicio,servicios,tamServ);
    printf("\n%d    %10s    %d/%d/%d    %10s\n",trabajo.idTrabajo,trabajo.patente,trabajo.fecha,descripcion);
}

void mostrartrabajos (eTrabajo trabajos[],int tamTra,eServicio servicios[],int tamServ)
{
    printf("**********Listado de Trabajos*********\n");
    printf(" ID        PATENTE    FECHA    SERVICIO\n");
    for(int i=0;i<tamTra;i++)
    {
            mostrarTrabajo(trabajos[i],servicios,tamServ);
    }
}

int cargarDescripcionServicio(char descripcion[],int id,eServicio servicio[],int tamSer)
{
    int retorno=0;

    for(int i=0;i<tamSer;i++)
    {
        if(servicio[i].idServicio==id)
        {
            strcpy(descripcion,servicio[i].descripcionServicio);
            retorno=1;
        }
    }

    return retorno;
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
        printf("*******Autos disponible*********\n");
        mostrarAutos(autos,tamAu,colores,tamCol,marcas,tamMar);
            if(getString(auxiliar.patente,20,"\nIngrese patente del auto: ","Error",1))
            {
                if(buscarPatenteAuto(auxiliar.patente,autos,tamAu))
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
