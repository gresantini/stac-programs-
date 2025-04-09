// author: Greta Santini
//date: 2/4/2025
// binary search tree program

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "WordTree.h"

using namespace std;

int main() {
    fstream file;
    string line, word, filename;
    int lineNumber = 0;

    filename = "C:\\Users\\gresa\\Downloads\\TestLab2.txt";
    file.open(filename.c_str());

    if (!file) {
        cerr << "Error: Unable to open file " << filename << endl;
        return 1;
    }

    WordTree* tree = new WordTree();

    while (getline(file, line)) {
        lineNumber += 1;
        stringstream ss(line);
        while (ss >> word) {
            // Remove punctuation
            word.erase(remove(word.begin(), word.end(), ','), word.end());
            word.erase(remove(word.begin(), word.end(), '.'), word.end());
            word.erase(remove(word.begin(), word.end(), ';'), word.end());
            word.erase(remove(word.begin(), word.end(), '-'), word.end());

            // Convert to lowercase
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            tree->insert(word, lineNumber);
        }
    }

    file.close();


    cout << "There are " << tree->countWords() << " words in the file." << endl;
    cout << "There are " << tree->countUniqueWords() << " unique words in the file." << endl;
    cout << "Alphabetical first word: " << tree->firstWord() << endl;
    cout << "Alphabetical last word: " << tree->lastWord() << endl;

    cout << "\n=== Word Frequency and Line Numbers ===\n";
    tree->printTreeInOrder();


    vector<string> frequentWords = tree->mostFrequentWords();
    cout << "The most frequent word(s): ";
    for (unsigned i = 0; i < frequentWords.size(); i++) {
        cout << frequentWords[i] << " ";
    }
    cout << endl;

    delete tree;
    return 0;
}
