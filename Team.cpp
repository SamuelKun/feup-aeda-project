#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <vector>
#include <string>
#include <fstream>

vector<Player *> read_player(string info){
    ifstream players_info(info);
    vector<Player *> players;
    vector<string> tempVec;
    string str_temp;
    while (getline(players_info, str_temp)){
        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            Date tempBirth(tempVec[1]);
            Player *p = new Player(tempVec[0], tempBirth, tempVec[2], tempVec[3], stoi(tempVec[4]), stoi(tempVec[5]), stoi(tempVec[6]));
            players.push_back(p);
            tempVec.clear();
        }
    }
    return players;
}

vector<Staff *> read_staff(string info){
    ifstream staff_info(info);
    vector<Staff *> staff;
    vector<string> tempVec;
    string str_temp;

    while (getline(staff_info, str_temp)){
        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            Date tempBirth(tempVec[1]);
            Staff *p = new Staff(tempVec[0], tempBirth, stod(tempVec[2]), tempVec[3]);
            staff.push_back(p);
            tempVec.clear();
        }
    }
    return staff;
}

vector<Game *> read_games(string info){
    ifstream game_info(info);
    vector<Game *> games;
    vector<string> tempVec;
    string str_temp;
    while (getline(game_info, str_temp)){
        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            Date game_day(28, 06, 2000);
            Game *g = new Game(tempVec[0], tempVec[1], tempVec[2], game_day);
            games.push_back(g);
            tempVec.clear();
        }
    }
    return games;
}

vector<Competion *> read_competion(string info, Team * t){
    ifstream competion_info(info);
    vector<Competion *> competion;
    vector<string> tempVec;
    string str_temp;
    while (getline(competion_info, str_temp)){

        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            //Ler Convocados
            vector<Player *> comp_convocado;
            ifstream called(tempVec[1]);
            vector<string> called_vec;
            while (getline(called, str_temp)) called_vec.push_back(str_temp);

            for(auto it = called_vec.begin(); it != called_vec.end(); it++)
                comp_convocado.push_back(t->findPlayer(*it));

            //Ler Jogos
            vector<Game *> competion_games = read_games(tempVec[2]);

            //Data de começo e fim
            Date startcomp(tempVec[3]);
            Date endcomp(tempVec[4]);
            Competion *tempComp = new Competion(tempVec[0], comp_convocado, competion_games, startcomp, endcomp);
            competion.push_back(tempComp);
            tempVec.clear();
        }
    }
    return competion;
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
    cout << team_players[0] << endl;
    this->team_competions = read_competion(file_info[3], this);
    cout << team_competions[0]->getCalled()[0];
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