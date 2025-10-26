#include <stdio.h>
#include <stdlib.h>

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

void insertarCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = crearNodo(valor);

    if (*inicio == NULL) {
        *inicio = nuevo;
        nuevo->siguiente = *inicio; 
    } else {
        struct Nodo *temp = *inicio;
        while (temp->siguiente != *inicio) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
        nuevo->siguiente = *inicio;
    }
}

void mostrarCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("\nLa lista está vacía.\n");
        return;
    }

    struct Nodo *temp = inicio;
    printf("\nContenido de la lista circular:\n");
    do {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);
    printf("(vuelve al inicio)\n");
}

void liberarCircular(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *actual = inicio;
    struct Nodo *siguiente;
    do {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != inicio);

    printf("\nMemoria liberada correctamente.\n");
}

int main(void) {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos elementos deseas agregar a la lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&inicio, valor);
    }

    mostrarCircular(inicio);
    liberarCircular(inicio);

    return 0;
}
