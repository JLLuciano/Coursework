#include <iostream>

using namespace std;

//I used pgs 182-183 from Volume 1 as a reference on how to use static_cast
void setValue(void* ptr,int num, int value) {
	int* s3 = static_cast<int*>(ptr); //if we convert it to int we can work byte by byte

	for (int i = 0; i < num; i++) {
		s3[i] = value; //the int pointer can accept int value, but void* ptr cannot because 'void*' is not a pointer-to-object type
	}

}
int main() {
	const int size = 9; //I tried doing int s1[9] = {...} but garbage values were being printed out along with the modified values
	int s1[size] = { 1,2,3,4,5,6,7,8,9 };
	void* s2 = static_cast<void*>(s1);

	cout << "Before: ";
	for (int j = 0; j < size; j++) {
		cout << s1[j] << ",";
	}
	cout << "\n";

	setValue(s2, 4, 11);//int num from setValue cannot exceed the size of the array
	
	cout << "After: ";
	for (int j = 0; j < size; j++) {
		cout << s1[j] << ","; //printing out the array values, since we are using int array we know we are print byte by byte
	}
	cout << "\n";

	return 0;
}