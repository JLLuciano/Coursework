#include <iostream>
#include <vector>

using namespace std;
//used page 738 of Volume 1 textbook to understand how to overload operator to print object
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
		operator<<(ostream& os, const Counted& x) { //had to overload operator in order to do directly print out object
		return os << x.id;
	}
	
};

int Counted::count = 0;

int main() {
	vector<Counted*> ptr;
	ptr.push_back(new Counted); //adding objects to vector
	ptr.push_back(new Counted);
	ptr.push_back(new Counted);
	for (int i = 0; i < ptr.size(); i++) {
		cout << *ptr[i] << endl;
		
	}
	int index = ptr.size()-1;

	while (index >= 0) { //once index is zero it means vector is empty
		ptr[index]->~Counted(); //calling destructor to delete objects
		index--;
	}
	return 0;
}