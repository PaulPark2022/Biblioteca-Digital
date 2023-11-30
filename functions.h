#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "queue.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

template <class T>
class Merge {
private:
	void copyArray(std::vector<T>&, std::vector<T>&, int, int);
	void mergeArray(std::vector<T>&, std::vector<T>&, int, int, int);
	void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
public:
	std::vector<T> mergeSort(const std::vector<T>&);
};

template <class T>
void Merge<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	for (int i = low; i <= high; i++) {
		A[i] = B[i];
	}
}

template <class T>
void Merge<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high) {
	int i, j, k;

	i = low;
	j = mid + 1;
	k = low;

	while (i <= mid && j <= high) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > mid) {
		for (; j <= high; j++) {
			B[k++] = A[j];
		}
	} else {
		for (; i <= mid; i++) {
			B[k++] = A[i];
		}
	}
}

template <class T>
void Merge<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high) {
	int mid;

	if ( (high - low) < 1 ) {
		return;
	}
	mid = (high + low) / 2;
	mergeSplit(A, B, low, mid);
	mergeSplit(A, B, mid + 1, high);
	mergeArray(A, B, low, mid, high);
	copyArray(A, B, low, high);
}

// 0(n log (n))
template <class T>
std::vector<T> Merge<T>::mergeSort(const std::vector<T> &source) {
	std::vector<T> v(source);
	std::vector<T> tmp(v.size());

	mergeSplit(v, tmp, 0, v.size() - 1);
	return v;
}

class Functions {
private:
    QueueList<int>& serials;
    QueueList<std::string>& titulos;
    QueueList<std::string>& autores;
    QueueList<int>& anios;
public:
    Functions(QueueList<int>& serials, QueueList<std::string>& titulos, QueueList<std::string>& autores, QueueList<int>& anios)
        : serials(serials), titulos(titulos), autores(autores), anios(anios) {}
        
    void addBooks(std::ofstream&);
    void searchBooks(const std::string& searchTerm, const std::string& searchCriteria);
    void deleteBook(const std::string&, std::ofstream&);
    void displayBooks();
    void readFromFile(QueueList<int>&, QueueList<std::string>&, QueueList<std::string>&, QueueList<int>&);
};

void Functions::addBooks(std::ofstream& archivoOutput) {
    int numLibros, nSerial, anio;
    std::string titulo, autor;

    std::cout << "Ingrese el número de libros que desee agregar: ";
    std::cin >> numLibros;

    for (int i = 1; i <= numLibros; ++i) {
        std::cout << "Ingrese el número de serie del libro " << i << ": ";
        std::cin >> nSerial;
        std::cout << "Ingrese el título del libro " << i << " (sin espacios): ";
        std::cin >> titulo;
        std::cout << "Ingrese el autor del libro " << i << " (sin espacios): ";
        std::cin >> autor;
        std::cout << "Ingrese el anio del libro " << i << ": ";
        std::cin >> anio;
        serials.enqueue(nSerial);
        titulos.enqueue(titulo);
        autores.enqueue(autor);
        anios.enqueue(anio);
        archivoOutput << nSerial << "," << titulo << "," << autor << "," << anio << "\n";
    }
}

void Functions::searchBooks(const std::string& terminoBusqueda, const std::string& criterioBusqueda) {
    std::vector<size_t> indices;
    
    if (criterioBusqueda == "titulo") {
        std::vector<std::string> vectorTitulos(titulos.begin(), titulos.end());
        auto it = std::find(vectorTitulos.begin(), vectorTitulos.end(), terminoBusqueda);

        if (it != vectorTitulos.end()) {
            std::cout << "Libro encontrado: " << *it << std::endl;
        } else {
            std::cout << "Libro no encontrado." << std::endl;
        }
    } else if (criterioBusqueda == "autor") {
        std::vector<std::string> vectorAutores(autores.begin(), autores.end());
        auto it = std::find(vectorAutores.begin(), vectorAutores.end(), terminoBusqueda);

        while (it != vectorAutores.end()) {
            size_t index = std::distance(vectorAutores.begin(), it);

            auto tituloIt = titulos.begin();
            std::advance(tituloIt, index);

            std::cout << "Libro encontrado: " << *tituloIt << std::endl;

            it = std::find(it + 1, vectorAutores.end(), terminoBusqueda);
        } if (it == vectorAutores.end()) {
            std::cout << "Libro no encontrado." << std::endl;
        }
    } else if (criterioBusqueda == "anio") {
        int anioABuscar = std::stoi(terminoBusqueda);
    
        auto itAnios = anios.begin();
        auto itTitulos = titulos.begin();

        while (itAnios != anios.end()) {
            if (*itAnios == anioABuscar) {
                std::cout << "Libro encontrado: " << *itTitulos << std::endl;
            }

            ++itAnios;
            ++itTitulos;
        }

        if (std::none_of(anios.begin(), anios.end(), [anioABuscar](int anio) { return anio == anioABuscar; })) {
            std::cout << "Libro no encontrado." << std::endl;
        }
    } else if (criterioBusqueda == "nSerial") {
        
        int serialABuscar = std::stoi(terminoBusqueda);
        auto it = std::find(serials.begin(), serials.end(), serialABuscar);

        if (it != serials.end()) {
            size_t index = std::distance(serials.begin(), it);

            auto tituloIt = titulos.begin();
            std::advance(tituloIt, index);

            std::cout << "Libro encontrado: " << *tituloIt << std::endl;
        } else {
            std::cout << "Libro no encontrado." << std::endl;
        }
    } else {
        std::cout << "Criterio de busqueda inválido." << std::endl;
    }
}

void Functions::deleteBook(const std::string& titulo, std::ofstream& archivoOutput) {
    auto serialIt = serials.begin();
    auto tituloIt = titulos.begin();
    auto autorIt = autores.begin();
    auto anioIt = anios.begin();

    std::ifstream archivoInput("libros.txt");

    std::string linea;
    std::vector<std::string> lineas;

    while (std::getline(archivoInput, linea)) {
        if (linea.find(titulo) == std::string::npos) {
            lineas.push_back(linea);
        } else {
            serials.dequeue();
            titulos.dequeue();
            autores.dequeue();
            anios.dequeue();
        }
    }

    archivoInput.close();  

    archivoOutput.open("libros.txt", std::ios::trunc);
    archivoOutput.close();  

    archivoOutput.open("libros.txt", std::ios::app);

    for (const auto& lineaNueva : lineas) {
        archivoOutput << lineaNueva << "\n";
    }

    archivoOutput.close();  
    std::cout << "Libro eliminado: " << titulo << std::endl;
}

void Functions::displayBooks() {
    std::vector<std::string> vectorLibros(titulos.begin(), titulos.end());
    Merge<std::string> mergeSorter;
    vectorLibros = mergeSorter.mergeSort(vectorLibros);

    std::cout << "Los libros que tenemos disponibles son: ";
    for (const auto& elemento : vectorLibros) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
    
}

void readFromFile(QueueList<int>& serials, QueueList<std::string>& titulos, QueueList<std::string>& autores, QueueList<int>& anios) {
    std::ifstream archivoInput("libros.txt");
    if (!archivoInput.is_open()) {
        std::cerr << "Error, no se pudo abrir el archivo: libros.txt" << std::endl;
        return;
    }

    int nSerial, anio;
    std::string titulo, autor, linea;

    while (std::getline(archivoInput, linea)) {
        std::istringstream iss(linea);
        std::string token;

        // Read each token separated by commas
        if (std::getline(iss, token, ',')) {
            nSerial = std::stoi(token);
        }
        if (std::getline(iss, token, ',')) {
            titulo = token;
        }
        if (std::getline(iss, token, ',')) {
            autor = token;
        }
        if (std::getline(iss, token, ',')) {
            anio = std::stoi(token);
        }

        serials.enqueue(nSerial);
        titulos.enqueue(titulo);
        autores.enqueue(autor);
        anios.enqueue(anio);
    }

    archivoInput.close();
}
#endif 
