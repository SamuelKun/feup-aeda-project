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

int chooseFile(){
    ifstream teamFile;
    string filename;

    cout << "Write the filename you wish to read: " << endl;
    cout << "Press [0] to go back to the previous screen" << endl;
    cin.clear();
    cin >> filename;

    teamFile.open(filename);
    while (teamFile.fail())
    {
        cin.clear();
        cout << "Incorrect filename, please enter again: " << endl;
        cin >> filename;
        teamFile.open(filename);

        if(filename == "0") return 1;
    }
    national_team = new Team(filename);
    while(!mainMenu());
    return 1;
}

int main() {


    char menu;

    cout << "========================================= " << endl;
    cout << "          National Football Team          " << endl;
    cout << "========================================= \n" << endl;
    cout << "Choose and option:" << endl;
    cout << "1. Select the Team File to read " << endl;
    cout << "2. Create a new Team File " << endl;
    cout << "3. Exit Program " << endl;

    cin.clear();
    cin >> menu;


    switch(menu){
        case '1': //Select the Team File to read
        while(!chooseFile());
        break;
        case '2': //Create a new Team File
        return 0;
            break;
        case '3': //Exits program
            return 1;
        default:  //
            cin.ignore(1000,'\n');
            return 0;
            break;
    }

    return 0;
}

