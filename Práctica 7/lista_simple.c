#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;
    printf("Elemento %d insertado al inicio.\n", valor);
}

void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    if (actual == NULL) {
        printf("(lista vacía)\n");
        return;
    }
    printf("Contenido de la lista:\n");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza, *anterior = NULL;

    if (actual == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    if (actual != NULL && actual->dato == valor) {
        *cabeza = actual->siguiente;
        free(actual);
        printf("Elemento %d eliminado.\n", valor);
        return;
    }

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Elemento %d no encontrado.\n", valor);
        return;
    }

    anterior->siguiente = actual->siguiente;
    free(actual);
    printf("Elemento %d eliminado.\n", valor);
}

void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
    printf("\nMemoria liberada correctamente.\n");
}

int main(void) {
    struct Nodo *cabeza = NULL;
    int n, valor, eliminarValor;

    printf("=== LISTA ENLAZADA SIMPLE ===\n");
    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("\nIngrese el valor que desea eliminar: ");
    scanf("%d", &eliminarValor);
    eliminar(&cabeza, eliminarValor);
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}
