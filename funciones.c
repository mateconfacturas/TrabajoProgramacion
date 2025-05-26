#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp26mayo.h"


void imprimirLista(tpuntero cabeza)
{
    tpuntero aux = cabeza;
    while (aux != NULL)
    {
        printf(" - %s", aux->nombre); // Imprimir el nombre del animal
        aux = aux->sig;               // Avanzar al siguiente nodo
    }
}

void cantidadAnimales(tpuntero cabeza, int cantidad)
{
    tpuntero aux = cabeza;
    int i = 0;

    while (aux != NULL && i < cantidad)
    {
        printf("%s", aux->nombre);
        aux = aux->sig;
        i++;
    }
}

int contarNodos(tpuntero cabeza) {
    int contador = 0;
    while (cabeza != NULL) {
        contador++;
        cabeza = cabeza->sig;
    }
    return contador;
}

void cargarArchivo(const char *nombreArchivo, tpuntero *cabeza)
{

    FILE *archivo = fopen(nombreArchivo, "r");
    char linea[256];        // Asumimos que ninguna línea excederá los 255 caracteres
    tpuntero ultimo = NULL; // Inicializar el puntero último a NULL

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        perror("Error");
        return;
    }
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        tpuntero nuevo = (tpuntero)malloc(sizeof(tnodo));
        if (nuevo == NULL)
        {
            perror("Error al asignar memoria");
            fclose(archivo);
            return;
        }
        strcpy(nuevo->nombre, linea); // Copiar la línea leída al nuevo nodo
        nuevo->sig = NULL;            // Inicializar el siguiente nodo a NULL

        if (*cabeza == NULL)
        {
            *cabeza = nuevo;
            ultimo = nuevo;
        }
        else
        {
            ultimo->sig = nuevo; // Enlazar el nuevo nodo al final de la lista
            ultimo = nuevo;      // Actualizar el último nodo
        }
    }
    fclose(archivo);
}