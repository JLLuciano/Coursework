#include <iostream>

using namespace std;
//used the pseudocode from textbook pg. 154 as a reference

void MAX_HEAPIFY(int* arr, int heapSize, int i) { //had to add heapSize parameter to avoid having to code for the heap size (array length)
	int l = 2*i; //even = left and odd = right
	int r = (2*i) + 1;
	int largest;
	if (l < heapSize && arr[l] > arr[i]) { //instead of <= it must be < to avoid out of bound errors
		largest = l;
	}
	else {
		largest = i;
	}
	if (r < heapSize && arr[r] > arr[largest]) {
		largest = r;
	}
	if (largest != i) {
		swap(arr[i], arr[largest]); //swaps values if the largest value is not found in index i
		MAX_HEAPIFY(arr, heapSize, largest);
	}
	
}
void BUILD_MAX_HEAP(int* arr, int heapSize) { // added heapSize to parameter to easily obtain length of heap
	for (int i = (heapSize / 2)-1; i >= 0; i--) { //heapsize is divided by 2 because of our first two lines for MAX_HEAPIFY()
		MAX_HEAPIFY(arr, heapSize, i);
	}
}

void HEAPSORT(int* arr, int arrSize) { 
	BUILD_MAX_HEAP(arr, arrSize);
	int heapSize = arrSize;
	for (int i = arrSize-1; i >= 1; i--) {
		swap(arr[0], arr[i]);
		heapSize = heapSize - 1;
		MAX_HEAPIFY(arr, heapSize, 0); // in c++ we start at 0 instead of 1
	}
}

int main() {
	int arrSize;
	cin >> arrSize;

	int* arr = new int[arrSize];

	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i]; //inputting values into empty array
	}

	HEAPSORT(arr, arrSize);
	//print array
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ";";
	}
	return 0;
}