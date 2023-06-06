#include <iostream>
#include <new>
#include <vector>
#include <string>

using namespace std;
//used code from question5 to complete void* operator new
class Placement {
	static vector<string> vec;//since vec is static we can continously add strings to it even from the creation of new objects
public:
	Placement() {}
	 void* operator new(size_t s, string str) {
		void* ptr = malloc(s);
		if (!ptr) puts("Out of memory");
		vec.push_back(str);//adding the string to the vector
		return ptr;
	}
	void PrintStr() {
		for (int i = 0; i < vec.size(); i++) {
			cout << vec[i] << endl;
		}
	}

};
vector<string>Placement::vec;//have to initialize it here or else vec.push_back(str) wont work

int main() {
	vector<Placement*> ptr;
	for (int i = 0; i < 10; i++) {
		ptr.push_back(new("Call " + to_string(i))Placement);//convert integer to string to help create a string that describes the object 
	}

	ptr[0]->PrintStr();//since the vector contains objects we can use a single object to call our print function

	for (int i = 0; i < 10; i++) {
		delete ptr[i];//I have to delete new objects to avoid memory leakage
	}

	return 0;
}