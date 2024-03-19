#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isValid(const string& word)
{
    if (!(isalpha(word[0]) || word[0] == '_'))
    {
        cout << "is not an identifier." << endl;
        return false;
    }
    for (char c : word)
    {
        if (!(isalnum(c) || c == '_'))
        {
            cout << "is not an identifier." << endl;
            return false;
        }
    }

    const string reservedKeywords[] = {
        "int", "char", "double", "float", "if", "else", "while",
        "for", "return", "class", "do", "new", "switch", "long",
        "operator", "template", "break"
    };

    for (const string& keyword : reservedKeywords)
    {
        if (word == keyword)
        {
            cout << " is not an identifier." << endl;
            return false;
        }
    }

    return true;
}

int main () {


  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile("C:/Users/student/Documents/myText.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
  }

    if (isValid(myText))
    {
        cout << "'" << myText << "' is an identifier." << endl;
    }

  // Close the file
  MyReadFile.close();
}
