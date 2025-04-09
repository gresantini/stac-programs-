//
// Created by Greta Santini on 2/4/2025.
//

#include "WordTree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

WordTree::WordTree() : root(nullptr), totalWords(0), uniqueWords(0) {}

WordTree::~WordTree() {
    deleteTree(root);
}

void WordTree::deleteTree(WordNode* node) {
    if (node) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

void WordTree::insert(string newWord, int lineNum) {
    root = insertRecursive(root, toLowerCase(newWord), lineNum);
}


WordNode* WordTree::insertRecursive(WordNode* node, const string& word, int lineNum) {
    if (node == nullptr) {
        return new WordNode(word, lineNum);
    }
    if (word < node->word) {
        node->left = insertRecursive(node->left, word, lineNum);
    } else if (word > node->word) {
        node->right = insertRecursive(node->right, word, lineNum);
    } else {
        node-> count++;
        if (find(node->lineNumbers.begin(), node->lineNumbers.end(), lineNum) == node->lineNumbers.end()) {
            node->lineNumbers.push_back(lineNum);
        }
    }
    return node;
}


void WordTree::printTreeInOrder() {
    printInOrder(root);
}

void WordTree::printInOrder(WordNode* node) {
    if (node== NULL) return;
        printInOrder(node->left);
        cout << node->word << " (" << node->count << ")";
    cout <<" appears on lines: ";

    for (size_t i=0; i< node -> lineNumbers.size(); i++) {
        cout<< node -> lineNumbers[i];
        if (i != node-> lineNumbers.size()-1)cout <<", ";
    }
    cout<< endl;
        printInOrder(node->right);
    }


int WordTree::countUniqueWords() const {
    return countUniqueWordsHelper(root);
}

int WordTree::countUniqueWordsHelper(WordNode* node) const {
    if (node == nullptr) return 0;
    return 1 + countUniqueWordsHelper(node->left) + countUniqueWordsHelper(node->right);
}


// Public function that calls the recursive helper
int WordTree::countWords() {
    return countWordsHelper(root);
}

// Private recursive helper function
int WordTree::countWordsHelper(WordNode* node) {
    if (node == nullptr) return 0; // Base case: empty node
    return node->count + countWordsHelper(node->left) + countWordsHelper(node->right);
}


string WordTree::lastWord() {
    WordNode* node = root;
    while (node && node->right) node = node->right;
    return node ? node->word : "";
}

string WordTree::firstWord() {
    WordNode* node = root;
    while (node && node->left) node = node->left;
    return node ? node->word : "";
}

vector<int> WordTree::wordLines(const string& word) {
    return wordLinesRecursive(root, toLowerCase(word));
}

vector<int> WordTree::wordLinesRecursive(WordNode* node, const string& word) {
    if (!node) return {};
    if (word < node->word) return wordLinesRecursive(node->left, word);
    if (word > node->word) return wordLinesRecursive(node->right, word);
    return node->lineNumbers;
}

string WordTree::toLowerCase(const string& str) {
    string result = str;
    for (char& c : result) c = tolower(c);
    return result;
}

vector<string> WordTree::mostFrequentWords() {
    vector<string> mostFrequent;
    int maxCount = 0;
    findMostFrequentWords(root, maxCount, mostFrequent);
    return mostFrequent;
}

void WordTree::findMostFrequentWords(WordNode* node, int& maxCount, vector<string>& words) {
    if (!node) return;

    findMostFrequentWords(node->left, maxCount, words);

    if (node->count > maxCount) {
        maxCount = node->count;
        words.clear();
        words.push_back(node->word);
    } else if (node->count == maxCount) {
        words.push_back(node->word);
    }

    findMostFrequentWords(node->right, maxCount, words);
}

