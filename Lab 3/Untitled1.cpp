#include <iostream>
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
            cout << "is not an identifier." << endl;
            return false;
        }
    }

    return true;
}

int main()
{
    string idntf;
    getline(cin, idntf);

    if (isValid(idntf))
    {
        cout << "'" << idntf << "' is an identifier." << endl;
    }
    return 0;
}
