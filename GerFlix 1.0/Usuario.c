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
         printf("%d---%s\n",usuario.idUsuario,usuario.nombre);
    }

}

void mostrarListaUsuarios(eUsuario* lista, int tam)
{
    int i;
    printf("ID --- NOMBRE\n");
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

int buscarIdUsuario(eUsuario lista[], int id,int tam)
{
    int i,indice = -1;
    for (i=0; i<tam; i++)
    {
        if (id == lista[i].idUsuario)
        {
            indice = i;
        }
    }
    return indice;
}

void bajaUsuario (eUsuario lista[], int i)
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
        printf("\n Usuario elilminado\n\n");
    }
}

void modificarUsuario (eUsuario lista[], int indice)
{
    int auxIdUsuario,auxIdSerie;
    char seguir = 's',auxNombre[50];
    int opcion;
    if (lista[indice].estado == 1)
    {
        while (seguir == 's')
        {
            system("cls");

            printf("DATOS DE LA SERIE SELECCIONADA\n\n\t\tNOMBRE\t\tID USUARIO\t\tID SERIE\tID\n");
            printf("\t\t%s\t\t%d\t\t%d\n",lista[indice].nombre,lista[indice].idUsuario,lista[indice].idSerie);
            printf("Que dato desea modificar? \n1 - Nombre\n2 - ID usuario\n3 - ID serie\n4 - Salir\n");
            scanf("%d",&opcion);

            switch (opcion)
            {
            case 1:
                system("cls");
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets (lista[indice].nombre);
                system("pause");
                break;
            case 2:
                system("cls");
                printf("Ingrese el nuevo ID de usuario: ");
                scanf("%d",&auxIdUsuario);
                lista[indice].idUsuario = auxIdUsuario;
                system("pause");
                break;
            case 3:
                system("cls");
                printf("Ingrese el id de serie: ");
                scanf("%d",&auxIdSerie);
                lista[indice].idSerie = auxIdSerie;
                system("pause");
                break;
            case 4:
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


