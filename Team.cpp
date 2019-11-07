//
// Created by samuel on 30/10/19.
//


#include "Player.h"
#include "Team.h"
#include <vector>
#include <string>
#include <fstream>

bool cmpPos( const Player &p1, const Player & p2)
{
    return p1.getPosition() > p2.getPosition();
}
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

    /* 1º while - team.txt - CONVOCATÓRIAS!
    */
/*
    ifstream team_info(all_info[1]);

    while (getline(team_info, str_temp)){
        cout << str_temp << endl;

        if (str_temp != "-----") tempVec.push_back(str_temp);
        else
        {
            Date tempBirth(10,10,10);
            enumPosition a = Goalkeeper; // Apenas para testar vai ser mudado depois!!!
            Player tempPlayer(tempVec[0], tempBirth, a, tempVec[3], std::stoi(tempVec[4]), std::stoi(tempVec[5]), stoi(tempVec[6]));
            this->players.push_back(&tempPlayer);
            tempVec.clear();
        }
    }
*/

    // 2º while - jogadores.txt -> append no vector
    ifstream players_info(all_info[2]);

    while (getline(players_info, str_temp)){
        cout << str_temp << endl;

        if (str_temp != "-----") tempVec.push_back(str_temp);
        else
        {
            Date tempBirth(tempVec[1]);
            enumPosition a = Goalkeeper; // Apenas para testar vai ser mudado depois!!!
            Player tempPlayer(tempVec[0], tempBirth, a, tempVec[3], std::stoi(tempVec[4]), std::stoi(tempVec[5]), stoi(tempVec[6]));
            this->players.push_back(&tempPlayer);
            tempVec.clear();
            cout<<"Limpou? " << tempVec.size() << endl;
        }
    }

    /* 3º while - jogos.txt
    */
}

vector<Player *> Team::GetPlayers() const {
    return players;
}

void Team::sortByPosition() {
    //sort(players.begin(),players.end(),cmpPos);
}

void Team::sortByName(){
    //sort(players.begin(),players.end(),cmpName);
}