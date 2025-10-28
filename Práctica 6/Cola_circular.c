#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size;
} ColaCircular;

void inicializarCola(ColaCircular *c) {
    c->frente = 0;
    c->final = 0;
    c->size = 0;
    printf("Cola circular inicializada\n");
}

int isEmpty(ColaCircular *c) {
    return c->size == 0;
}

int isFull(ColaCircular *c) {
    return c->size == MAX;
}

void enqueue(ColaCircular *c, int valor) {
    if (isFull(c)) {
        printf("Error: Cola llena, no se puede encolar %d\n", valor);
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->size++;
}

int dequeue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Error: Cola vacía\n");
        return -1;
    }
    int valor = c->datos[c->frente];
    c->frente = (c->frente + 1) % MAX;
    c->size--;
    return valor;
}

int peek(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Cola vacía\n");
        return -1;
    }
    return c->datos[c->frente];
}

void printQueue(ColaCircular *c) {
    if (isEmpty(c)) {
        printf("Cola vacía\n");
        return;
    }
    printf("Cola: ");
    for (int i = 0, idx = c->frente; i < c->size; i++) {
        printf("%d ", c->datos[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\nFrente: %d, Final: %d\n", c->frente, c->final);
}

int main() {
    ColaCircular c;
    inicializarCola(&c);

    enqueue(&c, 5);
    enqueue(&c, 10);
    enqueue(&c, 15);
    printQueue(&c);

    printf("Desencolado: %d\n", dequeue(&c));
    printQueue(&c);

    enqueue(&c, 20);
    enqueue(&c, 25);
    enqueue(&c, 30); 
    printQueue(&c);

    return 0;
}
