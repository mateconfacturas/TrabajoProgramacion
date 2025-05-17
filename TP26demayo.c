/* Escriba un programa en lenguaje C que inicialice datos de estas categorías en algún TAD visto en clases, y los almacene de manera ordenada.
Los datos deben ser leídos de archivos de datos (aves.txt, mamiferos.txt, peces.txt, reptiles.txt) .
Cada archivo contendrá muchas líneas, cada lineal con el nombre correspondiente al animal de la categoría. Ejemplo de aves.txt 
-- El programa, luego de inicializar el TAD elegido y leer los 4 archivos debe pedir al usuario una categoría y cuantos debe imprimir: 
deberá imprimir al azar elementos de esa categoría sin repetir (si, deberá meter los elementos impresos en algún otro tipo de datos.
Se evaluará prolijidad, solución elegida, TAD elegidos, separación en varios archivos.*/

#include <stdio.h>
#include <stdlib.h>
void cargarArchivos(); 
typedef struct snodo{
    char nombre; 
    struct snodo *sig; 
}tnodo; 
typedef tnodo *tpuntero; 
int main(){
   int endswitch = 1; 
   int option;
    
  do{ 
    printf("Elija una categoria: \n");
    printf(" (1)Reptiles \n (2)Peces \n (3)Aves \n (4)Mamiferos \n (5)Finalizar programa \n\n");
    scanf("%i",&option); 
    switch(option){
        case 1: 
               // imprimirReptiles(); 
               printf("Dentro de case 1\n");
               //cargarArchivos();
        break; 
        case 2: 
                //imprimirPeces(); 
                printf("Dentro de case 2\n");
        break; 
        case 3: 
                //imprimirAves(); 
                printf("Dentro de case 3\n");
              
        break; 
        case 4: 
                //imprimirMamiferos(); 
                printf("Dentro de case 4\n");
                cargarArchivos();
        break; 
        case 5:
                endswitch=0; 
                printf("Hasta Pronto!\n");
        break;  
    }
} while ( endswitch > 0 );
 
    return 0; 
}

void cargarArchivos(){
 FILE *archivo;
    char linea[256]; // Asumimos que ninguna línea excederá los 255 caracteres

    // Abrir y leer mamiferos.txt
    archivo = fopen("C:\\Users\\guerr\\OneDrive\\Escritorio\\Codigos C\\mamiferos.txt", "r");
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
        nuevo->nombre = linea[0]; // Asignar el primer carácter de la línea al nodo
        nuevo->sig = NULL; // Inicializar el siguiente puntero a NULL
        printf("%s", linea); // Imprimir la línea leída
    }
    fclose(archivo);
    printf("\n\n");
    /*
    // Abrir y leer aves.txt
    archivo = fopen("C:\\Users\\guerr\\OneDrive\\Escritorio\\Codigos C\\aves.txt", "r");
    if (archivo == NULL){ 
        perror("Error"); return; 
    }
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    fclose(archivo);
    // ...y así con los otros archivos
    printf("\n\n");
        // Abrir y leer Reptiles.txt
    archivo = fopen("C:\\Users\\guerr\\OneDrive\\Escritorio\\Codigos C\\Reptiles.txt", "r");
    if (archivo == NULL){ 
        perror("Error"); return; 
    }
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    fclose(archivo);
    // ...y así con los otros archivos
    printf("\n\n");

        // Abrir y leer peces.txt
    archivo = fopen("C:\\Users\\guerr\\OneDrive\\Escritorio\\Codigos C\\peces.txt", "r");
    if (archivo == NULL){ 
        perror("Error"); return; 
    }
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        printf("%s", linea);
    }
    fclose(archivo);
    // ...y así con los otros archivos
    printf("\n\n");*/
}
