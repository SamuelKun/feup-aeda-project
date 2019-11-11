#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

#include "Menus.h"
#include "input_utils.h"

using namespace std;
extern Team *national_team;
extern Competition* current_competition;

int menu_allPlayers() {
    string toSort;
    national_team->showPlayersTable();
    cout << "To sort write \"sort [ Name | Position | Value ]\" " << endl;
    cout << "Write something else to go back!" << endl;
    getline(cin, toSort);
    if(toSort == "sort Name" || toSort == "sort name"){
        national_team->sortPlayersName();
        return 0;
    }
    if(toSort == "sort Position" || toSort == "sort position"){
        national_team->sortPlayersPosition();
        return 0;
    }
    if(toSort == "sort Value" || toSort == "sort value") {
        national_team->sortPlayersValue();
        return 0;
    }
    return 1;
}

int menu_searchPlayers() {
    char menu;

    cout << "========================================= " << endl;
    cout << "           Search Player Menu             " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Search by Name " << endl;
    cout << "2. Search by Position " << endl;
    cout << "0. Return to Player Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu) {
        case '1':
            try {
                cout << "Write the name of the player you wish to find: " << endl;
                string name;
                getline(cin, name);
                if (name == "0") return 0;
                vector<Player *> to_print = national_team->findPlayerName(name);
                for (size_t i = 0; i < to_print.size(); i++) {
                    to_print[i]->info();
                    cout << endl;
                }
            }
            catch (PersonNotFound &er) {
                cout << "Player " << er.getName() << " not found" << endl;
            }
            waitInput();
            return 0;
        case '2':
            try {
                cout << "Write the position of the Player(s) you wish to find: " << endl;
                string position;
                getline(cin, position);
                if (position == "0") return 0;
                cout << endl;
                vector<Player *> to_print = national_team->findPlayerPos(position);
                for (size_t i = 0; i < to_print.size(); i++) {
                    to_print[i]->info();
                    cout << endl;
                }
            }
            catch (PositionNotFound &er) {
                cout << "Players for position " << er.getPosition() << " not found" << endl;
            }
            waitInput();
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

    cout << "1. View all players" << endl;
    cout << "2. Search Players " << endl;
    cout << "3. Add Player " << endl;
    cout << "4. Remove Player " << endl;
    cout << "0. Return to Main Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu)
    {
        case '1':    //View player info - Table
            while(!menu_allPlayers());
            return 0;//remove this line after inserting stuff
        case '2':    //Exit function
            while(!menu_searchPlayers());
            return 0;
        case '3':
            try{
                string n, c, pos;
                int wei,hei,val,earn;
                Date d;
                string checker;

                cout << "Write the name of the Player you wish to add: " << endl;
                getline(cin,n);

                cout << "Write " << n << "'s birthday " << endl;
                cin >> d;

                cout << "Write " << n << "'s club " << endl;
                cin >> c;

                cout << "Write " << n << "'s position " << endl;
                cin >> pos; checkPosition(pos);

                cout << "Write " << n << "'s weight " << endl;
                cin >> wei;
                failInput(wei);
                cout << "Write " << n << "'s height " << endl;
                cin >> hei;
                failInput(hei);
                cout << "Write " << n << "'s value " << endl;
                cin >> val;
                failInput(val);
                cout << "Write " << n << "'s earnings " << endl;
                cin >> earn;
                failInput(earn);

                Player *play = new Player(n,d,c,pos,wei,hei,val,earn);

                cout << "Do you wish to add " << n << " as a Player?" << endl;
                cout << "1. Add Player " << endl;
                cout << "Any other key. Cancel adding Player " << endl;
                cin.ignore(1000,'\n');
                getline(cin,checker);
                if (checker != "1"){
                    cout << "Player was not added!" << endl;
                }
                else{
                    national_team->addPlayer(play);
                    cout << "Player successfully added!!" << endl;
                }
            }
            catch(PlayerAlreadyExists &er){
                cout << "Player " << er.getName() << " already exists!!" << endl;
            }
            catch(CantUseThatName &er){
                cout << "Can't use " << er.getName() << " has a name!!" << endl;
            }
            waitInput();
            return 0;
        case '4':
            try {
                cout << "Write the name of the player you wish to remove: " << endl;
                string name;
                getline(cin,name);

                vector<Player *> to_print = national_team->findPlayerName(name);
                for (size_t i = 0; i < to_print.size(); i++) {
                    to_print[i]->info();
                    cout << endl;
                }
                if(to_print.size() > 1){ throw TooManyPeopleFound(name);}
                else{
                    string checker;
                    cout << "Do you wish to remove " << to_print[0]->getName() << endl;
                    cout << "1. Remove Player " << endl;
                    cout << "Any other key. Cancel removing Player " << endl;
                    getline(cin,checker);
                    if (checker != "1"){
                        cout << "Player was not removed!!" << endl;
                    }
                    else{
                        national_team->removePlayer(to_print[0]);
                        cout << "Player successfully removed" << endl;
                    }
                }
            }
            catch (PersonNotFound &er) {
                cout << "Player " << er.getName() << " not found" << endl;
            }
            catch (TooManyPeopleFound &er){
                cout << "Can't remove: " << endl;
                cout << "More than 1 Player named " << er.getName() << " was found!!" << endl;
            }
            waitInput();
            return 0;
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
    cout << "0. Return to Staff Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu){
        case '1':
            cout << "Write the name of the Staff you want to search: " << endl;
            cout << "0. Return to Staff Menu" << endl << endl;

            try {
                string name;
                cin.ignore(1000, '\n');
                getline(cin, name);
                if(name == "0") return 0;
                vector<Staff *> to_print = national_team->findStaffName(name);
                for (size_t i = 0; i < to_print.size(); i++) {
                    to_print[i]->info();
                    cout << endl;
                }
            }
            catch(PersonNotFound & er) {
                cout << "Staff member " << er.getName() << " not found" << endl;
            }
            waitInput();
            return 0;
        case '2':
            cout << "Write the function of the Staff you want to search: " << endl;
            cout << "0. Return to Staff Menu" << endl;
            try {
                string function;
                cin.ignore(1000, '\n');
                getline(cin, function);
                if(function == "0") return 0;
                vector<Staff *> to_print = national_team->findStaffFunction(function);
                for (size_t i = 0; i < to_print.size(); i++) {
                    to_print[i]->info();
                    cout << endl;
                }
            }
            catch(FunctionNotFound & er) {
                cout << "No Staff members for function " << er.getFunction() << endl;
            }
            waitInput();
            return 0;
        case '0':
            return 1;
        default:
            cin.ignore(1000,'\n');
            return 0;
    }
}

int menu_allStaff() {
    string toSort;
    national_team->showStaffTable();
    cout << "To sort write \"sort [ Name | Function ]\" " << endl;
    cout << "Write something else to go back!" << endl;
    getline(cin, toSort);
    if(toSort == "sort Name" || toSort == "sort name"){
        national_team->sortStaffName();
        return 0;
    }
    if(toSort == "sort Function" || toSort == "sort function") {
        national_team->sortStaffFunction();
        return 0;
    }
    return 1;
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
    cout << "4. Remove Staff Members " << endl;
    cout << "0. Return to Main Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu)
    {
        case '1':    //View player info
            while(!menu_allStaff());
            return 0;
        case '2':
            while(!menu_searchStaffMembers());
            return 0;
        case '3':
            try {
                string n, f, checker;
                double w;
                Date d;

                cout << "Write the name of the Staff Member you wish to add: " << endl;
                getline(cin, n);
                cout << "Write " << n << "'s birthday " << endl;
                cin >> d;
                cout << "Write " << n << "'s wage " << endl;
                cin >> w;
                failInput(w);
                cout << "Write " << n << "'s function " << endl;
                cin >> f;
                failInput(f);

                Staff *s = new Staff(n, d, w, f);

                cout << "Do you wish to add the Staff Member you have created?: " << endl;
                cout << "1. Add Staff Member " << endl;
                cout << "Any other key. Cancel adding Staff Member " << endl;
                cin.ignore(1000,'\n');
                getline(cin,checker);
                if (checker != "1"){
                    cout << "Staff Member was not added!!" << endl;
                }
                else{
                    national_team->addStaff(s);
                    cout << n << " was successfully added as a Staff member!!" << endl;
                }
            }
            catch(StaffMemberAlreadyExists &er){
                cout << "The Staff Member " << er.getName() << " already exists!!" << endl;
            }
            catch(CantUseThatName &er){
                cout << "Can't use " << er.getName() << " has a name!!" << endl;
            }
            waitInput();
            return 0;
        case '4':
            try{
                string name;
                vector <Staff *> v_staff;

                cout << "Write the name of the Staff member you wish to remove: " << endl;
                getline(cin,name);
                v_staff = national_team->findStaffName(name);

                for (size_t i = 0; i < v_staff.size(); i++) {
                    v_staff[i]->info();
                    cout << endl;
                }
                if(v_staff.size() > 1){ throw TooManyStaffFound(name);}

                else{
                    string checker;
                    cout << "Do you wish to remove " << v_staff[0]->getName() << "?" << endl;
                    cout << "1. Remove Staff Member " << endl;
                    cout << "Any other key. Cancel removing Staff Member " << endl;
                    getline(cin,checker);
                    if (checker != "1"){
                        cout << "Staff Member was not removed!!" << endl;
                    }
                    else{
                        national_team->removeStaff(v_staff[0]);
                        cout << "Staff Member successfully removed" << endl;
                    }
                }
            }
            catch (StaffMemberNotFound &er) {
                cout << "Staff Member " << er.getName() << " not found" << endl;
            }
            catch (TooManyStaffFound &er){
                cout << "Can't remove: " << endl;
                cout << "More than 1 Staff Member named " << er.getName() << " was found!!" << endl;
            }
            waitInput();
            return 0;
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
            cin.ignore(1000,'\n');
            return 0;
    }
    return 1;
}

int menu_games(){
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "             Games Menu                   " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Show all games " << endl;
    cout << "2. Search a Game" << endl;
    cout << "0. Return to Main Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');


    vector<Game *> print_it = national_team->getGames();
    switch(menu) {
        case '1':
            for(size_t i = 0; i < print_it.size(); i++){
                print_it[i]->info();
                cout << endl;
            }
            waitInput();
            return 0;
        case '2':
            try {
                cout << "Write the name of the Game's country: " << endl;
                string country,city,stadium;
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
            waitInput();
            return 0;
        case '0':
            return 1;
        default:     //Invalid input
            cin.ignore(1000, '\n');
            return 0;
    }

}
int menu_tournament_games(Competition * comp){
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "             Games Menu                   " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Show all games " << endl;
    cout << "2. Search a Game" << endl;
    cout << "3. Add a Game" << endl;
    cout << "0. Return to Main Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');


    vector<Game *> v_games = comp->getGames();
    switch(menu) {
        case '1':
            comp->showGames();
            waitInput();
            return 0;
        case '2':
            try {
                string country,city,stadium,opponent;
                Date d;
                cout << "Write the Game's opponent " << endl;
                getline(cin,opponent);
                cout << "Write the Game's country " << endl;
                getline(cin,country);
                cout << "Write the Game's city " << endl;
                getline(cin,city);
                cout << "Write the Game's stadium " << endl;
                getline(cin,stadium);
                cout << "Write the Game's date " << endl;
                cin >> d;

                comp->findGame(opponent,country,city,stadium,d)->info();
            }
            catch(GameNotFound & er) {
                cout << endl;
                cout << "Game:" << endl;
                cout << "Opponent: " << er.getOpponent() << endl;
                cout << "Country: " << er.getCountry() << endl;
                cout << "City: " << er.getCity() << endl;
                cout << "Stadium: " << er.getStadium() << endl;
                cout << "Date: " << er.getDate() << endl;
                cout << "This Game wasn't found" << endl;
            }
            waitInput();
            return 0;
        case '3':
            try{
                string country,city,stadium,opponent;
                Date d;
                cout << "Write the Game's opponent " << endl;
                getline(cin,opponent);
                cout << "Write the Game's country " << endl;
                getline(cin,country);
                cout << "Write the Game's city " << endl;
                getline(cin,city);
                cout << "Write the Game's stadium " << endl;
                getline(cin,stadium);
                cout << "Write the Game's date " << endl;
                cin >> d;

                Game *g = new Game(opponent,country,city,stadium,d);
                comp->addGame(g);
            }
            catch(GameAlreadyExists &er){
                cout << endl;
                cout << "Game:" << endl;
                cout << "Opponent: " << er.getOpponent() << endl;
                cout << "Country: " << er.getCountry() << endl;
                cout << "City: " << er.getCity() << endl;
                cout << "Stadium: " << er.getStadium() << endl;
                cout << "Date: " << er.getDate() << endl;
                cout << "This Game already exists!!" << endl;
            }
            return 0;
        case '0':
            return 1;
        default:     //Invalid input
            cin.ignore(1000, '\n');
            return 0;
    }

}
int menu_singleCompetition(Competition* comp){
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "National Football Team Competitions - VERIFICAR ERRO DEPOIS" << endl;
    for(int i = 0; i < (national_team->getCompetition()).size(); i++){
        cout << i << ". " << national_team->getCompetition()[i]->getCompetitionName() << " - Paid: " << national_team->getCompetition()[i]->getPaid() << endl;
    }
    int index;
    cin >> index; // VERIFICAR ERRO DEPOIS

    Competition * singleCompetition = national_team->getCompetition()[index];

    cout << "========================================= " << endl;
    cout << "            Competitions Menu             " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. View all games from this competition" << endl;
    cout << "2. View called Players" << endl;
    cout << "3. Games Menu" << endl;
    cout << "4. Add Game Statistics - To be done " << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu){
        case '1':
            for(size_t i = 0; i < singleCompetition->getGames().size(); i++)
                comp->getGames()[i]->info();
            return 0;
        case '2':
            for(size_t i = 0; i < singleCompetition->getCalled().size(); i++)
                comp->getCalled()[i]->infoTable();
            return 0;
        case '3':
            while(!menu_tournament_games(comp));
            return 0;
        case '4':
            return 0;
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
            cin.ignore(1000,'\n');
            return 0;
    }
}

int menu_tournaments()
{
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "            Competitions Menu             " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Show all competitions" << endl;
    cout << "2. Pay competitions fees" << endl;
    cout << "3. Detailed information about one competition" << endl;
    cout << "4. Create a Single Game / Competition - To be done " << endl;
    cout << "0. Return to Main Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu)
    {
        case '1':    //View player info
            for(int i = 0; i < (national_team->getCompetition()).size(); i++){
                cout << (*(national_team->getCompetition()[i]));
            }
            waitInput();
            return 0;
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
            waitInput();
            return 0;
        case '3':
            try{
                string name;
                Competition* comp;
                cout << "Choose the name of the Competition you wish to view: " << endl;
                getline(cin,name);
                comp = national_team->findCompetition(name);
                while(!menu_singleCompetition(comp));
            }
            catch(CompetitionNotFound &er){
                cout << "No competition named " << er.getName() << endl;
            }
            waitInput();
            return 0;
        case '4':
            return 0;
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
            cin.ignore(1000,'\n');
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
    cout << "Money spent with accommodation: " << national_team->getMoneyAccommodation() << endl;
    cout << "Money spent with players in competitions: " << national_team->getMoneyPlayers() << endl;
    cout << "Money spent with staff per month: " << national_team->getMoneyStaff() << endl;
    cout << "0. Return to Main Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

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
    cout << "0. Exit" << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu)
    {
        case '1':    //View player info
            while(!menu_players());
            return 0;
        case '2':    //View staff info
            while(!menu_staff());
            return 0;
        case '3':    //View app info
            while(!menu_tournaments());
            return 0;
        case '4':    //View app info
            while(!menu_games());
            return 0;
        case '5':    //View app info
            while(!menu_info());
            return 0;
        case '6':    //View app info
            while(!menu_credits());
            return 0;
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
    cin.ignore(1000,'\n');
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
    cout << "0. Exit Program" << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

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

