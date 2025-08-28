#include <stdio.h>
#include <stdlib.h>   
#include <time.h>     

int main(void) {
    int n;
    int a[100];

    srand(time(NULL));

    do {
        printf("Ingresa la cantidad de elementos (entre 1 y 100): ");
        scanf("%d", &n);
        if (n <= 0 || n > 100) {
            printf("Error: Ingresa un número válido.\n");
        }
    } while (n <= 0 || n > 100);

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100 + 1;  
    }

    printf("\nLos elementos generados aleatoriamente son:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
