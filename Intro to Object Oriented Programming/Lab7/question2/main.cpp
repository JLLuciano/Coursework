#include <iostream>

using namespace std;
// Used  C16:fibonacci.h  from page 726 of Volume 1 of txtbook as a reference for the Fibonacci formula
int Fib(bool add = false) {// default value is false
	static int t1 = 0;// n-1 value of sequence
	static int t2 = 1;// n-2 value of sequence
	static int t3; // n
	if (add == true) { //reset all values to 0
		t1 = 0;
		t2 = 1;
		t3 = 0;
		cout << "\nRestarting sequence value: " << t3 << "\n";
		return 0;
	}
	t3 = t1 + t2;// formula for fibonacci sequence
	t1 = t2;
	t2 = t3;

	return t3; //return value
}

int main() {
	int size = 15;
	int value = 0;

	for (int i = 0; i < size; i++) {
		value = Fib();//calling with default argument
		cout << value << ",";
	}
	value = Fib(true);//true causes a reset to 0
	return 0;
}