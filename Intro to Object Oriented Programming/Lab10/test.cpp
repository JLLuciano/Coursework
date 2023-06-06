#include <iostream>
using namespace std;
class A {
public:
	int f(int x) { return (x + 5); }
};
class C : public A {
public:
	int f(int x) { return (x - 5); }
};
int main() {
	C obj; cout << obj.f(15) << endl;
	C* c = new C; cout << c->f(15) << endl; delete c;
	A* a = new C; cout << a->f(15) << endl; delete a;
}