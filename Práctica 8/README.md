                                                  Preguntas (A)
- ¿Por qué es más fácil eliminar un nodo intermedio en una lista doblemente ligada que en una lista simple?

Porque en una lista doblemente ligada cada nodo tiene acceso directo tanto al nodo anterior como al siguiente y esto permite eliminar 
un nodo sin tener que recorrer la lista para encontrar el nodo previo, ya que el puntero anterior ya lo tiene almacenado, y en una lista 
simple se tendria que recorrer desde el inicio para encontrar el nodo anterior y poder ajustar los punteros.

- ¿Qué sucede si se olvida actualizar alguno de los punteros anterior o siguiente?

Se rompe la estructura de la lista y dependiendo del caso puede ocurrir:

    *Se pierde parte de la lista (nodos inaccesibles).
    
    *El recorrido hacia adelante o hacia atrás deja de funcionar.
    
    *El programa puede entrar en un ciclo infinito al recorrer.
    
    *Puede generar errores como segmentation fault por acceder a memoria inválida.

- ¿En qué escenarios prácticos se usa una lista doblemente ligada?

Las listas doblemente ligadas se usan cuando se necesita:

    *Navegación en dos direcciones, como el historial adelante/atrás de un navegador.
    
    *Reproductores multimedia, pasar a canción anterior o siguiente.
    
    *Administración de memoria (listas libres y ocupadas).
    
    *Edición de texto, donde el cursor puede moverse adelante o atrás.

                                                  Preguntas (B)
1. ¿Qué diferencia hay entre una lista doblemente ligada y una circular doblemente ligada?

La diferencia principal es el comportamiento de los punteros:

  *En la lista doblemente ligada normal:
  
      °El primer nodo tiene anterior = NULL
      
      °El último nodo tiene siguiente = NULL
      
  *En la lista doblemente ligada circular:
  
      °El primer nodo apunta al último en anterior
      
      °El último nodo apunta al primero en siguiente
      
      °No existen punteros NULL
      
Esto forma un ciclo cerrado, permitiendo recorrer la lista infinitamente en ambos sentidos.

2. ¿Qué errores pueden causar ciclos infinitos al recorrer una lista circular?

Los errores más comunes son:

      *Usar un ciclo while (temp != NULL) (esto nunca ocurre en una circular).
      
      *Olvidar detener el ciclo cuando temp vuelve al nodo inicial.
      
      *No actualizar correctamente los punteros siguiente o anterior.
      
      *Quedarse “saltando” entre dos nodos mal enlazados.
   
3. ¿Qué tipo de aplicaciones reales usan este tipo de listas?

Las listas doblemente ligadas circulares se usan cuando se necesita un recorrido continuo sin inicio ni fin claro, por ejemplo:

     *Reproductores multimedia con modo “repetir playlist”.
     
     *Juegos que manejan turnos cíclicos entre jugadores.
     
     *Buffers circulares en sistemas operativos o procesos en tiempo real.
     
     *Sistemas de menú cíclico (se regresa de la última opción a la primera).
     
     *Simulación de procesos, donde se recorre un conjunto de tareas repetidamente.
