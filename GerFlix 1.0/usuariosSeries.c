#include <stdio.h>
#include <stdlib.h>
#include "usuariosSeries.h"
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


