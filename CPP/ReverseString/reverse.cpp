#include <iostream>
using namespace std;


int main()
{
    string text;
    cout << "Enter a text: ";
    cin >> text;

    for(int i = text.length()-1; i >= 0; i--)
    {
        cout << text[i];        
    }
    cout << endl;
}
