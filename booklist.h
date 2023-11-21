#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "node.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class BookList {
private:
    Node* head;
    std::string fileName;
    
    bool bookExists(int);

public:
    BookList(const std::string& fileName);
    ~BookList();
    void addBook(const Book& newBook);
    void searchBooks(const std::string& searchTerm);
    void deleteBooks(const std::string& searchTerm, const std::string& fileName);
    void readBooksFromFile(const std::string& fileName);
    void displayBooks();
};

    BookList::BookList(const std::string& file) : head(nullptr), fileName(file) {}
    
    BookList::~BookList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

    void BookList::addBook(const Book& newBook) {
        Node* newNode = new Node(newBook);
        newNode->next = head;
        head = newNode;
        
        std::ofstream outputFile(fileName, std::ios::app);

    if (outputFile.is_open()) {
        outputFile << newBook.serialNumber << "," << newBook.title << ","
                   << newBook.author << "," << newBook.publicationYear << "\n";
        outputFile.close();
    } else {
        std::cerr << "Error opening file for writing: " << fileName << std::endl;
    }
}

    void BookList::searchBooks(const std::string& searchTerm) {
        Node* current = head;

        std::cout << "Books matching '" << searchTerm << "':" << std::endl;
        while (current != nullptr) {
            if (current->data.author.find(searchTerm) != std::string::npos ||
                current->data.title.find(searchTerm) != std::string::npos) {
                std::cout << "Book ID: " << current->data.serialNumber << ", Title: " << current->data.title
                          << ", Author: " << current->data.author << ", Year: " << current->data.publicationYear << "\n";
            }
            current = current->next;
        }
    }

    void BookList::deleteBooks(const std::string& searchTerm, const std::string& fileName) {
        Node* current = head;
        Node* prev = nullptr;

        std::vector<Book> bookVector;

        while (current != nullptr) {
            if (current->data.author.find(searchTerm) != std::string::npos ||
                current->data.title.find(searchTerm) != std::string::npos) {
  
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }

                bookVector.push_back(current->data);

                delete current;
                current = prev; 
            }

            prev = current;
            if (current != nullptr) {
                current = current->next;
            }
        }

        std::ofstream outputFile(fileName);
        if (outputFile.is_open()) {
            for (const Book& book : bookVector) {
                outputFile << book.serialNumber << "," << book.title << ","
                           << book.author << "," << book.publicationYear << "\n";
            }
            outputFile.close();
        } else {
            std::cerr << "Error opening file for writing: " << fileName << std::endl;
        }
    }

    void BookList::readBooksFromFile(const std::string& fileName) {
        std::ifstream inputFile(fileName);
    if (inputFile.is_open()) {
        int serialNumber, publicationYear;
        std::string title, author;

        while (inputFile >> serialNumber >> std::ws && std::getline(inputFile, title, ',') &&
               std::getline(inputFile, author, ',') && inputFile >> publicationYear) {
            // Check if the book with the same serial number already exists
            if (!bookExists(serialNumber)) {
                addBook(Book(serialNumber, title, author, publicationYear));
            }
        }

            inputFile.close();
        } else {
            std::cerr << "Error opening file for reading: " << fileName << std::endl;
        }
    }

    void BookList::displayBooks() {
        std::vector<Book> bookVector;
        Node* current = head;
        while (current != nullptr) {
            bookVector.push_back(current->data);
            current = current->next;
        }

        std::sort(bookVector.begin(), bookVector.end(), [](const Book& a, const Book& b) {
            return a.title < b.title;
        });

        for (const Book& book : bookVector) {
            std::cout << "Book ID: " << book.serialNumber << ", Title: " << book.title
                      << ", Author: " << book.author << ", Year: " << book.publicationYear << "\n";
        }
    }
    
    bool BookList::bookExists(int serialNumber) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.serialNumber == serialNumber) {
            return true; // Book already exists
        }
        current = current->next;
    }
    return false; // Book does not exist
}
#endif