#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include "Team.h"
#include "utils.h"

using namespace std;


Team::Team() {
}


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


string Team::getTeamName() const {
    return teamName;
}

vector<Player *> Team::getPlayers() const {
    return team_players;
}

vector<Staff *> Team::getStaff() const {
    return team_staff;
}

vector<Competition *> Team::getCompetition() const {
    return team_competitions;
}

vector<Game *> Team::getGames() const {
    vector<Game *> ret_games;
    for (size_t i = 0; i < team_competitions.size(); i++) {
        vector<Game *> competitions_games = team_competitions[i]->getGames();
        for (size_t j = 0; j < competitions_games.size();j++)
            ret_games.push_back(competitions_games[j]);
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
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Club" << " | " << setw(10) << "Position" << " | " << setw(6) << "Weight" << " | " << setw(8) << "Height" << " | " << setw(7) << "Value" << " | " << setw(9) <<  "Earnings" << " |" << endl;
    for(int i = 0; i < team_players.size(); i++){
        team_players[i]->infoTable();
    }
}

void Team::showStaffTable() const {
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Function" << " | " << setw(9) << "Salary" << " | " << endl;
    for(int i = 0; i < team_staff.size(); i++){
        team_staff[i]->infoTable();
    }
}


bool cmpName(const Person * p1, const Person * p2){
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

bool cmpFunction(const Staff * p1, const Staff * p2){
    string pos[2] = {"Coach", "Doctor"};
    int p1v, p2v;
    for(size_t i = 0; i < 2; i++)
        if (pos[i] == p1->getFunction()) p1v = i;

    for(size_t i = 0; i < 2; i++)
        if (pos[i] == p2->getFunction()) p2v = i;

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

void Team::sortStaffName() {
    sort(team_staff.begin(), team_staff.end(), cmpName);
}

void Team::sortStaffFunction() {
    sort(team_staff.begin(), team_staff.end(), cmpFunction);
}

void Team::addPlayer(Player* p) {

    if(p->getName() == "") throw CantUseThatName(p->getName());

    for(size_t i = 0; i < team_players.size();i++){
        if(team_players[i]->getName() == p->getName()){
            throw PlayerAlreadyExists(p->getName());
        }
    }
   team_players.push_back(p);
}

void Team::addStaff(Staff* s) {
    if(s->getName() == "") throw CantUseThatName(s->getName());

    for(size_t i = 0; i < team_staff.size();i++){
        if(team_staff[i]->getName() == s->getName()){
            throw StaffMemberAlreadyExists(s->getName());
        }
    }

    team_staff.push_back(s);

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

vector<Competition *> Team::findCompetition(string name) {
    vector<Competition *> comp;
    for (size_t i = 0; i < team_competitions.size(); i++) {
        if (team_competitions[i]->getCompetitionName().find(name) != string::npos)
            comp.push_back(team_competitions[i]);
    }
    if(comp.empty()) throw CompetitionNotFound(name);
    else return comp;
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
    vector<Competition *> v_competition;
    for (size_t i = 0; i < team_competitions.size(); i++) {
        if ((team_competitions[i]->getStartDate().isBefore(start) || team_competitions[i]->getStartDate().isEqualTo(start)) && ( 
        team_competitions[i]->getEndDate().isAfter(end) || team_competitions[i]->getEndDate().isEqualTo(end))) {
            v_competition.push_back(team_competitions[i]);
        }
    }
    if (v_competition.empty()) {
        throw(NoCompetitionsIn(start, end)); 
    } else { 
        return v_competition; }
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

void Team::removeStaff(Staff *s) {
    bool found_staff = false;
    for(size_t i = 0; i < team_staff.size();i++){
        if(team_staff[i]->getName() == s->getName()){
            found_staff = true;
            team_staff.erase(team_staff.begin()+i);
            break;
        }
    }
    if(!found_staff) throw (StaffMemberNotFound(s->getName()));
}

double Team::getMoneyAccommodation() const {
    double money = 0;
    for (size_t i = 0; i < team_competitions.size(); i++)
        money += team_competitions[i]->getMoneyAccommodation();
    return money;
}

void Team::addCompetition(Competition *comp) {
    for(size_t i = 0; i < team_competitions.size();i++){
        if(team_competitions[i]->getCompetitionName() == comp->getCompetitionName()){
            throw CompetitionAlreadyExists(comp->getCompetitionName());
        }
    }
    team_competitions.push_back(comp);
}

void Team::updateFile(string file_name) {

    ofstream init(file_name);
    init << teamName << endl;
    init << "players.txt" << endl;
    init << "staff.txt" << endl;
    init << "competition.txt" << endl;


    ofstream p("players.txt");
    for (size_t i = 0; i < team_players.size(); i++) {
        p << (*team_players[i]) << endl;
        p << "-----" << endl;
    }
    ofstream s("staff.txt");
    for (size_t i = 0; i < team_staff.size(); i++) {
        s << (*team_staff[i]) << endl;
        s << "-----" << endl;
    }


    ofstream c("competition.txt");

    int num = 0;
    for (size_t i = 0; i < team_competitions.size(); i++) {
        c << team_competitions[i]->getCompetitionName() << endl;

        ofstream call("called" + to_string(num) + ".txt");
        c << "called" + to_string(num) + ".txt" << endl;

        vector<Player *> called_write = team_competitions[i]->getCalled();
        for(size_t j = 0; j < team_competitions[i]->getCalled().size(); j++)
            call << called_write[j]->getName() << endl;

        ofstream gam("games" + to_string(num) + ".txt");
        c << "games" + to_string(num) + ".txt" << endl;

        vector<Game *> games_write = team_competitions[i]->getGames();
        for(size_t j = 0; j < games_write.size(); j++) {
            gam << (*games_write[j]) << endl;
            gam << "-----" << endl;
        }
        num++;
        c << team_competitions[i]->getStartDate() << endl;
        c << team_competitions[i]->getEndDate() << endl;
        c << team_competitions[i]->getMoneyAccommodation() << endl;
        c << team_competitions[i]->getPaid() << endl;
        c << "-----" << endl;
    }
}

void Team::removeCompetition(Competition *c) {
    bool found = false;
    for (size_t i = 0; i < team_competitions.size(); i++){
        if(team_competitions[i] == c){
            team_competitions.erase(team_competitions.begin() + i);
            found = true;
        }
    }
    if(!found){
        throw CompetitionNotFound(c->getCompetitionName());
    }
}

void Team::setTeamName(string team_name) {
this->teamName = team_name;
}



