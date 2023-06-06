#include <iostream>
#include <vector>

using namespace std;

bool Prime(int a, int b) { //this function is to determine if the number is a factor
	if (a % b == 0) { //if this statement is true then the number cannot be prime
		return false;
	}
	else {
		return true;
	}
}


int main() {
	
	int n;
	bool check; //the boolean is used to determine if the inner loop should skip the number since it isn't prime
	vector<int> list;

	cout << "Enter the length of the list: "; //asking user for length of vector
	cin >> n;

	for (int i = 2; i <= n; i++) { //start at 2 because 0 and 1 do not count as prime numbers

		check = true;
											//the reason for j <= i/2 is because we want to reduce the amount of time taken to check for factors
		for (int j = 2; j <= i/2; j++) { // by doing j <= i/2 we are stopping at the last maximum factor of the number i	


			if (check = Prime(i,j)) {	
				continue;
			}
			else { //it breaks because the number is not prime so it moves on to the next number
				break;
			}
			
		}
		if (check) {
			list.push_back(i); //fills in the vector with prime numbers
		}
	}

	cout << "The prime numbers from the list are: \n";

	for (int k = 0; k < list.size(); k++) {
		cout << list[k] << " "; //output the values of the vector containing prime numbers
	}

	cout << "\n";

	return 0;
}