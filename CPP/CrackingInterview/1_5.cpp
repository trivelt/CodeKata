/*
1.5
Metoda, ktora kompresuje lancuchy znakow
oparta na zliczaniu powtarzajacych sie liter
Np. aabccccaa -> a2b1c4a2
Jesli skompresowany lancuch nie jest mniejszy 
od wejsciowego, metoda powinna zwracac pierwotny
lancuch
*/

#include <cassert>
#include <string>
using namespace std;

string compressString(const string& longStr)
{
    if(longStr == "") return longStr;
    string shortStr = "";
    char previousChar = longStr[0];
    int numberOfPreviousChars = 1;
    for(int i = 1; i<longStr.length(); i++)
    {
        char currentChar = longStr.at(i);
        if(currentChar == previousChar)
        {
            numberOfPreviousChars++;
            if(i == longStr.length()-1)
                shortStr += previousChar + to_string(numberOfPreviousChars);
        }
        else
        {
            shortStr += previousChar + to_string(numberOfPreviousChars);
            previousChar = currentChar;
            numberOfPreviousChars = 1;
            if(i == longStr.length()-1)
                shortStr += previousChar + to_string(numberOfPreviousChars);
        }
    }
    if(shortStr.length() >= longStr.length())
        return longStr;
    else
        return shortStr;
}

int main()
{
    assert(compressString("aaabbccca") == "a3b2c3a1");
    assert(compressString("abcdd") == "abcdd");

    return 0;
}
