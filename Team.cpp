//
// Created by samuel on 30/10/19.
//


#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <vector>
#include <string>
#include <fstream>

bool cmpName( const Player &p1, const Player & p2)
{
    return p1.getName() > p2.getName();
}


Team::Team(string file_name) {

    //Read Agency File
    ifstream info(file_name);
    vector<string> all_info;
    string str_temp;

    while (getline(info, str_temp)) all_info.push_back(str_temp);

    teamName = all_info[0];
    vector<string> tempVec;

    // 1º while - jogadores.txt -> append no vector
    ifstream players_info(all_info[1]);

    while (getline(players_info, str_temp)){
        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            Date tempBirth(tempVec[1]);
            Player *p = new Player(tempVec[0], tempBirth, tempVec[3], std::stoi(tempVec[4]), std::stoi(tempVec[5]), stoi(tempVec[6]));
            this->team_players.push_back(p);
            tempVec.clear();
        }
    }

    /* 2º while - competion.txt
    */

    ifstream competion_info(all_info[2]);
    vector<string> temp2;
    while (getline(competion_info, str_temp)){

        if (str_temp != "-----") temp2.push_back(str_temp);
        else{
            //Ler Convocados
            ifstream comp_conmInfo(temp2[0]);
            vector<Player *> comp_convocado;
            while (getline(comp_conmInfo, str_temp)){
                if (str_temp != "-----") tempVec.push_back(str_temp);
                else{
                    Date tempBirth(tempVec[1]);
                    Player *p = new Player(tempVec[0], tempBirth, tempVec[3], std::stoi(tempVec[4]), std::stoi(tempVec[5]), stoi(tempVec[6]));

                    comp_convocado.push_back(p);
                    tempVec.clear();
                }
            }
            cout << comp_convocado[0]->getName() << endl << endl;
            //Ler Jogos
            ifstream comp_gameInfo(temp2[1]);
            vector<Game *> comp_jogos;
            while (getline(comp_gameInfo, str_temp)){
                if (str_temp != "-----") tempVec.push_back(str_temp);
                else{
                    Game *g = new Game(tempVec[0], tempVec[1], tempVec[2]);
                    comp_jogos.push_back(g);
                    tempVec.clear();

                }
            }
            Date startcomp(temp2[2]);
            Date endcomp(temp2[3]);
            class Competion tempComp(comp_convocado, comp_jogos, startcomp, endcomp);
            this->team_competions.push_back(&tempComp);
            tempVec.clear();
        }
    }
}

string Team::getTeamName() const {
    return teamName;
}

vector<Player *> Team::GetPlayers() const {
    return team_players;
}

vector<Staff *> Team::GetStaff() const {
    return team_staff;
}

vector<Competion *> Team::Competion() const {
    return team_competions;
}
