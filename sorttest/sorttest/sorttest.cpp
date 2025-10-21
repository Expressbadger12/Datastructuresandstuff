// sorttest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Boone Stewart
//sorting test

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

//start of heapsort
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
//endofheapsort

//start of bubblesort
void bubbleSort(int arr[], int n) {
	bool swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

//end of bubblesort


void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int* generateArray(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		int randomNum = rand() % 1000;
		arr[i] = randomNum;
	}
	return arr;
}


void testSort(int size) {
	cout << " sorting a " << size << " element array" << endl;

	int* original = generateArray(size);

	int* arrHeap = new int[size];
	int* arrBubb = new int[size];

	copy(original, original + size, arrHeap);
	copy(original, original + size, arrBubb);
	
	auto a = high_resolution_clock::now();
	heapSort(arrHeap, size);
	auto b = high_resolution_clock::now();

	float durationHeap = duration_cast<milliseconds>(b - a).count();

	cout << "Heapsort took " << durationHeap << " miliseconds to sort a " << size << " item array" << endl;

	auto c = high_resolution_clock::now();
	bubbleSort(arrBubb, size);
	auto d = high_resolution_clock::now();

	float durationBubb = duration_cast<milliseconds>(d - c).count();

	cout << "Bubble sort took " << durationBubb << " miliseconds to sort a " << size << " item array" << endl;

}

int main()
{
	testSort(10);
	testSort(100);
	testSort(1000);
	testSort(10000);
	testSort(100000);
}



//int hypothetical() {
//	cout << "sorting a 10 int array" << endl;
//	int* arr = generateArray(10);
//	int[] arr2 = arr;
//	cout << "heapsort" << endl;
//	auto a = high_resolution_clock::now();
//	heapSort(arr, 10);
//	auto b = high_resolution_clock::now();
//
//	float duration10Heap = duration_cast<milliseconds>(b - a).count();
//
//	cout << "Heapsort took" << duration10Heap << " miliseconds to sort a 10 item array" << endl;
//
//	
//	cout << "bubblesort" << endl;
//	auto a = high_resolution_clock::now();
//	bubbleSort(arr, 10);
//	auto b = high_resolution_clock::now();
//
//	cout << "bubblesort took" << duration_cast<milliseconds>(b - a).count() << " miliseconds to sort a 10 item array" << endl;
//
//	delete[] arr;
//	delete[] arr2;
//
//	//100 units
//
//	cout << "sorting a 100 int array" << endl;
//	int* arr3 = generateArray(100);
//	int[] arr4 = arr3;
//	cout << "heapsort" << endl;
//	auto a = high_resolution_clock::now();
//	heapSort(arr3, 100);
//	auto b = high_resolution_clock::now();
//
//	float duration100Heap = duration_cast<milliseconds>(b - a).count();
//
//	cout << "Heapsort took" << duration100Heap << " miliseconds to sort a 100 item array" << endl;
//
//
//	cout << "bubblesort" << endl;
//	auto a = high_resolution_clock::now();
//	bubbleSort(arr4, 100);
//	auto b = high_resolution_clock::now();
//
//	cout << "bubblesort took" << duration_cast<milliseconds>(b - a).count() << " miliseconds to sort a 100 item array" << endl;
//
//	delete[] arr3;
//	delete[] arr4;
//
//	//1000 units
//
//	cout << "sorting a 1000 int array" << endl;
//	int* arr5 = generateArray(1000);
//	int[] arr6 = arr5;
//	cout << "heapsort" << endl;
//	auto a = high_resolution_clock::now();
//	heapSort(arr5, 1000);
//	auto b = high_resolution_clock::now();
//
//	float duration1000Heap = duration_cast<milliseconds>(b - a).count();
//
//	cout << "Heapsort took" << duration1000Heap << " miliseconds to sort a 1000 item array" << endl;
//
//
//	cout << "bubblesort" << endl;
//	auto a = high_resolution_clock::now();
//	bubbleSort(arr6, 1000);
//	auto b = high_resolution_clock::now();
//
//	cout << "bubblesort took" << duration_cast<milliseconds>(b - a).count() << " miliseconds to sort a 1000 item array" << endl;
//
//	delete[] arr5;
//	delete[] arr6;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
