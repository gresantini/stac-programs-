//
// Created by gresa on 2/4/2025.
//

#ifndef WORDTREE_H
#define WORDTREE_H

#include <string>
#include <vector>
#include "WordNode.h"

using namespace std;

class WordTree {
public:
    WordTree();
    ~WordTree();

    void insert(string newWord, int lineNum);
    void printTreeInOrder();
    int countUniqueWords() const;
    int countWords();
    string lastWord();
    string firstWord();
    vector<int> wordLines(const string& word);
    vector<string> mostFrequentWords();
    void processFile(const string& fileName);

private:
    WordNode* root;
    int totalWords;
    int uniqueWords;

    WordNode* insertRecursive(WordNode* node, const string& newWord, int lineNum);
    void printInOrder(WordNode* node);
    int countUniqueWords(WordNode* node);
    int countUniqueWordsHelper(WordNode* node) const;
    int countWords(WordNode* node);
    int countWordsHelper(WordNode* node);
    string lastWord(WordNode* node);
    string firstWord(WordNode* node);
    vector<int> wordLinesRecursive(WordNode* node, const string& word);
    void findMostFrequentWords(WordNode* node, int& maxCount, vector<string>& words);
    void deleteTree(WordNode* node);
    string toLowerCase(const string& str);
};

#endif // WORDTREE_H
