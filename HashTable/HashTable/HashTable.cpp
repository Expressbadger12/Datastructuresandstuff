// HashTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Boone Stewart
//Hash Table
//10/28/25

#include <iostream>
#include<list>
using namespace std;

struct HashNode {
    string key;
    int value;
    HashNode(string k, int v) : key(k), value(v) { }
};
//class HashTable
class HashTable {
private:
    int tableSize;
    list<HashNode>* table; // array of lists for chaining
    //simple hash function: sum of ASCII values modulo tablesize
    int hashFunction(const string& key) {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % tableSize;
    }
public:
    HashTable(int size) {
        tableSize = size;
        table = new list<HashNode>[tableSize];
    }
    ~HashTable() {
        delete[] table; // free memory for table
    }
    //instert key-value pair
    void insert(const string& key, int value) {
        int index = hashFunction(key);
        //check if key already exists: update value
        //auto: let the compiler deduce the type (hashnode)
        for (auto& node : table[index]) {
            if (node.key == key) {
                node.value = value;
                return;
            }
        }
        //key doesn't exist, insert new node
        HashNode newNode(key, value);
        table[index].push_back(newNode);

    }   
    //retreive value by key; returns true if found
    bool retrieve(const string& key, int& value) {
        int index = hashFunction(key);
        for (auto& node : table[index]) {
            if (node.key == key) {
                value = node.value;
                return true;
            }
        }
        return false;

    }
    //print all key-value pairs
    void print() {
        cout << "Hash Table Contents: " << endl;
        for (int i = 0; i < tableSize; i++) {
            cout << "Bucket " << i << ": ";
            if (table[i].empty()) {
                cout << "Empty" << endl;
            }
            else {
                for (auto& node : table[i]) {
                    cout << "{" << node.key << " -> " << node.value << "}" << endl;
                }
            }

        }
    }
};

int main()
{
    HashTable hashTable1(13);
    //insert elements
    hashTable1.insert("Michael", 85);
    hashTable1.insert("Maria", 90);
    hashTable1.insert("Tony", 70);
    hashTable1.insert("Georgeo", 50);
    hashTable1.insert("Flayer", 99);

    hashTable1.print();

    int value;
    string key = "Charlie";
    if (hashTable1.retrieve(key, value)) {
        cout << "\nValue for key: " << key << " is: " << value << endl;
    }
    else {
        cout << "\nValue for Key: " << key << " not found" << endl;
    }

    string bing = "Maria";
    if (hashTable1.retrieve(bing, value)) {
        cout << "\nValue for key: " << bing << " is: " << value << endl;
    }
    else {
        cout << "\nValue for Key: " << bing << " not found" << endl;
    }
}