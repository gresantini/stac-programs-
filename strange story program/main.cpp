//
// Created by Greta Santini on 1/29/2025.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "StrangeStory.h"
using namespace std;

int main()
{
    vector<string> verbs;
    vector<string> nouns;
    string word, fileName;

    // Add code to open noun file and read words into vector
    ifstream nounFile("C:\\Users\\gresa\\OneDrive\\Documenti\\nouns.txt");
    if (!nounFile) {
        cerr << "Error: Could not open nouns.txt" << endl;
        return 1;
    }
    while (nounFile >> word) {
        nouns.push_back(word);
    }
    nounFile.close();




    // Add code to open verb file and read words into vector

    ifstream verbFile("C:\\Users\\gresa\\OneDrive\\Documenti\\verbs.txt");
    if (!verbFile) {
        cerr << "Error: Could not open verbs.txt" << endl;
        return 1;
    }
    while (verbFile >> word) {
        verbs.push_back(word);
    }
    verbFile.close();



    // Create a story object
    cout << "Enter the name of the story file: ";
    cin >> fileName;
    StrangeStory myStory = StrangeStory(fileName, nouns, verbs);

    // Output the story
    myStory.createStrange();

    return 0;
}
