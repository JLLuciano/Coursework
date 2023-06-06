#include <iostream>

//I used the code (Friend.cpp) from page 283 from Volume 1 textbook as a reference for creating pointers to a class

using namespace std;

class B; //"Declaration (incomplete type specification)"- pg 282

class A
{
public:
	void ptrB(B* ptr) { //takes adress of B object
		cout << "Pointing to class B:" << endl;
		cout << "Adress: " << ptr << endl; //printing out the object address
	}
};

class B
{
public:
	void ptrA(A* ptr) {
		cout << "Pointing to class A: " << endl;
		cout << "Adress: " << ptr << endl;
	}
};

int main() {
	A s1;
	B s2;

	s1.ptrB(&s2); //since the void takes in an address we use "&" to get the address of the class object
	s2.ptrA(&s1);
	return 0;
}