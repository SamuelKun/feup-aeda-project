#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

#include "Team.h"
#include "utils.h"

using namespace std;

Team::Team(){
}

Team::Team(string file_name) {
    ifstream info(file_name);
    vector<string> file_info;
    string str_temp;

    while (getline(info, str_temp)) file_info.push_back(str_temp);

    this->teamName = file_info[0];
    this->coachs = read_coachs("portugalcoaches.txt");
    this->team_players = read_player(file_info[1]);
    this->team_staff = read_staff(file_info[2]);
    this->team_competitions = read_competion(file_info[3], this);

    for(auto s : team_staff){
        this->table.insert(*s);
    }
}

void Team::updateFile(string file_name) {

    ofstream init(file_name);
    init << teamName << endl;
    init << teamName + "players.txt" << endl;
    init << teamName + "staff.txt" << endl;
    init << teamName + "competition.txt" << endl;


    ofstream p(teamName + "players.txt");
    for (size_t i = 0; i < team_players.size(); i++) {
        p << (*team_players[i]) << endl;
        p << "-----" << endl;
    }
    ofstream s(teamName + "staff.txt");
    for (size_t i = 0; i < team_staff.size(); i++) {
        s << (*team_staff[i]) << endl;
        s << "-----" << endl;
    }


    ofstream c(teamName + "competition.txt");

    int num = 0;
    for (size_t i = 0; i < team_competitions.size(); i++) {
        c << team_competitions[i]->getCompetitionName() << endl;

        ofstream call(teamName + "called" + to_string(num) + ".txt");
        c <<teamName + "called" + to_string(num) + ".txt" << endl;

        map<Player *, int> called_write = team_competitions[i]->getCalledInjured();
        for(auto i : called_write)
            call << i.first->getName() << "!" << i.second << endl;

        ofstream gam(teamName + "games" + to_string(num) + ".txt");
        c << teamName + "games" + to_string(num) + ".txt" << endl;

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

void Team::setTeamName(string team_name) {
    this->teamName = team_name;
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
    cout << setw(12) << "Club" << " | " << setw(10) << "Position" << " | " << setw(6) << "Weight" << " | " << setw(8)
    << "Height" << " | " << setw(7) << "Value" << " | " << setw(9) <<  "Earnings" << " |" <<setw(6) <<  "Index" << " |" << endl;
    for(int i = 0; i < team_players.size(); i++){
        team_players[i]->infoTable();
        cout << setw(6) <<  i << " |" << endl;
    }
}

void Team::showStaffTable() const {
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Function" << " | " << setw(9) << "Salary" << " | " <<setw(6) <<  "Index" << " |" << endl;;
    for(int i = 0; i < team_staff.size(); i++){
        team_staff[i]->infoTable();
        cout << setw(6) <<  i << " |" << endl;
    }
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
            throw PersonAlreadyExists(p->getName());
        }
    }
   team_players.push_back(p);
}

void Team::addStaff(Staff* s) {
    if(s->getName() == "") throw CantUseThatName(s->getName());

    for(size_t i = 0; i < team_staff.size();i++){
        if(team_staff[i]->getName() == s->getName()){
            throw PersonAlreadyExists(s->getName());
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

Player * Team::findPlayer(string name) {
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
    if(!found_staff) throw (PersonNotFound(s->getName()));
}

double Team::getMoneyAccommodation() const {
    double money = 0;
    for (size_t i = 0; i < team_competitions.size(); i++)
        money += team_competitions[i]->getMoneyAccommodation();
    return money;
}

void Team::addCompetition(Competition *c) {
    for(size_t i = 0; i < team_competitions.size();i++){
        if(team_competitions[i]->getCompetitionName() == c->getCompetitionName()){
            throw CompetitionAlreadyExists(c->getCompetitionName());
        }
    }
    team_competitions.push_back(c);
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

CoachTree * Team::getCoachs() {
    return &coachs;
}

ProviderPriorityQueue * Team::getProviders() {
    return &providers;
}

const vector<Staff *> &Team::getTeamStaff() const {
    return team_staff;
}

const vector<Staff *> &Team::getTeamStaffAntigos() const {
    return team_staff_antigos;
}

const tabH &Team::getTable() const {
    return table;
}

std::vector<Staff> Team::dispFindStaff(string name) {
    vector<Staff> v;
    for (const auto& stf : table){
        if( stf.getName().find(name) != string::npos) v.push_back(stf);
    }
    if(v.empty()) throw PersonNotFound(name);
    else return v;
}

void Team::addTable(Staff *s) {
    table.insert(*s);
    team_staff.push_back(s);
}

void Team::removeTable(Staff *s) {
    auto it = find(team_staff.begin(),team_staff.end(),s);
    if(it != team_staff.end()){
       team_staff_antigos.push_back(*it);
       team_staff.erase(it);
    }
    else throw PersonNotFound(s->getName());
}

void Team::dispTable() {
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Function" << " | " << setw(9) << "Salary" << " | " <<setw(6) <<  "Index" << " |" << endl;;
    int i = 0;
    auto it = table.begin();
    for(int i = 0; it != table.end();it++,i++){
        it->infoTable();
        cout << setw(6) <<  i << " |" << endl;
    }



}

void Team::dispRemoved() {
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Function" << " | " << setw(9) << "Salary" << " | " <<setw(6) <<  "Index" << " |" << endl;;
    for(int i = 0; i < team_staff_antigos.size(); i++){
        team_staff_antigos[i]->infoTable();
        cout << setw(6) <<  i << " |" << endl;
    }
}









