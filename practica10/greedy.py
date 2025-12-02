def cambio_greedy(cantidad, monedas):
    resultado = []
    for moneda in monedas:
        if cantidad >= moneda:
            num = cantidad // moneda
            resultado.append((moneda, num))
            cantidad -= moneda * num
    return resultado

monedas = [20, 10, 5, 1]

cantidad = int(input("Ingresa la cantidad de cambio: "))
sol = cambio_greedy(cantidad, monedas)

print("\nCambio usando Greedy:")
for moneda, cantidad in sol:
    print(f"Moneda {moneda}: {cantidad}")
