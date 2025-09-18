// doublylinkedlists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//09/18/2025
//doubly linked list

#include <iostream>
using namespace std;
struct DNode {
    int data;
    DNode* next;
    DNode* prev;
    // constructor
    DNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
//doublylinkedlist class
class DoublyLinkedList {
private:
    DNode* head;
public:
    //constructor to initialize
    DoublyLinkedList() {
        head = nullptr;
    }
    //function to insert a new node at the end of the list
    void insert(int value) {
        DNode* newNode = new DNode(value);
        if (!head) {
            head = newNode;
        }
        else {
            DNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    //function to display the list from head to tail
    void displayForward() {
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    //function to display the list from tail to head
    void displayBackward() {
        if (!head) return;
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->prev;
        }
        cout << "nullptr" << endl;
        
    }
    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            DNode* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        // Search for the node to delete
        DNode* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        //Node found
        if (temp != nullptr) {
            if (temp->next) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList list;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);
    cout << "Doubly linked list forward: ";
    list.displayForward();
    cout << endl;
    cout << "Doubly linked list backwards: ";
    list.displayBackward();
    list.deleteNode(30);
    cout << endl;
    cout << "After deleting 30 the list forward: ";
    list.displayForward();
}
