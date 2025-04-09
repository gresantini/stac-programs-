//
// Created by Greta Santini on 1/29/2025.
//

#ifndef STRANGESTORY_H
#define STRANGESTORY_H
#include <string>
#include <vector>
using namespace std;

class StrangeStory {

public:
    StrangeStory(string filename, vector<string> nouns, vector<string> verbs);
    void createStrange();

private:
    string m_filename;
    vector<string> m_nouns;
    vector<string> m_verbs;



};



#endif //STRANGESTORY_H
