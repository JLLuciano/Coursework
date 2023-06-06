#include<iostream>
#include<climits>
#include <stdio.h>

using namespace std;

void merge(int* array, int left, int mid, int right) {
    //int n1 = 0, n2 = 0, i = 0, j = 0; //m is the size of the left, n is the size of the right,
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = array[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = array[mid + 1 + j];
    }

    leftArr[n1] = INT_MAX;
    rightArr[n2] = INT_MAX;

    int i = 0;
    int j = 0;
    for (int k = left; k <= right; k++) {
        if (leftArr[i] <= rightArr[j]) {
            array[k] = leftArr[i];
            i++;
        }
        else {
            array[k] = rightArr[j];
            j++;

        }
    }
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, (mid + 1), right);
        merge(array, left, mid, right);
    }
}

int main(int argc, const char* argv[]) {
    //p, r, q //p is the left, r is the right, q is the mid. renaming later for personal Understanding

    int arrSize;
    cin >> arrSize;

    //Making the array
    int* array = new int[arrSize + 1];

    //filling the pointer with the values
    for (int i = 0; i < arrSize; i++) {
        cin >> array[i];
    }


    //Start of Algo
    mergeSort(array, 0, arrSize - 1);

    //printing the sorted array
    for (int i = 0; i < arrSize; i++) {
        cout << array[i] << ";";

    }

    return 0;
}
