
// Using code from C01:Replace.cpp from page 34 as a template for my code
// Simple find-and-replace in strings 
#include <string> 
#include <iostream> 
using namespace std;
int main() {
	string s("A piece of text, another piece of text");
	string tag("\r");
	s.insert(8, tag + "");
	cout << s << endl;
	int start = s.find(tag);
	cout << "start = " << start << endl;
	cout << "size = " << tag.size() << endl;
	s.replace(start, tag.size(), "");
	cout << s << endl;
} ///:~

