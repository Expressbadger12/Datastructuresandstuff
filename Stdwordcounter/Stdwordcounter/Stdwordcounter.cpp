// Maps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Boone Stewart
//11/10/25
//Std wordcount

#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

void countWord(string subject) {
	map<string, int> countEm;
	string word;

	stringstream ss(subject);

		while (ss >> word) {
			if (countEm.find(word) != countEm.end()) {
				countEm[word] += 1;
			}
			else {
				countEm[word] = 1;
			}
		}

		cout << "Contents of the map: " << endl;
		for (const auto& pair : countEm) {
			cout << pair.first << " appears " << pair.second << " times" << endl;
		}
}

void alphabet(string subject) {
	map<string, int> countEm;
	string word;

	stringstream ss(subject);
	
	while (ss >> word) {

		for (auto& l : word) {
			l = tolower(static_cast<unsigned char>(l));
		}

		if (countEm.find(word) != countEm.end()) {
			countEm[word] += 1;
		}
		else {
			countEm[word] = 1;
		}
	}

	cout << "Contents of the map: " << endl;
	for (const auto& pair : countEm) {
		cout << pair.first << " appears " << pair.second << " times" << endl;
	}
}


void Top(string subject) {
	map<string, int> countEm;
	string word;

	stringstream ss(subject);

	while (ss >> word) {

		if (countEm.find(word) != countEm.end()) {
			countEm[word] += 1;
		}
		else {
			countEm[word] = 1;
		}
	}

	int maxFreq = 0;
	for (auto& pair : countEm) {
		if (pair.second > maxFreq) {
			maxFreq = pair.second;
		}
	}

	cout << "The most frequently appearing word(s) are:" << endl;
	for (auto& pair : countEm) {
		if (pair.second == maxFreq) {
			cout << "'" << pair.first << "'" << " appears " << pair.second << " times!" << endl;
		}
	}


}

int main()
{
	cout << "we will be counting the words in the old rhyme 'Hey diddle diddle the cat and the fiddle the cow jumped over the moon'" << endl;

	cout << "In alphabetical order the words in the rhyme are:" << endl;

	alphabet("Hey diddle diddle the cat and the fiddle the cow jumped over the moon");

	cout << endl;

	Top("Hey diddle diddle the cat and the fiddle the cow jumped over the moon");
}