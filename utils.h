#ifndef AEDA_UTILS_H
#define AEDA_UTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Team.h"
#include "Game.h"
#include "Person.h"
#include "Staff.h"
#include "Player.h"

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


#endif //AEDA_UTILS_H
