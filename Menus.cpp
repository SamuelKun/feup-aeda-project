#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>

#include "Menus.h"
#include "Team.h"
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
    unsigned int index;
    vector<Player*> v_players;

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
            national_team->showPlayersTable();

            cout << "Write the index of the player you wish to remove " << endl;
            cout << "Press any char that is not a number to stop adding " << endl;
            cout << "Example: Press [a] to exit" << endl;

            while(cin >> index && !cin.eof()){
                v_players = national_team->getPlayers();
                if (index >= v_players.size()) {
                    cout << "Index too high!!" << endl;
                    continue;
                }
                else {
                    string name = v_players[index]->getName();
                    national_team->removePlayer(v_players[index]);
                    national_team->showPlayersTable();
                    cout << name << " was successfully removed!!" << endl;
                    cout << "Example: Press [a] to exit" << endl;
                }
            }
            cout << "Stopped removing Players!!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            waitInput();
            return 0;
        case '0':
            return 1;
        default:     //Invalid input
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
    unsigned int index;
    vector<Staff*> v_staff;

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
            national_team->showStaffTable();

            cout << "Write the index of the Staff Member you wish to remove " << endl;
            cout << "Press any char that is not a number to stop adding " << endl;
            cout << "Example: Press [a] to exit" << endl;

            while(cin >> index && !cin.eof()){
                v_staff = national_team->getStaff();
                if (index >= v_staff.size()) {
                    cout << "Index too high!!" << endl;
                    continue;
                }
                else {
                    string name = v_staff[index]->getName();
                    national_team->removeStaff(v_staff[index]);
                    national_team->showStaffTable();
                    cout << name << " was successfully removed!!" << endl;
                    cout << "Example: Press [a] to exit" << endl;
                }
            }
            cout << "Stopped removing Staff Members!!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            waitInput();
            return 0;
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
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
                string opponent;
                Date d;
                getline(cin, opponent);
                cout << "Write the Date of Game: " << endl;
                cin >> d;

                vector<Game *> all_games = national_team->getGames();
                for(size_t i = 0; i < all_games.size(); i++) {
                    if(all_games[i]->getOpponent() == opponent && all_games[i]->getDate().isEqualTo(d)){
                        all_games[i]->info();
                        waitInput();
                        return 0;
                    }
                }
                throw(GameNotFound(opponent, d));

            }
            catch(GameNotFound & er) {
                cout << endl;
                cout << "Game:" << endl;
                cout << "Opponent: " << er.getOpponent() << endl;
                cout << "Date: " << er.getDate() << endl;
                cout << "This Game wasn't found" << endl;
            }

            waitInput();
            return 0;
        case '0':
            return 1;
        default:     //Invalid input
            return 0;
    }
}
int menu_tournament_games(Competition * comp){
    char menu;
    unsigned int index;
    vector<Game *> games;

    cout << "========================================= " << endl;
    cout << "             Games Menu                   " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Show all games from this competition" << endl;
    cout << "2. Search a Game" << endl;
    cout << "3. Add a Game" << endl;
    cout << "4. Remove a Game " << endl;
    cout << "5. Add Game Statistics" << endl;
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
                cout << "Write the name of the Game's Opponent: " << endl;
                string opponent;
                Date d;
                getline(cin, opponent);

                cout << "Write the Date of Game: " << endl;
                cin >> d;
                comp->findGame(opponent, d)->info();
            }
            catch(GameNotFound &er) {
                cout << endl;
                cout << "Game:" << endl;
                cout << "Opponent: " << er.getOpponent() << endl;
                cout << "Date: " << er.getDate() << endl;
                cout << "This Game wasn't found" << endl;
            }
            waitInput();
            return 0;
        case '3':
            try{
                string country,city,stadium,opponent,checker;
                Date d;
                Statistics stats;

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
                Game *game = new Game(opponent,country,city,stadium, d, comp->getCalled(), stats);
                game->info();

                cout << "Do you wish to add this game? " << endl;
                cout << "1. Add Game " << endl;
                cout << "Any other key. Cancel adding Game " << endl;
                getline(cin,checker);
                if (checker != "1"){
                    cout << "Game was not added!" << endl;
                }
                else{

                    comp->addGame(game);
                    cout << "Game successfully added!!" << endl;
                }
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
            waitInput();
            return 0;
        case '4':
            //É preciso meter os jogos numa tabela com Oponentes , Date e indexs
            //comp->showGamesTable();

            cout << "Write the index of the player you wish to remove " << endl;
            cout << "Press any char that is not a number to stop adding " << endl;
            cout << "Example: Press [a] to exit" << endl;

            while(cin >> index && !cin.eof()){
                games = comp->getGames();
                if (index >= games.size()) {
                    cout << "Index too high!!" << endl;
                    continue;
                }
                else {
                    string opponent = games[index]->getOpponent();
                    comp->removeGame(games[index]);
                    //comp->showGamesTable();
                    cout << "Game vs " << opponent << " was successfully removed!!" << endl;
                    cout << "Example: Press [a] to exit" << endl;
                }
            }
            cout << "Stopped removing Games!!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            waitInput();
            return 0;
        case '5':
            try {
                for(size_t i = 0; i < comp->getGames().size(); i++){
                    cout <<" Index: " << i << "  ->" <<endl;
                    comp->getGames()[i]->info();
                }
                int idx;
                cout << "Index:" << endl;
                cin >> idx;

                while(idx >= comp->getGames().size() || idx < 0){
                    cout << "Index too high!!" << endl;
                    cout << "Index:" << endl;
                    cin >> idx;
                }

                string checker;
                int goalS, goalsC, shots, ballP, yellowC, redC, injured, freeKicks, cornerKicks;
                cout << "Number of goals scored: " << endl;
                cin >> goalS;
                failInput(goalS);
                cout << "Number of goals conceded: " <<  endl;
                cin >> goalsC;
                failInput(goalsC);
                cout << "Number of shots: " <<endl;
                cin >> shots;
                failInput(shots);
                cout << "Percentage of ball possession: "  << endl;
                cin >> ballP;
                failInput(ballP);
                cout << "Number of yellow cards: "  << endl;
                cin >> yellowC;
                failInput(yellowC);
                cout << "Number of red cards: "  << endl;
                cin >> redC;
                failInput(redC);
                cout << "Number of Injured players: " << endl;
                cin >> injured;
                failInput(injured);
                cout << "Number of free kicks: "  << endl;
                cin >> freeKicks;
                failInput(freeKicks);
                cout << "Number of corner kicks: " << endl;
                cin >> cornerKicks;
                failInput(cornerKicks);

                Statistics stats(goalS, goalsC, shots, ballP, yellowC, redC, injured, freeKicks, cornerKicks);

                cout << "Do you want to update the statistics of this game?" << endl;
                cout << "1. Update Statistics" << endl;
                cout << "Any other key. Cancel this action" << endl;
                cin.ignore(1000, '\n');
                getline(cin, checker);
                if (checker != "1") {
                    cout << "Statistics not updated!" << endl;
                } else {
                    comp->getGames()[idx]->setStats(stats);
                    cout << "Status updated!" << endl;
                }

            }
            catch(...) {
                cout << "Error occured";
            }
            return 0;
        case '0':
            return 1;
        default:     //Invalid input
            return 0;
    }

}
int menu_singleCompetition(Competition* comp){
    char menu;

    cout << "========================================= " << endl;
    cout << "            Competition Menu              " << endl;
    cout << "========================================= " << endl;
    cout << "This menu is about the Competition:" << endl;
    cout << comp->getCompetitionName() << endl << endl;

    cout << "1. Competition Games" << endl;
    cout << "2. View called Players" << endl;
    cout << "3. Money spent in this competition (Excluding Staff Members Salary)" << endl;
    cout << "0. Return to the previous Competition Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu){
        case '1':
            while(!menu_tournament_games(comp));
            return 0;
        case '2':
            cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
            cout << setw(12) << "Club" << " | " << setw(10) << "Position" << " | " << setw(6) << "Weight" << " | " << setw(8) << "Height" << " | " << setw(7) << "Value" << " | " << setw(9) <<  "Earnings" << " |" << endl;
            for(size_t i = 0; i < comp->getCalled().size(); i++)
                comp->getCalled()[i]->infoTable();
            waitInput();
            return 0;
        case '3':
            cout << "Accommodation:  " << comp->getMoneyAccommodation() << endl;
            cout << "Paid to players as Insurances: " << comp->getMoneyInsurance() << endl;
            cout << endl;
            waitInput();
            return 0;
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
            return 0;
    }
}

int menu_tournaments()
{
    char menu;
    string name;
    unsigned int number;
    vector<Competition*> comp = national_team->getCompetition();

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "            Competitions Menu             " << endl;
    cout << "========================================= \n" << endl;

    cout << "1. Show all competitions" << endl;
    cout << "2. Information about all games" << endl;
    cout << "3. Pay competitions fees" << endl;
    cout << "4. Detailed information about one competition" << endl;
    cout << "5. Create a new Competition " << endl;
    cout << "6. Remove a Competition " << endl;
    cout << "0. Return to Main Menu " << endl << endl;

    cin.clear();
    cin >> menu;
    cin.ignore(1000,'\n');

    switch(menu)
    {
        case '1':    //View player info
            for(int i = 0; i < (national_team->getCompetition()).size(); i++){
                cout << (*(national_team->getCompetition()[i])) << endl;
            }
            waitInput();
            return 0;
        case '2':
            while(!menu_games());
            return 0;
        case '3':
            cout << "National Football Team Competitions - VERIFICAR ERRO DEPOIS" << endl;
            for(int i = 0; i < (national_team->getCompetition()).size(); i++){
                cout << i << ". " << national_team->getCompetition()[i]->getCompetitionName() << " - Paid: " << national_team->getCompetition()[i]->getPaid() << endl;
            }
            int index;
            cin >> index;
            cin.ignore(1000,'\n');
            try {
                national_team->getCompetition()[index]->payPlayers();
                cout << "Competition successfully paid!" << endl;
            }
            catch(AlreadyPaid &er) {
                cout << "The " << er.getName() << " has already been paid to players." << endl;
            }
            waitInput();
            return 0;
        case '4':
            cout << "Write the number of the Competition you wish to view" << endl;
            cout << "Press any char that is not a number to go back" << endl;
            cout << "Example: Press [a] to exit" << endl;
            for(size_t i = 0; i < comp.size(); i++)
                cout << "Competition number " << i << ": " <<comp[i]->getCompetitionName() << endl;
            while(cin >> number && !cin.eof()){
                if( number >= comp.size()){
                    cout << "Index too high!!" << endl;
                }
                else{
                    while(!menu_singleCompetition(comp[number]));
                    return 0;
                }
            }
            return 0;
        case '5':
            try{
                string name, players, checker;
                Date start,end;
                vector<Player*> v_players;
                vector<Player*> team_players = national_team->getPlayers();
                vector<int> v_index;
                size_t n = team_players.size();

                cout << "Write the Competition's name: " << endl;
                getline(cin,name);
                cout << "Write " << name << "'s beginning date: " << endl;
                cin >> start;
                cout << "Write " << name << "'s ending date: " << endl;
                cin >> end; cout << endl;

                national_team->showPlayersTable(); cout << endl;

                cout << "Write the index of the player you wish to add" << endl;
                cout << "Press any char that is not a number to stop adding " << endl;
                cout << "Example: Press [a] to exit" << endl;
                while(cin >> index && !cin.eof()) {
                    if (index >= n) {
                        cout << "Index too high!!" << endl;
                        continue;
                    } else if (find(v_index.begin(), v_index.end(), index) != v_index.end()) {
                        cout << team_players[index]->getName() << " was already added!!" << endl;
                        continue;
                    } else {
                        v_players.push_back(team_players[index]);
                        v_index.push_back(index);
                        cout << team_players[index]->getName() << " was successfully added!!" << endl;
                    }
                }
                cin.clear();
                cin.ignore(1000,'\n');
                cout << "This Competition currently has no games." << endl;
                cout << "Use the menu system do add games if needed!" << endl;
                cout << "Are you sure you want to add this competition?" << endl;
                cout << "1. Add the competition: " << name << endl;
                cout << "0. Go back without adding the competition: " << name << endl;

                getline(cin,checker);
                if(checker == "0") return 0;
                else{
                    Competition * comp = new Competition(name, v_players, start, end, 0);
                    national_team->addCompetition(comp);
                }
            }
            catch(CompetitionAlreadyExists &er){
                cout << "Competition " << er.getName() << " already exists!!" << endl;
            }
            waitInput();
            return 0;
        case '6':
            //É preciso meter os jogos numa tabela com Oponentes , Date e indexs
            //comp->showGamesTable();
            for (size_t i = 0; i < comp.size(); i++){
                cout << "Competition number: " << i << " " << comp[i]->getCompetitionName() << endl;
            }
            cout << "Write the index of the Competition you wish to remove " << endl;
            cout << "Press any char that is not a number to stop adding " << endl;
            cout << "Example: Press [a] to exit" << endl;

            while(cin >> index && !cin.eof()){
                comp = national_team->getCompetition();
                if (index >= comp.size()) {
                    cout << "Index too high!!" << endl;
                    continue;
                }
                else {
                    name = comp[index]->getCompetitionName();
                    national_team->removeCompetition(comp[index]);
                    for (size_t i = 0; i < comp.size(); i++){
                        cout << "Competition number: " << i << " " << comp[i]->getCompetitionName(); << endl;
                    }
                    cout << name << " was successfully removed!!" << endl;
                    cout << "Example: Press [a] to exit" << endl;
                }
            }
            cout << "Stopped removing Competitions!!" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
            waitInput();
            return 0;
        case '0':    //Exit function
            return 1;
        default:     //Invalid input
            return 0;
    }
}

int menu_info()
{
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

    waitInput();
    return 1;
}

int menu_credits() {

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "This app was created by :" << endl << endl;
    cout << "Diogo Samuel Fernandes" << endl;
    cout << "Hugo Guimaraes" << endl;
    cout << "Joao Pires" << endl << endl;

    waitInput();
    return 1;
}

int mainMenu(string &file_name) {
    char menu;

    //cout << string(50, '\n');  //Clear Screen that works on linux(more portable)

    cout << "========================================= " << endl;
    cout << "          National Football Team          " << endl;
    cout << "                Main Menu                 " << endl;
    cout << "========================================= \n" << endl;
    cout << "1. Player Menu" << endl;
    cout << "2. Staff Menu" << endl;
    cout << "3. Competitions Menu" << endl;
    cout << "4. View Team Stats" << endl;
    cout << "5. Save Information" << endl;
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
            while(!menu_info());
            return 0;
        case '5':
            national_team->updateFile(file_name);
            cout << endl << "Information saved successfully in file: " << file_name << endl;
            waitInput();
            return 0;
        case '6':    //View app info
            while(!menu_credits());
            return 0;
        case '0':    //Exit function
            char confirmation;
            cout << "Are you sure you want to exit? [y/N] \nDon't forget to save your work before you leave." << endl;
            cin.clear();
            cin >> confirmation;
            cin.ignore(1000,'\n');
            if (confirmation == 'y') {
                exit(0);
            }
            return 0;
        default:     //Invalid input
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
    while(!mainMenu(filename));
    return 1;
}

int createNewTeamMenu(){
    string teamname;

    cout << "Write the name of your Team" << endl;
    cout << "0. Go back to the previous menu" << endl;
    cin.clear();
    cin >> teamname;
    cin.ignore(1000,'\n');

    if(teamname == "0") return 1;

    national_team = new Team();
    national_team->setTeamName(teamname);
    string file_name = teamname + ".txt";
    while(!mainMenu(file_name));
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
            return 0;
        case '2': //Create a new Team File
            while(!createNewTeamMenu());
            return 0;
        case '0': //Exits program
            return 1;
        default:  //Goes back
            return 0;
    }
}

