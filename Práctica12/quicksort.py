
def quicksort(lista):
    if len(lista) <= 1:
        return lista

    pivote = lista[len(lista) // 2]
    izquierda = [x for x in lista if x < pivote]
    centro = [x for x in lista if x == pivote]
    derecha = [x for x in lista if x > pivote]

    return quicksort(izquierda) + centro + quicksort(derecha)


if __name__ == "__main__":
    datos = [10, 5, 2, 8, 15, 3]
    print("Lista original:", datos)
    print("Lista ordenada:", quicksort(datos))
