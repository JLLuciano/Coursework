# include <iostream>

using namespace std;
//used slide 15-16 from lecture 11 to understand how to get started and how to get size of object
/*https://stackoverflow.com/questions/26755638/warning-pointer-of-type-void-used-in-arithmetic used the following to
* understand how to read address types and how to typecast the pointer properly, originally I used void but I was presented with 
a warning and in the forum I saw that they suggested unsigned so I went with it*/

class VTable {
	
public:
	int a;
	float b;
	double c;
	int d;
	char t;
	VTable() : a(123), b(456.4314f), c(789.987), d(9565), t('t') {} //Constructor
	virtual void f() { //virtual functions
		cout << "Function f()" << endl;
	}
	virtual void g() {
		cout << "Function g()" << endl;
	}
};
 
void Memory() {
	
	VTable* look = new VTable(); //creating object of class VTable and assigning it to a pointer of class VTable
	int size = sizeof(look); //getting the size of the pointer which corresponds to the size of the object
	unsigned* ptr = (unsigned*) look; //typcasting to unsigned to read addresses in generated VTable
	//included multiple data types to ensure that unsigned* works properly
	for (int i = 0; i < size; i++) {
		if (*(int*)(ptr + i) == look->a || *(int*)(ptr + i) == look->d) {
			cout << "Memory: " << (void*)(ptr + i);//typcasting to void pointer to print address
			cout << " ,Value: " << *(int*)(ptr + i) << endl;//typcasting to specified data type and dereferencing to get values
		}
		if (*(char*)(ptr + i) == look->t) {
			cout << "Memory: " << (void*)(ptr + i);
			cout << " ,Value: " << *(char*)(ptr + i) << endl;
		}
		if (*(float*)(ptr + i) == look->b) {
			cout << "Memory: " << (void*)(ptr + i);
			cout << " ,Value: " << *(float*)(ptr + i) << endl;
		}
		if (*(double*)(ptr + i) == look->c) {
			cout << "Memory: " << (void*)(ptr + i);
			cout << " ,Value: " << *(double*)(ptr + i) << endl;
		}
		
	}
	
	delete look; //deleting object created
}

int main() {

	Memory();

	return 0;
}