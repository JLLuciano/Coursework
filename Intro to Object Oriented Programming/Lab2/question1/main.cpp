#include <iostream>
#include <string>

using namespace std;
//for the pointer portion of this exercise I used lecture 5 as a reference
typedef struct Struct {
	string s1;
	string s2;
	int price;
};

int main() {
	Struct car;

	car.s1 = "Hot"; 
	car.s2 = "Wheels";
	car.price = 2;

	cout << car.s1 << " ";//printing the values of the members
	cout << car.s2 << ":$";
	cout << car.price << endl;

	Struct* p_car;

	p_car = &car;
	p_car->s1 = "Cold"; //modifying the values using the pointer
	p_car->s2 = "Tires";
	p_car->price = 9999;

	cout << (*p_car).s1 << " "; //(*p_car) is another way of saying p_car->
	cout << (*p_car).s2;
	cout << ":$" << (*p_car).price << endl;


	return 0;
}