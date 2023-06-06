#include <iostream>
#include <string>
#include <fstream>

using namespace std;
//used code from Lab 1 question2 for reading a file
//Used slide 17 from Lecture 7 as a reference to understand how to make more than one constructor
class Text {
	string content;//string object
public:
	Text() {//default constructor
		cout << "Default constructor: No file to read" << endl;
	}
	Text(string file) {//alternative constructor
		ifstream in(file); //telling program which file to read from
		string line;

		while (getline(in, line)) {
			 content+= line + "\n"; //inputting one line at a time to the string
		}
	}
	string contents() { //creating contents() function to 'print' the string
		return content;
	}

};

int main() {
	Text s1;
	string filename;

	cout << "Enter file to open: ";
	cin >> filename;
	cout << "-----------------------------\n";

	Text s2(filename);
	cout << s2.contents();
	

	

	
	return 0;
}