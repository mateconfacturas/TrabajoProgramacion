#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo
{
    char nombre[256]; // Ahora almacena toda la línea
    struct Nodo *sig;
} Nodo;

typedef Nodo *lista;

void cargarArchivo(const char *nombreArchivo, lista *cabeza);
void cantidadAnimales(lista cabeza, int cantidad);
void imprimirLista(lista );
int contarNodos(lista cabeza);
void liberarLista(lista* cabeza);


#endif