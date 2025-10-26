#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    return nuevo;
}

void insertarFinal(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = crearNodo(valor);

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        struct Nodo *temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void mostrarLista(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;
    printf("\nContenido de la lista:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

void liberarLista(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("\nMemoria liberada correctamente.\n");
}

int main(void) {
    struct Nodo *lista = NULL;
    int n, valor;

    printf("¿Cuántos elementos deseas agregar a la lista? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&lista, valor);
    }

    mostrarLista(lista);
    liberarLista(lista);
    return 0;
}
