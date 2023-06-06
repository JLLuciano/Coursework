#include <iostream>
#include "StackOfInt.h"

using namespace std;

int main() {

	StackOfInt stack;
	int input;

	cout << "Enter length of vector: ";
	cin >> input;

	stack.initialize();
	for (int k = 0; k < input; k++) {
		stack.push(k);
		cout << stack.read(k) << ",";
	}
	cout << "\n";
	stack.cleanup();
	return 0;
}