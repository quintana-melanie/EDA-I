import itertools
import string

def generar_contraseñas(longitud, archivo_salida, limite=None):
    caracteres = string.digits
    combinaciones = itertools.product(caracteres, repeat=longitud)

    with open(archivo_salida, "w") as archivo:
        count = 0
        for combo in combinaciones:
            archivo.write("".join(combo) + "\n")
            count += 1
            if limite and count >= limite:
                break

    print(f"Archivo generado: {archivo_salida} ({count} contraseñas)")


print("Generando contraseñas de fuerza bruta...\n")

generar_contraseñas(4, "passwords_4.txt")

generar_contraseñas(8, "passwords_8.txt", limite=500)

generar_contraseñas(10, "passwords_10.txt", limite=500)

print("\nProceso terminado.")
