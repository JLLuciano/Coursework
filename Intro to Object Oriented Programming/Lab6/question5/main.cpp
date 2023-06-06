#include <iostream>
#include <new>

using namespace std;
//Used GlobalOperatorNew.cpp from page 597-598 and 603 of textbook as a reference to overload operators new and delete
class Overload {
public:
	void* operator new(size_t s) {//single object, operator new’ takes type ‘size_t’ (‘long unsigned int’) as first parameter
		printf("Allocating memory: %lu Bytes\n", s);
		void* ptr = malloc(s);
		if (!ptr) puts("Out of memory");
		return ptr;//received warning that I had to return something
	}
	void operator delete(void* p) {//‘operator delete’ takes type ‘void*’ as first parameter
		printf("Deleting object memory located at: %p\n", p);
		free(p);
	}
	void* operator new[](size_t s) {
		printf("Allocating memory: %lu Bytes\n", s);
		return ::new int[s];//the :: helps us use the other new overloaded function
	}
	void operator delete[](void* p) {
		printf("Deleting array memory located at: %p\n", p);//using printf to avoid new memory allocating with cout
		::delete []p;
	}
};

int main() {
	Overload* s1 = new Overload;
	Overload* s2 = new Overload[10];

	delete s1;
	delete []s2;
}