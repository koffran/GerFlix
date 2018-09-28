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

int buscarIdSerie(eSerie lista[], int id,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id == lista[i].idSerie)
        {
            indice = i;
        }
    }
    return indice;
}

void bajaSerie (eSerie lista[], int i)
{
    char rta;
    printf("Nombre: %s\n",lista[i].nombre);
    printf("Desea eliminarlo? <S/N>\n");
    fflush(stdin);
    rta = getche();
    rta = tolower(rta);
    if ( rta == 's')
    {
        lista[i].estado = 0;
        printf("\Serie elilminada\n\n");
    }
}


void modificarSerie (eSerie lista[], int indice)
{
    int auxIdSerie, auxCantTemporadas;
    char seguir = 's',auxNombre[50],auxGenero[20];
    int opcion;

    if (lista[indice].estado == 1)
    {
        while (seguir == 's')
        {
            system("cls");

            printf("DATOS DE LA SERIE SELECCIONADA\n\n\t\tTITULO\t\tGENERO\t\tTemporadas\tID\n");
            printf("\t\t%s\t\t%s\t\t\t%d\n",lista[indice].nombre,lista[indice].genero,lista[indice].cantidadTemporadas,lista[indice].idSerie);
            printf("Que dato desea modificar? \n1 - Nombre\n2 - Genero\n3 - Cantidad de temporadas\n4 - ID\n5 - Salir\n");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                system("cls");
                printf("Ingrese el nuevo titulo: ");
                fflush(stdin);
                gets (lista[indice].nombre);
                system("pause");
                break;
            case 2:
                system("cls");
                printf ("Ingrese el nuevo genero: ");
                fflush(stdin);
                gets (lista[indice].genero);
                system("pause");
                break;
            case 3:
                system("cls");
                printf("Ingrese la Cantidad de temporadas: ");
                scanf("%d",&auxCantTemporadas);
                lista[indice].cantidadTemporadas = auxCantTemporadas;
                system("pause");
                break;
            case 4:
                system("cls");
                printf("Ingrese el id: ");
                scanf("%d",&auxIdSerie);
                lista[indice].idSerie = auxIdSerie;
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            }

        }
    }
    else
    {
        printf ("\nNo existe el ID ingresado");
    }
}
