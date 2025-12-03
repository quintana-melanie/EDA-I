
import pickle
import os

archivo_memoria = "memoria_fib.pkl"

if os.path.exists(archivo_memoria):
    with open(archivo_memoria, "rb") as f:
        memoria = pickle.load(f)
else:
    memoria = {0: 0, 1: 1}  

def fibonacci_top_down(n):
    if n in memoria:
        return memoria[n]

    memoria[n] = fibonacci_top_down(n-1) + fibonacci_top_down(n-2)

    with open(archivo_memoria, "wb") as f:
        pickle.dump(memoria, f)

    return memoria[n]

if __name__ == "__main__":
    n = int(input("Dame un número: "))
    print("Fibonacci Top-Down =", fibonacci_top_down(n))
    print("Memoria guardada en memoria_fib.pkl")
