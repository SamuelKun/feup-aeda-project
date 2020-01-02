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
    this->team_players = read_player(file_info[1]);
    this->table = read_staff(file_info[2]);
    this->team_competitions = read_competion(file_info[3], this);
    this->coachs = read_coachs(file_info[4]);
    this->providers = read_providers(file_info[5]);
}

void Team::updateFile(string file_name) {

    ofstream init(file_name);
    init << teamName << endl;
    init << teamName + "players.txt" << endl;
    init << teamName + "staff.txt" << endl;
    init << teamName + "competition.txt" << endl;
    init << teamName + "coaches.txt" << endl;
    init << teamName + "providers.txt" << endl;


    ofstream p(teamName + "players.txt");
    for (size_t i = 0; i < team_players.size(); i++) {
        p << (*team_players[i]) << endl;
        p << "-----" << endl;
    }

    ofstream s(teamName + "staff.txt");
    auto itTable = table.begin();
    for(int i = 0;  itTable  != table.end(); itTable ++,i++){
        s << (* itTable )<< endl;
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

    ofstream coach_w(teamName + "coaches.txt");
    BST<Coach> coach_tree = coachs.getTree();
    BSTItrIn<Coach> it(coach_tree);
    while (!it.isAtEnd()) {
        coach_w << it.retrieve().getName() << endl;
        coach_w << it.retrieve().getBirthday() << endl;
        coach_w << it.retrieve().getCurrentCoach() << endl;
        coach_w << it.retrieve().getTitles() << endl;
        vector<std::tuple<string, Date, Date>> tr = it.retrieve().getTrainedTeams();
        for(auto &i : tr) {
            coach_w << get<0>(i) << "!" <<get<1>(i) << "!" <<get<2>(i) <<endl;
        }
        coach_w << "-----" << endl;
        it.advance();
    }



    Equipment equip4;
    priority_queue<Provider> aux = providers.getProviders();
    ofstream pr(teamName + "providers.txt");
    while (!aux.empty()) {
        pr << aux.top().getName() << endl;
        pr << aux.top().getReputation() << endl;
        equip4 = aux.top().getEquipment();
        pr << equip4.football_kit << endl;
        pr << equip4.balls << endl;
        pr << equip4.football_boots << endl;
        pr << equip4.cones << endl;
        pr << equip4.goal << endl;
        pr << equip4.tactics_board << endl;
        pr << equip4.medical_kit << endl;
        pr << equip4.water_bottles << endl;
        pr << "-----" << endl;
        aux.pop();
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
/*
vector<Staff *> Team::getStaff() const {
    return team_staff;
}
*/
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

vector<int> Team::showStaffTable() const {
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Function" << " | " << setw(9) << "Salary" << " | " <<setw(6) <<  "Index" << " |" << endl;;
    auto it = table.begin();
    vector<int> vec;
    for(int i = 0; it != table.end();i++, it++){
        if(it->isWorking1()){
            it->infoTable();
            cout << setw(6) <<  i << " |" << endl;
            vec.push_back(i);
        }
    }
    return vec;
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
/*
void Team::sortStaffName() {
    sort(team_staff.begin(), team_staff.end(), cmpName);
}

void Team::sortStaffFunction() {
    sort(team_staff.begin(), team_staff.end(), cmpFunction);
}
*/
void Team::addPlayer(Player* p) {

    if(p->getName() == "") throw CantUseThatName(p->getName());

    for(size_t i = 0; i < team_players.size();i++){
        if(team_players[i]->getName() == p->getName()){
            throw PersonAlreadyExists(p->getName());
        }
    }
   team_players.push_back(p);
}

/*
void Team::addStaff(Staff* s) {
    if(s->getName() == "") throw CantUseThatName(s->getName());

    for(size_t i = 0; i < team_staff.size();i++){
        if(team_staff[i]->getName() == s->getName()){
            throw PersonAlreadyExists(s->getName());
        }
    }

    team_staff.push_back(s);
}
*/

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

vector<Staff> Team::findStaffName(string name) {
    auto it = table.begin();
    vector<Staff> v_staff;
    for( ; it != table.end(); it++) {
        if (it->getName().find(name) != string::npos)
            v_staff.push_back(*it);
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

vector<Staff> Team::findStaffFunction(string function) {
    auto it = table.begin();
    vector<Staff> v_staff;
    for( ; it != table.end(); it++) {
        if (it->getFunction() == function)
            v_staff.push_back(*it);
    }

    if (v_staff.empty()) throw(FunctionNotFound(function));
    else return v_staff;
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
/*
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
*/
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


const tabH &Team::getStaff() const {
    return table;
}
/*
std::vector<Staff> Team::findStaffName(string name) {
    vector<Staff> v;
    for (const auto& stf : table){
        if( stf.getName().find(name) != string::npos) v.push_back(stf);
    }
    if(v.empty()) throw PersonNotFound(name);
    else return v;
}
*/
void Team::addStaff(Staff *s) {
    table.insert(*s);
    team_staff.push_back(s);
}

void Team::deleteStaff(Staff s) {
    auto it = table.find(s);
    if( it != table.end()) table.erase(it);
    else throw PersonNotFound(s.getName());
}
void Team::removeStaff(Staff s) {
    auto it = table.find(s);
    if( it != table.end()){
        table.erase(it);
        s.setIsWorking(false);
        table.insert(s);
    }
    else throw PersonNotFound(s.getName());
}

void Team::showStaff() {
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Function" << " | " << setw(9) << "Salary" << " | " <<setw(6) <<  "Index" << " |" << endl;;
    int i = 0;
    auto it = table.begin();
    for(int i = 0; it != table.end();it++,i++){
        it->infoTable();
        cout << setw(6) <<  i << " |" << endl;
    }
}

int Team::showStaffRemoved() {
    cout << setw(19) << "Name" << " | " << setw(10) << "Birthday" <<" | ";
    cout << setw(12) << "Function" << " | " << setw(9) << "Salary" << " | " <<setw(6) <<  "Index" << " |" << endl;;
    auto it = table.begin();
    int i = 0;
    for(; it != table.end();i++, it++){
        if(!it->isWorking1()){
            it->infoTable();
            cout << setw(6) <<  i << " |" << endl;
        }
    }
    return i;
}











