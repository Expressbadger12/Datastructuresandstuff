// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Boone Stewart
//09/25/2025
//stack ADT implementation

#include <iostream>
using namespace std;
class Stack {
private:
    int top; // Index of the top element
    int capacity; //maximum size of stack
    int* arr; //array to hold stack elements

public:
    //constructor to initialize stack
    Stack(int size) {
        capacity = size; 
        arr = new int[capacity]; //dynamic array allocation
        top = -1; // stack is initially empty
    }
    ~Stack() {
        delete[] arr;
    }
    //Push operation to add element to stack
    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack overflow: cannot push " << value << endl;
        }
        else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }
    // pop function to delete an element 
    void pop() {
        if (top == -1) {
            cout << "Stack underflow! cannot pop element." << endl;
        }
        else {
            cout << arr[top--] << " popped from stack!" << endl;
        }
    }
    //peek operation to get the top element
    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
        } 
        else {
            return arr[top];
        }
    }
    //check if stack is emptuy
    bool isEmpty() {
        return top == -1;
    }
    //Check if stack is full 
    bool isFull() {
        return top == capacity - 1;
    }
    //display stack elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack stack1(5);
    //push some elements in the stack
    stack1.push(50);
    stack1.push(25);
    stack1.push(42);
    stack1.push(22);

    cout << stack1.peek();
    cout << endl;
    stack1.display();
    cout << endl;
    stack1.pop();
    cout << stack1.peek();
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
