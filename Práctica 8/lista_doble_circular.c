#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevo->dato = valor;

    if (*inicio == NULL) {
        *inicio = nuevo;
        nuevo->siguiente = nuevo;
        nuevo->anterior = nuevo;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;

    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *temp = inicio;
    printf("Lista circular: ");

    do {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    struct Nodo *temp = *inicio;

    do {
        if (temp->dato == valor) {
            if (temp->siguiente == temp) {
                free(temp);
                *inicio = NULL;
                printf("Último nodo eliminado.\n");
                return;
            }

            temp->anterior->siguiente = temp->siguiente;
            temp->siguiente->anterior = temp->anterior;

            if (temp == *inicio)
                *inicio = temp->siguiente;

            free(temp);
            printf("Nodo circular eliminado.\n");
            return;
        }
        temp = temp->siguiente;
    } while (temp != *inicio);

    printf("Valor no encontrado.\n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos valores insertarás en la lista circular? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        insertarCircular(&inicio, valor);
    }

    recorrerCircular(inicio);

    printf("Valor a eliminar: ");
    scanf("%d", &valor);
    eliminarCircular(&inicio, valor);

    recorrerCircular(inicio);
    return 0;
}
