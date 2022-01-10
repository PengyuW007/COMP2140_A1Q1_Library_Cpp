#include "Library.h"

Library::Library() {
    books;
    numBooks = getNumBooks();
    rent;
}

int Library::getNumBooks() {
    return books.size();
}

vector<Book> Library::getBooks() {
    return books;
}

void Library::addBook(string last, string first, string title) {
    Book book = Book(title, first, last);
    books.push_back(book);
}

vector<Book> Library::listByAuthor(string last) {
    cout<<"Books by "+last+":"<<endl;
}