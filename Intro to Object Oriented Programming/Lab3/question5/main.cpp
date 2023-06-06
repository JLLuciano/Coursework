#include <iostream>
#include <vector>
#include <string>

using namespace std;
//used lab 2 exercise 2 as a reference for static_cast
//I used lecture 10, pg 15 as a reference for my code
class StringVector : public vector<void*>
{
	vector<string*>str;

	public:
		void push_back(string* ptr) { //function needs to accept string* and produce one as well
			str.push_back(ptr); //redefining push_back to accept string*
		}
		string* operator [](int i) {
			return (str[i]);//returning string pointer at ith index
		}
};

int main() {
	StringVector str;

	string s1 = "Have a wonderful day";
	string *s2 = static_cast<string*>(&s1);
	str.push_back(s2);

	cout << "Pointer: " << str.operator[](0) << endl;// the operator[] function properly returns the string pointer of specified index
	cout << "Value held in first index of pointer: " << *(str.operator[](0)) << endl; //de-referencing to print the value pointed to by the pointer

	return 0;
}