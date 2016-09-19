/*
1.2
Zaimplementuj w jezyku C lub C++ funkcje void reverse(char* str),
ktora odwraca znaki w lancuchu zakonczonym znakiem null
*/

#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

void reverse(char*);

int main()
{
    char str[] = "test123";
    reverse(str);
    assert(strcmp("321tset", str) == 0);

    return 0;
}

void reverse(char* str)
{
    char* end = str;
    char tmp;
    if(str)
    {
        while(*end) // znajdowanie konca lancucha
        {
            ++end;
        }
        --end; // cofniecie sie o jeden znak
        
        while(str < end)
        {
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
}
