#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
public:
    int serialNumber;
    std::string title;
    std::string author;
    int publicationYear;

    Book(int serial, const std::string& t, const std::string& a, int year);
};

Book::Book(int serial, const std::string& t, const std::string& a, int year)
    : serialNumber(serial), title(t), author(a), publicationYear(year) {}

#endif