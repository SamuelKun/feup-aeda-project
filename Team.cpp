#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <vector>
#include <string>
#include <fstream>
#include "utils.h"

template <class form>
void failInput(form input)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cin.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        cin >> input;
    }
}

/// \brief Constructor
Team::Team() {
}

/// \brief Constructor
/// \param file_name file containing team
Team::Team(string file_name) {
    //Read Agency File
    ifstream info(file_name);
    vector<string> file_info;
    string str_temp;

    while (getline(info, str_temp)) file_info.push_back(str_temp);

    this->teamName = file_info[0];
    this->team_players = read_player(file_info[1]);
    this->team_staff = read_staff(file_info[2]);
    this->team_competions = read_competion(file_info[3], this);
}

/// \brief Get Method
/// \return Team's name
string Team::getTeamName() const {
    return teamName;
}
/// \brief Get Method
/// \return Team's vector with teams players
vector<Player *> Team::getPlayers() const {
    return team_players;
}
/// \brief Get Method
/// \return Team's vector with staff members
vector<Staff *> Team::getStaff() const {
    return team_staff;
}
/// \brief Get Method
/// \return Team's vector with Competitions
vector<Competion *> Team::getCompetion() const {
    return team_competions;
}

vector<Game *> Team::getGame() const {
    return team_games;
}

Player * Team::findPlayer(string name) {
    for (size_t i = 0; i < team_players.size(); i++)
    {
        if (team_players[i]->getName().find(name) != string::npos)
            return team_players[i];
    }
    throw(PlayerNotFound(name));
}

int Team::addPlayer() {
    string n, c, pos, go_back;
    int wei,hei,val,earn,day,month,year;
    char checker = false;

    cout << "Write the name of the Player you wish to add: " << endl;

    cin.ignore(1000, '\n');
    getline(cin,n);

    cout << "Write " << n << "'s birthday " << endl;
    cout << "Write " << n << "'s day of birth" << endl;
    cin >> day; failInput(day);
    cout << "Write " << n << "'s month of birth" << endl;
    cin >> month; failInput(month);
    cout << "Write " << n << "'s year of birth" << endl;
    cin >> year; failInput(year);

    cout << "Write " << n << "'s club " << endl;
    cin >> c;

    cout << "Write " << n << "'s position " << endl;
    cin >> pos;

    cout << "Write " << n << "'s weight " << endl;
    cin >> wei;failInput(wei);

    cout << "Write " << n << "'s height " << endl;
    cin >> hei;failInput(hei);

    cout << "Write " << n << "'s value " << endl;
    cin >> val;failInput(val);

    cout << "Write " << n << "'s earnings " << endl;
    cin >> earn;failInput(earn);

    cout << "Do you wish to add the Player you have created?: " << endl;
    cout << "1. Add Player " << endl;
    cout << "2. Cancel adding Player " << endl;
    cin >> checker;
    if(checker == '2') return 0;

    Date *b = new Date(day,month,year);
    Player *play = new Player(n,*b,c,pos,wei,hei,val,earn);
    team_players.push_back(play);

    cout << "Player added successfully!!" << endl;
    cout << "Press any button to continue" << endl;
    cin >> go_back;
    return 0;
}

int Team::addStaff() {
    string n, f , go_back;
    double w;
    int day,month,year;
    bool checker = false;

    cout << "Write the name of the Player you wish to add: " << endl;
    cin.ignore(1000, '\n');
    getline(cin,n);

    cout << "Write " << n << "'s birthday " << endl;
    cout << "Write " << n << "'s day of birth" << endl;
    cin >> day; failInput(day);
    cout << "Write " << n << "'s month of birth" << endl;
    cin >> month; failInput(month);
    cout << "Write " << n << "'s year of birth" << endl;
    cin >> year; failInput(year);

    cout << "Write " << n << "'s wage " << endl;
    cin >> w;
    failInput(w);

    cout << "Write " << n   << "'s function " << endl;
    cin >> f;
    failInput(f);

    cout << "Do you wish to add the Staff Member you have created?: " << endl;
    cout << "1. Add Staff Member " << endl;
    cout << "2. Cancel adding Staff Member " << endl;
    cin >> checker;
    if(checker == '2') return 0;

    Date *b = new Date(day,month,year);
    Staff *s = new Staff(n,*b,w,f);
    team_staff.push_back(s);

    cout << "Staff Member added successfully!!" << endl;
    cout << "Press any button to continue" << endl;
    cin >> go_back;
    return 0;
}

double Team::getMoneyPlayers() const {
    double money = 0;
    for (size_t i = 0; i < team_players.size(); i++)
        money += team_players[i]->getEarnings();
    return money;
}

double Team::getMoneyStaff() const {
    double money = 0;
    for (size_t i = 0; i < team_staff.size(); i++)
        money += team_staff[i]->getWage();
    return money;
}
/*
vector<Player *> & Team::findPlayerByPos(string position) {
    vector<Player *> to_return;
    for (size_t i = 0; i < team_players.size(); i++) {
        if (team_players[i]->getPosition() == position) {
            to_return.push_back(team_players[i]);
        }
    }
    if (to_return.empty()) { throw(NoPlayersForPos(position)); }
    else { return to_return; }
}

Staff & Team::findStaff(string name) {
    for (size_t i = 0; i < team_staff.size(); i++)
    {
        if (team_staff[i]->getName().find(name) != string::npos)
            return *team_staff[i];
    }
    throw(StaffNotFound(name));
}

Competion & Team::findCompetion(string name) {
    for (size_t i = 0; i < team_competions.size(); i++)
    {
        if (team_competions[i]->getCompetionName().find(name) != string::npos)
            return *team_competions[i];
    }
    throw(CompetionNotFound(name));
}

vector<Staff *> & Team::findStaffByFunction(string function) {
    vector<Staff *> to_return;
    for (size_t i = 0; i < team_staff.size(); i++) {
        if (team_staff[i]->getFunction() == function) {
            to_return.push_back(team_staff[i]);
        }
    }
    if (to_return.empty()) { throw(NoStaffForFunction(function)); }
    else { return to_return; }
}

vector<Competion *> & Team::findCompetionByDate(Date start, Date end) {
    vector<Competion *> to_return;
    for (size_t i = 0; i < team_competions.size(); i++) {
        if (team_competions[i]->getStartDate() >= start && team_competions[i]->getEndDate() <= end) {
            to_return.push_back(team_competions[i]);
        }
    }
    if (to_return.empty()) { throw(NoCompetionsIn(Date start, Date end)); }
    else { return to_return; }
}
*/