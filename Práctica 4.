#include <stdio.h>
#include <stdlib.h>  

int main(void) {
    int n, m;
    int *arr, *arr2;

    printf("¿Cuántos enteros deseas almacenar? ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Error: no se pudo asignar memoria con malloc.\n");
        return 1;
    }

    printf("\nValores iniciales con malloc (basura):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    arr2 = (int *)calloc(n, sizeof(int)); 

    if (arr2 == NULL) {
        printf("Error: no se pudo asignar memoria con calloc.\n");
        free(arr);
        return 1;
    }

    printf("\nValores iniciales con calloc (inicializados a 0):\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("\nIngresa %d valores enteros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    printf("\nContenido actual de arr2:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("\n¿Cuál será el nuevo tamaño del arreglo? ");
    scanf("%d", &m);

    int *temp = (int *)realloc(arr2, m * sizeof(int));

    if (temp == NULL) {
        printf("Error: no se pudo redimensionar la memoria.\n");
        free(arr);
        free(arr2);
        return 1;
    }

    arr2 = temp; 

    if (m > n) {
        printf("\nEl arreglo se amplió. Ingresa los %d nuevos valores:\n", m - n);
        for (int i = n; i < m; i++) {
            printf("Valor %d: ", i + 1);
            scanf("%d", &arr2[i]);
        }
    }

    printf("\nContenido final del arreglo arr2:\n");
    for (int i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    free(arr);
    free(arr2);

    printf("\n Memoria liberada correctamente.\n");

    return 0;
}

                                //Actividad:
1. ¿Qué diferencia observaron entre los valores iniciales con malloc y calloc?
   malloc deja basura (valores aleatorios en memoria), mientras que calloc inicializa todos los valores a 0.
2. ¿Qué sucede si en realloc piden un tamaño más grande que el original? 
  Se reserva más espacio, los nuevos elementos quedan sin inicializar (basura) y puedes llenarlos con nuevos valores.
  ¿y más pequeño? Se pierden los valores que estaban más allá del nuevo tamaño.
3. ¿Qué pasa si olvidan llamar a free?
  Se genera una fuga de memoria (el sistema no recupera la memoria reservada).
