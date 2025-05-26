/* Escriba un programa en lenguaje C que inicialice datos de estas categorías en algún TAD visto en clases, y los almacene de manera ordenada.
Los datos deben ser leídos de archivos de datos (aves.txt, mamiferos.txt, peces.txt, reptiles.txt) .
Cada archivo contendrá muchas líneas, cada lineal con el nombre correspondiente al animal de la categoría. Ejemplo de aves.txt
-- El programa, luego de inicializar el TAD elegido y leer los 4 archivos debe pedir al usuario una categoría y cuantos debe imprimir:
deberá imprimir al azar elementos de esa categoría sin repetir (si, deberá meter los elementos impresos en algún otro tipo de datos.
Se evaluará prolijidad, solución elegida, TAD elegidos, separación en varios archivos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    char nombre[256]; // Ahora almacena toda la línea
    struct Nodo *sig;
} Nodo;

typedef Nodo *lista;

void cargarArchivo(const char *nombreArchivo, lista *cabeza)
{

    FILE *archivo = fopen(nombreArchivo, "r");
    char linea[256];        // Asumimos que ninguna línea excederá los 255 caracteres
    lista ultimo = NULL; // Inicializar el puntero último a NULL

    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo %s\n", nombreArchivo);
        printf("Error");
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

/*void imprimirLista(tpuntero cabeza)
{
    tpuntero aux = cabeza;
    while (aux != NULL)
    {
        printf(" - %s", aux->nombre); // Imprimir el nombre del animal
        aux = aux->sig;               // Avanzar al siguiente nodo
    }
}
*/

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

void liberarListas(lista* cabeza){

    Nodo* actual = *cabeza
    while (cabeza != NULL) {
        Nodo* temp = cabeza;
        cabeza = cabeza->sig;
        free(temp);
    }
}









int main()
{
    int salida = 1;
    int categoria;
    int cantidad;

    lista cabezaMamiferos = NULL;
    lista cabezaAves = NULL;
    lista cabezaPeces = NULL;
    lista cabezaReptiles = NULL;

    cargarArchivo("mamiferos.txt", &cabezaMamiferos);
    cargarArchivo("aves.txt", &cabezaAves);
    cargarArchivo("Reptiles.txt", &cabezaReptiles);
    cargarArchivo("peces.txt", &cabezaPeces);

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


    

    return 0;
}

/*#include <time.h>

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

void seleccionarAnimalesAzar(lista original, int cantidad, lista* seleccionados) {
    // Paso 1: contar animales
    int total = contarNodos(original);
    if (cantidad > total) cantidad = total;

    // Paso 2: cargar los nodos en un arreglo
    lista aux = original;
    char** arreglo = malloc(total * sizeof(char*));
    for (int i = 0; i < total && aux != NULL; i++) {
        arreglo[i] = aux->nombre;
        aux = aux->sig;
    }

    // Paso 3: seleccionar aleatoriamente sin repetir
    srand(time(NULL));
    int elegidos = 0;
    while (elegidos < cantidad) {
        int pos = rand() % total;
        char* candidato = arreglo[pos];
        if (!yaSeleccionado(*seleccionados, candidato)) {
            agregarALista(seleccionados, candidato);
            elegidos++;
        }
    }

    // Paso 4: mostrar seleccionados
    printf("\nAnimales seleccionados al azar:\n");
    imprimirLista(*seleccionados);

    free(arreglo);
}
*/
