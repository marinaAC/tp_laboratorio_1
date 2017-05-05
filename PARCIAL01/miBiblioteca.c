#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "miBiblioteca.h"

float promedio (int numero[], int cantidad) {
    int suma=0;
    float resultadoProm;
    int i;
    for (i=0; i<cantidad;i++) {

        suma = suma + numero[i];

    }
    resultadoProm = (float)suma / cantidad;

    return resultadoProm;
}

int max(int numero[], int cantidad)
{
    int flag=0;
    int i;
    int max;
    for (i=0; i<cantidad; i++)
    {
        if (flag == 0)
        {
            flag = 1;
            max = numero[i];
        }

        if(numero[i]>max)
        {
            max = numero[i];
        }
    }
    return max;
}


int min(int numero[], int cantidad)
{
    int min;
    int i;
    int flag=0;

    for (i=0; i<cantidad; i++)
    {
        if (flag == 0){
            flag = 1;
            min = numero[i];
        }
        if (numero[i]<min){
            min = numero[i];
        }
    }
    return min;
}

int minIndice(int numero[], int cantidad)
{
    int minIndice, min;
    int i;
    int flag=0;

    for (i=0; i<cantidad; i++)
    {
        if (flag == 0){
            flag = 1;
            min = numero[i];
            minIndice=i;
        }
        if (numero[i]<min){
            min = numero[i];
            minIndice=i;
        }
    }
    return minIndice;
}

int compactar(int numero[], int cantidad, int eliminar){
    int i;
    for(i=eliminar;i<cantidad;i++){
        numero[i]=numero[i+1];
    }
    return cantidad-1;
}

void ordernar(int numero[], int cantidadArray,int array2[]){
    int indiceMenor;
    int iterar=cantidadArray;
    int i;
    for(i=0;i<iterar;i++){
        indiceMenor=minIndice(numero,cantidadArray);
        array2[i]=numero[indiceMenor];
        cantidadArray=compactar(numero,cantidadArray,indiceMenor);
    }
}


 float promedioUno(float numerosSumados,float cantidadDeVeces){
    float resultado;
    resultado = numerosSumados/cantidadDeVeces;
    return resultado;

}

float suma(float numero1, float numero2){
    float result;
    fflush(stdin);
    result = numero1 + numero2;
    return result;
}

float resta(float numero1, float numero2){
    float result;
    fflush(stdin);
    result = numero1 - numero2;
    return result;
}

float division(float numero1, float numero2){
    float result;
    fflush(stdin);
    while(numero2<=0){
        printf("No se puede realizar una division por 0 o menor a 0. Ingrese nuevos valor para el numero b: ");
        fflush(stdin);
        scanf("%f",&numero2);
    }
    result = numero1/numero2;
    return result;
}

float multilicacion(float numero1, float numero2){
    float result;
    fflush(stdin);
    result = numero1 * numero2;
    return result;
}

float factorial(float numero){
    float result=1.0;
    for(;numero>0;numero--){
        result = result*numero;
    }
    return result;
}

int esNumerico(char num[]){
    int i=0;
    while(num[i]!='\0'){
        if(num[i]<'0'||num[i]>'9'){
            return 0;
        }
        i++;
    }
    return 1;
}

int soloLetras(char palabra[]){
    int i = 0;
    while(palabra[i]!='\0'){
        if((palabra[i]!=' ')&&(palabra[i]<'a'||palabra[i]>'z')&&(palabra[i]<'A'||palabra[i]>'Z')){
            return 0;
        }
        i++;
    }
    return 1;
}

int alfaNum(char palabra[]){
    int i=0;
    while(palabra[i]!='\0'){
        if((palabra[i]!=' ')&&(palabra[i]<'a'||palabra[i]>'z')&&(palabra[i]<'A'||palabra[i]>'Z')&&(palabra[i]<'0'||palabra[i]>'9')){
            return 0;
        }
        i++;
    }
    return 1;
}

int esTel(char tel[]){
    int i=0;
    int contadorGuiones = 0;
    while(tel[i]!='\0'){
        if((tel[i]!=' ')&&(tel[i]!='-')&&(tel[i]<'0'||tel[i]>'9')){
            return 0;
        }
        if(tel[i]=='-'){
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones==1){
        return 1;
    }
    return 0;
}


int getInt(char mensaje[]){
    int buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%d",&buffer);
    return buffer;
}

float getFloat(char mensaje[]){
    float buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%f",&buffer);
    return buffer;
}

char getChar(char mensaje[]){
    char buffer;
    printf(mensaje);
    fflush(stdin);
    scanf("%c",&buffer);
    return buffer;
}

void getString(char mensaje[], char input[]){
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",input);
}

int getStringSoloLetras(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(soloLetras(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringSoloNum(char mensaje[], char input[]){
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux)){
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

void inicializarListaInt(EUsuario lista[],int cantidadPersonas,int valor){
    int i;
    for(i=0;i<cantidadPersonas;i++){
        lista[i].isEmpty=valor;
    }
}

void inicializarArrayInt(int arrayDos[][3],int primerElemento,int segundoElemento,int valor){
    int i,j;
    for(i=0;i<primerElemento;i++){
        for(j=0;j<segundoElemento;j++){
            arrayDos[i][j]=valor;
        }
    }
}


int obtenerEspacioLibre(EUsuario lista[], int cantidadPersonas, int valor){
    int i;
    for(i=0;i<cantidadPersonas;i++){
        if(lista[i].isEmpty==valor){
            return i;
        }
    }
    return -1;
}
/*
int buscarPorDni(EUsuario lista[], int dni, int cantidadPersonas){
    int i;
    for(i=0;i<cantidadPersonas;i++){
        if(lista[i].dni==dni){
            return i;
        }
    }
    return -1;
}
*/
void graficar(int graf[][3],int cantidadElementos){
    int i,j;
    for(i=cantidadElementos;i>=0;i--){
        for(j=0;j<3;j++){
            if(graf[i][j]!=1 && graf[i][j]!=0){
                continue;
            }
            if(graf[i][j]==1){
                printf("\t*");
            }else{
                printf("\t");
            }
        }
        printf("\n");
   }
}

void ordenarMayor(int graf[][3],int cantidadElementos){
    int x, y, m;
    int aux;

        for(y=0;y<=2;y++){
            for(x=0;x<cantidadElementos;x++){
                    for(m=x+1;m<cantidadElementos;m++){
                        if(graf[x][y]<graf[m][y]){
                            aux = graf[m][y];
                            graf[m][y] = graf[x][y];
                            graf[x][y] = aux;
                    }
                }
            }
        }
}

int menu()
{
    //El menu, tiene una validacion, ya que si lo declaro como un entero y por pantalla le ingresan un flotante, el programa se rompe.
    //Habilito que por pantalla pueda tomar un flotante, lo parseo a entero y luego, esa validacion tendra otra que le dira que el valor ingresado es incorrecto.
    float opcion=0.0;
    printf("\nSistema de ingreso: \n");
    printf("1- ALTA DE USUARIO\n");
    printf("2- MODIFICAR DATOS DEL USUARIO\n");
    printf("3- BAJA DEL USUARIO\n");
    printf("4- PUBLICAR PRODUCTO\n");
    printf("5- MODIFICAR PUBLICACION\n");
    printf("6- CANCELAR PUBLICACION\n");
    printf("7- COMPRAR PRODUCTO\n");
    printf("8- LISTAR PUBLICACIONES DE USUARIO\n");
    printf("9- LISTAR PUBLICACIONES\n");
    printf("10- LISTAR USUARIOS\n");
    printf("11- Salir\n");
    printf("Ingrese su opcion: ");
    scanf("%f", &opcion);
    int opcionfinal=(int)opcion;
    return opcionfinal;
}

void validacionIngreso(int opcion){
    while(opcion>6||opcion<0){
            printf("Valor incorrecto!.\nSolo puede elegir las opciones entre 1 y 5.\nPor favor, vuelva a ingresar una opcion: \n");
            opcion=menu();
        }
}



int initUsuario(EUsuario* pUsuario, int length)
{   int retorna = -1;
    int i;
    if(pUsuario != NULL && length >0){

        for(i=0;i<length;i++){
            pUsuario[i].isEmpty=1;
        }
        retorna = 0;
    }
    return retorna;
}

int initPub(EPublicacion* pPublicacion, int length)
{   int retorna = -1;
    int i;
    if(pPublicacion != NULL && length >0){

        for(i=0;i<length;i++){
            pPublicacion[i].isEmpty=1;
        }
        retorna = 0;
    }
    return retorna;
}


int addUsuario(EUsuario* pUsuario, int length, int id, char name[],char pass[])
{   int retorna = -1;
    int i;
    if(pUsuario != NULL && length >0){
        for(i=0;i<length;i++){
            if(pUsuario[i].isEmpty==1){
                pUsuario[i].id=id;
                strcpy(pUsuario[i].nombre,name);
                strcpy(pUsuario[i].passwords,pass);
                pUsuario[i].calificacion=0;
                pUsuario[i].idPublicacion[0]=-1;
                pUsuario[i].cantidadPublicaciones=0;
                pUsuario[i].isEmpty=0;
                retorna = 0;
                break;
            }
        }
    }
    return retorna;
}


int addPublicacion(EPublicacion* pPublicacion, int length, int id, char name[],int precio, int stock, int idUsuario)
{   int retorna = -1;
    int i;
    if(pPublicacion != NULL && length >0){
        for(i=0;i<length;i++){

                pPublicacion[i].id=id;
                strcpy(pPublicacion[i].nombreProducto,name);
                pPublicacion[i].precio= precio;
                pPublicacion[i].stock=stock;
                pPublicacion[i].idUsuario = idUsuario;
                pPublicacion[i].cantidadVendida = 0;
                retorna = 0;
                break;

        }
    }
    return retorna;
}



EUsuario* findUsuarioById(EUsuario* pUsuario, int length,int id)
{   EUsuario* retorna = NULL;
    int i;
    if(pUsuario != NULL && length > 0){
        for(i=0;i<length;i++){
            if(pUsuario[i].id==id){
                return &pUsuario[i];
            }
        }
    }
    return retorna;
}

EPublicacion* findPublicacionById(EPublicacion* pPublicacion, int length,int id)
{   EPublicacion* retorna = NULL;
    int i;
    if(pPublicacion != NULL && length > 0){
        for(i=0;i<length;i++){
            if(pPublicacion[i].id==id){
                return &pPublicacion[i];
            }
        }
    }
    return retorna;
}


EUsuario* findPrimerLugar(EUsuario* pUsuario, int length)
{   EUsuario* retorna = NULL;
    int i;
    if(pUsuario != NULL && length > 0){
        for(i=0;i<length;i++){
            if(pUsuario[i].isEmpty==1){
                return &pUsuario[i];
            }
        }
    }
    return retorna;
}



int removeEmployee(EUsuario* pUsuario, int length, int id)
{   int retorna = -1;
    EUsuario* auxUss;
    if(auxUss != NULL && length >0){

        auxUss = findUsuarioById(auxUss,length,id);
        (*auxUss).isEmpty = 1;
        retorna = 0;
    }
    return retorna;
}

int removePublicacion(EPublicacion* pUsuario, int length, int id)
{   int retorna = -1;
    EPublicacion* auxPub;
    if(auxPub != NULL && length >0){

        auxPub = findPublicacionById(auxPub,length,id);
        (*auxPub).isEmpty = 1;
        retorna = 0;
    }
    return retorna;
}






