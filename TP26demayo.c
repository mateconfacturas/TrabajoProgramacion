/* Escriba un programa en lenguaje C que inicialice datos de estas categorías en algún TAD visto en clases, y los almacene de manera ordenada.
Los datos deben ser leídos de archivos de datos (aves.txt, mamiferos.txt, peces.txt, reptiles.txt) .
Cada archivo contendrá muchas líneas, cada lineal con el nombre correspondiente al animal de la categoría. Ejemplo de aves.txt 
-- El programa, luego de inicializar el TAD elegido y leer los 4 archivos debe pedir al usuario una categoría y cuantos debe imprimir: 
deberá imprimir al azar elementos de esa categoría sin repetir (si, deberá meter los elementos impresos en algún otro tipo de datos.
Se evaluará prolijidad, solución elegida, TAD elegidos, separación en varios archivos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cargarArchivos(); 
        typedef struct snodo{
        char nombre[256]; // Ahora almacena toda la línea
        struct snodo *sig;
    } tnodo; 
typedef tnodo *tpuntero; 

int main(){
   int endswitch = 1; 
   int option;
    
    cargarArchivo("mamiferos.txt", &cabezaMamiferos);
    cargarArchivo("aves.txt", &cabezaAves);
    cargarArchivo("reptiles.txt", &cabezaReptiles);
    cargarArchivo("peces.txt", &cabezaPeces);
    
    tpuntero cabezaMamiferos = NULL; 
    tpuntero cabezaAves = NULL;
    tpuntero cabezaPeces = NULL;
    tpuntero cabezaReptiles = NULL; 

  do{ 
    printf("Elija una categoria: \n");
    printf(" (1)Reptiles \n (2)Peces \n (3)Aves \n (4)Mamiferos \n (5)Finalizar programa \n\n");
    scanf("%i",&option); 
    switch(option){
        case 1: 
          imprimirLista(cabezaReptiles);           
        break; 
        case 2: 
        imprimirLista(cabezaPeces);
        break; 
        case 3: 
                imprimirLista(cabezaAves);             
        break; 
        case 4:
                imprimirLista(cabezaMamiferos);
        break; 
        case 5:
                endswitch=0; 
                printf("Hasta Pronto!\n");
        break;  
    }
} while ( endswitch > 0 );
 
    return 0; 
}

void cargarArchivos(const char *nombreArchivo, tpuntero *cabeza){
 FILE *archivo= fopen(nombreArchivo, "r");
    char linea[256]; // Asumimos que ninguna línea excederá los 255 caracteres
    tpuntero ultimo = NULL; // Inicializar el puntero último a NULL 
    if (archivo == NULL){ 
        perror("Error"); return; 
    }
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
    tpuntero nuevo = (tpuntero)malloc(sizeof(tnodo));
        if (nuevo == NULL) {
            perror("Error al asignar memoria");
            fclose(archivo);
            return;
        }
        strcpy(nuevo->nombre, linea); // Copiar la línea leída al nuevo nodo 
        nuevo->sig = NULL; // Inicializar el siguiente nodo a NULL 
        if(*cabeza == NULL){
            *cabeza = nuevo; 
            ultimo= nuevo; 
        }
        else{
            ultimo->sig = nuevo; // Enlazar el nuevo nodo al final de la lista
            ultimo = nuevo; // Actualizar el último nodo 
        }
    }
    fclose(archivo);
    printf("\n\n");
}

void imprimirLista(tpuntero cabeza){
    tpuntero aux = cabeza; 
    while (aux != NULL) {
        printf("%s", aux->nombre); // Imprimir el nombre del animal
        aux = aux->sig; // Avanzar al siguiente nodo
    }
}