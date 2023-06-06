#include <iostream>

using namespace std;
//Used slide 7 from CSE 165 Lecture 21.pptx as a reference for throw, try, and catch
class A {
public:
	void f() {//member function of A that throws exception object B
		throw B("Exception object is thrown and caught");
	}
	class B {	
	public:
		const char* data;//made it public to enable printing in main()
		B(const char* msg) : data(msg) {}//assign string or char* to data
	};
	
};

int main() {
	A a;//creaing object
	try {
		a.f();//using member function to throw exception object
	}
	catch(A::B str){//catching object B
		cout << str.data << endl;//printing description string
	}

	return 0;
}