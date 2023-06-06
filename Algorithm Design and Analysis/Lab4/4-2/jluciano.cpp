#include <iostream>

using namespace std;

//used the pseudocode from pages 179 and 171 from the textbook as a reference

int PARTITION(int* arr, int p, int r) {
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r - 1; j++) {
		if (arr[j] <= x) {
			i++;
			swap(arr[i], arr[j]); //swaps values to order them from least to greatest
		}
	}
	swap(arr[i + 1], arr[r]);
	return i + 1; //return index which will be used in RANDOM_PARTITION
}

int RANDOMIZED_PARTITION(int* arr, int p, int r) {
	int i = p + (rand() % (r - p + 1));  //using rand() to obtain random values from p to r inclusively
	swap(arr[r], arr[i]); //swaps value with a random index generated from rand()
	return PARTITION(arr, p, r); //uses PARTITION to obtain pivot index
}

void RANDOMIZED_QUICKSORT(int* arr,int p,int r) {
	if (p < r) {
		int q = RANDOMIZED_PARTITION(arr, p, r);
		RANDOMIZED_QUICKSORT(arr, p, q - 1);// handles left side recursively
		RANDOMIZED_QUICKSORT(arr, q + 1, r);//handles right side recursively
	}
}

int main() {
	int arrSize;
	cin >> arrSize;

	int* arr = new int[arrSize];
	//fill in empty array
	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}
	RANDOMIZED_QUICKSORT(arr, 0, arrSize - 1); //since we start at 0 we must subtract 1 from arrSize

	//print array
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ";";
	}
	return 0;
}