#include <iostream>

using namespace std;

int counter; //global variable to keep track of bits
//used code from Volume 1 Pg 203 and 173
void printBinary(const unsigned char val) {
	for (int i = 7; i >= 0; i--){ //iterate through the bits of the bytes from left to right
		counter++;
		if (val & (1 << i)) { //using left shift operator to compare bit pattern to val
			cout << "1";
		}
		else {
			cout << "0";
		}
		if (counter == 1 || counter == 12) { //counter keeps track of bits to separate bit sign, exponent, and mantissa
			cout << " ";
		}
	}
}
int main() { //FloatingAsBinary
	double num;

	cout << "Enter double value: ";
	cin >> num;

	unsigned char* cp = reinterpret_cast<unsigned char*>(&num); //cp is treated as an array of bytes

	for (int i = sizeof(double); i > 0; --i) { //iterate through the bytes of double which is 8
		printBinary(cp[i-1]);
		//removed printBinary(cp[i]) so I modified the for loop
	}
	cout << " \n";
	return 0;
} 
	