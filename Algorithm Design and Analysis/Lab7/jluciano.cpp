#include <iostream>
#include <limits.h>

//using pseudocode from page 369 as a reference

using namespace std;

void EXTENDED_BOTTOM_UP_CUT_ROD(int* p,int n) {

	int* r = new int[n+1]; //lines 48-49 explain why we allocated n+1 size to our pointers
	int* s = new int[n+1];

	r[0] = 0; // the first cut length and max profit are zero since our first price is 0
	s[0] = 0; // this array will hold the optimzed cut lengths for the rod

	for (int j = 1; j <= n; j++) {

		int q = INT_MIN; //setting it to the lowest number possible,-infinity

		for (int i = 1; i <= j; i++) {

			if (q < p[i] + r[j - i]) {

				q = p[i] + r[j - i]; //updating our max profit value

				s[j] = i; //updating the optimized cut lengths
			}
			r[j] = q; //when j = n, r[n] will hold the max profit value
		}
	}
	//implementing PRINT_CUT_ROD_SOLUTION(p,n) in the function to avoid dealing with (return r and s)

	cout << r[n] << "\n";
	while (n > 0) {
		cout << s[n] << " ";
		n = n - s[n]; //n is the rod and s[n] cuts the rod and when it is zero it will exit the while loop
	}
	cout << "-1\n";
}

int main() {
	int size;

	cin >> size;

	int* arr = new int[size+1];

//since we will be setting our first price to 0 we must make allocate one more space in our array
// which explains the new int[size +1] for each pointer created 

	for (int i = 0; i <= size; i++) { 
		if (i == 0) {
			arr[i] = 0; //setting the first price to 0 
		}
		else {
			cin >> arr[i]; //inputting values into array from index 1 to size
		}
	}

	EXTENDED_BOTTOM_UP_CUT_ROD(arr, size); //calling our function to print out max profit value and cut lengths


	return 0;
;}