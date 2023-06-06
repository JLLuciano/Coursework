//: C14:Combined.cpp 
// Inheritance & composition 
#include <iostream>
//used Instrument3.cpp from slide 10 of Lecture 11 as a reference
using namespace std;
class A {
	int i;
public:
	A(int ii) : i(ii) {}
	~A() {}
	void f() const {
		cout << "Class A, Function f()" << endl;
	}
};
class B {
	int i;
public:
	B(int ii) : i(ii) {}
		~B() {}
		virtual void f() const {//make this virtual because C inherits from B
			cout << "Class B, Function f()" << endl; //this is here to check if virtual call is done correctly
		} 
};
class C : public B {
	A a;
public:
	C(int ii) : B(ii), a(ii) {}
	~C() {} // Calls ~A() and ~B() 
	void f() const { // Overriding function f() 
		a.f();
		B::f();
		cout << "Class C, Function f()" << endl;
	}
};
//function Upcasting uses Late Binding
void Upcasting(B& i) { //using address of base class will get derived-class function
	i.f();//does a virtual call using address of object class B
}
int main() {
	C c(47);
	Upcasting(c);
 
} ///:~