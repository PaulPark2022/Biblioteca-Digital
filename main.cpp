#include <iostream>
#include <vector>
#include <algorithm>
#include "functions.h"
using namespace std;

int main() {
    int op, viejoIndice;
    string nuevoTitulo;
    Functions bookVector;
    vector<string> books { "Harry Potter", "Cien años de soledad", "It", "Percy Jackson" };
    vector<string> v;
    
    cout << "\tBienvenido a la Biblioteca Digital" << endl;
    cout << "¿Cuál es la operación que desea realizar?" << endl;
    cout << "1. Ordenar libros alfabéticamente" << endl;
    cout << "2. Agregar libro" << endl;
    cout << "3. Quitar libro" << endl;
    cin >> op;
    
    switch(op){
        case 1:
            v = bookVector.sortBooks(books);
            for ( auto& element : v ) {
                cout << element << "  ";
            }
        case 2:
            cout << "Escriba el nombre del libro que desea agregar: " << endl;
            cin >> nuevoTitulo;
            books.push_back(nuevoTitulo);
            for ( auto& element : books ) {
                cout << element << "  ";
            }
        case 3:
            for ( auto& element : books ) {
                cout << element << "  ";
            }
            cout << "\nEscriba la posición del libro que desea eliminar: " << endl;
            cin >> viejoIndice;
            books.erase(books.begin() + viejoIndice);
            for ( auto& element : books ) {
                cout << element << "  ";
            }
        case 4: break;
    }
    
    return 0;
}        
    
