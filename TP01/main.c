#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

int main()
{
    char seguir='s';
    int opcion=0;
    char mensaje[]="\nValor: ";
    char menError[]="\nValor fuera del rango permitido, ingrese otro de nuevo: ";
    float resultado;
    float numA,numB;
    float max=3000.0;
    float min=0.0;
    while(seguir=='s')
    {
        opcion=menu();
        validacionIngreso(opcion);
        switch(opcion)
        {
            case 1:
                numA=obtenerFloat(mensaje,menError,max,min);
                break;
            case 2:
                numB=obtenerFloat(mensaje,menError,max,min);
                break;
            case 3:
                resultado=suma(numA,numB);
                printf("\nEl resultado de la operacion es: %.3f\n",resultado);
                break;
            case 4:
                resultado=resta(numA,numB);
                printf("\nEl resultado de la operacion es: %.3f\n",resultado);
                break;
            case 5:
                resultado=division(numA,numB);
                printf("\nEl resultado de la operacion es: %.3f\n",resultado);
                break;
            case 6:
                resultado=multilicacion(numA,numB);
                printf("\nEl resultado de la operacion es: %.3f\n",resultado);
                break;
            case 7:
                if(numA!=0){
                    resultado=factorial(numA);
                }else{
                    resultado=factorial(numB);
                }
                printf("\nEl resultado de la operacion es: %.3f\n",resultado);
                break;
            case 8:
                resultado= resultado+resta(numA,numB)+suma(numA,numB)+multilicacion(numA,numB)+division(numA,numB);
                printf("\nEl resultado de la operacion es: %.3f\n",resultado);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
