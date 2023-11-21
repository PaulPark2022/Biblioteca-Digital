# Biblioteca-Digital
Este proyecto simula el comportamiento de una plataforma de biblioteca digital con un menú que ejecuta una de estas 7 funciones: Agregar un libro, agregar una serie de libros, buscar un libro, buscar una serie de libros, quitar un libro, quitar una serie de libros. Los datos de cada libro están almacenados en un archivo de texto actualizable.
# SICT0302B: Toma decisiones
## Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
La estructura seleccionada es una lista ligada, ya que el conjunto de datos planteado para este proyecto es considerable pequeño y simple, además de que las funciones que más se van a utilizar son las de agregar y quitar libros, operaciones que se pueden realizar al inicio o final de la lista. Otra ventaja es el uso de la memoria; la lista ligada únicamente tiene los valores de los libros y sus referencias.
## Selecciona un algoritmo de ordenamiento adecuado al problema
El algoritmo utilizado para ordenar los libros por orden alfabético ascendente es un merge sort, pues es uno de los algoritmos de ordenamiento más consistentes (su rendimiento es 0 (n log(n)) para los casos peor, promedio y mejor). No se utilizó un heap sort porque, si bien es cierto que su rendimiento de espacio en el peor caso (0(1)) es más eficiente que el de un merge sort (0(n)), un heap sort genera un árbol con los elementos para ordenarlos, una operación que ya está contemplada en el programa (copia los elementos de un AVL y los ordena).
# SICT0301B: Evalúa los componentes
## Hace un análisis de complejidad correcto y completo para todo el programa y sus componentes
### ordenamiento de libros
ordenamiento con merge sort: 0(n log(n)), puesto que divide la lista en mitades de manera recursiva para después combinarlas de nuevo una por una.
### lista de libros
Función para agregar libro: 0(1), puesto que el sistema ya tiene la posición predeterminada.

Función para eliminar libro: 0(1), debido al mismo motivo que la opción anterior.

Función para buscar libro: 0(n), porque recorre los elementos de la lista uno por uno.

# SICT0303B: Implementa acciones científicas
## Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
El programa tiene la opción de buscar un libro (opción 3 en el menú) en el archivo txt o una serie de libros por medio de su número de serie en el AVL (opción 4 en el menú). También despliega los libros disponibles en cualquier momento (opción 7 del menú).
## Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.
Los libros están registrados en el archivo libros.txt de donde se leen al iniciar el programa. Cada línea contiene los siguientes elementos (en orden): Número de serie, título, autor y año.
## Implementa mecanismos de escritura de archivos correctos y útiles dentro de un programa.
Los libros agregadas se guardan en el archivo libros.txt, con la función add del AVL; los libros se eliminan del archivo con la función remove del AVL. El ofstream tiene la sección "std::ios::app" para que el archivo se actualice por cada vez que se realicen estas operaciones (no se reescriben libros).
