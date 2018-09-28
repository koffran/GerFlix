#include <stdio.h>
#include <stdlib.h>
#include "Serie.h"
#include <string.h>


void inicializarSeriesEstado(eSerie series[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        series[i].estado = 0;
    }
}


void inicializarSeriesHardCode(eSerie series[])
{
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};

    int i;

    for(i=0; i<5; i++)
    {
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado = 1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}

void mostrarSerie (eSerie serie)
{
    if(serie.estado == 1)
    {
         printf("%d...%s--%s--Cantidad de temporadas: %d\n",serie.idSerie,serie.nombre,serie.genero,serie.cantidadTemporadas);
    }

}

void mostrarListaSeries(eSerie* lista, int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        mostrarSerie(lista[i]);
    }
}

int obtenerEspacioLibreSerie(eSerie lista[],int tam)
{
    int indice = -1,i;
    for (i=0; i<tam; i++)
    {
        if (lista[i].estado ==0)
        {
            indice = i;
        }
    }
    return indice;
}

void altaSerie (eSerie lista[], int i)
{
    printf("ingrese el nombre: \n");
    fflush(stdin);
    gets(lista[i].nombre);

    printf("ingrese el genero: \n");
    fflush(stdin);
    gets(lista[i].genero);

    printf("Ingrese el id: ");
    scanf("%d",&lista[i].idSerie);

    printf("Ingrese la cantidad de temporadas: ");
    scanf("%d",&lista[i].cantidadTemporadas);

    lista[i].estado = 1;
}
