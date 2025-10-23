// DIYHashFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Create your own hashing function
//Boone Stewart

#include <iostream>
using namespace std;

int BalloonHash(string& message) {
	int hashValue = 0;

	string key = "Casablanca";
	for (char ch : message) {
		hashValue = (hashValue + static_cast<int>(ch)) * 17;
		hashValue += 1;
	}
	hashValue = hashValue * 14;
	for (char ch : key) {
		hashValue = hashValue - (hashValue % static_cast<int>(ch));
	}
	return hashValue;
}


int main()
{
	string message1 = "Apple";
	string message2 = "Banana";
	string message3 = "Bornana";
	string message4 = "Balloon";

	unsigned int hash1 = BalloonHash(message1);
	unsigned int hash2 = BalloonHash(message2);
	unsigned int hash3 = BalloonHash(message3);
	unsigned int hash4 = BalloonHash(message4);


	cout << "Hash value for " << message1 << " is : " << hash1 << endl;
	cout << "Hash value for " << message2 << " is : " << hash2 << endl;
	cout << "Hash value for " << message3 << " is : " << hash3 << endl;
	cout << "Hash value for " << message4 << " is : " << hash4 << endl;
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
