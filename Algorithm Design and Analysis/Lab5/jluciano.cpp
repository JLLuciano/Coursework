#include <iostream>
#include <vector>

using namespace std;
//using the bubble sort and radix sort pseudocode from pages 40 and 198
vector<vector<int>> BUBBLESORT(vector<vector<int>> A, int index) { //implemented BUBBLESORT into RADIX_SORT
	int j = 0, k = 0;

	for (j = 0; j < A.size()-1; j++) {
		for (k = A.size()-1; k > j ; k--) {
			if (A[k][index] < A[k-1][index]) {  //sorts the vectors by row according to the values in the columns
					swap(A[k], A[k - 1]); //if the condition is met it will swap rows to organize from least to greatest
			}
		}
		
	 }
	return A;
}

vector<vector<int>> RADIX_SORT(vector<vector<int>> A) {
	int index = 0;
	for (int i = 9; i >= 0 ; i--) { //start from 9 so that BUBBLESORT can ultimately sort the vectors according to their first index
		 index = i;
		 A = BUBBLESORT(A, index);
	}
	return A;
}

int main() {
	int rows;
	cin >> rows;

	int i = 0, j = 0;

	vector<vector<int>> A;

	int value;
	//inputting values into the 2D vector
	for (i = 0; i < rows; i++) {
		vector<int> row;
		for (j = 0; j < 10; j++) {
			cin >> value;
			row.push_back(value);
		}
		A.push_back(row);
	}
	A = RADIX_SORT(A);
	//printing the 2D vector out
	for  (i = 0; i < rows; i++) {
		for (j = 0; j < 10; j++) {
			cout << A[i][j] << ";";
		}
		cout << endl;
	}

	return 0;
}

