// hashhh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//oone Stewart
//hashattack

#include <iostream>
using namespace std;

//simple hash function for strings
unsigned int simpleHash(string message) {
    unsigned int hash = 0;
    for (char c : message) {
        hash = hash * 31 + c; //multiply by 31 and add char value
    }
    return hash;

}

unsigned int intHash(int message) {
    //bit shifting (>> 16)
    //this shifts bites of message 16 positions to the right
    //essentially, it takes the upper 16 bites of a 32 bit integer
    // ^ is the bitwise XOR operator
    //XOR mixes the upper 16 bites with the orignial value
    //which helps to scramble the bites and reduce patterns
    message = ((message >> 16) ^ message) * 0x45d9f3b;
    message = ((message >> 16) ^ message) * 0x45d9f3b;
    message = (message >> 16) ^ message;
    return message;
}

int main()
{
//    cout << "hash of Banana is: " << simpleHash("Banana") << endl;
  //  cout << "hash of apple is: " << simpleHash("apple") << endl;

    cout << "Hash of 10: " << intHash(10) << endl;
    cout << "Hash of 123456: " << intHash(123456) << endl;

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
