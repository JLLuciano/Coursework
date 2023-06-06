#include "StackOfInt.h"
#include <iostream>
//#include <require.h>
#include <vector>
//this cpp file is to define the functions and class StackImp in StackOfInt.h
//I am using the code provided in (pg 296-297) to define StackOfInt and StackImp
// Hiding the Implementation (pg 297)
using namespace std;
class StackOfInt::StackImp {
	public:
		vector<int> list;
};

void StackOfInt::initialize() {
	next = new StackImp;
	cout << "Setting up Vector" << endl;
}

void StackOfInt::cleanup() {
	delete next;
}

int StackOfInt::read(int index) { //value cannot exceed current size of vector
	if (index >= next->list.size()) {
		cout << "Index value out of bounds" << endl;
		return -1;
	}
	return next->list[index];
}

void StackOfInt::push(int value) {
	next->list.push_back(value);
}