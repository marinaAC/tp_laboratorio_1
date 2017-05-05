#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    int id;
    char nombre[50];
    char passwords[50];
    int isEmpty;
    int calificacion;
    int idPublicacion[10];
    int cantidadPublicaciones;

}EUsuario;

typedef struct {

    int id;
    char nombreProducto[50];
    int precio;
    int stock;
    int idUsuario;
    int cantidadVendida;
    int isEmpty;

}EPublicacion;

/**
 * Inicializa el array con un valor determinado.
 * @param Recibe como parametro el array de tipo de persona, más la cantidad del array y el valor
 * @param con el que se desea guardar.
 * @return no retorna nada.
 */
void inicializarListaInt(EUsuario lista[],int cantidadPersonas,int valor);

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EUsuario lista[], int cantidadPersonas, int valor);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EUsuario lista[], int dni, int cantidadPersonas);

#endif // FUNCIONES_H_INCLUDED

/**
 * Obtiene el promedio de un array.
 * @param se envia el array como parametro y la cantidad maxima del array.
 * @return devuelve el resultado.
 */
float promedio (int numero[], int cantidad);

/**
 * Calcula el maximo de un array
 * @param se envia el array como parametro y la cantidad maxima del array.
 * @return devuelve el valor maximo de ese array.
 */
int max(int numero[], int cantidad);

/**
 * Calcula el minimo de un array
 * @param se envia el array como parametro y la cantidad maxima del array.
 * @return devuelve el valor minimo de ese array.
 */
int min(int numero[], int cantidad);

/**
 * Calcula el mnimo de un array y retorna el indice en el cual se encuentra ubicado ese minimo
 * @param se envia el array como parametro y la cantidad maxima del array.
 * @return devuelve el indice donde esta el valor minimo.
 */
int minIndice(int numero[], int cantidad);

/**
 * Dado el valor, el indice del cual se desea eliminar se corre el array hacia la siguiente posicion.
 * @param se envia el array como parametro, la cantidad maxima del array y el indice en el cual se quiere compactar.
 * @return retorna la cantidad-1.
 */
int compactar(int numero[], int cantidad, int eliminar);

/**
 * Se ordena de una forma que no es con el burbujeo, realizando una busqueda del indice menor, se guarda en otro array
 * y luego se compacta para poder obtener el array nuevo, ordenado sin el indice eliminado.
 * @param se envia el array como parametro, la cantidad maxima del array y el segundo array donde se van a guardar.
 * @return no retorna nada.
 */
void ordernar(int numero[], int cantidadArray,int array2[]);

/**
 * Este grupo de funciones, se encargan de trabajar con tipos flotantes, reciben dos valores
 * y ejecutan la operacion matematica pedida.
 * @param se envian por parametros dos numeros, salvo en el factorial que recibe solo uno
 * @return retornan el resultado.
 */
 float promedioUno(float numerosSumados,float cantidadDeVeces);
 float suma(float numero1, float numero2);
 float resta(float numero1, float numero2);
 float division(float numero1, float numero2);
 float multilicacion(float numero1, float numero2);
 float factorial(float numero);



 void validacionIngreso(int opcion);

 /**
  * Valida que los caracteres ingresados sean solo de tipo numerico
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
 int esNumerico(char num[]);

  /**
  * Valida que los caracteres ingresados sean solo letras
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
 int soloLetras(char palabra[]);

  /**
  * Valida que los caracteres ingresados sean solo letras y numeros
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
 int alfaNum(char palabra[]);

  /**
  * Valida que los caracteres ingresados sean alfanumericos y permite solo un guion
  * @param recibe el array de caracteres
  * @return retorna un 0 cuando es verdadero y un 1 cuando es falso.
 */
 int esTel(char tel[]);

 /**
  * Obtiene un caracter ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el caracter ingresado para guardarlo en alguna variable.
 */
 char getChar(char mensaje[]);

  /**
  * Obtiene un numero flotante ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el valor ingresado para guardarlo en alguna variable.
 */
 float getFloat(char mensaje[]);

  /**
  * Obtiene un entero ingresado por teclado y lo retorna en una variable
  * @param recibe el mensaje que sale por pantalla.
  * @return devuelve el entero ingresado para guardarlo en alguna variable.
 */
 int getInt(char mensaje[]);


/**
  * Funcion que se encarga de mostrar por pantalla un mensaje y guardarlo en un array de string
  * @param necesita un mensaje y el array donde se va a guardar lo escrito
  * @return no retorna nada
 */
 void getString(char mensaje[], char input[]);

/**
  * Funcion que se encarga de guardar lo escrito solo si son letras
  * @param el array con el mensaje, y el lugar donde se va a guardar el dato
  * @return no devuelve nada
 */
 int getStringSoloLetras(char mensaje[], char input[]);

 /**
  * Funcion que se encarga de guardar lo escrito solo si son numeros
  * @param el array con el mensaje, y el lugar donde se va a guardar el dato
  * @return no devuelve nada
 */
 int getStringSoloNum(char mensaje[], char input[]);

/**
  * Funcion necesaria para incilizar un array en un valor determinado
  * @param recibe el array a inicializar, la cantidad de lugares que tiene, y el valor a guardar
  * @return no devuelve nada.
 */
void inicializarArrayInt(int arrayDos[][3],int primerElemento,int segundoElemento,int valor);

/**
  * Realiza el grafico dependiendo de los valores guardados en la matriz de grafico
  * @param recibe el array una matriz y la cantidad de elementos, dependiendo de la cantidad de elementos
  * graficara lo que se encuentra guardado en la primera posicion de la matriz.
  * @return no devuelve nada.
 */
void graficar(int graf[][3],int cantidadElementos);

/**
  * Ordena la matriz de mayor a menor. Re corre primero las columnas y las ordena por fila.
  * @param recibe el array una matriz y la cantidad de elementos,
  * @return no retorna nada, solo realiza el ordenamiento de la matriz enviada por parametro.
 */
void ordenarMayor(int graf[][3],int cantidadElementos);

/**
  * Valida que la opcion ingresada pertenesca a los rangos 1 y 5
  * @param recibe la opcion
  * @return no retorna nada
 */
void validacionIngreso(int opcion);

/**
  * Menu en el cual se encuentra cargado lo que aparece por pantalla (esta funcion la mejorare en algun futuro)
  * @param no recibe nada
  * @return retorna el valor ingresado.
 */
int menu();

/**
  * Inicializa la lista de usuarios para saber que lugar esta disponible
  * @param recibe el puntero de donde se encuentra la lista y el tamaño
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initUsuario(EUsuario* pUsuario, int length);

/**
  * Agrega el usuario en un lugar vacio de la lista
  * @param recibe el puntero de donde se encuentra la lista, el tamaño de la lista, el id, el nombre y la pasword a guardar
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int addUsuario(EUsuario* pUsuario, int length, int id, char name[],char pass[]);

/**
  * Encuentra un usuario por id
  * @param recibe el puntero de donde se encuentra la lista, el tamaño de la lista, el id
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
EUsuario* findUsuarioById(EUsuario* pUsuario, int length,int id);

/**
  * Borra de forma logica el usuario, ponieno en valor 1 si se encuentra vacio, otra vez
  * @param recibe el puntero de donde se encuentra la lista, el tamaño de la lista y el id
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int removeEmployee(EUsuario* pUsuario, int length, int id);

/**
  * Agrega una publicacion a la lista
  * @param recibe el puntero donde se enceutnra la lista, el tamaño, id, el nombre, el precio, el stock y el id del usuario que lo ingreso
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int addPublicacion(EPublicacion* pPublicacion, int length, int id, char name[],int precio, int stock, int idUsuario);


/**
  * Encuentra una publicacion por id
  * @param recibe el puntero de donde se encuentra la lista, el tamaño de la lista, el id
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
EPublicacion* findPublicacionById(EPublicacion* pPublicacion, int length,int id);

/**
  * Inicializa la lista de publicaciones para saber que lugar esta disponible
  * @param recibe el puntero de donde se encuentra la lista y el tamaño
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int initPub(EPublicacion* pPublicacion, int length);

/**
  * Borra de forma logica la publicacion, ponieno en valor 1 si se encuentra vacio, otra vez
  * @param recibe el puntero de donde se encuentra la lista, el tamaño de la lista y el id
  * @return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */
int removePublicacion(EPublicacion* pUsuario, int length, int id);
