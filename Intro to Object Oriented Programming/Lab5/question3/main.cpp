# include <iostream>
# include <ctime>

using namespace std;
//https://www.cplusplus.com/reference/ctime/clock/, used as a reference to calculate time for each call
// Used slide 21 of lecture 8 to remember how to upcast
class Base {
public:
	int x, y = 0;
	virtual void Virtual() {
		x++; //incrementing values
	}
	void NonVirtual() {
		y++;
	}
};

class Derived : public Base { //using this to make virtual calls
};

float VTime(Base* ptr) { //makes multiple virtual calls
	float temp = clock();
	for (int i = 0; i < 99999999; i++) {
		ptr->Virtual();
	}
	temp = clock() - temp;
	return temp / CLOCKS_PER_SEC;
}
float Time(Base* ptr) { //makes multiple nonvirtual calls
	float temp = clock();
	for (int i = 0; i < 99999999; i++) {
		ptr->NonVirtual();
	}
	temp = clock() - temp; //results in total time taken
	return temp / CLOCKS_PER_SEC; //return time in seconds
}

int main() {
	Derived ptr;
	Derived* ptr2 = &ptr;
	Base* time = (Base*)ptr2; //upcasting

	cout << "Time taken for virtual calls: " << VTime(ptr2) << endl;
	cout << "Time taken for nonvirtual calls: " << Time(ptr2) << endl;

	return 0;
}