// hashfunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//hashfunction
//Boone Stewart

#include <iostream>
using namespace std;

int customHash(string& message, int tableSize) {
    int hashValue = 0;

    for (char ch : message) {
        hashValue = (hashValue * 31) + static_cast<int>(ch);
    }
    return hashValue;
}

int main()
{
    int tableSixe = 10;
    string message1 = "Apple";
    string message2 = "Banana";
    string message3 = "Orange";
    //Get the hash values for the message
    unsigned int hashvalue1 = customHash(message1, tableSixe);
    unsigned int hashvalue2 = customHash(message2, tableSixe);
    unsigned int hashvalue3 = customHash(message3, tableSixe);

    cout << "Hash value for: " << message1 << " : " << hashvalue1 << endl;
    cout << "Hash value for: " << message2 << " : " << hashvalue2 << endl;
    cout << "Hash value for: " << message3 << " : " << hashvalue3 << endl;

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
