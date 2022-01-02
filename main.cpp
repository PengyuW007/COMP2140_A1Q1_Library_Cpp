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

        vector<string>strArr;

        while (iss >> stuff) {
            strArr.push_back(stuff);
            cout<<stuff<<"|";
        }

        cout << endl;
    }
}