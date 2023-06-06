#include <iostream>

using namespace std;
//Used slides 13 and 16 from Lecture 9 as a reference for my code
int& ModifyPtr(int* x) {//I would use void but it says to return as a reference
	(*x)++; //incrementing x
	int& y = *x; //when a reference is created it must be initialized to an existing object
	//*x is used because of invalid conversion from int* to int
	return y;
}

int main() {
	int s1 = 25;
	int* s2 = &s1;
	//to get the value of the pointer we have to use the dereference operator *
	cout << "Before: Value:" << *s2 << ", Destination:" << s2 << endl;
	ModifyPtr(s2);
	cout << "After: Value:" << *s2 << ", Destination:" << s2 << endl;
	//ModifyPtr successfully changed what the pointer points to and contains the same address
	return 0;
}
