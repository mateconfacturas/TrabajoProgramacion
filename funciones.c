#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp26mayo.h"


void imprimirLista(lista cabeza)
{
    lista aux = cabeza;
    while (aux != NULL)
    {
        printf(" - %s", aux->nombre); // Imprimir el nombre del animal
        aux = aux->sig;               // Avanzar al siguiente nodo
    }
}

void cantidadAnimales(lista cabeza, int cantidad)
{
    lista aux = cabeza;
    int i = 0;

    while (aux != NULL && i < cantidad)
    {
        printf("%s", aux->nombre);
        aux = aux->sig;
        i++;
    }
}

int contarNodos(lista cabeza) {
    int contador = 0;
    while (cabeza != NULL) {
        contador++;
        cabeza = cabeza->sig;
    }
    return contador;
}

void liberarListas(Nodo** cabeza) {
    Nodo* actual = *cabeza;
    Nodo* temp;

    while (actual != NULL) {
        temp = actual;
        actual = actual->sig;
        free(temp);
    }

    *cabeza = NULL;  // Importante: evitar punteros colgantes
}

void cargarArchivo(const char *nombreArchivo, lista *cabeza)
{

    FILE *archivo = fopen(nombreArchivo, "r");
    char linea[256];        // Asumimos que ninguna línea excederá los 255 caracteres
    lista ultimo = NULL; // Inicializar el puntero último a NULL

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        perror("Error");
        return;
    }
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        lista nuevo = (lista)malloc(sizeof(Nodo));
        if (nuevo == NULL)
        {
            printf("Error al asignar memoria");
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