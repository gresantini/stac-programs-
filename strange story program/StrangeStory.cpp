//
// Created by Greta Santini on 1/29/2025.
//

#include "StrangeStory.h"
#include <iostream>
#include <fstream>
#include <cstdlib>  // For rand()
#include <ctime>
using namespace std;


StrangeStory::StrangeStory(string filename, vector<string> nouns, vector<string> verbs)
    : m_filename(filename), m_nouns(nouns), m_verbs(verbs) {}

void StrangeStory::createStrange() {
    ifstream storyFile(m_filename);
    if (!storyFile) {
        cerr << "Error: Could not open story file.\n";
        return;
    }

    srand(time(0));

    string word;
        while (storyFile >> word) {
            if (word.find("#") != string::npos && !m_nouns.empty()) {
                word.replace(word.find("#"), 1, m_nouns[rand() % m_nouns.size()]);
            }
            if (word.find("$") != string::npos && !m_verbs.empty()) {
                word.replace(word.find("$"), 1, m_verbs[rand() % m_verbs.size()]);
            }
            cout << word << " ";
    }
    cout << endl;

    storyFile.close();
}
