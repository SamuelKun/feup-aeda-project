#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include "Team.h"
#include "utils.h"

void wait(){
    string waiting;
    cout << "Press any key to continue: " << endl;
    getline(cin,waiting);
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
    this->team_competitions = read_competion(file_info[3], this);
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
vector<Competition *> Team::getCompetition() const {
    return team_competitions;
}

vector<Game *> Team::getGames() const {
    vector<Game *> ret_games;
    for (size_t i = 0; i < team_competitions.size(); i++) {
        vector<Game *> competitions_games = team_competitions[i]->getGames();
        for (size_t j = 0; j < competitions_games.size();j++){
            ret_games.push_back(competitions_games[i]);
        }
    }
    return ret_games;
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
        money += team_staff[i]->getSalary();
    return money;
}

int Team::missingPay() {
    double not_paid = 0;
    for (size_t i = 0; i < team_competitions.size(); i++)
        if (!(team_competitions[i]->getPaid()))
            not_paid++;
    return not_paid;
}

void Team::showPlayersTable() const {
    cout << setw(19) << "Name" << " | " << setw(10) << "Date" <<" | ";
    cout << setw(12) << "Position" << " | " << setw(10) << "Position" << " | " << setw(6) << "Weight" << " | " << setw(8) << "Height" << " | " << setw(7) << "Value" << " | " << setw(9) <<  "Earnings" << " |" << endl;
    for(int i = 0; i < team_players.size(); i++){
        team_players[i]->infoTable();
    }
}

bool cmpName(const Player * p1, const Player * p2){
    return p1->getName() < p2->getName();
}

bool cmpPosition(const Player * p1, const Player * p2){
    string pos[4] = {"Goalkeeper", "Defender", "Midfielder", "Forward"};
    int p1v, p2v;
    for(size_t i = 0; i < 4; i++)
        if (pos[i] == p1->getPosition()) p1v = i;

    for(size_t i = 0; i < 4; i++)
        if (pos[i] == p2->getPosition()) p2v = i;

    return p1v < p2v;
}

bool cmpValue(const Player * p1, const Player * p2){
    return p1->getValue() > p2->getValue();
}


void Team::sortPlayersName() {
    sort(team_players.begin(), team_players.end(), cmpName);
}

void Team::sortPlayersPosition() {
    sort(team_players.begin(), team_players.end(), cmpPosition);
}

void Team::sortPlayersValue() {
    sort(team_players.begin(), team_players.end(), cmpValue);
}


void Team::addPlayer(Player* p) {

    if(p->getName() == "") throw CantUseThatName(p->getName());

    for(size_t i = 0; i < team_players.size();i++){
        if(team_players[i]->getName().find(p->getName()) != string::npos ){
            throw PlayerAlreadyExists(p->getName());
        }
    }

   team_players.push_back(p);

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
    wait();
    return 0;
}

vector<Player *> Team::findPlayerName(string name) {
    vector<Player *> v_players;
    for (size_t i = 0; i < team_players.size(); i++) {
        if (team_players[i]->getName().find(name) != string::npos) {
            v_players.push_back(team_players[i]);
        }
    }
    if (v_players.empty()) throw(PersonNotFound(name));
    else return v_players;
}

vector<Staff *> Team::findStaffName(string name) {
    vector<Staff *> v_staff;
    for (size_t i = 0; i < team_staff.size(); i++)
    {
        if (team_staff[i]->getName().find(name) != string::npos)
            v_staff.push_back(team_staff[i]);
    }
    if (v_staff.empty()) throw(PersonNotFound(name));
    else return v_staff;
}

Game *Team::findGame(string country, string city, string stadium) {
    vector<Game *> team_games = Team::getGames();
    for(size_t i = 0 ; i < team_games.size(); i++){
        if( team_games[i]->getCountry().find(country) != string::npos &&
            team_games[i]->getCity().find(city) != string::npos &&
            team_games[i]->getStadium().find(stadium) != string::npos){
            return team_games[i];
        }
    }
    throw GameNotFound(country,city,stadium);
}


vector<Player *> Team::findPlayerPos(string position) {
    vector<Player *> v_players;
    for (size_t i = 0; i < team_players.size(); i++) {
        if (team_players[i]->getPosition().find(position) != string::npos) {
            v_players.push_back(team_players[i]);
        }
    }
    if (v_players.empty()) throw(PositionNotFound(position));
    else return v_players;
}

Competition * Team::findCompetition(string name) {
    for (size_t i = 0; i < team_competitions.size(); i++)
    {
        if (team_competitions[i]->getCompetitionName().find(name) != string::npos)
            return team_competitions[i];
    }
    throw CompetitionNotFound(name);
}

vector<Staff *> Team::findStaffFunction(string function) {
    vector<Staff *> v_staff;
    for (size_t i = 0; i < team_staff.size(); i++) {
        if (team_staff[i]->getFunction() == function) {
            v_staff.push_back(team_staff[i]);
        }
    }
    if (v_staff.empty()) { throw(FunctionNotFound(function)); }
    else { return v_staff; }
}

vector<Competition *> Team::findCompetitionDate(Date start, Date end) {
    vector<Competition *> to_return;
    for (size_t i = 0; i < team_competitions.size(); i++) {
        if ((team_competitions[i]->getStartDate().isBefore(start) || team_competitions[i]->getStartDate().isEqualTo(start)) && ( 
        team_competitions[i]->getEndDate().isAfter(end) || team_competitions[i]->getEndDate().isEqualTo(end))) {
            to_return.push_back(team_competitions[i]);
        }
    }
    if (to_return.empty()) { 
        throw(NoCompetitionsIn(start, end)); 
    } else { 
        return to_return; }
}

Player *Team::findPlayer(string name) {
    for (size_t i = 0; i < team_players.size(); i++)
    {
        if (team_players[i]->getName().find(name) != string::npos)
            return team_players[i];
    }
    throw(PersonNotFound(name));
}

void Team::removePlayer( Player * p) {

    for(size_t i = 0; i < team_players.size();i++){
        if(team_players[i]->getName() == p->getName()){
            team_players.erase(team_players.begin()+i);
        }
    }


}

