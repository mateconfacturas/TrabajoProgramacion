/* Escriba un programa en lenguaje C que inicialice datos de estas categorías en algún TAD visto en clases, y los almacene de manera ordenada.
Los datos deben ser leídos de archivos de datos (aves.txt, mamiferos.txt, peces.txt, reptiles.txt) .
Cada archivo contendrá muchas líneas, cada lineal con el nombre correspondiente al animal de la categoría. Ejemplo de aves.txt 
-- El programa, luego de inicializar el TAD elegido y leer los 4 archivos debe pedir al usuario una categoría y cuantos debe imprimir: 
deberá imprimir al azar elementos de esa categoría sin repetir (si, deberá meter los elementos impresos en algún otro tipo de datos.
Se evaluará prolijidad, solución elegida, TAD elegidos, separación en varios archivos.*/

#include <stdio.h>
#include <stdlib.h>

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
        break; 
        case 5:
                end=0; 
                printf("Hasta Pronto!\n");
        break;  
    }
} while ( end > 0 );
 
    return 0; 
}

void cargarArchivos(){
FILE *archivo;
    char linea[256]; // Asumimos que ninguna línea excederá los 255 caracteres

    // Abrir el archivo en modo lectura ("r")
    archivo = fopen(nombreArchivo, "r");

    // Verificar si el archivo se abrió correctamente
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        return; // Salir de la función si no se pudo abrir el archivo
    }

    // Leer el archivo línea por línea hasta el final del archivo (EOF)
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        //
        // Insertar de manera ordenada en la lista
        //
    }

    // Cerrar el archivo para liberar los recursos
    fclose(archivo);
}
