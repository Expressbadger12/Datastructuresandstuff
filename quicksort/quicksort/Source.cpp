//Boone Stewart
//quicksort
#include <iostream>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//partition function to place the pivot element in the correct position
int partition(int arr[], int low, int high) {
	int pivot = arr[high]; // chooose the last element as a pivot
	int i = (low - 1); // index of the smaller element
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot){
		i++;
		swap(&arr[i], &arr[j]);
		}
	}
	//swap  pivot element with the element at i+1
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		//recursivly sort the two halves
		quickSort(arr, low, pi - 1); //left half
		quickSort(arr, pi + 1, high);// right half
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}


int main()
{
	int arr[] = { 50, 20, 70, 10, 90, 80 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Original array: ";
	printArray(arr, n);
	cout << endl;
	quickSort(arr, 0, n - 1);
	cout << "Quick Sort ordered array elements: ";
	printArray(arr, n);
}
