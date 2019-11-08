#include <iostream>

//
#include "string"
#include "Menus.h"
#include "Person.h"
#include "Player.h"
#include "Team.h"
#include <fstream>
//

using namespace std;

Team *national_team;

int main() {
    cout << "========================================= " << endl;
    cout << "          National Football Team          " << endl;
    cout << "========================================= \n" << endl;
    cout << "Choose and option:" << endl;
    cout << "1. Select the Team File to read " << endl;
    cout << "2. Create a new Team File " << endl;
    ifstream teamFile;
    string filename;

    cin >> filename;

    teamFile.open(filename);
    while (teamFile.fail())
    {
        cin.clear();
        cout << "Incorrect filename, please enter again: " << endl;
        cin >> filename;
        teamFile.open(filename);
    }

    national_team = new Team(filename);

    while(!mainMenu());
    return 0;
}
