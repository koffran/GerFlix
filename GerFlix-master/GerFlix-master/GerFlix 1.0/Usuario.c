
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


void mostrarUsuarioConSuSerie(eUsuario* usuarios , int tamUsu, eSerie* series, int tamSer)
{
    int i,j;
    for (i=0; i<tamUsu; i++)
    {
        if (usuarios[i].estado == 1  )
        {
            printf ("\n%s: \n",usuarios[i].nombre);
            for (j=0; j<tamSer;j++)
            {
                if(usuarios[i].idSerie == series[j].idSerie)
                {
                    printf("%8s\n",series[j].nombre);
                }
            }
        }
    }
}

void mostrarSerieConUsuarios (eSerie* series, int tamSer,eUsuario* usuarios, int tamUsu)
{
    int i,j;
    for (i=0; i<tamSer; i++)
    {
        if (series[i].estado == 1)
        {
            printf ("\n%s: \n",series[i].nombre);
            for (j=0; j<tamUsu;j++)
            {
                if(series[i].idSerie == usuarios[j].idSerie)
                {
                    printf("%8s\n",usuarios[j].nombre);
                    }
            }
        }
    }
}
