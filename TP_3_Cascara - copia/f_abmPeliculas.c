#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define cELEMENTS 20
#define EMPTY 0
#define DELETED -1
#define OCCUPIED 1


int altaPeliculas(eMovie *peliculas,int cantElementos)
{
    char auxTitulo[50], auxGenero[25],auxDuracion[4],auxPuntaje[3], auxLinkImagen[100], auxIdPeli[4] ;
    int ultimo_id = 0;


    int freeIndex;

    freeIndex = buscarLugarLibre(peliculas,cELEMENTS,-1);
        if (freeIndex == -1)
        {
            printf("No hay  espacio suficiente para seguir ingresando");
        }
    else
    {

        while(!getStringValidado("Ingrese titulo: ",auxTitulo))
        {
            printf("Error, solo letras!!\n");
        }
        /*while(!getStringValidado("Ingrese genero: ",auxGenero))
        {
            printf("Error, solo letras!!\n");
        }

        while(!getNumerosString("Ingrese duracion: ",auxDuracion))
        {
            printf("Error, solo numeros!\n");
        }

        obtenerDatosPorTeclado("Ingrese descripcion: ",peliculas[freeIndex].descripcion);

        while(!getNumerosString("Ingrese el puntaje: ",auxPuntaje))
        {
            printf("Error, solo numeros!\n");
        }

        obtenerDatosPorTeclado("Ingrese link de imagen: ",peliculas[freeIndex].linkImagen);*/

        strcpy(peliculas[freeIndex].titulo,auxTitulo);
        /*strcpy(peliculas[freeIndex].genero,auxGenero);
        peliculas[freeIndex].duracion=atoi(auxDuracion);
        peliculas[freeIndex].puntaje=atoi(auxPuntaje);*/
        peliculas[freeIndex].flag_estado = OCCUPIED;
        ultimo_id = ultimo_id +1;
        peliculas[freeIndex].id_movie = ultimo_id;

        return 1;
    }
    return 0;

}

/** \brief Realiza la baja logica de un elemento del array peliculas
 * \param el array peliculas
 * \param la cantidad de elementos que posee el array
 * \return 1 si la tarea se realizo, caso contrario 0
 *
 */

int bajaPliculas(eMovie *peliculas,int cantElementos)
{
    int valFound, i, convertInt;

    char auxID[4];

    for (i = 0 ; i < cantElementos ; i++)
    {
        if (peliculas[i].flag_estado == OCCUPIED)
        {
            printf( "\t Titulo: %s \t- ID: %d\n",peliculas[i].titulo,peliculas[i].id_movie);
        }
    }
    while (getNumerosString("Ingrese el  ID que desee eliminar: ", auxID) == -1)
    {
        printf("Error,  solo  numeros!\n");
    }

    convertInt = atoi(auxID);
    valFound=buscarLugarLibre(peliculas,cantElementos,auxID);
    if(valFound != -1)
    {
        printf( "\tHa eliminado\n Titulo: %s \t ID: %d\n",peliculas[i].titulo,peliculas[i].id_movie);
        return 1;
    }
    else{

    printf("No se encontro el ID!\n");
    }

    return 0;
}

