
memoria = {0: 0, 1: 1}

def fibonacci(n):
    if n in memoria:
        return memoria[n]
    memoria[n] = fibonacci(n - 1) + fibonacci(n - 2)
    return memoria[n]

posiciones = [7, 21, 40, 71, 94]

print("Cálculo recursivo de Fibonacci con memorización:\n")

for pos in posiciones:
    print(f"Fibonacci({pos}) = {fibonacci(pos)}")

