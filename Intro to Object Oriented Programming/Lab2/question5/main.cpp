#include <iostream>

using namespace std;
//Used the code provided on Volume 1 pg 268 to complete Link function
struct Node {
	int data;
	Node* next; //create a pointer of the struct
};

void Link(Node* head, int length) {
	if (head->data == 0) {
		cout << "Root has unknown or zero value" << endl; //head cannot be 0 because it would meant that it is empty
		exit(2);
	}
	else {
		Node* t1 = head;
		for (int i = 2; i <= length; i++) {
			Node* t2 = new Node; //creating a new node
			t2->data = i;	//giving the new node a value
			t1->next = t2; //linking the new node 
			t1 = t1->next; //moving onto the next node to prepare to link
			if (i == length) {
				t1->next = 0; //setting the last struct to 0 to indicate that it is empty
			}
		}
	}
}

void PrintList(Node* root) {
	Node* temp = root;//create temp to traverse the list
	bool full = true;

	while(full){
		if (temp->next == 0) { //0 means that it is the end of the list
			cout << "Int: " << temp->data << ", Adress:";//printing the last non-empty list
			cout << " " << temp << endl;
			full = false;//setting boolean to false to terminate while loop
		}
		else {
			cout << "Int: " << temp->data << ", Adress:"; //printing lists
			cout << " " << temp << endl;
			temp = temp->next;
			
		}
	}
}

int main() {
	int size;
	Node* root;

	cout << "Enter length of list: ";
	cin >> size;

	root->data = 1;//reserving the value 0 to indicate empty list

	Link(root, size);
	PrintList(root);

	return 0;
}