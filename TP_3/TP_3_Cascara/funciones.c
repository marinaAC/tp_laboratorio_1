#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

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
/*
int loadPerson(S_Persona* pPersona){
    getString("Ingrese el nombre: ", pPersona->nombre);

    pPersona->edad = getInt("Ingrese la edad: ");
    if(pPersona->edad<=0 || pPersona->edad>100){
        return 0; //error
    }
    if(getStringSoloNum("Ingrese el DNI: ",pPersona->id)==0){
        return 0;
    }
    return 1;
}

void printPerson(S_Persona* pPersona){
    printf("Nombre: %s, Edad: %d, DNI: %s",pPersona->nombre,pPersona->edad,pPersona->id);
}



/**
 * \brief Permite al usuario ingresar un texto y lo devuelve en un nuevo espacio de memoria
 * \param char* msg. Mensaje a ser impreso.
 * \return puntero a cadena de caracteres con texto ingresado. Se debe liberar con free().
*//*
char* getDynamicString(char* msg){
    printf(msg);
    char* pData = (char*) malloc(sizeof(char)*1024);
    scanf("%1023s", pData); // cantidad maxima 1023 (dejamos 1 byte para tener el cuenta el caracter terminador)
    int len = strlen(pData); //para saber cuantas letras hay dentro de la cadena de caracteres que usamos con malloc
    pData = (char*)realloc(pData,sizeof(char)*(len+1)); // hacemos un realloc de len para poder achicar el espacio de la memoria
    return pData;
}

int loadDataFile(char* fileName,S_Data* array, int arrayLen){
    FILE *fp;
    char lineStr[128]; //variable donde almaccena la linea leida
    //abrimos el archivo para lectura
    fp = fopen(fileName, "r");
    if(fp == NULL){
        perror("Error opening file");
        return -1;
    }

    //leemos las lineas
    int index = 0;
    while(fgets(lineStr,128,fp)!=NULL){ //leemos una linea, 128 caracteres como un maximo
        int indexDivider =strcspn(lineStr,"="); //devuelve la posicion del signo "="
        int keyLen = indexDivider+1; // calculo el tamaño del texto de la clave, se suma 1 ya que tiene que terminar en 0
        int valueLen = strlen(lineStr)- indexDivider-1;//calculo la palabra clave y la palabra del valor

        char* key = (char*)malloc(keyLen);
        char* value = (char*)malloc(valueLen);

        strncpy(key,lineStr,keyLen-1);
        key[keyLen-1]=0x00;

        strncpy(value,&lineStr[keyLen],valueLen-1);
        value[valueLen-1]=0x00;

        //guardamos los punteros creados con malloc en la struct
        array[index].key = key;
        array[index].value = value;
        index++;
        if(index>=arrayLen){
            break;
        }
    }

    fclose(fp);
    return index;
}
*/

/**
 *\brief Pide al usuario los datos y los guarda en la struct
 *\param struct S_person* p puntero a struct donde se almacenan los datos ingresados
 *\return void
**/
/*
void loadData(S_Pers* p){
    getStringSoloLetras("Ingrese el nombre: ",p->name);
    getStringSoloLetras("Ingrese el apellido: ",p->surname);
    p->age=getInt("Ingrese la edad");
}
*/
/**
 *\brief Guarda una struct al final de un archivo binario bin.dat
 *\param struct S_Pers* p puntero a struct a ser escrita
 *\return 0:error, 1: ok
**//*
int savePerson(S_Pers* p){
    FILE* fp;
    fp=fopen("bin.dat","ab+"); //append binario, lo crea sino existe
    if(fp==NULL){
        printf("Error abriendo el archivo");
        return 0;
    }
    fwrite(p,sizeof(S_Pers),1,fp);//escribo una strut al final
    fclose(fp);
    return 1;
}

S_Pers* readPerson(char* surname){
     FILE* fp;
     fp= fopen("bin.dat","rb"); //lectura binaria
     if(fp==NULL){
        printf("Error abriendo el archivo");
        return  NULL;
     }
     S_Pers* pRet = malloc(sizeof(S_Pers));
     int flagFound = 0;
     while(fread(pRet,sizeof(S_Pers),1,fp)!=0){
        if(strcmp(surname,pRet->surname)==0){
            flagFound = 1;
            break;
        }
     }
     fclose(fp);
     if(flagFound){
        return pRet;
     }
     free(pRet);
     return NULL;
}
*/
void cargarPelicula(EMovie* movie){
    printf("Agregar Pelicula\n");
    char auxDuracion[50];
    char auxPuntaje[50];
    if(!getStringSoloLetras("\nIngrese el titulo de la pelicula: ",movie->titulo)){
        printf("Error!! solo puede ingresar letras!!");
        return;
    }
    if(!getStringSoloLetras("\nIngrese el genero de la pelicula: ",movie->genero)){
        printf("Error!! solo puede ingresar letras!!");
        return;
    }
    if(!getStringSoloNum("\nIngrese la duracion de la pelicula: ",auxDuracion)){
        printf("Error!! solo puede ingresar numeros");
        return;
    }
    if(!getStringSoloLetras("\nIngrese la descripcion: ",movie->descripcion)){
        printf("Error!! solo se puede ingresar letras!!");
        return;
    }
    if(!getStringSoloNum("\nIngrese el puntaje de la pelicula: ",auxPuntaje)){
        printf("Error solo se puede ingresar numeros");
        return;
    }
    getString("\nPegue el link de la imagen: ",movie->linkImagen);
    movie->duracion = atoi(auxDuracion);
    movie->puntaje = atoi(auxPuntaje);
    movie->isEmpty = 1;
}

int agregarPelicula(EMovie* movie){
    FILE* fp;
    fp = fopen("bin.data","ab+");
    if(fp==NULL){
        printf("Error!!! no se pudo abrir el archivo");
        return 0;
    }

    fwrite(movie,sizeof(EMovie),1,fp);

    fclose(fp);
    return 1;
}

int borrarPelicula(EMovie* movie){
    FILE* fp;
    EMovie* auxMovie;
    int contadorLineas = 0;
    fp= fopen("bin.data","rb");
    if(fp==NULL){
        printf("Error!! no se pudo abrir el archivo");
        return -1;
    }
    printf("\nIngrese el titulo de la pelicula que desa borrar: ");
    scanf("%s",auxMovie->titulo);
    contadorLineas = obtenerLinea(movie,auxMovie,fp,contadorLineas);
    fclose(fp);
    return contadorLineas;
}

int obtenerLinea(EMovie* movie, EMovie* tituloBuscado, FILE* peli, int contador){

    while(!feof(peli)){
        fread(movie,sizeof(EMovie),1,peli);
        if(strcmp(tituloBuscado->titulo,movie->titulo)==0){
            movie->isEmpty = 0;
            break;
        }
        contador++;
    }
    return contador;
}

int modificarPelicula(EMovie* movie){
    FILE* fp;
    fp = fopen("bin.data","rwb");
    EMovie* auxiliarPeli=(EMovie*)malloc(sizeof(EMovie));
    if(auxiliarPeli== NULL){
        printf("ERROR");
        return -1;
    }
    if(fp == NULL){
        printf("Error!!! no se pudo leer el archivo");
        return -1;
    }
    printf("\nIngrese el titulo de la pelicula: ");
    fflush(stdin);
    scanf("%s",auxiliarPeli->titulo);
    while(!feof(fp)){
        fread(movie,sizeof(EMovie),1,fp);
        if(strcmp(auxiliarPeli->titulo,movie->titulo)==0){
            cargarPelicula(movie);
            break;
        }
    }
    fclose(fp);

}
/*
int generarLista(EMovie lista[]){
    FILE* fp;
    fp = fopen("bin.data","rb");
    EMovie* movie;
    int i = 0;
    if(fp== NULL){
        printf("Error!! el archivo no pudo ser lido");
        return -1;
    }
    while(!feof(fp)){
        fread(movie,sizeof(EMovie),1,fp);
        strcpy(lista[i]->titulo,movie->titulo);
        strcpy(lista[i]->descripcion,movie->descripcion);
        strcpy(lista[i]->genero,movie->genero);
        strcpy(lista[i]->linkImagen,movie->linkImagen);
        lista[i]->duracion = movie->duracion;
        lista[i]->puntaje = movie->puntaje;
        lista[i]->isEmpty = movie->isEmpty;
        i++;
    }
    fclose(fp);
    return i;
}
/*

int generarPagina(EMovie lista[], char nombre[], int len){
    FILE* fhtml;
    fhtml=fopen("index.html","a+");
    int i;
    if(fhtml==NULL){
        printf("Error al generar el archivo html");
        return -1;
    }
    fputs("<!DOCTYPE html>",fhtml);
    fputs("<html>",fhtml);
    fputs("<head>",fhtml);
    fputs("<meta charset='utf-8'>",fhtml);
    fputs("<meta http-equiv='X-UA-Compatible' content='IE=edge'>",fhtml);
    fputs("<meta name='viewport' content='width=device-width, initial-scale=1'>",fhtml);
    fputs("<title>Lista peliculas</title>",fhtml);
    fputs("<link href='css/bootstrap.min.css' rel='stylesheet'>",fhtml);
    fputs("<link href='css/custom.css' rel='stylesheet'>",fhtml);
    fputs("<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>",fhtml);
    fputs("<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>",fhtml);
    fputs("</head>",fhtml);
    fputs("<body>",fhtml);
    fputs("<div class='container'>",fhtml);
    fputs("<div class='row'>",fhtml);
    for(i=0;i<len;i++){
        fputs("<article class='col-md-4 article-intro'>",fhtml);
        fputs("<a href='#'>",fhtml);
        fputs("<a href='#'>",fhtml);
    }








                    <img class='img-responsive img-rounded' src='http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg' alt=''>
                </a>
                <h3>
                    <a href='#'>Back to the future</a>
                </h3>
				<ul>
					<li>Género:Aventura</li>
					<li>Puntaje:86</li>
					<li>Duración:116</li>
				</ul>
                <p>A young man is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his friend, Dr. Emmett Brown, and must make sure his high-school-age parents unite in order to save his own existence.</p>
            </article>
			<!-- Repetir esto para cada pelicula -->


        </div>
        <!-- /.row -->
    </div>
    <!-- /.container -->
    <!-- jQuery -->
    <script src='js/jquery-1.11.3.min.js'></script>
    <!-- Bootstrap Core JavaScript -->
    <script src='js/bootstrap.min.js'></script>
	<!-- IE10 viewport bug workaround -->
	<script src='js/ie10-viewport-bug-workaround.js'></script>
	<!-- Placeholder Images -->
	<script src='js/holder.min.js'></script>
</body>
</html>

}
*/
