#include <iostream>
#include <string.h>

using namespace std;
//I used lecture 5 ppt to understand how to traverse the pointers so that I can copy from one char* to another
//I also used pgs 182-183 from Volume 1 for static_cast
char* stringCopy(char* ptr) {
	string t1 = static_cast<string>(ptr); //copy to string t1 to get length and allocate correct memory
	char* t2 = new char[t1.length() + 1];
	ptr = static_cast<char*>(ptr); //typcasting it back to a pointer to start string copying
	
	for (int i = 0; i < t1.length(); i++) {
		*(t2 + i) = *(ptr + i); //copying string from ptr to t2
	}
	*(t2 + t1.length()) = '\0';//implementing null terminator

	return t2; //return copied string
}

int main() {
	char* s1 = "I love C++";
	char* s2 = stringCopy(s1); //assign copy to s2
	char* s3 = stringCopy(s2); //assign copy of the copy to s3

	cout << "  String \t\t Adress" << endl;
	cout << "Original: " << s1 << "\t " << &s1 << endl; //print strings with pointer address
	cout << "First Copy: " << s2 << "   " << &s2 << endl;
	cout << "Second Copy: " << s3 << "  " << &s3 << endl;

	delete[] s2; //delete allocated memory
	delete[] s3;

	return 0;
}