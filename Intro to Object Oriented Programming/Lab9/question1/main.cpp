#include <iostream>

using namespace std;
//used C06:MultipleInheritance2.cpp from page 347 of the book, and slide 15 of CSE 165 Lecture 22.pptx
class X {
public:
	X(int c){
		cout << "X constructor called\n";
	}
	void f() {
		cout << "X::f()\n";
	}
};
class Y : virtual public X {//made it virtual to avoid subojects
public:
	Y(int x):X(x) {
		cout << "Y constructor called\n";
	}
	void f() {
		cout << "Y::f()\n";
	}
};
class Z : virtual public X {
public:
	Z(int x):X(x) {
		cout << "Z constructor called\n";
	}
	void f() {
		cout << "Z::f()\n";
	}
};
class A : public Y, public Z {
public:
	A(int x) : Z(x), Y(x), X(x) {//only one object of class X is created due to the virtual keyword
		cout << "A constructor called\n";
	}
	void f() {
		return Z::f();//explicit disambiguation, stating which f() to use
	}
};
int main() {
	A s1(2);
	s1.f();//calling f() from class A which uses Z::f()
	return 0;
}