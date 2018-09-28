#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{
    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};
    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);
    }
}

void mostrarUsuario (eUsuario usuario)
{
    if(usuario.estado == 1)
    {
         printf("%s\n",usuario.nombre);
    }

}

void mostrarListaUsuarios(eUsuario* lista, int tam)
{
    int i;
    for (i=0;i<tam;i++)
    {
        mostrarUsuario(lista[i]);
    }
}


int obtenerEspacioLibre(eUsuario lista[],int tam)
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

void altaUs (eUsuario lista[], int i)
{
    printf("ingrese el nombre: \n");
    fflush(stdin);
    gets(lista[i].nombre);

    printf("Ingrese el id: ");
    scanf("%d",&lista[i].idUsuario);

    lista[i].estado = 1;
}
