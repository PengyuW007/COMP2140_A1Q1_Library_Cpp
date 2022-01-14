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
    if (title.size() == 0)
        title = "unknown";
    return title;
}

string Book::getFirst() {
    if (first.size() == 0) {
        first = "unknown";
    }
    return first;
}

string Book::getLast() {
    if (last.size()== 0)
        last = "unknown";
    return last;
}

void Book::setLoan(bool loanStatus) { loan = loanStatus; }

bool Book::getLoan() { return loan; }