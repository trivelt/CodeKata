/*
18.07.2015
Maciej Michalec

Classical FizzBuzz exercise
https://en.wikipedia.org/wiki/Fizz_buzz
*/

#include <iostream>
using namespace std;

int main()
{
	for(int i=1;i<=100;i++)
	{
		bool isMultipleOfThree = (i % 3 == 0);
		bool isMultipleOfFive = (i % 5 == 0);

		if(isMultipleOfThree)
			cout << "Fizz";
		if(isMultipleOfFive)
			cout << "Buzz";
		if(!isMultipleOfThree && !isMultipleOfFive)
			cout << i;
		cout << std::endl;
	}
}
