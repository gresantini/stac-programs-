//
// Created by gresa on 4/4/2025.
//

#ifndef VBROSTER_H
#define VBROSTER_H

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Player {
    string first_name;
    string last_name;
    string position;
    int height_cm;
    string hometown;
};

class VolleyballTeam {
private:
    unordered_map<string, Player> team;
public:
    void addPlayer(const string& first_name, const string& last_name, const string& position, int height_cm, const string& hometown);
    Player queryPlayer(const string& last_name);
    vector<Player> listByPosition(const string& position);
    double averageHeight();
    void listAllByPosition();
    void interactiveQuery();
};

#endif //VBROSTER_H
