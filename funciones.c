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


void liberarLista(lista* cabeza) {
    lista actual = cabeza;  // lista es equivalente a Nodo
    while (actual != NULL) {
        lista temp = actual; // temp es del mismo tipo que actual (Nodo*)
        actual = actual->sig;
        free(temp);
    }
    *cabeza = NULL; // Importante para evitar "dangling pointers"
}
void seleccionarAnimalesAzar(lista original, int cantidad, lista* seleccionados) {
    //contar animales
    int total = contarNodos(original);
    if (cantidad > total) cantidad = total;

    //cargar los nodos en un arreglo
    lista aux = original;
    char** arreglo = malloc(total * sizeof(char*));
    for (int i = 0; i < total && aux != NULL; i++) {
        arreglo[i] = aux->nombre;
        aux = aux->sig;
    }

    //seleccionar aleatoriamente sin repetir
    srand(time(NULL));
    int elegidos = 0;
    while (elegidos < cantidad) {
        int pos = rand() % total;
        char* candidato = arreglo[pos];
        if (yaSeleccionado(*seleccionados, candidato) == 0) {
            agregarALista(seleccionados, candidato);
            elegidos++;
        }
    }

    //mostrar seleccionados
    printf("\nAnimales seleccionados al azar:\n");
    imprimirLista(seleccionados);

    free(arreglo);
}
void imprimirLista(lista cabeza)
{
    lista aux = cabeza;
    while (aux != NULL)
    {
        printf(" - %s", aux->nombre); // Imprimir el nombre del animal
        aux = aux->sig;               // Avanzar al siguiente nodo
    }
}
int yaSeleccionado(lista listaSeleccionados, const char* nombre) {
    while (listaSeleccionados != NULL) {
        if (strcmp(listaSeleccionados->nombre, nombre) == 0)
            return 1; // ya fue elegido
        listaSeleccionados = listaSeleccionados->sig;
    }
    return 0;
}

void agregarALista(lista* cabeza, const char* nombre) {
    lista nuevo = (lista)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria.\n");
        return;
    }
    strcpy(nuevo->nombre, nombre);
    nuevo->sig = NULL;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        lista aux = *cabeza;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    }
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