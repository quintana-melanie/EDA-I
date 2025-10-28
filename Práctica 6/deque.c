#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int size;
} Deque;

void inicializarDeque(Deque *d) {
    d->frente = 0;
    d->size = 0;
    printf("Deque inicializado\n");
}

int isEmpty(Deque *d) {
    return d->size == 0;
}

int isFull(Deque *d) {
    return d->size == MAX;
}

int rearIndex(Deque *d) {
    return (d->frente + d->size - 1 + MAX) % MAX;
}

void insert_front(Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: Deque lleno\n");
        return;
    }
    d->frente = (d->frente - 1 + MAX) % MAX;
    d->datos[d->frente] = valor;
    d->size++;
}

void insert_rear(Deque *d, int valor) {
    if (isFull(d)) {
        printf("Error: Deque lleno\n");
        return;
    }
    int rear = (d->frente + d->size) % MAX;
    d->datos[rear] = valor;
    d->size++;
}

int delete_front(Deque *d) {
    if (isEmpty(d)) {
        printf("Error: Deque vacío\n");
        return -1;
    }
    int valor = d->datos[d->frente];
    d->frente = (d->frente + 1) % MAX;
    d->size--;
    return valor;
}

int delete_rear(Deque *d) {
    if (isEmpty(d)) {
        printf("Error: Deque vacío\n");
        return -1;
    }
    int rear = rearIndex(d);
    int valor = d->datos[rear];
    d->size--;
    return valor;
}

int peek_front(Deque *d) {
    if (isEmpty(d)) return -1;
    return d->datos[d->frente];
}

int peek_rear(Deque *d) {
    if (isEmpty(d)) return -1;
    return d->datos[rearIndex(d)];
}

void printDeque(Deque *d) {
    if (isEmpty(d)) {
        printf("Deque vacío\n");
        return;
    }
    printf("Deque: ");
    for (int i = 0; i < d->size; i++) {
        int idx = (d->frente + i) % MAX;
        printf("%d ", d->datos[idx]);
    }
    printf("\nFrente: %d, Rear: %d\n", d->frente, rearIndex(d));
}

int main() {
    Deque d;
    inicializarDeque(&d);

    insert_front(&d, 10);
    insert_rear(&d, 15);
    insert_rear(&d, 20);
    insert_front(&d, 30);
    insert_rear(&d, 40);
    printDeque(&d);

    printf("Eliminado front: %d\n", delete_front(&d));
    printf("Eliminado rear: %d\n", delete_rear(&d));
    printDeque(&d);

    return 0;
}
