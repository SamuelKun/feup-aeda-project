#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Menus.h"
#include "Team.h"


using namespace std;
extern Team *national_team;

void wait_2(){
    string waiting;
    cout << "Press any key to continue: " << endl;
    getline(cin,waiting);
}

int menu_searchPlayers()
{
    char menu;

    cout << "========================================= " << endl;
    cout << "           Search Player Menu             " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Search by Name " << endl;
    cout << "2. Search by Position " << endl;
    cout << "0. Return to Player Menu " << endl;

    cin.clear();
    cin >> menu;

    switch(menu) {
        case '1':
            try {
                string name;
                cin.ignore(1000, '\n');
                getline(cin, name);
                if (name == "0") return 0;
                national_team->findPlayer(name)->info();
            }
            catch (PersonNotFound &er) {
                cout << "Player " << er.getName() << " not found" << endl;
            }
            return 0;
        case '2':
            //João, mete aqui a procura de Players por posição
            return 0;
        case '0':
            return 1;
        default:
            return 0;
    }
}

int menu_players()
{
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)
    cout << "========================================= " << endl;
    cout << "               Player Menu                " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. View all Players " << endl;
    cout << "2. Search Players " << endl;
    cout << "3. Add Player " << endl;
    cout << "0. Return to Main Menu " << endl;

    cin.clear();
    cin >> menu;

    switch(menu)
    {
        case '1':    //View player info
            cout << setw(19) << "Name" << " | " << setw(10) << "Date" <<" | ";
            cout << setw(12) << "Position" << " | " << setw(10) << "Position" << " | " << setw(6) << "Weight" << " | " << setw(8) << "Height" << " | " << setw(7) << "Value" << " | " << setw(9) <<  "Earnings" << " |" << endl;
            for(int i = 0; i < (national_team->getPlayers()).size(); i++){
                (national_team->getPlayers())[i]->info();
            }
            cout << "Press any key to go back to Player Menu: " << endl;
            cout << "Sort by:" << endl;
            cout << "Position" << endl;
            cout << "Name" << endl;
            cin >> menu;
            cin.ignore(1000,'\n');
            return 0;//remove this line after inserting stuff
        case '2':    //Exit function
            while(!menu_searchPlayers());
            return 0;
        case '3':
            return national_team->addPlayer();
        case '0':
            return 1;
        default:     //Invalid input
            cin.ignore(1000,'\n');
            return 0;
    }
}
int menu_searchStaffMembers(){
    char menu;

    cout << "========================================= " << endl;
    cout << "           Search Staff Menu              " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Search by Name " << endl;
    cout << "2. Search by Staff Function " << endl;
    cout << "0. Return to Main Menu " << endl;

    cin.clear();
    cin >> menu;

    switch(menu){
        case '1':
            cout << "Write the name of the Staff you want to search: " << endl;
            cout << "0. Return to Staff Menu" << endl;
            try {
                string name;
                cin.ignore(1000, '\n');
                getline(cin, name);
                if(name == "0") return 0;
                national_team->findStaff(name)->info();
            }
            catch(PersonNotFound & er) {
                cout << "Staff member " << er.getName() << " not found" << endl;
            }
            return 0;
        case '2':
            //João, mete aqui a procura de staff members por função
            return 0;
        case '0':
            return 1;
        default:
            return 0;
    }
}
int menu_staff() {
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "               Staff Menu                 " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. View all Staff Members " << endl;
    cout << "2. Search Staff Members " << endl;
    cout << "3. Add Staff Members " << endl;
    cout << "0. Return to Main Menu " << endl;

    cin.clear();
    cin >> menu;

    switch(menu)
    {
        case '1':    //View player info
            for(int i = 0; i < (national_team->getStaff()).size(); i++){
                (national_team->getStaff())[i]->info();
                cout << endl;
            }
            cout << "0. Return to Main Menu " << endl;
            cin >> menu;
            return 0;
        case '2':
            while(!menu_searchStaffMembers());
            return 0;
        case '3':
            return national_team->addStaff();
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
            cin.ignore(1000,'\n');
            return 0;
    }
    return 1;
}

int menu_tournaments()
{
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "            Competitions Menu             " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Show all competitions " << endl;
    cout << "2. Pay competitions fees" << endl;
    cout << "0. Return to Main Menu " << endl;

    cin.clear();
    cin >> menu;

    switch(menu)
    {
        case '1':    //View player info
            for(int i = 0; i < (national_team->getCompetition()).size(); i++){
                cout << (*(national_team->getCompetition()[i]));
            }
            return 0;//remove this line after inserting stuff
        case '2':
            cout << "National Football Team Competitions - VERIFICAR ERRO DEPOIS" << endl;
            for(int i = 0; i < (national_team->getCompetition()).size(); i++){
                cout << i << ". " << national_team->getCompetition()[i]->getCompetitionName() << " - Paid: " << national_team->getCompetition()[i]->getPaid() << endl;
            }
            int index;
            cin >> index; // VERIFICAR ERRO DEPOIS
            try {
                national_team->getCompetition()[index]->payPlayers();
                cout << "Competition successfully paid!" << endl;
            }
            catch(AlreadyPaid &er) {
                cout << "The " << er.getName() << " has already been paid to players." << endl;
            }
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
            cin.ignore(1000,'\n');
            return 0;
    }
}

int menu_games(){
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "             Games Menu                   " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Show all games " << endl;
    cout << "2. Search a Game" << endl;
    cout << "0. Return to Main Menu " << endl;

    cin.clear();
    cin >> menu;

    switch(menu) {
        case '1':
            for(auto it = national_team->getGame().begin();it != national_team->getGame().end(); it++){
                (*it)->info();
                cout << endl;
            }
            wait_2();
            return 0;
        case '2':
            try {
                cout << "Write the name of the Game's country: " << endl;
                string country,city,stadium;
                cin.ignore(1000, '\n');
                getline(cin, country);

                cout << "Write the name of the Game's city: " << endl;
                getline(cin, city);

                cout << "Write the name of the Game's stadium: " << endl;
                getline(cin, stadium);

                national_team->findGame(country,city,stadium)->info();
            }
            catch(GameNotFound & er) {
                cout << endl;
                cout << "Game:" << endl;
                cout << "Country: " << er.getCountry() << endl;
                cout << "City: " << er.getCity() << endl;
                cout << "Stadium: " << er.getStadium() << endl;
                cout << "This Game wasn't found" << endl;
            }
            wait_2();
            return 0;
        case '3':
            return 1;
        default:     //Invalid input
            cin.ignore(1000, '\n');
            return 0;
    }

}

int menu_info()
{
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "            Team Information             " << endl;
    cout << "========================================= \n" << endl;

    cout << "Team Name: " << national_team->getTeamName() << endl;
    cout << "Number of Players: " << national_team->getPlayers().size() << endl;
    cout << "Number of Competitions: " << national_team->getCompetition().size() << endl;
    cout << "Competitions not paid: " << national_team->missingPay() << endl;
    cout << "Money spent with players in competitions: " << national_team->getMoneyPlayers() << endl;
    cout << "Money spent with staff per month: " << national_team->getMoneyStaff() << endl;
    cout << "0. Return to Main Menu " << endl;

    cin.clear();
    cin >> menu;


    return 1;

}

int menu_credits() {
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "This app was created by :" << endl << endl;
    cout << "Diogo Samuel Fernandes" << endl;
    cout << "Hugo Guimaraes" << endl;
    cout << "Joao Pires" << endl << endl;

    cout << "Press [1] to go back to the main menu" << endl;
    cin.clear();
    cin >> menu;
    if (menu == '1') {cin.ignore(1000,'\n'); return 1;}
    else {
        cin.ignore(1000,'\n');
        return 0;
    }

}

int mainMenu() {
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "          National Football Team          " << endl;
    cout << "                Main Menu                 " << endl;
    cout << "========================================= \n" << endl;
    cout << "1. Player Menu" << endl;
    cout << "2. Staff Menu" << endl;
    cout << "3. Competitions Menu" << endl;
    cout << "4. Games Menu" << endl;
    cout << "5. View Team Stats" << endl;
    cout << "6. App Info" << endl;
    cout << "0. Exit" << endl;

    cin.clear();
    cin >> menu;

    switch(menu)
    {
        case '1':    //View player info
            while(!menu_players());
            break;
        case '2':    //View staff info
            while(!menu_staff());
            break;
        case '3':    //View app info
            while(!menu_tournaments());
            break;
        case '4':    //View app info
            while(!menu_games());
            break;
        case '5':    //View app info
            while(!menu_info());
            break;
        case '6':    //View app info
            while(!menu_credits());
            break;
        case '0':    //Exit function
            exit(0);
        default:     //Invalid input
            cin.ignore(1000,'\n');
            return 0;
    }
}

int fileMenu(){
    ifstream teamFile;
    string filename;

    cout << "Write the filename you wish to read: " << endl;
    cout << "0. Go back to the previous menu" << endl;
    cin.clear();
    cin >> filename;
    teamFile.open(filename);

    if(filename == "0") return 1;

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

int initMenu(){
    char menu;
    cout << "========================================= " << endl;
    cout << "          National Football Team          " << endl;
    cout << "========================================= \n" << endl;
    cout << "Choose and option:" << endl;
    cout << "1. Select the Team File to read " << endl;
    cout << "2. Create a new Team File " << endl;
    cout << "0. Exit Program" << endl;

    cin.clear();
    cin >> menu;

    switch(menu){
        case '1': //Select the Team File to read
            while(!fileMenu());
            break;
        case '2': //Create a new Team File
            return 0;
            break;
        case '0': //Exits program
            return 1;
        default:  //
            cin.ignore(1000,'\n');
            return 0;
    }
}

