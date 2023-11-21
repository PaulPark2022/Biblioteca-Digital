#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include "book.h"
#include "node.h"
#include "booklist.h"

int main() {
    BookList bookList("books.txt");

    bookList.readBooksFromFile("books.txt");

    int choice;
    do {
        std::cout << "\nLibrary System Menu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Search Books\n";
        std::cout << "3. Delete Book\n";
        std::cout << "4. Show Books\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Invalid input. Please enter a number.\n";
            continue; 
        }

        switch (choice) {
            case 1: {
                int serialNumber, publicationYear;
                std::string title, author;

                std::cout << "Enter Book ID: ";
                std::cin >> serialNumber;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter Title: ";
                std::getline(std::cin, title);

                std::cout << "Enter Author: ";
                std::getline(std::cin, author);

                std::cout << "Enter Publication Year: ";
                std::cin >> publicationYear;

                Book newBook(serialNumber, title, author, publicationYear);
                bookList.addBook(newBook);
                break;
            }
            case 2: {
                std::string searchTerm;
                std::cout << "Enter the search term: ";
                std::cin >> searchTerm;
                bookList.searchBooks(searchTerm);
                break;
            }
            case 3: {
                std::string searchTerm;
                std::cout << "Enter the search term to delete: ";
                std::cin >> searchTerm;
                bookList.deleteBooks(searchTerm, "books.txt");
                break;
            }
            case 4: {
                bookList.displayBooks();
                break;
            }
            case 5: {
                std::cout << "Exiting the Library System. Thank you!\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
            }
        }
    } while (choice != 5);
    
    
    return 0;
}
