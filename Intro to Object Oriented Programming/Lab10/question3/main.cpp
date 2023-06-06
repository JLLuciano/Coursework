#include <iostream>
#include <stack>

using namespace std;

int main() {
	int length;
	stack<int> fib;
	int n1 = 0;
	int n2 = 1;
	int n3;

	cout << "Enter length of fibonacci sequence\n";
	cin >> length;

	cout << n1 << endl;//print first integer of fibonacci sequence
	for (int i = 0; i < length; i++) {// fib: n3 = n2 + n1
		n3 = n2 + n1;//updating n3 for our new number	
		fib.push(n1);
		fib.push(n2);
		fib.push(n3);//pushing our newly calculated value to the top and will be use to calculate the next number
		n2 = fib.top();
		fib.pop();//deleting from stack to update it with new last two integers 
		n1 = fib.top();
		fib.pop();
		cout << n3 << endl;

	}

	return 0;
}