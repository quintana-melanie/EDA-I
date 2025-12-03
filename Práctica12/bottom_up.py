
def fibonacci_bottom_up(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    tabla = [0, 1]

    for i in range(2, n + 1):
        tabla.append(tabla[i-1] + tabla[i-2])

    return tabla[n]

if __name__ == "__main__":
    n = int(input("Dame un número: "))
    print("Fibonacci Bottom-Up =", fibonacci_bottom_up(n))
