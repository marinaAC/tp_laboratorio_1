#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miBiblioteca.h"
#define MAXUSUARIOS 100
#define MAXPRODUCTOS 100




int main()
{   EUsuario listaUsuario[MAXUSUARIOS];
    EPublicacion listaPublicacion[MAXPRODUCTOS];

    char auxNombreUs[50];
    char auxPass[50];
    char auxId[10];
    char auxNombreProducto[50];
    char auxPrecio[10];
    char auxStock[10];
    char auxCalificacion;

    int calificacacionAguardar;
    int stockAGuardar;
    int precioAGuardar;
    int auxIdProd;
    char idProdIngresado;
    float prom;
    int auxCantidadVendida;


    EUsuario* auxUsuario;
    EPublicacion* auxPublicacion;
    int idBuscar;
    int idIncremento = 0;
    int idIncrementoProducto = 0;
    int flag;
    int j;
    int opcion = 0;


    initUsuario(listaUsuario,MAXUSUARIOS);
    initPub(listaPublicacion,MAXPRODUCTOS);
    while(opcion!=11){
        opcion = menu();
        switch(opcion){
            case 1:
                flag = 0;
                if(!getStringSoloLetras("\nIngrese el nombre de usuario: ", auxNombreUs)){
                    printf("\nSolo se permiten el ingreso de letras");
                    flag = 1;
                    break;
                }
                if(!getStringSoloLetras("\nIngrese el password: ", auxPass)){
                    printf("\nSolo se permite el ingreso de caracteres alfanumericos");
                    flag = 1;
                    break;
                }
                if(flag == 0){
                   idIncremento++;
                }
                addUsuario(listaUsuario,MAXUSUARIOS,idIncremento,auxNombreUs,auxPass);
                break;
            case 2:
                if(!getStringSoloNum("\nIngrese el id del usuario: ", auxId)){
                    printf("\nSolo se permite el ingreso de numeros para la busqueda del ID: ");
                    break;
                }
                int idBuscar = atoi(auxId);
                if(!findUsuarioById(listaUsuario,MAXUSUARIOS,idBuscar)){
                    printf("\nEl id del usuario no es encontrado");
                    break;
                }
                auxUsuario = findUsuarioById(listaUsuario,MAXUSUARIOS,idBuscar);
                if(!getStringSoloLetras("\nIngrese el nombre a modificar: ", auxNombreUs)){
                    printf("\nSolo se permiten el ingreso de letras");
                    break;
                }
                if(!getStringSoloLetras("\nIngrese el password a modificar: ", auxPass)){
                    printf("\nSolo se permite el ingreso de caracteres alfanumericos");
                }
                strcpy((*auxUsuario).nombre,auxNombreUs);
                strcpy((*auxUsuario).passwords,auxPass);
                break;
            case 3:
                if(!getStringSoloNum("\nIngrese el id del usuario: ", auxId)){
                    printf("\nSolo se permite el ingreso de numeros para la busqueda del ID: ");
                    break;
                }
                idBuscar = atoi(auxId);
                if(!removeEmployee(listaUsuario,MAXUSUARIOS,idBuscar)){
                    printf("\nEl id del usuario no es encontrado");
                    break;
                }
                removeEmployee(listaUsuario,MAXUSUARIOS,idBuscar);
                break;
            case 4:
                flag = 0;
                if(!getStringSoloNum("\nIngrese el id del usuario: ", auxId)){
                    printf("\nSolo se permite el ingreso de numeros para la busqueda del ID: ");
                    break;
                }
                idBuscar = atoi(auxId);
                if(!findUsuarioById(listaUsuario,MAXUSUARIOS,idBuscar)){
                    printf("\nEl id del usuario no es encontrado");
                    break;
                }
                if(!getStringSoloLetras("\nIngrese el nombre del producto: ", auxNombreProducto)){
                    printf("\nSolo se permiten el ingreso de letras");
                    flag = 1;
                    break;
                }
                if(!getStringSoloNum("\nIngrese el precio de cada producto: ", auxPrecio)){
                    printf("\nSolo se permite el ingreso de numeros");
                    flag = 1;
                    break;
                }
                if(!getStringSoloNum("\nIngrese la cantidad de productos que tiene disponible ", auxStock)){
                    printf("\nSolo se permite el ingreso de numeros");
                    flag = 1;
                    break;
                }
                precioAGuardar = atoi(auxPrecio);
                stockAGuardar = atoi(auxStock);

                if(flag == 0){
                    idIncrementoProducto++;
                }
                addPublicacion(listaPublicacion,MAXPRODUCTOS,idIncrementoProducto,auxNombreProducto,precioAGuardar,stockAGuardar,idBuscar);
                break;
            case 5:
                if(!getStringSoloNum("\nIngrese el id del usuario: ", auxId)){
                    printf("\nSolo se permite el ingreso de numeros para la busqueda del ID: ");
                    break;
                }
                idBuscar = atoi(auxId);
                if(!findUsuarioById(listaUsuario,MAXUSUARIOS,idBuscar)){
                    printf("\nEl id del usuario no es encontrado");
                    break;
                }
                if(listaUsuario[idBuscar].idPublicacion[0]==-1){
                    printf("El usuario no tiene ninguna publicacion");
                    break;
                }
                for(j=0;j<MAXPRODUCTOS;j++){
                        if(listaPublicacion[j].idUsuario==idBuscar){
                            printf("\nID: %d- NOMBRE: %s- PRECIO: $%d-CANTIDAD VENDIDA: %d- STOCK: %d", listaPublicacion[j].id, listaPublicacion[j].nombreProducto, listaPublicacion[j].precio, listaPublicacion[j].cantidadVendida ,listaPublicacion[j].stock);
                        }
                }
                if(!getStringSoloNum("\n\nIngrese el id del producto: ", idProdIngresado)){
                    printf("Ingrese solo numeros");
                    break;
                }
                auxIdProd = atoi(idProdIngresado);
                if(!findPublicacionById(listaPublicacion,MAXPRODUCTOS,auxIdProd)){
                    printf("\nEl id del producto no es encontrado");
                    break;
                }
                auxPublicacion = findPublicacionById(listaPublicacion,MAXPRODUCTOS,auxIdProd);
                if(!getStringSoloLetras("Ingrese el nuevo nombre del producto", auxNombreProducto)){
                    printf("Ingrese solo letras");
                    break;
                }
                if(!getStringSoloNum("\nIngrese el nuevo precio: ", auxPrecio)){
                    printf("Ingrese solo numeros ");
                    break;
                }
                if(!getStringSoloNum("\nIngrese el nuevo stock: ", auxStock)){
                    printf("Ingrese solo numeros");
                    break;
                }
                strcpy((*auxPublicacion).nombreProducto, auxNombreProducto);
                (*auxPublicacion).precio = auxPrecio;
                (*auxPublicacion).stock = auxStock;
                break;
            case 6:
                 if(!getStringSoloNum("\nIngrese el id del usuario: ", auxId)){
                    printf("\nSolo se permite el ingreso de numeros para la busqueda del ID: ");
                    break;
                }
                idBuscar = atoi(auxId);
                if(!findUsuarioById(listaUsuario,MAXUSUARIOS,idBuscar)){
                    printf("\nEl id del usuario no es encontrado");
                    break;
                }
                if(listaUsuario[idBuscar].idPublicacion[0]==-1){
                    printf("El usuario no tiene ninguna publicacion");
                    break;
                }
                for(j=0;j<MAXPRODUCTOS;j++){
                        if(listaPublicacion[j].idUsuario==idBuscar){
                            printf("\nID: %d- NOMBRE: %s- PRECIO: $%d-CANTIDAD VENDIDA: %d- STOCK: %d", listaPublicacion[j].id, listaPublicacion[j].nombreProducto, listaPublicacion[j].precio, listaPublicacion[j].cantidadVendida ,listaPublicacion[j].stock);
                        }
                }
                if(!getStringSoloNum("\n\nIngrese el id del producto: ", idProdIngresado)){
                    printf("Ingrese solo numeros");
                    break;
                }
                auxIdProd = atoi(idProdIngresado);
                if(!findPublicacionById(listaPublicacion,MAXPRODUCTOS,auxIdProd)){
                    printf("\nEl id del producto no es encontrado");
                    break;
                }
                removePublicacion(listaPublicacion,MAXPRODUCTOS,auxIdProd);
                break;
            case 7:
                  if(!getStringSoloNum("\n\nIngrese el id del producto: ", idProdIngresado)){
                    printf("Ingrese solo numeros");
                    break;
                }
                auxIdProd = atoi(idProdIngresado);
                if(!findPublicacionById(listaPublicacion,MAXPRODUCTOS,auxIdProd)){
                    printf("\nEl id del producto no es encontrado");
                    break;
                }
                if(listaPublicacion[auxIdProd].stock<0){
                    printf("No hay mas stock disponible");
                    break;
                }

                if(!getStringSoloNum("Ingrese la calificacion del vendedor 1 muy mala y 10 muy buena: ", auxCalificacion)){
                    printf("Ingrese solo numeros");
                    break;
                }
                calificacacionAguardar = atoi(auxCalificacion);
                listaPublicacion[auxIdProd].stock=listaPublicacion[auxIdProd].stock-1;
                listaPublicacion[auxIdProd].cantidadVendida = listaPublicacion[auxIdProd].cantidadVendida +1;
                idBuscar = listaPublicacion[auxIdProd].idUsuario;
                listaUsuario[idBuscar].calificacion = calificacacionAguardar;

                break;
            case 8:

                 if(!getStringSoloNum("\nIngrese el id del usuario: ", auxId)){
                    printf("\nSolo se permite el ingreso de numeros para la busqueda del ID: ");
                    break;
                }
                idBuscar = atoi(auxId);
                if(!findUsuarioById(listaUsuario,MAXUSUARIOS,idBuscar)){
                    printf("\nEl id del usuario no es encontrado");
                    break;
                }
                if(listaUsuario[idBuscar].idPublicacion[0]==-1){
                    printf("El usuario no tiene ninguna publicacion");
                    break;
                }
                printf("\nLISTA PUBLICACIONES DE USUARIO");
                for(j=0;j<MAXPRODUCTOS;j++){
                        if(listaPublicacion[j].idUsuario==idBuscar){
                            printf("\nID: %d- NOMBRE: %s- PRECIO: $%d-CANTIDAD VENDIDA: %d- STOCK: %d", listaPublicacion[j].id, listaPublicacion[j].nombreProducto, listaPublicacion[j].precio, listaPublicacion[j].cantidadVendida ,listaPublicacion[j].stock);
                        }
                }

                break;
            case 9:
                printf("\nLISTA PUBLICACIONES");
                for(j=0;j<MAXPRODUCTOS;j++){
                    idBuscar = listaPublicacion[auxIdProd].idUsuario;
                    printf("\nID: %d- NOMBRE: %s- PRECIO: $%d-CANTIDAD VENDIDA: %d- STOCK: %d-NOMBRE US: %s", listaPublicacion[j].id, listaPublicacion[j].nombreProducto, listaPublicacion[j].precio, listaPublicacion[j].cantidadVendida ,listaPublicacion[j].stock, listaUsuario[idBuscar].nombre);

                }
                break;
            case 10:
                printf("\nLISTA USUARIOS");

                break;
            case 11:

                break;
        }
    }

    return 0;
}
