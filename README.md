# Biblioteca-Digital
Este proyecto simula el comportamiento de una plataforma de biblioteca digital con un menú que ejecuta una de estas 4 funciones: Agregar uno o varios libros, buscar uno o varios libros (por cualquiera de sus elementos, incluyendo su número de serie, autor, título, o año de publicación), quitar uno o varios libros y desplegar los títulos de todos los libros disponibles ordenados alfabéticamente. Los datos de cada libro están almacenados en un archivo de texto actualizable.
# SICT0302B: Toma decisiones
## Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
La estructura lineal seleccionada es un queue, ya que, debido a que debido a su comportamiento FOFI (First In, First Out), permite almacenar, buscar, eliminar y desplegar los elementos (libros, en este caso) en el orden en el que fueron agregados y seleccionados. Es debido a este orden que no se necesitan los índices de los elementos y, por lo tanto, no se utilizó una lista para el problema. Además, su funcionamiento beneficia las operaciones de lectura y escritura de archivos. Las funciones addBook, searchBook y deleteBook se encuentran en el archivo functions.h en las líneas 99, 123 y 189, respectivamente.
## Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
El algoritmo utilizado para ordenar los libros por orden alfabético ascendente es un merge sort, pues es uno de los algoritmos de ordenamiento más consistentes (su rendimiento es 0 (n log(n)) para los casos peor, promedio y mejor). No se utilizó un heap sort porque, si bien es cierto que su rendimiento de espacio en el peor caso (0(1)) es más eficiente que el de un merge sort (0(n)), un merge sort tiene un comportamiento predecible, además de que es más fácil de implementar y entender. El merge sort se utiliza en la función displayBooks del archivo functions.h en la línea 225.
# SICT0301B: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
#### ordenamiento de libros
ordenamiento con merge sort: 0(n log(n)), puesto que divide la lista en mitades de manera recursiva para después combinarlas de nuevo una por una.
#### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa
### funciones de queues (Clase QueueList de Queue)
Función enqueue: 0(1), debido a que agrega un elemento al final del queue; ya tiene la posición en la que el elemento debe ir.

Función dequeue: 0(1), puesto que elimina el elemento al frente (inicio) del queue; la ubicación ya está definida.

Función front: 0(1), ya que únicamente devuelve una referencia al primer elemento del queue.
#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
### funciones para libros (Clase Functions)
Función para agregar libro: 0(n), puesto que el sistema almacena cada libro inmediatamente después de ingresarlo.

Función para buscar libro: 0(n), porque recorre los elementos de los queues uno después del otro.

Función para eliminar libro: 0(n), debido a que revisa cada elemento en el queue de títulos.

Función para consultar libros: 0(n log n), ya que se compone principalmente por el merge sort.

Función para leer archivo de libros: 0(n); el algoritmo se desplaza de línea en línea.

Como la función searchBook es la que más se va a utilizar (búsquedas frecuentes), la complejidad final de este proyecto es de 0(n).

# SICT0303B: Implementa acciones científicas
## Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de buscar cualquier elemento de un libro (opción 2 en el menú) en el queue que corresponda al criterio ingresado. 
También despliega los títulos de libros disponibles, ordenados alfabéticamente (opción 4 del menú).
## Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.
Los libros están registrados en el archivo libros.txt, de donde se leen al iniciar el programa. Cada línea contiene los siguientes elementos (en orden): Número de serie, título, autor y año, todos los cuales provienen de sus queues correspondientes.
## Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa.
En la función para agregar libros (opción 1 en el menú), también se escriben los elementos agregados al archivo txt.
