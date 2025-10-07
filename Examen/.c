#include <stdio.h>   // Librería estándar (printf, scanf)
#include <stdlib.h>  // Librería para malloc(), realloc() y free()

int main() {
    int n, nuevos, total;      // Variables para el número de estudiantes
    float *calificaciones = NULL; // Puntero que almacenará la dirección del bloque de memoria
    float suma = 0.0, promedio = 0.0; // Variables para calcular el promedio

    // Pedir al usuario cuántos estudiantes desea registrar inicialmente
    printf("¿Cuántos estudiantes deseas registrar? ");
    scanf("%d", &n);

    // Reservar memoria dinámicamente con malloc()
    // Se multiplica n por sizeof(float) para reservar el espacio necesario
    calificaciones = (float *) malloc(n * sizeof(float));

    // Verificar si malloc() devolvió NULL 
    if (calificaciones == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1; // Termina el programa con un código de error
    }

    // Capturar las calificaciones desde el teclado
    suma = 0;
    for (int i = 0; i < n; i++) {
        printf("Calificación del estudiante %d: ", i + 1);
        scanf("%f", &calificaciones[i]); // Guardar cada calificación en el arreglo
        suma += calificaciones[i];       // Sumar para luego calcular el promedio
    }

    // Calcular el promedio general inicial
    promedio = suma / n;
    printf("Promedio inicial: %.2f\n", promedio);

    // Preguntar si desea agregar más estudiantes
    printf("¿Deseas agregar más estudiantes? (cantidad, 0 para no): ");
    scanf("%d", &nuevos);

    // Si el usuario quiere agregar más estudiantes:
    if (nuevos > 0) {
        // Calcular el nuevo tamaño total del arreglo
        total = n + nuevos;

        // Usar realloc() para ampliar el tamaño del arreglo
        float *temp = (float *) realloc(calificaciones, total * sizeof(float));

        // Verificar si realloc() falló
        if (temp == NULL) {
            printf("Error: no se pudo reasignar memoria.\n");
            free(calificaciones); // Liberar la memoria anterior antes de salir
            return 1;
        }

        // Si realloc() funcionó, actualizar el puntero original
        calificaciones = temp;

        // Capturar las nuevas calificaciones
        for (int i = n; i < total; i++) {
            printf("Calificación del estudiante %d: ", i + 1);
            scanf("%f", &calificaciones[i]);
        }

        // Recalcular el promedio total de todos los estudiantes
        suma = 0;
        for (int i = 0; i < total; i++) {
            suma += calificaciones[i];
        }
        promedio = suma / total;

        // Actualizar el número total de estudiantes
        n = total;
    }

    // Mostrar todas las calificaciones y el promedio final
    printf("\n=== Calificaciones registradas ===\n");
    for (int i = 0; i < n; i++) {
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);
    }

    // Mostrar el promedio general final
    printf("Promedio general: %.2f\n", promedio);

    // Liberar la memoria utilizada al final del programa
    free(calificaciones);

    // Mensaje final de confirmación
    printf("Memoria liberada correctamente.\n");

    // Fin del programa
    return 0;
}
