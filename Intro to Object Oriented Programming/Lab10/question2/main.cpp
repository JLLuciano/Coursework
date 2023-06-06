#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;
// I am using my code from lab 1,question2 to read and insert words to vector from a file
class Hangman {
	char c;
	bool guess = true; //used to determine when to stop accepting user input
	int count;//used to determine when to stop accepting user input
public:
	string game;//the main string being printed
	string temp;//this is the word that is being guessed
	Hangman(string);//constructor initializes temp to random word inputted
	void checkGame();//used in while loop to tell program when there are no more chances
	void compareChar(char);//compares user input to temp
	void compareWord(string);//if a user enters more than 1 character it will compare it to temp
	bool stillGuess();//main component for while loop
};

Hangman::Hangman(string word){
	temp += "" + word;
	int x = temp.size();
	count = x + 3;
	for (int i = 0; i < x; i++) {
		game += "_"; //setting it to underscores and will update it
	}
}
void Hangman::compareWord(string t) {
	if (temp.compare(t) == 0) {//compare checks if the strings are the same and if not it will return a non-zero integer
		cout << "YOU WON" << endl;
		guess = false;
		exit(0);
	}
	else {
		guess = false;
		cout << "YOU LOSE :(" << endl;
		exit(0);
	}
}
bool Hangman::stillGuess() {//while loop purposes
	return guess;
}

void Hangman::checkGame() {//when out of chances you lose
	if (count == 0) {
		cout << "No more chances left :(" << endl;
		guess = false;
		exit(0);
	}
}
void Hangman::compareChar(char input) {
	char t[] = { input };//technically a char* which is for initializion purposes
	string replace(t);
	int y = temp.find(replace);//finding where to replace char
	int dup = std::count(temp.begin(), temp.end(), t[0]);
	if (y != -1) {//if char is part of string replace the underscore
		if ( dup > 1) {//if duplicate letter check locations and then replace
			for (int i = 0; i < temp.size(); i++) {
				if (temp[i] == t[0]) {
					game.replace(i, sizeof(char), replace);
				}
			}
		}
		game.replace(y, sizeof(char), replace);
	}
	if (game.compare(temp) == 0) {//if there are still chances and game is complete you win!
		cout << game << endl;
		cout << "YOU WON" << endl;
		exit(0);
	}
count--;//reducing chances left after each guess
}

int main() {
	vector<string> v; //created a vector
	string con;
	string word;
	char single;

	ifstream in("text.txt"); //telling program which file to read from
	string line;

	while (getline(in, line)) {
		v.push_back(line); //inputting one line at a time to the vector
	}
	srand(time(NULL));//random seed generator
	int random = rand() % v.size();//get a random index of vector
	int remove = v[random].find("\r");

	v[random].replace(remove, sizeof(char), ""); //removing the \r after every word from text
	Hangman play(v[random]);
	
	cout << "Game has started" << endl;
	cin >> word;

	while (play.stillGuess()) {
		
		if (word.size() == 1) {
		
			single = word[0];
			play.compareChar(single);
			play.checkGame();
			cout << play.game << endl;
		}
		else {
			play.compareWord(word);
		}
			cin >> word;
	}
	return 0;
}