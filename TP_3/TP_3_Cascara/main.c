#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    EMovie* movie = (EMovie*)malloc(sizeof(EMovie));
    if(movie==NULL){
        printf("No se pudo crear la pelicula");
        return 1;
    }
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                cargarPelicula(movie);
                agregarPelicula(movie);
                break;
            case 2:
                borrarPelicula(movie);
                break;
            case 3:
                modificarPelicula(movie);
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
