#include <iostream>

using namespace std;
//Used slides 7 and 10 from Lecture 11 as a reference for code
//Also used sample code provided by TA,Yuanzhou Yang, as a reference
class Subject //base class functions must have virtual keyword for overriding to work
{
public:
	virtual void f() {} //using virtual keyword
	virtual void g() {}
	virtual void h() {}
};

class Implementation1 : public Subject
{
public: //overriding functions of base class, derived classes don't need the virtual keyword
	void f() {
		cout << "Implementation1: Function f()" << endl;
	}
	void g() {
		cout << "Implementation1: Function g()" << endl;
	}
	void h() {
		cout << "Implementation1: Function h()" << endl;
	}
};
class Implementation2 : public Subject
{
public:
	void f() {
		cout << "Implementation2: Function f()" << endl;
	}
	void g() {
		cout << "Implementation2: Function g()" << endl;
	}
	void h() {
		cout << "Implementation2: Function h()" << endl;
	}
};

class Proxy : public Subject {
	Subject* next; //virtual functions should be accessed using a pointer
public:
	Proxy(Subject* ptr) {
		next = ptr;//setting pointer equal to address of input
	}
	void f() {
		next->f();//acessing overwritten function with pointer
	}
	void g() {
		next->g();
	}
	void h() {
		next->h();
	}
};

int main() {
	//created two Proxy objects using constructor with address/pointer argument
	Implementation1 s1;
	Implementation2 s2;

	Proxy proxy(&s1);//using address of variable to access Implementation1 class
	proxy.f();
	proxy.g();
	proxy.h();

	cout << "\n";

	Proxy proxy2(&s2);//using address of variable to access Implementation2 class
	proxy2.f();
	proxy2.g();
	proxy2.h();
	return 0;
}