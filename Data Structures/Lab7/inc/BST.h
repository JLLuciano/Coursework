#pragma once

#include <iostream>
#include <string>

struct BST {
	std::string data;
	BST* left;
	BST* right;
};

void traverse(BST* root){
	if (root != NULL){
		traverse(root->left);
		std::cout << root->data << std::endl;
		traverse(root->right);
	}
}

BST* insert(BST* root, std::string value){
	if (root == NULL){
		root = new BST();
		root->data = value;
		root->left = NULL;
		root->right = NULL;
	}
	else{
		if (value >= root->data){
			// go right
			root->right = insert(root->right, value);
		}
		else{
			// go left
			root->left = insert(root->left, value);
		}
	}

	return root;
}

bool search (BST* root, std::string value){
	if (root == NULL){
		return false;
	}
	else{
		if (root->data == value){
			return true;
		}
		else{
			if (value < root->data){
				return search(root->left, value);
			}
			else{
				return search(root->right, value);
			}
		}
	}
}
