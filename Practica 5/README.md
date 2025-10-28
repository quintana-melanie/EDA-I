Preguntas (A)
- ¿Por qué en la cola circular no se desperdician posiciones como en la cola lineal?
  Porque en la cola circular, cuando el índice final llega al final del arreglo, vuelve al inicio gracias a la operación (índice + 1) % MAX, que permite reutilizar los espacios que se liberan al hacer dequeue, y evita que queden posiciones vacías sin poder usarse, pero en una cola lineal los índices solo avanzan hacia un extremo y el espacio inicial se desperdicia.
-  ¿Qué pasa cuando el índice final llega al final del arreglo?
  Cuando "final" llega al último índice del arreglo, se recicla automáticamente al principio (índice 0), que se logra con la operación //final = (final + 1) % MAX;//, así la cola “gira” sobre sí misma que simula una estructura circular en memoria
- ¿Qué sucede si intentas encolar cuando la cola está llena?
  El programa detecta que size == MAX y muestra un mensaje de error sin agregar el nuevo elemento, evitando escribir datos existentes y mantiene la integridad de la cola.
Reflexión (B)
- ¿Qué diferencia tiene el deque frente a la cola circular normal?
  Deque permite insertar y eliminar elementos por ambos extremos (frente y final), mientras que la cola circular solo permite insertar por el final y eliminar por el frente.
- ¿Qué operaciones permiten simular tanto FIFO como LIFO?
  Para simular FIFO (como una cola normal): insert_rear() y delete_front().
  Para simular LIFO (como una pila): insert_front() y delete_front() o bien insert_rear() y delete_rear().
- Investiga que aplicaciones prácticas tiene deque:
  En algoritmos que requieren ventanas deslizantes como en análisis de datos o procesamiento de señales, en el manejo de historiales. En estructuras como colas de prioridad, buffers circulares, o simuladores de procesos donde se necesita flexibilidad de acceso a los extremos.
