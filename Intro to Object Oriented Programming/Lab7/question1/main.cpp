#include <iostream>

using namespace std;
// I used C10:StaticVariablesInfunctions.cpp from page 429 of Volume 1 textbook as a reference 
int ArrPtr(const int* intArray = 0) {//default argument of zero
	static const int* s;

	if (intArray) {
		s = intArray; //point to beginning of array
		return *s;
	}
	else {
		if (*s == -1) {// acts as the terminator
			cout << "End of array\n";
			return 0;
		}
		return *s++; //return next value of array
	}
}

int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, -1 }; 

int main() {
	ArrPtr(arr);//make *s point to the beginning of the array
	int s1;

	while ((s1 = ArrPtr()) != 0) { //printing array values
		cout << s1 << endl;
	}
	return 0;
}