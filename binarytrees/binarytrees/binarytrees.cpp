// binarytrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Boone stewart
//Binary Search Tree

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	// Constructor to initialize a new node
	Node(int value): data(value), left(nullptr), right(nullptr) {}
};
class BinarySearchTree {
private:
	Node* root;
	//helper functions for iinserting a node
	Node* insertNode(Node* node, int value) {
		if (node == nullptr) {
			return new Node(value);
		}
		if (value < node->data) {
			node->left = insertNode(node->left, value);
		}
		else if (value > node->data) {
			node->right = insertNode(node->right, value);
		}
		return node;
	}
	//helper function for searching a node
	bool searchNode(Node* node, int value) const {
		if (node == nullptr) {
			return false;
		}
		else if (value == node->data) {
			return true;
		}
		else if (value < node->data) {
			return searchNode(node->left, value);
		}
		else {
			return searchNode(node->right, value);
		}
	}
	//helper function to find the minimum value node
	Node* findMinNode(Node* node) {
		Node* current = node;
		while (current && current->left != nullptr) {
			current = current->left;
		}
		return current;
	}
	//Helper function for deleting a node
	Node* deleteNode(Node* node, int value) {
		if (node == nullptr) {
			return node;
		}
		if (value < node->data) {
			node->left = deleteNode(node->left, value);
		}
		else if (value > node->data) {
			node->right = deleteNode(node->right, value);
		}
		else {
			//Node with only one child or no children
			if (node->left == nullptr) {
				Node* temp = node->right;
				delete node;
				return temp;
			}
			else if (node->right == nullptr) {
				Node* temp = node->left;
				delete node;
				return temp;
			}
			//Mpde with 2 children: get in order successor (smallest in the right subtree)
			Node* temp = findMinNode(node->right);
			//Copy the inorder successor's data to this node and delete the successor
			node->data = temp->data;
			node->right = deleteNode(node->right, temp->data);
		}
	}
};

int main()
{
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
