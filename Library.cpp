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
    cout << "Books by " + last + ":" << endl;
    vector<Book> authors;

    for (int i = 0; i < getNumBooks(); i++) {
        Book book = books[i];

        if (strcmp(book.getLast().c_str(), last.c_str()) == 0) {
            authors.push_back(book);
            cout << book.getLast() + ", " + book.getFirst() + ", " + book.getTitle() << endl;
        }
    }
    cout << endl;
    return authors;
}//end listByAuthor

vector<Book> Library::listByTitle(string title) {
    cout << "Books named " + title + ":" << endl;
    vector<Book> titles;

    for (int i = 0; i < getNumBooks(); i++) {
        Book book = titles[i];

        if (strcmp(book.getTitle().c_str(), title.c_str()) == 0) {
            titles.push_back(book);
        }
    }
    return titles;
}//end listByTitle

bool Library::loanBook(string last, string title) {
    cout << "Book loaned: ";
    bool loaned = true;//in lib
    cout << books.size() << endl;
    for (int i = 0; i < getNumBooks(); i++) {
        Book book = books[i];
        if(strcmp(book.getLast().c_str(), last.c_str()) == 0){
            cout<<"Yes"<<endl;
            string line = getBook(last,title);
            cout<<line<<endl;
        }

        /*
        if (strcmp(book.getLast().c_str(), last.c_str()) == 0 && strcmp(book.getTitle().c_str(), title.c_str()) == 0) {
            loaned = false;
            book.setLoan(true);
            string line = getBook(last, title);
            cout << line << endl;
            books.erase(books.begin() + i);
            rent.push_back(book);
        }
         */
    }
    cout<<books.size()<<endl;
    return loaned;
}//end loanBook

bool Library::returnBook(string last, string title) {
    cout << "Book returned: " << endl;

    bool returned = false;
   // cout<<"RETURN: "<<rent.size()<<endl;
    for (int i = 0; i < rent.size(); i++) {
        Book book = rent[i];

        /*
        if (strcmp(book.getLast().c_str(), last.c_str()) == 0 && strcmp(book.getTitle().c_str(), title.c_str()) == 0) {
            returned = true;
            book.setLoan(false);
            books.push_back(book);
            string line = getBook(last, title);
            cout << line << endl;
            rent.erase(rent.begin() + i);
        }
         */
    }
    return returned;
}

string Library::getBook(string last, string title) {
    string res = "";

    for (int i = 0; i < getNumBooks(); i++) {
        Book book = books[i];

        if (strcmp(book.getLast().c_str(), last.c_str()) == 0 && strcmp(book.getTitle().c_str(), title.c_str()) == 0) {
            res = book.getLast() + ", " + book.getFirst() + ", " + book.getTitle();
        }
    }
    return res;
}//end getBook

void Library::printLibrary() {
    for (int i = 0; i < getNumBooks(); i++) {
        Book book = books[i];
        cout << book.getLast() + ", " + book.getFirst() + ", " + book.getTitle() << endl;
    }
}//end printLibrary