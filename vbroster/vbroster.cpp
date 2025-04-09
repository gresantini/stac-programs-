//
// Created by gresa on 4/4/2025.
//
#include "vbroster.h"

void VolleyballTeam::addPlayer(const string& first_name, const string& last_name, const string& position, int height_cm, const string& hometown) {
    team[last_name] = {first_name, last_name, position, height_cm, hometown};
}

Player VolleyballTeam::queryPlayer(const string& last_name) {
    if (team.find(last_name) != team.end()) {
        return team[last_name];
    }
    return {"Not Found", "", "", 0, ""};
}

vector<Player> VolleyballTeam::listByPosition(const string& position) {
    vector<Player> result;
    for (const auto& entry : team) {
        if (entry.second.position == position) {
            result.push_back(entry.second);
        }
    }
    return result;
}

double VolleyballTeam::averageHeight() {
    if (team.empty()) return 0.0;
    int totalHeight = 0;
    for (const auto& entry : team) {
        totalHeight += entry.second.height_cm;
    }
    return static_cast<double>(totalHeight) / team.size();
}

void VolleyballTeam::listAllByPosition() {
    unordered_map<string, vector<Player>> positionMap;
    for (const auto& entry : team) {
        positionMap[entry.second.position].push_back(entry.second);
    }

    for (const auto& pos : positionMap) {
        cout << "\nPosition: " << pos.first << "\n";
        for (const auto& player : pos.second) {
            cout << player.first_name << " " << player.last_name << " (" << player.height_cm << " cm, " << player.hometown << ")\n";
        }
    }
}

void VolleyballTeam::interactiveQuery() {
    string last_name;
    cout << "\nEnter the last name of the player to search: ";
    cin >> last_name;
    Player p = queryPlayer(last_name);
    if (p.first_name == "Not Found") {
        cout << "Player not found.\n";
    } else {
        cout << "Player: " << p.first_name << " " << p.last_name << ", Position: " << p.position
             << ", Height: " << p.height_cm << " cm, Hometown: " << p.hometown << "\n";
    }
}