#include <iostream>

using namespace std;

class A {
public:
	A() { cout << "A\n"; }
	~A() { cout << "~A\n"; }
};
class B : public A {
public:
	B() { cout << "B\n"; }
	 ~B() { cout << "~B\n"; }
};
class C : public B
{
public:
	C() { cout << "C\n"; }
	 ~C() { cout << "~C\n"; }
};
int main() {
	B* c = new A;
	if (true) { C c; }
	delete c;
	return 0;
}