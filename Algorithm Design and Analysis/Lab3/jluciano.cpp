#include<stdio.h>
#include<climits>
#include<iostream>

using namespace std;
//used the pseudocode from the textbook as reference

int MAX_CROSSING_SUBARRAY(int A[],int low, int mid, int high){
int left_sum = INT_MIN;
int sum = 0;

for(int i = mid; i>= low; i-- ){ //traverse the left side of the array and find the index with the highest possible sum
    sum = sum + A[i];
    if(sum > left_sum){
        left_sum = sum;
    }
}
int right_sum = INT_MIN;
sum = 0;

for(int j = mid+1; j <= high; j++){//traverse the right side of the array and find the index with the highest possible sum
    sum = sum + A[j];
    if(sum > right_sum){
        right_sum = sum;

    }
}
return (left_sum + right_sum); //add up both sums to obtain the max sum
}

int MAXIMUM_SUBARRAY(int A[], int low, int high) {
    int mid;
    int left_Sum;
    int right_Sum;
    int cross_Sum;
    if (low == high) {
        return A[low];
    }
    else {
        mid = (high + low) / 2;
        left_Sum = MAXIMUM_SUBARRAY(A, low, mid); //recursively call the function to break the array into single elements
        right_Sum = MAXIMUM_SUBARRAY(A, mid + 1, high);
        cross_Sum = MAX_CROSSING_SUBARRAY(A, low, mid, high);

        if (left_Sum >= right_Sum && left_Sum >= cross_Sum) { //if statements check for the maximum sum of a subarray
            return left_Sum;
        }
        else if (right_Sum >= left_Sum && right_Sum >= cross_Sum) {
            return right_Sum;
        }
        else {
            return cross_Sum;
        }
        return 0;
    }
}

int main(){
    int size;
    cin >> size;
    int arr[size];
    int max_Sum;

    for (int i = 0; i <= size; i++) {
        cin >> arr[i]; //input values into the array
    }
    max_Sum = MAXIMUM_SUBARRAY(arr, 0, size - 1);
    cout << max_Sum; //print out sum of subarray with max value
    return 0;
}

