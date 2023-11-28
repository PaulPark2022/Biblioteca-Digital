#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "queue.h"
#include "functions.h"

using namespace std;

int main() {
    QueueList<int> serials;
    QueueList<std::string> titulos;
    QueueList<std::string> autores;
    QueueList<int> anios;
    Functions functions(serials, titulos, autores, anios);
    
    readFromFile(serials, titulos, autores, anios);
    
    ofstream archivoBiblio("libros.txt", std::ios::app);
    
    if (!archivoBiblio.is_open()) {
        std::cerr << "Error, no se pudo abrir el archivo: " << "libros.txt" << std::endl;
        return 1;
    }

    int opcion;
    do {
        std::cout << "\tBienvenido(a) a la Biblioteca TEC" << endl;;
        std::cout << "Seleccione la operación que desee realizar: " << endl;
        std::cout << "1. Agregar libro(s)\n";
        std::cout << "2. Buscar libro(s)\n";
        std::cout << "3. Quitar libro(s)\n";
        std::cout << "4. Mostrar libros disponibles\n";
        std::cout << "5. Salir\n";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                functions.addBooks(archivoBiblio);
                break;
            }
            case 2: {
                int opcionBusqueda = 1;
                std::string terminoBusqueda;
    
                while (opcionBusqueda == 1) {
                    std::cout << "Escriba el tipo de término que desee buscar: " << endl;
                    std::cout << "NSerial, Autor, Titulo, Anio" << endl;
                    std::cin >> terminoBusqueda;

                    if (terminoBusqueda == "NSerial") {
                        int nSerial;
                        std::cout << "Escriba el número de serie del libro: ";
                        std::cin >> nSerial;
                        functions.searchBooks(std::to_string(nSerial), "nSerial");
                    } else if (terminoBusqueda == "Autor") {
                        std::string autor;
                        std::cout << "Escriba el nombre del autor del libro (sin espacios): ";
                        std::cin >> autor;
                        functions.searchBooks(autor, "autor");
                    } else if (terminoBusqueda == "Titulo") {
                        std::string titulo;
                        std::cout << "Escriba el titulo del libro (sin espacios): ";
                        std::cin >> titulo;
                        functions.searchBooks(titulo, "titulo");
                    } else if (terminoBusqueda == "Anio") {
                        int anio;
                        std::cout << "Escriba el anio del libro: ";
                        std::cin >> anio;
                        functions.searchBooks(std::to_string(anio), "anio");
                    } else {
                        std::cout << "Término inválido" << std::endl;
                    }

                    std::cout << "¿Desea realizar otra búsqueda? (1: Sí, 0: No): ";
                    std::cin >> opcionBusqueda;
                }   
                break;
            }
            case 3: {
                std::string terminoBusqueda;
                std::cout << "Escriba el titulo del libro que desee eliminar: ";
                std::cin >> terminoBusqueda;
                functions.deleteBook(terminoBusqueda, archivoBiblio);
                break;
            }
            case 4: {
                functions.displayBooks();
                break;
            }
            case 5: {
                std::cout << "Gracias por utilizar nuestro servicio" << std::endl;
                archivoBiblio.close();
                break;
            }
            default: {
                std::cout << "Opción inválida, por favor seleccione un número del 1 al 5\n";
            }
        }
    } while (opcion != 5);
    return 0;
}
