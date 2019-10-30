//
// Created by samuel on 30/10/19.
//


#include "Player.h"
#include "Team.h"
#include <vector>
#include <string>
#include <fstream>

Team::Team(string file_name) {

    //Read Agency File
    ifstream info(file_name);
    vector<string> all_info;
    string str_temp;

    while (getline(info, str_temp)) all_info.push_back(str_temp);

    teamName = all_info[0];

    ifstream team_info(all_info[1]);

    vector<string> tempVec;

    /* 1º while - team.txt
    while (getline(team_info, str_temp)){
        if (str_temp != "-----") tempVec.push_back(str_temp);
        else
        {
            //pos = tempVec[0]; // Ver como fazer para passar
            //jogador name 1
            //jogador nome 2
            // ... loop
        }


    }
     */

    // 2º while - jogadores.txt -> append no vector

    ifstream players_info(all_info[2]);
    string str_temp2;

    while (getline(players_info, str_temp)){
        cout << str_temp << endl;
        /*
         * if (str_temp != "-----") tempVec.push_back(str_temp);
        else
        {

            Date tempBirth(10,10,10);
            //enumPosition a = Goalkeeper; // Apenas para testar vai ser mudado depois!!!
            cout << tempVec[4] << endl;
            cout << tempVec[5] << endl;
            cout << tempVec[6] << endl;
            //Player tempPlayer(tempVec[0], tempBirth, a, tempVec[3], std::stoi(tempVec[4]), std::stoi(tempVec[5]), stoi(tempVec[6]));
            //this->players.push_back(tempPlayer);
        }*/
    }

    /* 3º while - jogos.txt


    */

}

vector<Player> Team::GetPlayers() const {
    return players;
}
