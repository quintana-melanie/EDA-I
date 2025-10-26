#include <stdio.h>
#include <stdlib.h>

#define MAX 5

                           // PILA //
struct Pila {
    int elementos[MAX];
    int tope;
};

void inicializarPila(struct Pila *p) {
    p->tope = -1;
    printf("Pila inicializada vacía.\n");
}

int pilaLlena(struct Pila *p) {
    return p->tope == MAX - 1;
}

int pilaVacia(struct Pila *p) {
    return p->tope == -1;
}

void push(struct Pila *p, int valor) {
    if (pilaLlena(p)) {
        printf("La pila está llena, no se puede insertar %d.\n", valor);
        return;
    }
    p->tope++;
    p->elementos[p->tope] = valor;
    printf("Elemento %d apilado.\n", valor);
}

int pop(struct Pila *p) {
    if (pilaVacia(p)) {
        printf("La pila está vacía, no se puede desapilar.\n");
        return -1;
    }
    int valor = p->elementos[p->tope];
    p->tope--;
    printf("Elemento %d desapilado.\n", valor);
    return valor;
}

void mostrarPila(struct Pila *p) {
    if (pilaVacia(p)) {
        printf("(vacía)\n");
        return;
    }
    printf("Estado de la pila: ");
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->elementos[i]);
    }
    printf("\n");
}

                         // COLA //
struct Cola {
    int elementos[MAX];
    int frente;
    int final;
};

void inicializarCola(struct Cola *c) {
    c->frente = 0;
    c->final = -1;
    printf("Cola inicializada vacía.\n");
}

int colaLlena(struct Cola *c) {
    return c->final == MAX - 1;
}

int colaVacia(struct Cola *c) {
    return c->frente > c->final;
}

void enqueue(struct Cola *c, int valor) {
    if (colaLlena(c)) {
        printf("La cola está llena, no se puede encolar %d.\n", valor);
        return;
    }
    c->final++;
    c->elementos[c->final] = valor;
    printf("Elemento %d encolado.\n", valor);
}

int dequeue(struct Cola *c) {
    if (colaVacia(c)) {
        printf("La cola está vacía, no se puede desencolar.\n");
        return -1;
    }
    int valor = c->elementos[c->frente];
    c->frente++;
    printf("Elemento %d desencolado.\n", valor);
    return valor;
}

void mostrarCola(struct Cola *c) {
    if (colaVacia(c)) {
        printf("(vacía)\n");
        return;
    }
    printf("Estado de la cola: ");
    for (int i = c->frente; i <= c->final; i++) {
        printf("%d ", c->elementos[i]);
    }
    printf("\n");
}

                         //MENÚ PRINCIPAL //
int main(void) {
    struct Pila pila;
    struct Cola cola;
    int opcion, n, valor;

    do {
        printf("\n=== MENÚ PRINCIPAL ===\n");
        printf("1. Operaciones con PILA\n");
        printf("2. Operaciones con COLA\n");
        printf("3. Comparación Pila vs Cola\n");
        printf("0. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                inicializarPila(&pila);
                printf("\n¿Cuántos elementos deseas apilar (máximo %d)? ", MAX);
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Elemento %d: ", i + 1);
                    scanf("%d", &valor);
                    push(&pila, valor);
                    mostrarPila(&pila);
                }
                printf("\n¿Cuántos elementos deseas desapilar? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    pop(&pila);
                    mostrarPila(&pila);
                }
                break;

            case 2:
                inicializarCola(&cola);
                printf("\n¿Cuántos elementos deseas encolar (máximo %d)? ", MAX);
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Elemento %d: ", i + 1);
                    scanf("%d", &valor);
                    enqueue(&cola, valor);
                    mostrarCola(&cola);
                }
                printf("\n¿Cuántos elementos deseas desencolar? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    dequeue(&cola);
                    mostrarCola(&cola);
                }
                break;

            case 3:
                printf("\n COMPARACIÓN ENTRE PILA Y COLA:\n");
                printf(" - PILA → LIFO (Último en entrar, primero en salir)\n");
                printf(" - COLA → FIFO (Primero en entrar, primero en salir)\n");
                break;

            case 0:
                printf("\nSaliendo del programa... \n");
                break;

            default:
                printf("Opción inválida. Intenta nuevamente.\n");
        }
    } while (opcion != 0);

    return 0;
}
