//
// Created by Greta Santini on 2/4/2025.
//

#include "WordNode.h"

WordNode::WordNode(string w, int lineNum) : word(w), count(1), left(nullptr), right(nullptr) {
    lineNumbers.push_back(lineNum);
}
