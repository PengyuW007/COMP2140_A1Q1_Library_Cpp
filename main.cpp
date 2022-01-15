#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "Library.h"

using namespace std;

void processFile(char *);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <file name>" << endl;
    }

    processFile(argv[1]);

    cout << "End of Processing." << endl;
    return 0;
}

void processFile(char *filename) {
    ifstream inFile;
    inFile.open(filename);
    string nextLine;
    cout << "Processing file " << filename << "...\n" << endl;

    Library *library = new Library();

    while (getline(inFile, nextLine)) {
        istringstream iss(nextLine);
        string stuff;

        vector<string> tokens;
        while (iss >> stuff) {
            tokens.push_back(stuff);
        }

        for (int i = 0; i < tokens.size(); i++) {
            int len = tokens[i].length();//length of curr string
            if (tokens[i][len - 1] == ',') {
                tokens[i] = tokens[i].substr(0, len - 1);
            }
        }
        string command = tokens[0];

        if (strcmp(command.c_str(), "ADD") == 0) {
            string last = tokens[1];
            string first = tokens[2];
            string title;
            int i = 3;
            while (i < tokens.size() - 1) {
                title += tokens[i] + " ";
                i++;
            }
            title += tokens[tokens.size() - 1];

            library->addBook(last, first, title);
        }//end ADD
        else if (strcmp(command.c_str(), "SEARCHA") == 0) {
            string last = tokens[1];

            library->listByAuthor(last);
        }//end SEARCHA
        else if(strcmp(command.c_str(),"GETBOOK")){
            string last = tokens[1];
            string title = tokens[2];

            library->loanBook(last,title);
            cout<<endl;
        }//end GETBOOK
        else if(strcmp(command.c_str(),"RETURNBOOK")){
            string last = tokens[1];
            string title = tokens[2];

            //library->returnBook(last,title);
        }
    }
    //library->printLibrary();
    // cout<<library->getNumBooks()<<endl;
}