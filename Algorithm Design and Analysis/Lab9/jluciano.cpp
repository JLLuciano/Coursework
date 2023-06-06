#include <iostream>
#include <limits.h>
#include <vector>

//using page 431 from the textbook as a reference

using namespace std;

struct Node { //Constructing nodes
	Node *left;
	Node *right;

	int frequency;
	string encode;
	int character;
};
//used HEAP_EXTRACT_MAX from page 163 to make EXTRACT_MIN
Node EXTRACT_MIN(vector<Node>& hfTree) { //we want to find the minimum key and return it, as well as remove the node from the huffman tree
	int min = INT_MAX;
	int index;
	int i = 0;
	while (i < hfTree.size()) {
		if (min > hfTree[i].frequency) {
			min = hfTree[i].frequency; //updating minimum value
			index = i; //writing the location of minimum value
		}
		i++;
	}
	Node minNode = hfTree[index];//will be returning this Node that has the minimum value
	hfTree.erase(hfTree.begin() + index); //erasing the node from the huffman tree

	return minNode;
}

Node BUILD_HF_TREE(vector<Node>& hfTree) {//create the huffman tree of nodes
	for (int i = hfTree.size(); i > 1; i--) {
		Node* z = new Node;
		Node* left = new Node;
		Node* right = new Node;

		*left = EXTRACT_MIN(hfTree);
		*right = EXTRACT_MIN(hfTree); //had to create more nodes because I couldn't assign a node pointer to a node

		z->left = left;
		z->right = right;
		z->frequency = (left->frequency) + (right->frequency);
		hfTree.push_back(*z);
	}
	return hfTree[0]; //return the root of the tree
}

void HF_ENCODE(Node* z,string input, string arr[]) { //encoding the nodes with 0s and 1s
	int root;
	Node* temp = new Node;
	temp = z;

	temp->encode = input;
	if (temp->left == NULL && temp->right == NULL) { //checking if the nodes are empty
		root = z-> character - 'A';
		arr[root] = z->encode;
	}
	else {
		z->left->encode = input.append("0"); //concatenating with 0s and 1s
		input.erase(input.end() - 1);

		z->right->encode = input.append("1");
		input.erase(input.end() - 1);

		HF_ENCODE(z->left, input.append("0"), arr);
		input.erase(input.end() - 1);

		HF_ENCODE(z->right, input.append("1"), arr);
		input.erase(input.end() - 1);
	}

}
int main() {


	int size = 6;
	string arr[size];
	vector<Node> hfTree; //creating a vector of Nodes
	int character;
	int freq;

	for (int i = 0; i < size; i++) {//Filling the huffman tree

		Node node;
		

		cin >> freq;
		character = 'A' + i; // A,B,C,D,E,F
		node.frequency = freq; //using . instead of -> because node is not a pointer here
		node.character = character;
		node.left = NULL;
		node.right = NULL;

		hfTree.push_back(node); //inserting nodes into vector

	}
	Node root = BUILD_HF_TREE(hfTree); 

	HF_ENCODE(&root, "", arr); 
	
	char alphabet = 'A';
	//printing the values with their corresponding letter
	for (int i = 0; i < size; i++) {
		cout << alphabet++ << ":";
		cout << arr[i] << endl;
	}

	return 0;

}