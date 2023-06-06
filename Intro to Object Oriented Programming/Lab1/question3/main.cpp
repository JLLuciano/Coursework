#include "data.h"
#include <iostream>

using namespace std;
using namespace m;

int main() {
	Type data;//creates a variable with the class that has all the functions

	data.Integer(5, 2.255f,'b'); //calls the Integer function
	cout << endl;

	data.Void(256,'t'); //calls void function
	cout << endl;

	data.Float(2.236f , 4.314f, 5, 'y'); // calls Float function
	cout << endl;

	data.Character('c', 1.8888f);//calls the Character class
	//Each class has valid arguments

	return 0;
}