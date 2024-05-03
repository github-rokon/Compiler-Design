#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Define sets for keywords, preprocessor directives, data types, and library functions
unordered_set<string> keywords = {"auto", "break", "case", "const", "continue", "default", "do", "else", "enum", "extern", "for", "goto", "if", "register", "return", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "volatile", "while"};
unordered_set<string> preprocessorDirectives = {"#include", "#define", "#ifdef", "#endif", "#pragma"};
unordered_set<string> dataTypes = {"int", "char", "float", "double", "bool", "void", "long", "short"};
unordered_set<string> libraryFunctions = {"iostream", "ifstream", "ofstream", "vector", "algorithm"};

// Function to check if a string is a keyword
bool isKeyword(const string &word) {
    return keywords.find(word) != keywords.end();
}

// Function to check if a string is a preprocessor directive
bool isPreprocessorDirective(const string &word) {
    return preprocessorDirectives.find(word) != preprocessorDirectives.end();
}

// Function to check if a string is a data type
bool isDataType(const string &word) {
    return dataTypes.find(word) != dataTypes.end();
}

// Function to check if a string is a library function
bool isLibraryFunction(const string &word) {
    return libraryFunctions.find(word) != libraryFunctions.end();
}

// Function to check if a string is a variable
bool isVariable(const string &word) {
    return word.size() == 1 && isalpha(word[0]) && islower(word[0]);
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        cout << "Error opening file\n";
        return 1;
    }

    string line;
    while (getline(file, line)) {
        string buffer;
        bool inString = false; // Flag to indicate if currently parsing a string
        bool inNumber = false; // Flag to indicate if currently parsing a number
        for (char ch : line) {
            if (ch == '"' && !inString) {
                inString = true;
                buffer += ch;
            } else if (ch == '"' && inString) {
                inString = false;
                buffer += ch;
                cout << buffer << " is an output statement\n";
                buffer.clear();
            } else if (inString) {
                buffer += ch;
            } else if (isdigit(ch) && !inNumber) {
                inNumber = true;
                buffer += ch;
            } else if (isdigit(ch) && inNumber) {
                buffer += ch;
            } else if (!isdigit(ch) && inNumber) {
                cout << buffer << " is a constant\n";
                buffer.clear();
                inNumber = false;
                buffer += ch;
            } else if (isspace(ch)) {
                // Check if buffer contains a keyword, preprocessor directive, data type, library function, or variable
                if (!buffer.empty()) {
                    if (isKeyword(buffer)) {
                        cout << buffer << " is a reserved keyword\n";
                    } else if (isPreprocessorDirective(buffer)) {
                        cout << buffer << " is a preprocessor directive\n";
                    } else if (isDataType(buffer)) {
                        cout << buffer << " is a data type\n";
                    } else if (isLibraryFunction(buffer)) {
                        cout << buffer << " is a library function\n";
                    } else if (isVariable(buffer)) {
                        cout << buffer << " is a variable\n";
                    }
                    buffer.clear();
                }
            } else {
                buffer += ch;
            }
        }
        // Check buffer at the end of the line
        if (!buffer.empty()) {
            if (isKeyword(buffer)) {
                cout << buffer << " is a reserved keyword\n";
            } else if (isPreprocessorDirective(buffer)) {
                cout << buffer << " is a preprocessor directive\n";
            } else if (isDataType(buffer)) {
                cout << buffer << " is a data type\n";
            } else if (isLibraryFunction(buffer)) {
                cout << buffer << " is a library function\n";
            } else if (isVariable(buffer)) {
                cout << buffer << " is a variable\n";
            }
        }
    }

    file.close();
    return 0;
}
