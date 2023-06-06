#include <iostream>

using namespace std;

class Object {
public:
	static int count;
	Object() {
		cout << "Object()" << endl;
		count++;
	}
	~Object() {
		cout << "~Object()" << endl;
		count--;
	}
};
int Object::count = 0;
Object f(){
}
int main(int argc, const char* argv[])
{
	Object myObject;
	cout << Object::count << endl;
	Object another = f;
	cout << Object::count << endl;
	return 0;
}