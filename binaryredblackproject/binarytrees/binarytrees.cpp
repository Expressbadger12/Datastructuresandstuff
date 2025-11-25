// binarytrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Boone stewart
//Binary Search Tree

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Nodey {
    int data;
    string color;
    Nodey* left, * right, * parent;

    Nodey(int data)
        : data(data)
        , color("RED")
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    {
    }
};

// Red-Black Tree class
class RedBlackTree {
private:
    Nodey* root;
    Nodey* NIL;

    // Utility function to perform left rotation
    void leftRotate(Nodey* x)
    {
        Nodey* y = x->right;
        x->right = y->left;
        if (y->left != NIL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->left) {
            x->parent->left = y;
        }
        else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // Utility function to perform right rotation
    void rightRotate(Nodey* x)
    {
        Nodey* y = x->left;
        x->left = y->right;
        if (y->right != NIL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            root = y;
        }
        else if (x == x->parent->right) {
            x->parent->right = y;
        }
        else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // Function to fix Red-Black Tree properties after
    // insertion
    void fixInsert(Nodey* k)
    {
        while (k != root && k->parent->color == "RED") {
            if (k->parent == k->parent->parent->left) {
                Nodey* u = k->parent->parent->right; // uncle
                if (u->color == "RED") {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->right) {
                        k = k->parent;
                        leftRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    rightRotate(k->parent->parent);
                }
            }
            else {
                Nodey* u = k->parent->parent->left; // uncle
                if (u->color == "RED") {
                    k->parent->color = "BLACK";
                    u->color = "BLACK";
                    k->parent->parent->color = "RED";
                    k = k->parent->parent;
                }
                else {
                    if (k == k->parent->left) {
                        k = k->parent;
                        rightRotate(k);
                    }
                    k->parent->color = "BLACK";
                    k->parent->parent->color = "RED";
                    leftRotate(k->parent->parent);
                }
            }
        }
        root->color = "BLACK";
    }

    // Inorder traversal helper function
    void inorderHelper(Nodey* node)
    {
        if (node != NIL) {
            inorderHelper(node->left);
            cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    // Search helper function
    Nodey* searchHelper(Nodey* node, int data)
    {
        if (node == NIL || data == node->data) {
            return node;
        }
        if (data < node->data) {
            return searchHelper(node->left, data);
        }
        return searchHelper(node->right, data);
    }

public:
    // Constructor
    RedBlackTree()
    {
        NIL = new Nodey(0);
        NIL->color = "BLACK";
        NIL->left = NIL->right = NIL;
        root = NIL;
    }

    // Insert function
    void insert(int data)
    {
        Nodey* new_node = new Nodey(data);
        new_node->left = NIL;
        new_node->right = NIL;

        Nodey* parent = nullptr;
        Nodey* current = root;

        // BST insert
        while (current != NIL) {
            parent = current;
            if (new_node->data < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }

        new_node->parent = parent;

        if (parent == nullptr) {
            root = new_node;
        }
        else if (new_node->data < parent->data) {
            parent->left = new_node;
        }
        else {
            parent->right = new_node;
        }

        if (new_node->parent == nullptr) {
            new_node->color = "BLACK";
            return;
        }

        if (new_node->parent->parent == nullptr) {
            return;
        }

        fixInsert(new_node);
    }

    // Inorder traversal
    void inorder() { inorderHelper(root); }

    // Search function
    Nodey* search(int data)
    {
        return searchHelper(root, data);
    }
};

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

void fill(BinarySearchTree& tree, int size) {
	for (int i = 0; i < size; i++) {
		int randomNum = rand() % 10000;
		tree.insert(randomNum);
	}
}

void fill(RedBlackTree& tree, int size) {
    for (int i = 0; i < size; i++) {
        int randomNum = rand() % 10000;
        tree.insert(randomNum);
    }
}

void rbsbsbs() {
    RedBlackTree rbt;
    int size = 100;

    auto aone = high_resolution_clock::now();
    fill(rbt, size);
    auto bone = high_resolution_clock::now();

    float duration = duration_cast<microseconds>(bone - aone).count();

    cout << "it took " << duration << " microseconds to sort " << size << " numbers into a red black tree" << endl;

    RedBlackTree rbt2;
    size = 1000;

    auto atwo = high_resolution_clock::now();
    fill(rbt2, size);
    auto btwo = high_resolution_clock::now();

    duration = duration_cast<microseconds>(btwo - atwo).count();

    cout << "it took " << duration << " microseconds to sort " << size << " numbers into a red black tree" << endl;

    RedBlackTree rbt3;
    size = 10000;

    auto athree = high_resolution_clock::now();
    fill(rbt, size);
    auto bthree = high_resolution_clock::now();

    duration = duration_cast<microseconds>(bthree - athree).count();

    cout << "it took " << duration << " microseconds to sort " << size << " numbers into a red black tree" << endl;

    RedBlackTree rbt4;
    size = 100000;

    auto afour = high_resolution_clock::now();
    fill(rbt, size);
    auto bfour = high_resolution_clock::now();

    duration = duration_cast<microseconds>(bfour - afour).count();

    cout << "it took " << duration << " microseconds to sort " << size << " numbers into a red black tree" << endl;

}

int main()
{

    cout << "Inserting into a binary search tree" << endl;
	BinarySearchTree bst1;
	int size = 100;

	auto aone = high_resolution_clock::now();
	fill(bst1, size);
	auto bone = high_resolution_clock::now();

	float duration = duration_cast<microseconds>(bone - aone).count();

	cout << "it took " << duration << " microseconds to sort " << size << " numbers into a binary search tree" << endl;

    BinarySearchTree bst2;
	size = 1000;

	auto atwo = high_resolution_clock::now();
	fill(bst1, size);
	auto btwo = high_resolution_clock::now();

	 duration = duration_cast<microseconds>(btwo - atwo).count();

	cout << "it took " << duration << " microseconds to sort " << size << " numbers into a binary search tree" << endl;

    BinarySearchTree bst3;
	size = 10000;

	auto athree = high_resolution_clock::now();
	fill(bst1, size);
	auto bthree = high_resolution_clock::now();

	duration = duration_cast<microseconds>(bthree - athree).count();

	cout << "it took " << duration << " microseconds to sort " << size << " numbers into a binary search tree" << endl;

    BinarySearchTree bst4;
    size = 100000;

	auto afour = high_resolution_clock::now();
	fill(bst1, size);
	auto bfour = high_resolution_clock::now();

	duration = duration_cast<microseconds>(bfour - afour).count();

	cout << "it took " << duration << " microseconds to sort " << size << " numbers into a binary search tree" << endl;


    cout << "Inserting into a red black tree" << endl;
    rbsbsbs();
}




//BinarySearchTree bst1;
////insert elements
//bst1.insert(50);
//bst1.insert(60);
//bst1.insert(20);
//bst1.insert(10);
//bst1.insert(40);
//bst1.insert(90);
//cout << "Inorder traversal of the BST: ";
//bst1.displayInorder();
//cout << "Search for 40: " << (bst1.search(40) ? "Found" : "Not found") << endl;
//cout << "Search for 100: " << (bst1.search(100) ? "Found" : "Not found") << endl;
////Deleting an element
//cout << "Delete 20" << endl;
//bst1.remove(20);
//cout << "Inorder traversal after deleting (20): ";
//bst1.displayInorder();
//cout << "Delete 60" << endl;
//bst1.remove(60);
//cout << "Inorder traversal after deleting (60): ";
//bst1.displayInorder();