#include <iostream>

using namespace std;
//Used page 500 of textbook as a reference for my code
//Also used slide 30 of Lecture 9 as a reference
class IntArray {//in order for pointer to index through the array, all components relating to the array must be public
public:
	enum{size = 10};
	int arr[size] = { 0,1,2,3,4,5,6,7,8,9 }; //initialized array to 10 elements
};

int main() {
	IntArray s1;
	IntArray* s2 = &s1;
	int (IntArray::* ptr)[s1.size] = &IntArray::arr; //create a pointer to arr member of IntArray

	for (int i = 0; i < s1.size; i++) {
		cout << *(s1.*ptr + i) << ",";//de-referencing pointer to print out numbers
	}
	cout << "\n";//
	for (int i = 0; i < s1.size; i++) {
		cout << *(s2->*ptr + i) << ",";//demonstrating two ways to use a pointer to data member
	}
	cout << "\n";

	return 0;
}