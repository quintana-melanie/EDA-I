#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }

    nuevo->dato = valor;

    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->siguiente = *cabeza; 
    } else {
        nuevo->siguiente = *cabeza;
        (*ultimo)->siguiente = nuevo;
        *cabeza = nuevo;
    }
    printf("Elemento %d insertado en lista circular.\n", valor);
}

void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("(lista vacía)\n");
        return;
    }
    struct Nodo *actual = cabeza;
    printf("Contenido de la lista circular:\n");
    do {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    } while (actual != cabeza);
    printf("(vuelve al inicio)\n");
}

void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;
    int encontrado = 0;

    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Elemento %d no encontrado.\n", valor);
        return;
    }

    if (actual == *cabeza) {
        if (*cabeza == *ultimo) {
            *cabeza = *ultimo = NULL; 
        } else {
            *cabeza = actual->siguiente;
            (*ultimo)->siguiente = *cabeza;
        }
    } else if (actual == *ultimo) {
        *ultimo = anterior;
        (*ultimo)->siguiente = *cabeza;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    free(actual);
    printf("Elemento %d eliminado de la lista circular.\n", valor);
}

void liberarCircular(struct Nodo *cabeza) {
    if (cabeza == NULL)
        return;

    struct Nodo *actual = cabeza;
    struct Nodo *siguiente;

    do {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    } while (actual != cabeza);

    printf("\nMemoria liberada correctamente.\n");
}

int main(void) {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;
    int n, valor, eliminarValor;

    printf("=== LISTA CIRCULAR ===\n");
    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarCircular(&cabeza, &ultimo, valor);
        recorrerCircular(cabeza);
    }

    printf("\nIngrese el valor que desea eliminar: ");
    scanf("%d", &eliminarValor);
    eliminarCircular(&cabeza, &ultimo, eliminarValor);
    recorrerCircular(cabeza);

    liberarCircular(cabeza);
    return 0;
}
