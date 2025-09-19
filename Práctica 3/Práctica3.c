#include <stdio.h>
#include <string.h>

#define MAX 10   
#define MAX_DIR 5

struct pelicula {
    char nombre[50];
    char genero[20];
    int anio;
    int numDirectores;
    char directores[MAX_DIR][50];
};

int main(void) {
    struct pelicula videoteca[MAX];
    struct pelicula *p = videoteca; 
    int n;

    printf("¿Cuántas películas deseas registrar (1 a %d)? ", MAX);
    scanf("%d", &n);
    getchar();

    if (n <= 0 || n > MAX) {
        printf("Error: El número de películas debe estar entre 1 y %d.\n", MAX);
        return 1;
    }

for (int i = 0; i < n; i++) {
        printf("\n--- Película %d ---\n", i + 1);

        printf("Nombre: ");
        fgets((p+i)->nombre, sizeof((p+i)->nombre), stdin);
        (p+i)->nombre[strcspn((p+i)->nombre, "\n")] = 0;

        printf("Género: ");
        fgets((p+i)->genero, sizeof((p+i)->genero), stdin);
        (p+i)->genero[strcspn((p+i)->genero, "\n")] = 0;

        printf("Año: ");
        scanf("%d", &(p+i)->anio);
        getchar();

        printf("Número de directores: ");
        scanf("%d", &(p+i)->numDirectores);
        getchar();

        if ((p+i)->numDirectores <= 0) {
            printf("Error: número inválido de directores.\n");
            return 1;
        }

        for (int j = 0; j < (p+i)->numDirectores; j++) {
            printf("Director %d: ", j + 1);
            fgets((p+i)->directores[j], sizeof((p+i)->directores[j]), stdin);
            (p+i)->directores[j][strcspn((p+i)->directores[j], "\n")] = 0;
        }
    }

    printf("\n##### Videoteca en orden inverso #####\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("\nPelicula: %s\n", (p+i)->nombre);
        printf("Genero: %s\n", (p+i)->genero);
        printf("Año: %d\n", (p+i)->anio);
        printf("Directores (%d):\n", (p+i)->numDirectores);
        for (int j = 0; j < (p+i)->numDirectores; j++) {
            printf("  - %s\n", (p+i)->directores[j]);
        }
    }

    int opcion;
    char cadena[50];
    int anioBuscar;
    int encontrado;

    do {
        printf("\n##### Menú de búsqueda #####\n");
        printf("1. Buscar por nombre\n");
        printf("2. Buscar por año\n");
        printf("3. Buscar por director\n");
        printf("4. Buscar por todas las variables\n");
        printf("5. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &opcion);
        getchar();

        encontrado = 0;
        switch (opcion) {
            case 1: 
                printf("Ingresa nombre de la película: ");
                fgets(cadena, sizeof(cadena), stdin);
                cadena[strcspn(cadena, "\n")] = 0;
                for (int i = 0; i < n; i++) {
                    if (strcmp((p+i)->nombre, cadena) == 0) {
                        printf("Encontrada: %s (%d)\n", (p+i)->nombre, (p+i)->anio);
                        encontrado = 1;
                    }
                }
                if (!encontrado) printf("No se encontró.\n");
                break;

            case 2: 
                printf("Ingresa año: ");
                scanf("%d", &anioBuscar);
                getchar();
                for (int i = 0; i < n; i++) {
                    if ((p+i)->anio == anioBuscar) {
                        printf("Encontrada: %s (%d)\n", (p+i)->nombre, (p+i)->anio);
                        encontrado = 1;
                    }
                }
                if (!encontrado) printf("No se encontró.\n");
                break;

            case 3: 
                printf("Ingresa nombre del director: ");
                fgets(cadena, sizeof(cadena), stdin);
                cadena[strcspn(cadena, "\n")] = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < (p+i)->numDirectores; j++) {
                        if (strcmp((p+i)->directores[j], cadena) == 0) {
                            printf("Encontrada: %s (%d)\n", (p+i)->nombre, (p+i)->anio);
                            encontrado = 1;
                        }
                    }
                }
                if (!encontrado) printf("No se encontró.\n");
                break;

            case 4: 
                printf("Ingresa texto para buscar en nombre, año o director: ");
                fgets(cadena, sizeof(cadena), stdin);
                cadena[strcspn(cadena, "\n")] = 0;

                for (int i = 0; i < n; i++) {
                    char anioStr[10];
                    sprintf(anioStr, "%d", (p+i)->anio);

                    if (strstr((p+i)->nombre, cadena) ||
                        strstr((p+i)->genero, cadena) ||
                        strstr(anioStr, cadena)) {
                        printf("Coincidencia: %s (%d)\n", (p+i)->nombre, (p+i)->anio);
                        encontrado = 1;
                    }
                    for (int j = 0; j < (p+i)->numDirectores; j++) {
                        if (strstr((p+i)->directores[j], cadena)) {
                            printf("Coincidencia: %s (%d)\n", (p+i)->nombre, (p+i)->anio);
                            encontrado = 1;
                        }
                    }
                }
                if (!encontrado) printf("No hubo coincidencias.\n");
                break;

            case 5:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

 
    char generoBuscar[20];
    printf("\n Ingresa género para contar películas: ");
    fgets(generoBuscar, sizeof(generoBuscar), stdin);
    generoBuscar[strcspn(generoBuscar, "\n")] = 0;

    int contador = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp((p+i)->genero, generoBuscar) == 0) {
            contador++;
        }
    }
    printf("Existen %d películas del género '%s'.\n", contador, generoBuscar);

    return 0;
}
  
