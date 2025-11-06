// Sets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Boone Stewart
//11/06/2025
//sets

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main()
{
	set<int> setNumbers;
	setNumbers.insert(5);
	setNumbers.insert(3);
	setNumbers.insert(5);// duplicate will be ignored 
	setNumbers.insert(8); 
	//multiset
	multiset<int> multiNumbers; // uses binary tree sorting/particioning 
	multiNumbers.insert(5);
	multiNumbers.insert(3);
	multiNumbers.insert(5);
	multiNumbers.insert(8);

	cout << "Set Elements: ";
	for (int num : setNumbers) {
		cout << num << " ";
	}
	cout << endl;
	//search for element
	if (setNumbers.find(3) != setNumbers.end()) {
		cout << "3 found in the set" << endl;
	}
	//erase an element
	setNumbers.erase(5);
	cout << "After erasing 5, the dataset of the set is:";
	for (int num : setNumbers) {
		cout << num << " ";
	}
	cout << endl;
	cout << "Multiset elements: ";
	for (int num : multiNumbers) {
		cout << num << " ";
	}
	cout << endl;
	cout << "Count of 5: " << multiNumbers.count(5) << endl;
	multiNumbers.erase(multiNumbers.find(5)); // erase one instance of 5
	for (int num : multiNumbers) {
		cout << num << " ";
	}

}

