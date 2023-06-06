#include <iostream>

using namespace std;
// I used the following as a reference for initializing the static int count : https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
class Counted {
	int id;
	static int count;//cant do in-class initialization
public:
	Counted() :id(count++) {
		cout << "Creating id: " << id << endl;
	}
	~Counted(){
		cout << "Destroying id: " << id << endl;
	}
};

int Counted::count = 0;

int main() {
	Counted s1;
	Counted s2;
	return 0;
}