/*
1.1
Zaimplementuj algorytm okreslajacy, czy lancuch zawiera tylko
niepowtarzajace sie znaki. Jak wykonasz zadanie, jesli nie mozna
stosowac dodatkowych struktur danych?
*/

//#define NDEBUG
#include <iostream>
#include <cassert>
using namespace std;

bool hasUniqueChars(string text)
{
    int chars[30]{0};

    for(char c : text)
    {
        c = tolower(c);
        chars[c-'a']++;
        if(chars[c-'a'] > 1)
            return false;
    }
    return true;
}

void testUniqueChars()
{
    string ok = "abcdef";
    string notOk = "abcdAf";
    assert( hasUniqueChars(ok) == true );
    assert( hasUniqueChars(notOk) == false );
}

int main()
{
    testUniqueChars(); 
    return 0;
}
