//
// Created by Greta Santini on 2/4/2025.
//
#ifndef WORDNODE_H
#define WORDNODE_H

#include <string>
#include <vector>
using namespace std;

class WordNode {
public:
    string word;
    int count;
    vector<int> lineNumbers;
    WordNode* left;
    WordNode* right;

    WordNode(string w, int lineNum);
};

#endif // WORDNODE_H





