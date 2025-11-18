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
		return node;
	}
	//Helper function for inorder traversal
	void inorderTraversal(Node* node) {
		if (node == nullptr) return;
		inorderTraversal(node->left);
		cout << node->data << " ";
		inorderTraversal(node->right);
	}
public:
	//constructor
	BinarySearchTree(): root(nullptr){}
	//function to insert a value in a BST
	void insert(int value) {
		root = insertNode(root, value);
	}
	//function to search the value in the bst
	bool search(int value) {
		return searchNode(root, value);
	}
	//function to delete a value from the BST
	void remove(int value) {
		root = deleteNode(root, value);
	}
	//Function to display the BST in order
	void displayInorder() {
		inorderTraversal(root);
		cout << endl;
	}

};

int main()
{
	BinarySearchTree bst1;
	//insert elements
	bst1.insert(50);
	bst1.insert(60);
	bst1.insert(20);
	bst1.insert(10);
	bst1.insert(40);
	bst1.insert(90);
	cout << "Inorder traversal of the BST: ";
	bst1.displayInorder();
	cout << "Search for 40: " << (bst1.search(40) ? "Found" : "Not found") << endl;
	cout << "Search for 100: " << (bst1.search(100) ? "Found" : "Not found") << endl;
	//Deleting an element
	cout << "Delete 20" << endl;
	bst1.remove(20);
	cout << "Inorder traversal after deleting (20): ";
	bst1.displayInorder();
	cout << "Delete 60" << endl;
	bst1.remove(60);
	cout << "Inorder traversal after deleting (60): ";
	bst1.displayInorder();
}