/*
18.07.2015
Maciej Michalec

Simple translator to the "Pig Latin"
https://en.wikipedia.org/wiki/Pig_Latin
*/

#include <iostream>
using namespace std;

/*
Check if the letter is a vowel
*/
bool isVowel(char letter)
{
    if(letter == 'a' || letter == 'e' 
        || letter == 'i' || letter == 'o'
        || letter == 'u' || letter == 'y')
    {
        return true;
    }
    return false;
}


/*
Move consonant cluster to the end of the word
*/
string moveConsonantsToTheEnd(string word)
{
    string newWord = word;
    for(int i=0; i<word.length(); i++)
    {
        char letter = word[i];
        if(isVowel(letter))
        {
            break;
        }
        else
        {
            newWord += letter;
            newWord = newWord.substr(1);
        }
    }
    return newWord;
}

int main()
{
    string word;

    cout << "$: ";
    cin >> word;

    char firstLetter = word[0];
    if(isVowel(firstLetter))
        word += "way";
    else
    {
        word = moveConsonantsToTheEnd(word);
        word += "ay";
    }

    cout << word << endl;;
}
