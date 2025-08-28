#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n;
    printf("Ingresa la cantidad de elementos del arreglo (max 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Error: el tamaño debe estar entre 1 y 100.\n");
        return 1;
    }

    int a[100];

    srand(time(NULL));

    printf("\nArreglo original:\n");
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;  
        printf("%d ", a[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    printf("\n\nArreglo invertido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
    return 0;
}
