// Heapsort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Boone Stewart
//heapsort


#include <iostream>
using namespace::std;

void heapify(int arr[], int n, int i) {
    int largest = i; //Initialize the largest as the root
    int left = 2 * i + 1; //left child
    int right = 2 * i + 2;
    //if the left child is larger than the root
    if (left< n && arr[left] > arr[largest]) {
        largest = left;
    }
    //if right child is larger than the largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    // if the largest is not the root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        //recursivly heapify the affected subtree
        heapify(arr, n, largest);
    }
}

//heapsort function
void heapSort(int arr[], int n) {
    //build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    //extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        //move the current root to end
        swap(arr[0], arr[i]);
        //heapify the reduced heap
        heapify(arr, i, 0);
    }
}
//function to display 
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout <<  endl;
}
int main()
{
    int arr[] = { 89, 2, 414, 39, 5, 12, 25 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: " << endl;
    printArray(arr, n);
    cout << endl;
    heapSort(arr, n);
    cout << "Heap sorted array: " << endl;
    printArray(arr, n);
    cout << endl;
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
