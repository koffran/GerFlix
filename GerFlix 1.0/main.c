#include <stdio.h>
#include <stdlib.h>
#include "usuariosSeries.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

int main()
{
    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    char rta = 's';
    int opcion,aux,aux2;

    while(rta=='s')
    {
        /*  1. Mostrar el listado de series
            2. Mostrar el listado de usuarios
            3. Mostrar el listado de Usuarios con el nombre de la serie que ve
            4. Mostrar por cada serie, el nombre de los usuarios que la ven.
        */
        system("cls");
        printf("1- Mostrar series\n");
        printf("2- Mostrar usuarios\n");
        printf("3- Mostrar el listado de usuarios con el nombre de la serie que ve\n");
        printf("4- Mostrar por cada serie el nombre de los usuarios que la ven\n\n");
        printf("5- Alta Serie\n");
        printf("6- Baja Serie\n");
        printf("7- Modificar Serie\n");
        printf("8- Alta Usuario\n");
        printf("9- Baja Usuario\n");
        printf("10- Modificar Usuario\n");
        printf("11-Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                mostrarListaSeries(listaDeSeries,TAMSERIE);
                system("pause");
                break;
            case 2:
                system("cls");
                mostrarListaUsuarios(listaDeUsuarios,TAMUSUARIO);
                system("pause");
                break;
            case 3:
                system("cls");
                mostrarUsuarioConSuSerie(listaDeUsuarios,TAMUSUARIO,listaDeSeries,TAMSERIE);
                system("pause");
                break;
            case 4:
                system("cls");
                mostrarSerieConUsuarios (listaDeSeries,TAMSERIE,listaDeUsuarios,TAMUSUARIO);
                system("pause");
                break;
            case 5:
                system("cls");

                aux = obtenerEspacioLibreSerie(listaDeSeries,TAMSERIE);
                if (aux== -1)
                {
                    printf("No hay espacio disponible");
                }
                else
                {
                    altaSerie(listaDeSeries,aux);
                }
                system("pause");
                break;
            case 6:
                system("cls");

                mostrarListaSeries(listaDeSeries,TAMSERIE);
                printf("\nIngrese el ID de la serie que quiere eliminar: ");
                scanf("%d",&aux);

                aux2 = buscarIdSerie(listaDeSeries,aux,TAMSERIE);
                if (aux2 == -1)
                {
                    printf("No se encontro el DNI ingresado\n");
                }
                else
                {
                    bajaSerie(listaDeSeries,aux2);
                }

                system("pause");
                break;
            case 7:
                system("cls");

                mostrarListaSeries(listaDeSeries,TAMSERIE);
                printf("\nIngrese el ID de la serie que quiere modificar: ");
                scanf("%d",&aux);

                aux2 = buscarIdSerie(listaDeSeries,aux,TAMSERIE);

                modificarSerie (listaDeSeries, aux2);
                system("pause");
                break;
            case 8:
                system("cls");

                 aux = obtenerEspacioLibre(listaDeUsuarios,TAMUSUARIO);

                if (aux== -1)
                {
                    printf("No hay espacio disponible");
                }
                else
                {
                    altaUs(listaDeUsuarios,aux);
                    printf("Ingrese la Serie que ve: \n");
                    mostrarListaSeries(listaDeSeries,TAMSERIE);
                    scanf("%d",&listaDeUsuarios[aux].idSerie);
                }
                system("pause");
                break;
            case 9:
                system("cls");

                mostrarListaUsuarios(listaDeUsuarios,TAMUSUARIO);
                printf("\nIngrese el ID del usuario que quiere eliminar: ");
                scanf("%d",&aux);

                aux2 = buscarIdUsuario(listaDeUsuarios,aux,TAMUSUARIO);
                if (aux2 == -1)
                {
                    printf("No se encontro el DNI ingresado\n");
                }
                else
                {
                    bajaUsuario(listaDeUsuarios,aux2);
                }

                system("pause");
                break;
            case 10:
                system("cls");

                mostrarListaUsuarios(listaDeUsuarios,TAMUSUARIO);
                printf("\nIngrese el ID del usuario que quiere modificar: ");
                scanf("%d",&aux);

                aux2 = buscarIdUsuario(listaDeUsuarios,aux,TAMSERIE);

                modificarUsuario(listaDeUsuarios, aux2);
                system("pause");
                break;

            default:
                printf("Ingrese una opcion valida <1-5>\n");
                system("Pause");
        }
    }
    return 0;
}
