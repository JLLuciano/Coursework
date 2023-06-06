#include "StackOfInt.h"
#include <iostream>
//#include <require.h>
//this cpp file is to define the functions and class StackImp in StackOfInt.h
//I am using the code provided in (pg 296-297) to define StackOfInt and StackImp
// Hiding the Implementation (pg 297)

using namespace std;

class StackOfInt::StackImp {
	public:
		enum { i = 1000 }; //preset max size for int arr
		int arr[i];
		int index;
};

void StackOfInt::initialize() {
	next = new StackImp;
	next->index = 0; //set index to 0 to start pushing values from beginning of array
	cout << "Setting up Array" << endl;
}

void StackOfInt::cleanup() {
	delete next;
}

int StackOfInt::read(int index) {//get a value from a specifix array,index argument cannot exceed max preset size 
	if (index >= next->i) {
		cout << "Index value out of bounds" << endl;
		return 0;
	}
	return next->arr[index];
}

void StackOfInt::push(int value) {
	if (next->index == next->i) { //checking because index argument cannot exceed max preset size 
		cout << "Cannot expand the array any further" << endl;
	}
	else {
		next->arr[next->index] = value;
		next->index += 1; //moving from left to right in the array
	}
}

int StackOfInt::size() {
	return next->i;
}