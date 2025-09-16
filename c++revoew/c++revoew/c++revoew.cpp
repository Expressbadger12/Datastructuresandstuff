// c++revoew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//09/16/2025
//Review pointers and references

#include <iostream>
using namespace std;
//create 3 functions
void passByValue(int x) {
	x = x * 2; 
	cout << "Inside passByValue: " << x << endl;
}

void passByReference(int& y) {
	y = y * 2;
	cout << "Inside passByReference: " << y << endl;
}


int main()
{

	int num = 100;
	passByValue(num);
	cout << "After passByValue: " << num << endl;
	cout << endl;
	int num2 = 10;
	passByReference(num2);
	cout << "after passbyrefreenerew " << num2 << endl;

	//pointers:

	//int num = 10;
	//int* ptr = &num; // ptr stores the address of num
	//cout << "Value of num: " << num << endl;
	//cout << "Address of num: " << &num << endl;
	//cout << "Value of pointer ptr: " << *ptr;


	//references: 

	//int num = 20;
	//int& ref = num; //ref is another name for num

	//cout << "Original value: " << num << endl;
	//cout << "Ref: " << ref << endl;
	//ref = 30;
	//cout << "Value after modiftying ref: " << ref << endl;
	//cout << "num after change: " << num << endl;
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
