// CSC382.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Boone Stewart
// 09/11/2025
//Linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Linked_list {
private:
    Node *head, *tail;
public:
    Linked_list() {
        head = NULL;
        tail = NULL;
    }
    void add_node(int n) {
        Node* tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;
        if (head == NULL) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    // Method to display the linkedlist
    void printList() {
        Node* temp = head;
        if (head == NULL) {
            cout << "List Empty!!" << endl;
            return;
        }
        //traverse the list
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
   
};

int main()
{
    Linked_list list1;
    /*list1.add_node(1);
    list1.add_node(2);
    list1.add_node(3);
    list1.add_node(4);*/
    list1.printList();
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
