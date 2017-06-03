#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int isEmpty;
}EMovie;


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie* movie);

/**
 *  Borra una pelicula del archivo binario
 * nota: tengo problemas al leer y comparar el archivo, para modificar el movie
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 * Nota: no llegue a generar este archivo, ya que tuve problemas con la modificacion y el borrado
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
int generarPagina(EMovie lista[], char nombre[]);


/**
 *  Interactua con el usuario, pidiendole los datos para luego ser cargados en el archivo
 *  @param recibe un puntero tipo emovie, donde va a realizar el cargado de los archivos momentaneos
 *  @return void
 */
void cargarPelicula(EMovie* movie);

/**
 *  Modificar realiza la apertura del archivo, lo lee y compara si el titulo ingresado es igual a alguno del archivo
 *  si, es el mismo, llama a la funcion cargar, repitiendo las preguntas para poder cargarlo.
 *NOTA: este metodo no me funciono y ya no cuento con tiempo para moficiarlo.
 *  @param recibe un puntero de pelicula para poder utilizarlo en la busqueda
 *  @return devuelve 0 si fue correctamente cargado, -1 si hay un error en la lectura del archivo.
 */
int modificarPelicula(EMovie* movie);

#endif // FUNCIONES_H_INCLUDED
