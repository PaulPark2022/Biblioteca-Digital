#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "avl.h"
#include "stack.h"
#include "merge.h"

using namespace std;

int main() {
    AVL<int> avlLibros;
    StackVector<int> stackLibros(10);
    Merge<int> mergeLibros;
    int nSerialLibro, numLibros, op;
    std::vector<int> vectorLibros;
    std::string titulo, autor, anio;
    
    std::string nombreArchivo = "libros.txt";
    
    std::ifstream archivoBiblioLectura(nombreArchivo);
    
    if (!archivoBiblioLectura.is_open()) {
        std::cerr << "Error; no se pudo abrir el archivo: " << "libros.txt" << std::endl;
        return 1; 
    }
    
    std::string libro;
    while (getline (archivoBiblioLectura, libro)) {
        std::istringstream iss(libro);
        int idLibro;
        if (iss >> idLibro) {
            avlLibros.add(idLibro);
        } else {
            std::cerr << "Error al extraer el primer elemento como entero." << std::endl;
        }
    }
    
    archivoBiblioLectura.close();
    
    std::ofstream archivoBiblioEscritura(nombreArchivo, std::ios::app);
    
    if (!archivoBiblioEscritura.is_open()) {
        std::cerr << "Error opening file for writing: " << nombreArchivo << std::endl;
        return 1;
    }

    while (true) {
        cout << "\tBienvenido a la Biblioteca Digital" << endl;
        cout << "¿Cuál es la operación que desea realizar?" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Agregar serie de libros" << endl;
        cout << "3. Buscar libro" << endl;
        cout << "4. Buscar serie de libros" << endl;
        cout << "5. Quitar libro" << endl;
        cout << "6. Quitar serie de libros" << endl;
        cout << "7. Mostrar libros" << endl;
        cout << "8. Salir" << endl;
        cin >> op;
        std::cin.ignore(); 

        switch(op){
            case 1: {
                std::cout << "Escriba el número de serie del libro que desea agregar: ";
                std::cin >> nSerialLibro;
                std::cout << "Escriba el título del libro que desea agregar (sin espacios): ";
                std::cin >> titulo;
                std::cout << "Escriba el nombre del autor del libro que desea agregar (sin espacios): ";
                std::cin >> autor;
                std::cout << "Escriba el anio del libro que desea agregar: ";
                std::cin >> anio;
                archivoBiblioEscritura << nSerialLibro << "," << titulo << "," << autor << "," << anio << "\n";
                break;
            }
            
            case 2: {
                std::cout << "Escriba el número de libros que desea agregar: ";
                std::cin >> numLibros;
                std::cin.ignore(); 
                
                for (int i = 0; i < numLibros; ++i) {
                    std::cout << "Ingrese el número de serie del libro " << i + 1 << ": ";
                    std::cin >> nSerialLibro;
                    vectorLibros.push_back(nSerialLibro);
                    std::cout << "Escriba el título del libro que desea agregar (sin espacios): ";
                    std::cin >> titulo;
                    std::cout << "Escriba el nombre del autor del libro que desea agregar (sin espacios): ";
                    std::cin >> autor;
                    std::cout << "Escriba el anio del libro que desea agregar: ";
                    std::cin >> anio;
                    archivoBiblioEscritura << nSerialLibro << "," << titulo << "," << autor << "," << anio << "\n";
                }
                
                for (int i : vectorLibros) {
                    avlLibros.add(i);
                }
                break;
            }
        
            case 3: {
                std::ifstream archivoBiblioLecturaBuscar(nombreArchivo);
    
                if (!archivoBiblioLecturaBuscar.is_open()) {
                    std::cerr << "Error; no se pudo abrir el archivo: " << nombreArchivo << std::endl;
                    return 1; 
                }
                
                std::cout << "Escriba el número de serie del libro que desea buscar: ";
                std::cin >> nSerialLibro;
                
                std::string libro;
                bool libroEncontrado = false;
                
                while (std::getline (archivoBiblioLecturaBuscar, libro)) {
                    std::istringstream iss(libro);
                    int idLibro;
                    std::string titulo, autor, anio;
                    
                    if (iss >> idLibro) {
                // Read other details only if the serial number matches
                        std::getline(iss, titulo, ',');
                        std::getline(iss, autor, ',');
                        std::getline(iss, anio, ',');

                        if (idLibro == nSerialLibro) {
                            std::cout << "Libro encontrado: " << titulo << std::endl;
                            libroEncontrado = true;
                            break;
                        }
                    }else {
                        std::cerr << "Error al extraer el primer elemento como entero." << std::endl;
                        iss.clear(); // Clear the fail state
                    }
                }

                if (!libroEncontrado) {
                    std::cout << "Libro no encontrado." << std::endl;
                }

                
                /*std::string libroBuscado;
                std::cout << "Escriba el título del libro que desea buscar: ";
                std::getline(std::cin, libroBuscado);

                int indiceLibro = list.search(libroBuscado);
                if (indiceLibro != -1) {
                    std::cout << "Libro encontrado en el indice: " << indiceLibro << std::endl;
                } else {
                    std::cout << "El libro no se encuentra en este espacio" << std::endl;
                }*/
                archivoBiblioLecturaBuscar.close();
                break;
            }
            
            /*case 4: {
                std::string listaLibros = list.printList();
                if (listaLibros == "NULL") {
                    std::cout << "No tenemos libros por el momento" << endl;
                } else {
                    std::cout << "Estos son los libros que tenemos disponibles: " << listaLibros << std::endl;
                }
                break;
            }
            
            case 5: {
                std::string listaLibros = list.printList();
                std::string libroAEliminar;
                std::cout << "Ingrese el nombre del libro que desea eliminar: ";
                std::getline(std::cin, libroAEliminar);

                if (list.deleteBook(libroAEliminar)) {
                    std::cout << "Libro eliminado." << std::endl;
                } else {
                    std::cout << "No puedes eliminar un libro que no existe." << std::endl;
                }
                break;
            }*/
            
            case 7: {
                std::cout << avlLibros.preorder() << std::endl;
                break;
            }
            
            case 8: {
                std::cout << "Gracias por utilizar nuestro servicio" << std::endl;
                archivoBiblioEscritura.close();
                return 0;
            }
                
            default:
                std::cout << "Este número no es válido; seleccione otra opción" << std::endl;
                break;
        }
    }
    return 0;
}        
