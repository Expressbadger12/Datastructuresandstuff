// Queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//9/30/25/
// Boone Stewart
//queueueue
#include <iostream>
using namespace std;

//Node strucutre for linked list
struct Node {
	int data;
	Node* next;

	//constructor
	Node(int value) {
		data = value;
		next = nullptr;
	}
};

//queue class using a linkedlist
class Queue {
private:
	Node* front; // pointer to the front of the queue
	Node* rear; // to the rear of the queue
public:
	//constructor
	Queue() {
		front = nullptr;
		rear = nullptr;
	}
	//Function to check if the quwuw is empty
	bool isEmpty() {
		return front == nullptr;
	}
	//function to enqueue (add) an element to the que
	void enqueue(int value) {
		Node* newNode = new Node(value); // created a new element in the queue
		if (rear == nullptr) { // if the que is empty, both front and rear point to the new node
			front = rear = newNode;
		}
		else {
			rear->next = newNode; //link the newnode at the end of the que
			rear = newNode; // update rear to point to the new node
		}
	}
	// function to dequeue (remove) an element from the queue
	void dequeue() {
		if (isEmpty()) {
			cout << "Queue is empty! Cannot Dequeue" << endl;
			return;
		}
		Node* temp = front;//store the current front node
		front = front->next; //move the front pointer to the next node
		//if front becoms nullptr, set rear to nullptr as well (empty queue)
		if (front == nullptr) {
			rear = nullptr;
		}
		delete temp; //free the memory of the dequeue node
	}
	//function to get the fron element of a queue
	int peek() {
		if (isEmpty()){
			cout << "Queue is empty!" << endl;
			return -1;
		}
		return front->data;
	}

	void display() {
		if (isEmpty()) {
			cout << "Queue is empty!" << endl;
			return;
		}
		Node* temp = front;
		while (temp != nullptr) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "nullptr" << endl;
	}
};

int main()
{
	Queue q;
	q.enqueue(2);
	q.enqueue(4);
	q.enqueue(6);
	q.enqueue(8);
	q.display();

	q.dequeue();
	q.dequeue();

	q.display();
}
