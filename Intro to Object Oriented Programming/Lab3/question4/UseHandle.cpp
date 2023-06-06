//: C05:UseHandle.cpp 
//{L} Handle 
// Use the Handle class 
#include "Handle.h" 
#include <iostream>
//298 Thinking in C++ www.BruceEckel.com
//I got the code from the book
//Used Lecture 7, slides 19-20 to understand how to use constructor and destructor
using namespace std;
int main() {
	Handle u;
	//u.initialize(); <- the constructor initializes the object so this function is no longer needed
	u.change(999);
	cout << u.read() << endl;
	//u.cleanup(); <- not needed anymore because destructor is automatically called
} ///:~