Preguntas Parte A: 
- ¿Por qué las listas enlazadas no requieren tamaño fijo como los arreglos?

Porque cada nodo se reserva dinámicamente con `malloc()`, que esto permite agregar o eliminar elementos sin preocuparse por un tamaño fijo como ocurre con los arreglos estáticos.

- ¿Qué diferencia hay entre mover la cabeza y modificar los punteros internos?

Mover la cabeza cambia el inicio de la lista (por ejemplo, al eliminar el primer nodo).  
Modificar los punteros internos cambia las conexiones entre nodos intermedios, manteniendo la cabeza igual.

  Preguntas Parte B:

- ¿Qué ventaja tiene la lista circular frente a la simple?
  
En una lista circular se puede recorrer infinitamente sin llegar a `NULL`, que facilita procesos cíclicos.

- ¿Qué error puede causar un bucle infinito en una lista circular?

Si el puntero de final no apunta correctamente al inicio, o si el recorrido no detecta la vuelta al primer nodo, el ciclo nunca termina y el programa se bloquea.

- ¿Qué estructuras o programas del mundo real se basan en listas circulares?

Sistemas operativos para la planificación por turnos, listas de reproducción de música, juegos multijugador de control de turnos.  

  

