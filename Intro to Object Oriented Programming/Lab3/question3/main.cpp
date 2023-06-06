#include <iostream>
#include "StackOfInt.h"
//#include "StackOfInt2.cpp"

using namespace std;

int main() {

	StackOfInt stack;

	stack.initialize();
	for (int k = 0; k < stack.size(); k++) {
		stack.push(k);
		cout << stack.read(k) << ",";
	}
	cout << "\n";
	cout << "Before cleanup: " << stack.read(15) << endl;
	stack.cleanup();
	cout << "After cleanup: " << stack.read(15) << endl;
	cout << "Proof that array and vector are stored on the stack" << endl; //just the object is deleted to prevent memory leak
	
	return 0;
}