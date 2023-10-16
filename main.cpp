#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using namespace std;

int main() {
    Functions list;
    int numLibros, op;

    while (true) {
        cout << "\tBienvenido a la Biblioteca Digital" << endl;
        cout << "¿Cuál es la operación que desea realizar?" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Ordenar lista de libros" << endl;
        cout << "3. Buscar libro" << endl;
        cout << "4. Mostrar lista de libros" << endl;
        cout << "5. Quitar libro" << endl;
        cout << "6. Salir del menú" << endl;
        cin >> op;
        std::cin.ignore(); 

        switch(op){
            case 1:{
                std::cout << "Escriba el número de libros que desea agregar: ";
                std::cin >> numLibros;
                std::cin.ignore(); 
                
                for (int i = 0; i < numLibros; ++i) {
                    std::string value;
                    std::cout << "Ingrese el nombre del libro " << i + 1 << ": ";
                    std::getline(std::cin, value);
                    list.push(value);
                }

                std::string listaLibros = list.printList();
                if (listaLibros == "NULL") {
                    std::cout << "No tenemos libros por el momento" << endl;
                } else {
                    std::cout << "La lista de libros disponibles es la siguiente: " << listaLibros << endl;
                }
                break;
            }
            
            case 2: {
                list.mergeSort();
                std::string listaLibros = list.printList();
                if (listaLibros == "NULL") {
                    std::cout << "No tenemos libros por el momento" << endl;
                } else {
                    std::cout << "Esta es la lista de libros ordenada: " << listaLibros << endl;
                }
                break;
            }
        
            case 3: {
                std::string libroBuscado;
                std::cout << "Escriba el título del libro que desea buscar: ";
                std::getline(std::cin, libroBuscado);

                Node* libroEncontrado = list.search(libroBuscado);
                if (libroEncontrado) {
                    std::cout << "Libro encontrado: " << libroEncontrado->getData() << std::endl;
                } else {
                    std::cout << "El libro no se encuentra en este espacio" << std::endl;
                }
                break;
            }
            
            case 4: {
                std::string listaLibros = list.printList();
                if (listaLibros == "NULL") {
                    std::cout << "No tenemos libros por el momento" << endl;
                } else {
                    std::cout << "Estos son los libros que tenemos disponibles: " << listaLibros << std::endl;
                }
                break;
            }
            
            case 5: {
                list.mergeSort();
                std::string listaLibros = list.reversePrintList();
                if (listaLibros == "NULL") {
                    std::cout << "No tenemos libros por el momento" << endl;
                } else {
                    std::cout << "Estos son los libros que tenemos disponibles: " << listaLibros << std::endl;
                }
                break;
            }
            
            case 6: {
                std::string listaLibros = list.printList();
                std::string libroAEliminar;
                std::cout << "Ingrese el nombre del libro que desea eliminar: ";
                std::getline(std::cin, libroAEliminar);

                if (list.deleteNode(libroAEliminar)) {
                    std::cout << "Libro eliminado." << std::endl;
                } else {
                    std::cout << "No puedes eliminar un libro que no existe." << std::endl;
                }
                break;
            }
            
            case 7:
                std::cout << "Gracias por utilizar nuestro servicio" << std::endl;
                return 0;

            default:
                std::cout << "Este número no es válido; seleccione otra opción" << std::endl;
                break;
        }
    }
    return 0;
}      
