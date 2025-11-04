// Maps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Boone Stewart
//11/4/25
//Maps

#include <iostream>
#include <map>
#include<string>

using namespace std;

int main()
{
	//declare a a map to store age with names as keys
	map<string, int> ageMap;
	//Insert elements into the map using insert function or square bracketoperator
	ageMap.insert(make_pair("John", 25));
	ageMap["Alice"] = 30;
	ageMap["Michael"] = 22;

	//Access elemts in the map
	cout << "Age of John: " << ageMap["John"] << endl;
	cout << "Age of Alice: " << ageMap.at("Alice") << endl;
	//check if a ke exists in the map
	if (ageMap.find("Michael") != ageMap.end()) {
		cout << "Age of Michael: " << ageMap["Michael"] << endl;
	}
	else {
		cout << "Michael's age not found in the map!" << endl;
	}
	//another way to check if a key exists using found method
	if (ageMap.count("Mary") > 0) {
//		cout << ageMap.count("Alice") << endl;
		cout << "Age of Mary: " << ageMap["Mary"] << endl;
	}
	else {
		cout << "Mary's age not found in the map!" << endl;
	}

	ageMap.erase("Alice");
	//check if a key exists after deletion
	if (ageMap.count("Alice") > 0) {
		cout << "Age of Alice: " << ageMap["Alice"] << endl;
	}
	else {
		cout << "Alice's age not found in the map after deletion" << endl;
	}
	//Iterate throughout the map using the range based for loop
	cout << "Contents of the map: " << endl;
	for (const auto& pair : ageMap) {
		cout << pair.first << " is " << pair.second << " years old!" << endl;
	}
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
