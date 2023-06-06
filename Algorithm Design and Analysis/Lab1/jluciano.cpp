#include <iostream>

using namespace std;

void insertionSort(int arr[], int length) { 
    for (long i = 1; i <= length; i++) { //created a for loop that iterates through the array
        long j = i;
        if (i >= 2) {
            for (int y = 0; y < i; y++) { //created a for loop that prints out the array line by line each time it iterates     
                cout << arr[y] << ";";
            }
            cout << endl;
        }
        while (j > 0 && arr[j - 1] > arr[j]) { //created a whie loop that sorts the array by comparing both i and j indices
            long temp = arr[j]; //created a temp variable so that the values can be swapped if it meets the conitions of the while loop
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j = j - 1;  
        }
    }
}

int main() {
    int size = 0;
    cin >> size;
    int arr[size]; //intializes the array to the first integer from the input file
    for (int i = 0; i < size; i++) { //inputs the values into the array
        cin >> arr[i];
    }
    insertionSort(arr, size); //calls the function I created above called insertionSort
}