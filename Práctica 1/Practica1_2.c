#include <stdio.h>
#include <stdlib.h>   
#include <time.h>    

int main(void) {
    int n;
    int a[100];
    int suma = 0, resta = 0;
    int min, max, idxMin = 0, idxMax = 0;

    srand(time(NULL)); 

    n = rand() % 96 + 5;  
    printf("Tamaño del arreglo generado aleatoriamente: %d\n", n);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100 + 1;
    }

    suma = a[0];
    min = a[0];
    max = a[0];

    for (int i = 1; i < n; i++) {
        suma += a[i];

        if (a[i] < min) {
            min = a[i];
            idxMin = i;
        }
        if (a[i] > max) {
            max = a[i];
            idxMax = i;
        }
    }

    resta = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        resta -= a[i];
    }

    printf("\nElementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("\nResultados:\n");
    printf("Suma: %d\n", suma);
    printf("Resta (de final a inicio): %d\n", resta);
    printf("Promedio: %.2f\n", (float)suma / n);
    printf("Mínimo: %d (posición %d)\n", min, idxMin);
    printf("Máximo: %d (posición %d)\n", max, idxMax);

    return 0;
}

