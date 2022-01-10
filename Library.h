#ifndef A1Q1_LIBRARY_H
#define A1Q1_LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "Book.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    int numBooks;
    vector<Book> rent;
public:
    Library();

    int getNumBooks();

    vector<Book> getBooks();

    void addBook(string, string, string);

    vector<Book> listByAuthor(string);

    vector<Book> listByTitle(string);

    bool loanBook(string, string);

    bool returnBook(string last, string title);

    string getBook(string, string);
};

#endif //A1Q1_LIBRARY_H
