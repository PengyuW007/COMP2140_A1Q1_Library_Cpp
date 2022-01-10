#ifndef A1Q1_BOOK_H
#define A1Q1_BOOK_H

#include <string>
#include <cstring>

using namespace std;

class Book {
private:
    string title;
    string first;
    string last;
    bool loan;

public:
    Book(string title, string first, string last);

    Book();

    string getTitle();

    string getLast();
    string getFirst();
    void setLoan(bool loanStatus);
    bool getLoan();
};


#endif //A1Q1_BOOK_H
