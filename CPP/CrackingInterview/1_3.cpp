/*
1.3
Metoda, ktora przyjmuje dwa stringi i okresla
czy jeden jest permutacja drugiego
*/

#include <string>
#include <cassert>
#include <vector>
using namespace std;

vector<int> getChars(const string& str)
{
    vector<int> res(256, 0);
    for(char c : str)
    {
        res[c]++;
    }
    return res;
}

vector<int> getCharsWithoutWhitespaces(const string& str)
{
    vector<int> res(256, 0);
    for(char c : str)
    {
        if(isspace(c))
            continue;
        res[c]++;
    }
    return res;
}

vector<int> getCharsCaseInsensitive(const string& str)
{
    vector<int> res(256, 0);
    for(char c : str)
    {
        res[tolower(c)]++;
    }
    return res;
}

bool isPermutation(string first, string second)
{
    vector<int> chars_of_first = getChars(first);
    vector<int> chars_of_second = getChars(second);

    for(int i=0; i<chars_of_first.size(); i++)
    {
        if(chars_of_first.at(i) != chars_of_second.at(i))
            return false;
    }
    return true;
}

void test()
{
    string mama1 = "mama1";
    assert(isPermutation(mama1, "mma1a"));
    assert(isPermutation(mama1, "mam1") == false);
}

int main()
{
    test();    
    return 0;
}
