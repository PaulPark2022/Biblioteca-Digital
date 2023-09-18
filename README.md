# Biblioteca-Digital
Este proyecto simula el comportamiento de una plataforma de biblioteca digital por medio de un menú hecho con la instrucción switch que selecciona una de estas 3 funciones: Ordenar una lista de libros alfabéticamente por su título, agregar un libro y quitarlo del almacenamiento.
# SICT0302B: Toma decisiones
## Selecciona un algoritmo de ordenamiento adecuado al problema
El algoritmo utilizado para ordenar los libros por orden alfabético ascendente es la función sort de la librería estándar de C++; un introsort. El motivo de esta selección es debido a sus propiedades como algoritmo de ordenamiento híbrido (quick sort, heap sort e insertion sort), las cuales le otorgan una alta velocidad y un menor riesgo de terminar en el peor caso (tiempo y espacio) de entre sus tres subalgoritmos. Se encuentra en la función sortBooks de las líneas 11 y 15 en el archivo functions.h.
# SICT0301B: Evalúa los componentes
## Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes
Función sortBooks(Introsort): 0(log(n)), ya que no es necesario comparar cada par de títulos; divide y compara los elementos del vector de manera recursiva.
# SICT0303B: Implementa acciones científicas
## Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de mostrar un vector de libros ordenado (opción 1), agregar un libro al vector (opción 2), o eliminarlo del almacenamiento (opción 3).
