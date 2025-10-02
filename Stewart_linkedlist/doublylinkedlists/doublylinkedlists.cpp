// doublylinkedlists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//09/18/2025
//doubly linked list

#include <iostream>
#include <cstdlib>
using namespace std;
struct DNode {
    string data;
    DNode* next;
    DNode* prev;
    // constructor
    DNode(string value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
//doublylinkedlist class
class DoublyLinkedList {
private:
    DNode* head = nullptr;
public:
    //constructor to initialize
    /*DoublyLinkedList() {
        head = nullptr;
    }*/
    //function to insert a new node at the end of the list
    void insert(string value) {
        DNode* newNode = new DNode(value);
        if (!head) {
            head = newNode;
        }
        else {
            DNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    //function to display the list from head to tail
    void displayForward() {
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
    //function to display the list from tail to head
    void displayBackward() {
        if (!head) return;
        DNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->prev;
        }
        cout << "nullptr" << endl;
        
    }
    void deleteNode(string value) {
        if (!head) return;
        if (head->data == value) {
            DNode* temp = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete temp;
            return;
        }
        // Search for the node to delete
        DNode* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        //Node found
        if (temp != nullptr) {
            if (temp->prev) temp->prev->next = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            delete temp;
        }
    }
    void find(string value) {
        DNode* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << value << " found in list" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << value << " not found in list" << endl;
    }
};

void StartingList(DoublyLinkedList list) {
    list.insert("www.google.com");
    list.insert("www.youtube.com");
    list.insert("www.amazon.com");
    list.insert("www.reddit.com");
    list.insert("www.kermaniumexplainium.com");
    list.insert("kahoot.it");
    list.insert("chatgpt.com");
    list.insert("www.roblox.com");
    list.insert("www.nytimes.com");
    list.insert("www.chess.com");
    list.insert("www.fangamer.com");
    list.insert("www.musescore.com");
    list.insert("www.pianobin.com");
    list.insert("www.deltarune.com");
    list.insert("www.tryhackme.com");
    list.insert("www.kahnacademy.org");
    list.insert("www.wikipedia.org");
    list.insert("www.schoolschoolschool.com");
    list.insert("www.wheelofnames.com");
    list.insert("www.desmos.com");
}

void Options(DoublyLinkedList list) {
    string choice;
    cout << "Press 1 to display list forward -- Press 2 to display list backwards -- Press 3 to add to list -- Press 4 to delete from list -- Press 5 to find in list -- Press 6 to exit" << endl;
    cout << "Then press enter" << endl;
    cin >> choice;
    if (choice == "1") {
        cout << "1 Pressed" << endl;
        list.displayForward();
    }
    else if (choice == "2") {
        cout << "2 Pressed" << endl;
        list.displayBackward();
    }
    else if (choice == "3") {
        string addText;
        cout << "3 Pressed" << endl;
        cout << "Enter what you would like to add" << endl;
        cin >> addText;
        list.insert(addText);
    }
    else if (choice == "4") {
        string deleteText;
        cout << "4 Pressed" << endl;
        cout << "Enter what you would like to delete" << endl;
        cin >> deleteText;
        list.deleteNode(deleteText);
    }
    else if (choice == "5") {
        string findText;
        cout << "5 Pressed" << endl;
        cout << "Enter what you would like to find" << endl;
        cin >> findText;
        list.find(findText);
    }
    else if (choice == "6") {
        cout << "Press enter again to fully exit" << endl;
        exit(EXIT_SUCCESS);
    }
    else {
        cout << "That's not one of the options" << endl;
    }
    choice = "";
    Options(list);

}

int main()
{
    DoublyLinkedList list;
    //StartingList(list);
    list.insert("www.google.com");
    list.insert("www.youtube.com");
    list.insert("www.amazon.com");
    list.insert("www.reddit.com");
    list.insert("www.kermaniumexplainium.com");
    list.insert("kahoot.it");
    list.insert("chatgpt.com");
    list.insert("www.roblox.com");
    list.insert("www.nytimes.com");
    list.insert("www.chess.com");
    list.insert("www.fangamer.com");
    list.insert("www.musescore.com");
    list.insert("www.pianobin.com");
    list.insert("www.deltarune.com");
    list.insert("www.tryhackme.com");
    list.insert("www.kahnacademy.org");
    list.insert("www.wikipedia.org");
    list.insert("www.schoolschoolschool.com");
    list.insert("www.wheelofnames.com");
    list.insert("www.desmos.com");
    Options(list);
}
