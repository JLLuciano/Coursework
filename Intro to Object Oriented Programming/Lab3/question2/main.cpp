#include <iostream>

using namespace std;
//According to Exercise 6 I had to nest Nest to Hen and Egg to Nest
//Exercise 7 only asks to assign private data and grant friendship
//I used pages 282-283 and 286 from Volume 1 to understand how to grant friendship and access private members
class Hen
{
public:
		class Nest
		{
			int x; //private data
			friend class Hen;
		public:
			void dataNest(Nest* nest);
				class Egg
				{
					int y; //private data
					friend class Nest;
				public:
					void dataEgg(Egg* egg);
				};
		};
		
};
void Hen::Nest::dataNest(Nest* nest) { //taking address of class object
	cout << "Accessing Hen::Nest" << endl;
	cout << "Enter an integer for Nest private member: ";
	cin >> nest->x; //accessing private member of Nest and inputting a value
	cout << "Private Data in Nest: " << nest->x << endl; //printing the value
}
void Hen::Nest::Egg::dataEgg(Egg* egg) {
	cout << "Accessing Hen::Nest::Egg" << endl;
	cout << "Enter an integer for Egg private member: ";
	cin >> egg->y;
	cout << "Private Data in Egg: " << egg->y << endl;
}

int main() {
	Hen s1; //creating class objects
	Hen::Nest s2;
	Hen::Nest::Egg s3;

	s2.dataNest(&s2); //calling class public functions
	cout << "\n";
	s3.dataEgg(&s3);
	return 0;
}