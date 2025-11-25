// priority queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//11/25/25
//Boone Stewart

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class PriorityQueue {
private:
	vector<int> queue;
public:
	//Insert an element into the priority queue
	void push(int value) {
		queue.push_back(value); // add the int vallue
		//sort in descending order
		sort(queue.begin(), queue.end(), greater<int>());

	}
	//Remove and return the highest-priority element
	int pop() {
		if (queue.empty()) {
			throw runtime_error("Priority Queue is empty!");

		}
		int topElement = queue.front();
		queue.erase(queue.begin()); //remove the first element
		return topElement;
	}
	//Get the highest-priority element without removing it
	int top() {
		if (queue.empty()) {
			throw runtime_error("Priority Queue is empty!!");
		}
		return queue.front();
	}
	//check if the priority queue is empty
	bool empty() {
		return queue.empty();
	}
	//Get the size of priority queue
	int size() {
		return queue.size();
	}
	//Print the elements of the priority queue
	void print() {
		for (int value : queue) {
			cout << value << " ";
		}
		cout << endl;
	}
};


int main()
{
	PriorityQueue pq;
	//insert some elements to the priority queueu
	pq.push(10);
	pq.push(20);
	pq.push(15);
	pq.push(5);
	
	cout << "Priority queue elements: ";
	pq.print();
	cout << endl;
	cout << "Top element (highest priority): " << pq.top() << endl;
	cout << "Removing the top element: " << pq.pop() << endl;
	cout << "Queue after removal: ";
	pq.print();
	cout << endl;
	cout << "Adding 12 to the priority queue" << endl;
	pq.push(12);
	cout << "Priority queue after pushing new value: ";
	pq.print();
	cout << endl;
}

