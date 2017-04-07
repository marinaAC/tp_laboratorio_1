//Funciones para obtener valores, con una rango determinado
int obtenerInt(char mensaje[],char mensajeError[],int maximo, int minimo);
float obtenerFloat(char mensaje[],char mensajeError[],float maximo, float minimo);
char obtenerChar(char mensaje[],char mensajeError[],char maximo, char minimo);
//Funciones para obtener promedio de un array, max y min, y el indice del minimo
float promedio (int numero[], int cantidad);
int max(int numero[], int cantidad);
int min(int numero[], int cantidad);
int minIndice(int numero[], int cantidad);
//Funcion para compactar y ordenar un array de enteros
int compactar(int numero[], int cantidad, int eliminar);
void ordernar(int numero[], int cantidadArray,int array2[]);
//Funcion donde muestra el texto para el usuario
int menu();
//Funcion para obtener un promedio y suma
 float promedioUno(float numerosSumados,float cantidadDeVeces);
 float suma(float numero1, float numero2);
 float resta(float numero1, float numero2);
 float division(float numero1, float numero2);
 float multilicacion(float numero1, float numero2);
 float factorial(float numero);
 void validacionIngreso(int opcion)
