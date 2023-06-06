#include <iostream>
#include <climits>
#include <stdio.h>

using namespace std;

void merge(int* arr, int p, int q, int r) {
	int n1 = q - p + 1; //calculating length of subarrays
	int n2 = r - q;

	int L[n1+1]; //initializing sub arrays with the caluculated lengths
	int R[n2+1];

	for (int i = 0; i < n1; i++) { //filling the subarrays with values from our array pointer
		L[i] = arr[p + i];
}
	for (int j = 0; j < n2; j++) {
		R[j] = arr[q + j + 1];
	}

	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	
	int i = 0; //resetting the values to use in another for loop
	int j = 0;

	for (int k = p; k <= r; k++) { //comparing values from the subarrays and replacing them into our array pointer
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}
}

void mergeSort(int* arr,int p,int r) { //recursively calling the function when the left value is lower than the right
	//if (p < r) {
		int q = (p + r) / 2; //q takes the position of the p and r in the recursive calls
		mergeSort(arr,p, q);
		mergeSort(arr,(q + 1),r);
		merge(arr, p, q, r);
	//}
}

int main() {
	int size = 0;
	cin >> size;
	int* arr = new int[size +1]; //initialzing array with size+1 to avoid any segmentation faults or out of bound errors
	for (int i = 0; i < size; i++) {
		cin >> arr[i]; //filling in the array pointer
	}
	mergeSort(arr, 0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << arr[i] << ";";
	}
	return 0;
}
