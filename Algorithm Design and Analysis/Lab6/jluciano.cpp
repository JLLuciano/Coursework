#include<iostream>
#include<iterator>
#include<list>

using namespace std;

class Hash {
	int hashSize;

	list<int> *hashTable;

public:
	Hash(int size);//constructor
	//creating member functions for the class Hash
	void CHAINED_HASH_INSERT(int x);

	void CHAINED_HASH_DELETE(int key);

	void CHAINED_HASH_SEARCH(int key);

	int hashFunction(int x) {
		return (x % hashSize); //h(k) = k % m
	}

	void printHASHTABLE();
};
//defining the member functions
void Hash::CHAINED_HASH_INSERT(int x) {
	int index = hashFunction(x);
	hashTable[index].push_front(x); //inserting values to the front of the list
}

	Hash::Hash(int size) {
	this->hashSize = size; //using the pointer "this" to get the hashSize from our class and define it with int size
	hashTable = new list<int>[hashSize]; //create a list of size hashSize
}

void Hash::CHAINED_HASH_DELETE(int key) {
	int x = hashFunction(key);
	list<int> :: iterator i = hashTable[x].begin();//start at the beginning of our hash table

	while (i != hashTable[x].end()) {
		if (*i == key) {
			break;
		}
		i++;
	}
	if (i == hashTable[x].end()) { //if it was able to iterate towards the end of the list then it means that the value was not found, therefore, it wasnt able to be deleted
		cout << key << ":DELETE_FAILED;" << endl;
	}
	else {
		hashTable[x].erase(i);
		cout << key << ":DELETED;" << endl; // the key was found and deleted from the hash table
	}
}

void Hash::CHAINED_HASH_SEARCH(int key) {
	int x = hashFunction(key);
	int y = 0;

	list<int> ::iterator i = hashTable[x].begin();
	while (i != hashTable[x].end()) { //iterate throughout the hash table
		if (*i == key) { //if the key is found then it will break from the while loop
			break;
		}
		y++;
		i++;
	}
	if (i == hashTable[x].end()) { // if this condition is true then it iterated through the hash table and did not find the key
		cout << key << ":NOT_FOUND;" << endl;
	}
	else {
		cout << key << ":FOUND_AT" << x << "," << y <<";"<< endl;
	}
}

void Hash::printHASHTABLE() {
	for (int i = 0; i < hashSize; i++) { //prints the index of the hash table
		cout << i << ":";
		for (int j : hashTable[i]) {
			cout << j << "->"; //prints out the individual elements of the list of each index
		}
		cout <<";" <<endl;
	}
}

int main() {
	char operation;
	int hashSize;
	int key;

	cin >> hashSize;

	Hash table(hashSize);
	//goes through while loop as long as 'e' is not assigned to operation
	while (operation != 'e') {
		cin >> operation;
		if (operation == 'i') { //inserts element
			cin >> key;
			table.CHAINED_HASH_INSERT(key);
		}
		if (operation == 's') { //searches for element
			cin >> key;
			table.CHAINED_HASH_SEARCH(key);
		}
		if (operation == 'o') { //displays the hash table
			table.printHASHTABLE();
		}
		if (operation == 'd') { //deletes an element
			cin >> key;
			table.CHAINED_HASH_DELETE(key);
		}
		
	}
	if (operation == 'e') {
		return 0; //terminates the program
		}
	return 0;
}