
import math

def menu():
    print("\n--- MENÚ PRINCIPAL ---")
    print("1. Mostrar datos")
    print("2. Calcular área de un círculo")
    print("3. Sumar dos números")
    print("4. Salir")

def mostrar_datos():
    persona = {"nombre": "Melanie", "edad": 20}
    print("Datos:", persona)

def area_circulo():
    r = float(input("Radio: "))
    area = math.pi * r * r
    print("Área:", area)

def sumar():
    a = float(input("A: "))
    b = float(input("B: "))
    print("Resultado:", a + b)

op = 0
while op != 4:
    menu()
    op = int(input("Opción: "))

    if op == 1:
        mostrar_datos()
    elif op == 2:
        area_circulo()
    elif op == 3:
        sumar()
    elif op == 4:
        print("Saliendo del programa...")
    else:
        print("Opción no válida.")

