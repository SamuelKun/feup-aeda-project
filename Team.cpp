//
// Created by samuel on 30/10/19.
//

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
            Player *p = new Player(tempVec[0], tempBirth, tempVec[3], std::stoi(tempVec[4]), std::stoi(tempVec[5]), stoi(tempVec[6]));
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

vector<Competion *> read_competion(string info){
    ifstream competion_info(info);
    vector<Competion *> competion;
    vector<string> tempVec;
    string str_temp;
    while (getline(competion_info, str_temp)){

        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            //Ler Convocados
            vector<Player *> comp_convocado = read_player(tempVec[0]);
            //Ler Jogos
            vector<Game *> competion_games = read_games(tempVec[1]);
            //Data de começo e fim
            Date startcomp(tempVec[2]);
            Date endcomp(tempVec[3]);
            Competion *tempComp = new Competion(comp_convocado, competion_games, startcomp, endcomp);
            competion.push_back(tempComp);
            tempVec.clear();
        }
    }
    return competion;
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
    this->team_competions = read_competion(file_info[3]);

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
