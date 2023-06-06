//: C15:AddingVirtuals.cpp, pg. 685-686 Volume 1 of textbook
// Adding virtuals in derivation 
#include <iostream> 
#include <string> 
//used slide 26 of Lecture 11 to understand how to declare pure virtual functions
using namespace std;
class Pet { // it is now an abstract class
	string pname;
public:
		Pet(const string& petName) : pname(petName) {} //cannot be virtual
		virtual string name() const = 0;
		virtual string speak() const = 0;//declaring a pure virtual function
};

string Pet::name() const {//providing a definition for our pure virtual function
	cout << "Their name is: ";
	return pname;
}
class Dog : public Pet {
	//string name; had to remove due to 'conflicts with a previous declaration'
public:
	Dog(const string& petName) : Pet(petName) {}
	// New virtual function in the Dog class: 
	virtual string sit() const {
		return Pet::name() + " sits";
	}
	string speak() const { // Override 
		return Pet::name() + ". Now bark!";
	}
	string name() const {//implemented name() so class Dog won't become abstract 
		return Pet::name();
	}
};
int main() {
	Pet* p[] = { new Dog("bob") };// had to remove new Pet() because instances cannot be created from abstract classes
	cout << "p[0]->speak() = " << endl;
	cout << p[0]->speak() << endl;
	//! cout << "p[1]->sit() = " 
	//! << p[1]->sit() << endl; // Illegal 
} ///:~