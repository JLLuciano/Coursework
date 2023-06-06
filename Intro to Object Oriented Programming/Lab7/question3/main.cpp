#include <iostream>

using namespace std;
// I used C09:Noinsitu.cpp from page 417 of Volume 1 textbook as a reference for inline constructor and function
class Arr {
	static const int size = 25;//initializing static const int
	int arr[size];
	static int member;
public:
	Arr();
	const int variable;
	static void data();
	void print();
};
inline Arr::Arr() : variable(15) {//initializes const int variable 
	for (int i = 0; i < Arr::size; i++) {//initializing array with static const int size
		Arr::arr[i] = i;
	}
}
inline void Arr::data() { //prints the static int member
	cout << "Static member value: " << Arr::member << endl;
}
inline void Arr::print() {//calls static member function and prints array values
	cout << "Printing array values\n";
	for (int i = 0; i < Arr::size; i++) {
		cout << Arr::arr[i] << ", ";
	}
	cout << '\n';
	Arr::data();
}

int Arr::member = 10;//initializing static int member

int main() {
	Arr s1;
	s1.print();
	cout << "Const int variable: " << s1.variable << endl;//printing const int variable
	return 0;
}