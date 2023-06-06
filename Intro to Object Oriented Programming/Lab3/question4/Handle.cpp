//: C05:Handle.cpp {O} 
// Handle implementation 
#include "Handle.h" 
//#include "../require.h" 

// Define Handle's implementation: 
//5: Hiding the Implementation 297
struct Handle::Cheshire {
	int i;
};

Handle::Handle() {//defining the constructor
	smile = new Cheshire;
	smile->i = 0;
}

Handle::~Handle() {//defining the destructor
	delete smile;
}

int Handle::read() {
	return smile->i;
}

void Handle::change(int x) {
	smile->i = x;
} ///:~ 