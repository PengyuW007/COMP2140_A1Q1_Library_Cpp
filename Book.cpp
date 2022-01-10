#include "Book.h"

Book::Book() {

}

Book::Book(string t, string f, string l) {
    title = t;
    first = f;
    last = l;
    loan = false;
}

string Book::getTitle() {
    return title;
}

string Book::getFirst() {
    if (first[0] == ' ') {
        first = "unknown";
    }
    return first;
}

string Book::getLast() {
    return last;
}

void Book::setLoan(bool loanStatus) { loan = loanStatus; }

bool Book::getLoan() {return loan;}