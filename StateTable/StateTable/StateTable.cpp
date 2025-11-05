// StateTable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Boone Stewart
//State Tables
//10/28/25

#include <iostream>
#include <string>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;


struct HashNode {
    string key;
    string value;
    HashNode(string k, string v) : key(k), value(v) {}
};

//key cannot be same (in this case name) value can be same (in this case state)
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
    void insert(const string& key, string value) {
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
    bool retrieve(const string& key, string& value) {
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

string generateName() {
    string name;
    for (int i = 0; i < 4; i++) {
        int rasm = rand();
        string namepart = to_string(rasm);
        name = name + namepart;
    }
    return name;
}

string pickState() {
    string states[50] = { "Alabama", "Alaska", "Arizona", "Arkansas", "California", "Colorado", "Connecticut", "Delaware", "Florida", "Georgia", "Hawaii", "Idaho", "Illinois", "Indiana", "Iowa", "Kansas", "Kentucky", "Louisiana", "Maine", "Maryland", "Massachusetts", "Michigan", "Minnesota", "Mississippi", "Missouri", "Montana", "Nebraska", "Nevada", "New Hampshire", "New Jersey", "New Mexico", "New York", "North Carolina", "North Dakota", "Ohio", "Oklahoma", "Oregon", "Pennsylvania", "Rhode Island", "South Carolina", "South Dakota", "Tennessee", "Texas", "Utah", "Vermont", "Virginia", "Washington", "West Virginia", "Wisconsin", "Wyoming" };
    int random = (rand() % 50);
    return states[random];
}

void makelist(HashTable& table) {
    table.insert("Alice", "California");
    for (int i = 0; i < 999; i++) {
        table.insert(generateName(), pickState());
    }
}


void doTheThing(int buckets) {

    auto start = high_resolution_clock::now();

    HashTable hashTable1(buckets);
    makelist(hashTable1);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time it took to generate data and put data in the "<< buckets << " bucket hash table: " << duration.count() << " microseconds" << endl;

    string nothing;

    cin >> nothing;
   
    auto start2 = high_resolution_clock::now();

    string key, value;

    key = "Alice";
    if (hashTable1.retrieve(key, value)) {
        cout << "Retrieve example" << endl;
        cout << "\nValue for key: " << key << " is: " << value << endl;
    }

    auto stop2 = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(stop2 - start2);

    cout << "Time it took to find the given value in a " << buckets << " bucket hash table was " << duration2.count() << " microseconds" << endl;
 
    cout << "Continue to print hashtable" << endl;
    cin >> nothing;
    
    auto start3 = high_resolution_clock::now();

    hashTable1.print();

    auto stop3 = high_resolution_clock::now();

    auto duration3 = duration_cast<microseconds>(stop3 - start3);

    cout << "Time it took to print a " << buckets << " bucket hash table was " << duration3.count() << " microseconds" << endl;
}

int main()
{
    string nothing;


    cout << "10 bucket hash table:" << endl;
    doTheThing(10);
    cout << endl;
    cout << "type anything to move on to the 100 bucket hash table:" << endl;
    cin >> nothing;

    cout << "100 bucket hash table:" << endl;
    doTheThing(100);
    cout << endl;
    cout << "type anything to move on to the 1000 bucket hash table:" << endl;
    cin >> nothing;

    cout << "1000 bucket hash table:" << endl;
    doTheThing(1000);
    cout << endl;
}
