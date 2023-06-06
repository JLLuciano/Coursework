#include <iostream>
#include <string>

using namespace std;

int main() {

	bool check = true;
	string word;
	char value;

	while (check) { //if true it will continue to run while loop, false means terminate while loop
		cout << "Enter a word: ";
		cin >> word;
		//each word corresponds to a value of 0, 1, 2, 3
		if (word == "Gaming") {
			value = '0';
		}
		else if (word == "Homework") {
			value = '1';
		}
		else if (word == "Food") {
			value = '2';
		}
		else if (word == "Sleep") { //this will terminate the while loop
			value = '3';
		}
		else if (word == "Outside") {
			value = '4';
		}
		
		switch (value) { //the value of the variable value decides what case will be chosen
		case '0': {
			cout << "Timmy will play video games until midnight." << endl;
			break;
		}
		case'1': {
			cout << "Timmy will work on some of his homework until he gets bored." << endl;
			break;
		}
		case'2': {
			cout << "Timmy will go get food to eat." << endl;
			break;//break is in each case so that the program can ask again for user input
		}
		case'3': {
			cout << "It is past Timmy's bedtime. Time for Timmy to sleep" << endl;
			check = false; //only time check is false is when the word sleep is inputted which will terminate the while loop
			break;
		}
		case'4': {
			cout << "Timmy goes outside to play soccer." << endl;
			break;//break is in each case so that the program can ask again for user input
		}
		}
	}
	return 0;
}