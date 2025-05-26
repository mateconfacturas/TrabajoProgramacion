/* Escriba un programa en lenguaje C que inicialice datos de estas categorías en algún TAD visto en clases, y los almacene de manera ordenada.
Los datos deben ser leídos de archivos de datos (aves.txt, mamiferos.txt, peces.txt, reptiles.txt) .
Cada archivo contendrá muchas líneas, cada lineal con el nombre correspondiente al animal de la categoría. Ejemplo de aves.txt
-- El programa, luego de inicializar el TAD elegido y leer los 4 archivos debe pedir al usuario una categoría y cuantos debe imprimir:
deberá imprimir al azar elementos de esa categoría sin repetir (si, deberá meter los elementos impresos en algún otro tipo de datos.
Se evaluará prolijidad, solución elegida, TAD elegidos, separación en varios archivos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp26mayo.h"

int main()
{
    int salida = 1;
    int categoria;
    int cantidad;

    lista cabezaMamiferos = NULL;
    lista cabezaAves = NULL;
    lista cabezaPeces = NULL;
    lista cabezaReptiles = NULL;

    cargarArchivo("C:\\Users\\caro\\Documents\\GitHub\\TrabajoProgramacion\\mamiferos.txt", &cabezaMamiferos);
    cargarArchivo("C:\\Users\\caro\\Documents\\GitHub\\TrabajoProgramacion\\aves.txt", &cabezaAves);
    cargarArchivo("C:\\Users\\caro\\Documents\\GitHub\\TrabajoProgramacion\\Reptiles.txt", &cabezaReptiles);
    cargarArchivo("C:\\Users\\caro\\Documents\\GitHub\\TrabajoProgramacion\\peces.txt", &cabezaPeces);

    do
    {

        printf("\n==============================\n");
        printf("Elija una categoria:\n");
        printf(" (1) Reptiles\n (2) Peces\n (3) Aves\n (4) Mamiferos\n (5) Finalizar programa\n");
        printf("==============================\n\n");
        scanf("%i", &categoria);

        switch (categoria)
    {
        case 1:
        {   
            int totalReptiles = contarNodos(cabezaReptiles);
            printf("Ingrese la cantidad de reptiles que quiere ver: ");
            scanf("%d", &cantidad);

             if (cantidad > totalReptiles) 
             {
                printf("Error: Solo hay %d reptiles disponibles.\n", totalReptiles);
             } 
             else 
             {
                cantidadAnimales(cabezaReptiles, cantidad);
             }
            break;
        }
        case 2:
        {
            int totalPeces = contarNodos(cabezaPeces);
            printf("Ingrese la cantidad de peces que quiere ver: ");
            scanf("%d", &cantidad);
             if (cantidad > totalPeces) 
             {
                printf("Error: Solo hay %d peces disponibles.\n", totalPeces);
             } 
             else 
             {
                cantidadAnimales(cabezaPeces, cantidad);
             }
            break;
        }
        case 3:
        {
            int totalAves = contarNodos(cabezaAves);
            printf("Ingrese la cantidad de aves que quiere ver: ");
            scanf("%d", &cantidad);
             if (cantidad > totalAves) 
             {
                printf("Error: Solo hay %d aves disponibles.\n", totalAves);
             } 
             else 
             {
                cantidadAnimales(cabezaAves, cantidad);
             }
            break;
        }
        case 4:
        {
            int totalMamiferos = contarNodos(cabezaMamiferos);
            printf("Ingrese la cantidad de mamiferos que quiere ver: ");
            scanf("%d", &cantidad);
             if (cantidad > totalMamiferos) 
             {
                printf("Error: Solo hay %d mamiferos disponibles.\n", totalMamiferos);
             } 
             else 
             {
                cantidadAnimales(cabezaMamiferos, cantidad);
             }
            break;
        }
        case 5:
        {
            salida = 0;
            printf("Hasta Pronto!\n");
            break;
        }
    }
    } while (salida > 0);


    
    liberarLista(&cabezaAves);
    liberarLista(&cabezaMamiferos);
    liberarLista(&cabezaReptiles);
    liberarLista(&cabezaPeces);

    return 0;
}

