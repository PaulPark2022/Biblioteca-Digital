# Biblioteca-Digital
Este proyecto simula el comportamiento de una plataforma de biblioteca digital con un menú que ejecuta una de estas 6 funciones: Agregar un libro, agregar una serie de libros, buscar un libro, buscar una serie de libros, quitar un libro y quitar una serie de libros. Los datos de cada libro están almacenados en un archivo de texto actualizable.
# SICT0302B: Toma decisiones
## Selecciona y usa una estructura lineal adecuada al problema
La estructura lineal seleccionada es una lista doblemente ligada, ya que, a diferencia de un vector, su tamaño aumenta y disminuye durante la ejecución de las funciones de inserción y eliminación de elementos, de modo que no requiere un tamaño inicial definido y no se desperdicia memoria. La ventaja de que sea doblemente ligada es que considera apuntadores para la cola y el elemento anterior, lo cual resulta en menor probabilidad de errores durante la ejecución del código. Si bien la memoria total que ocupa es mayor a la de un vector, la implementación de sus funciones es más sencilla y limpia en comparación. Además, dado que contiene un sistema de búsqueda, no se recomienda el acceso aleatorio.
## Selecciona un algoritmo de ordenamiento adecuado al problema
El algoritmo utilizado para ordenar los libros por orden alfabético ascendente es un merge sort (originalmente iba a ser el introsort de la librería estándar de C++, pero la idea fue descartada porque únicamente funcionaba con iteradores de acceso aleatorio, lo cual no concuerda con los apuntadores de una lista doblemente ligada), pues es uno de los algoritmos de ordenamiento más consistentes (su rendimiento es 0 (n log(n)) para los casos peor, promedio y mejor) y su método de división es compatible con el comportamiento de los apuntadores de una lista doblemente ligada.
# SICT0301B: Evalúa los componentes
## Presenta Casos de Prueba correctos y completos para todas las funciones y procedimientos del programa
Los casos de pruebas para todas las funciones se encuentran en el archivo pruebas.cpp donde se prueban las funciones de:

la lista doblemente ligada de libros

el merge sort de la lista doblemente ligada de libros

## Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes
### ordenamiento de libros
ordenamiento con merge sort: 0(n log(n)), puesto que divide la lista en mitades de manera recursiva para después combinarlas de nuevo una por una.
### lista de libros
Función para agregar libro: 0(1), puesto que el sistema ya tiene la posición predeterminada.

Función para eliminar libro: 0(1), debido al mismo motivo que la opción anterior.

Función para buscar libro: 0(n), porque recorre los elementos de la lista uno por uno.

# SICT0303B: Implementa acciones científicas
## Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de ordenar títulos de libros en la lista alfabéticamente (opción 2 en el menú), desplegando la lista ordenada inmediatamente después. También es capaz de buscar un título específico, desplegando su posición en la lista si llegara a existir (opción 3 en el menú). 
