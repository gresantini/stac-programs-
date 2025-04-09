#include <iostream>
#include "vbroster.h"

int main() {
    VolleyballTeam team;

    // Adding players
    team.addPlayer("Kaylin", "Hamilton", "DS", 160, "Bardonia, NY");
    team.addPlayer("Lea", "Venghaus", "S", 173, "Muenster, Germany");
    team.addPlayer("Addison", "Miller", "L/DS", 160, "Allentown, PA");
    team.addPlayer("Alexyss", "Chartier", "OH/RS", 173, "Blackstone, MA");
    team.addPlayer("Dahiana", "Garcia Atuesta", "DS/L", 170, "Pereira, Colombia");
    team.addPlayer("Evie", "Paalman", "OH", 175, "Laren Gelderland, Netherlands");
    team.addPlayer("Anna", "Gazzerro", "S", 175, "Padova, Italy");
    team.addPlayer("Yulis", "Vidal", "MH", 173, "Garnerville, NY");
    team.addPlayer("Christianna", "Roberts", "MH", 185, "Hesperia, CA");
    team.addPlayer("Alana", "Rider", "OH", 173, "Hyde Park, NY");
    team.addPlayer("Isis", "Barrett", "MH", 180, "Nyack, NY");
    team.addPlayer("Kamila Zoe", "Rosa", "RS", 175, "San Lorenzo, Puerto Rico");
    team.addPlayer("Chloe", "Weiting", "OH/RS", 178, "Bakersfield, CA");
    team.addPlayer("Natassia", "Romanoff", "OH/RS", 178, "Haverstraw, NY");
    team.addPlayer("Greta", "Santini", "OH", 185, "Reggio Emilia, Italy");
    team.addPlayer("Elizabeth", "Salmon", "MH/RS", 178, "San Marcos, TX");
    team.addPlayer("Lauren", "Fields", "MH", 183, "Tampa, FL");
    team.addPlayer("India", "Newman", "OH", 170, "White Plains, NY");

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Query player by last name\n";
        cout << "2. List all players by position\n";
        cout << "3. Get average team height\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                team.interactiveQuery();
                break;
            case 2:
                team.listAllByPosition();
                break;
            case 3:
                cout << "\nAverage Team Height: " << team.averageHeight() << " cm\n";
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
