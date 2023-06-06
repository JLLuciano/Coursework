#include <iostream>
#include "Pstash.h" 
#include "Pstash.cpp"
//I got the PStash code directly from the textbook page 588 and 587
//On Pstash.cpp I removed anything related to ../require.h since it was causing problems for me
using namespace std;

class Counted {
	int id;
	static int count;//cant do in-class initialization
public:
	Counted() :id(count++) {
		cout << "Creating id: " << id << endl;
	}
	~Counted() {
		cout << "Destroying id: " << id << endl;
	}
	friend ostream& //copied code from page 738 of Volume 1 textbook
		operator<<(ostream& os, const Counted& x) {
		return os << x.id;
	}
	void f() {
		cout << "Function f()" << endl;
	}

};

int Counted::count = 0;

int main() {
	PStash s1;
	
	s1.add(new Counted);//filling in PStash object with Counted objects
	s1.add(new Counted);
	s1.add(new Counted);

	for (int i = 0; i < s1.count(); i++) {
		cout << *((Counted*)s1[i]) << ", "; //printing objects, had to typcast it to Counted* to access members of class Counted
		((Counted*)s1[i])->f();
	}
	for (int i = s1.count() - 1; i >= 0; i--) {
		((Counted*)s1[i])->~Counted();//deleting the object
		s1.remove(i); //removing the pointer since object is no longer there
	}
	
}