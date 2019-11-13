#ifndef AEDA_UTILS_H
#define AEDA_UTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Game.h"
#include "Person.h"
#include "Staff.h"
#include "Player.h"
#include "Statistics.h"

/// \brief Reads a player from a .txt file.
/// \param info .txt file containing a Team of Players
/// \return Vector of Players belonging to a team
std::vector<Player *> read_player(std::string info){
    std::ifstream players_info(info);
    std::vector<Player *> players;
    std::vector<std::string> tempVec;
    std::string str_temp;
    while (getline(players_info, str_temp)){
        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            Date tempBirth(tempVec[1]);

            PlayerStatistics *stats_virtual;
            if (tempVec[3] == "Goalkeeper") {

                GoalkeeperStatistics *s = new GoalkeeperStatistics(stoi(tempVec[8]), stoi(tempVec[9]), stoi(tempVec[10]), stoi(tempVec[11]));
                stats_virtual= s;
            }
            if (tempVec[3] == "Defender") {
                DefenderStatistics *s = new DefenderStatistics(stoi(tempVec[8]), stoi(tempVec[9]), stoi(tempVec[10]), stoi(tempVec[11]));
                stats_virtual = s;
            }
            if (tempVec[3] == "Midfielder") {
                MidfielderStatistics *s = new MidfielderStatistics(stoi(tempVec[8]), stoi(tempVec[9]), stoi(tempVec[10]), stoi(tempVec[11]));
                stats_virtual = s;
            }
            if (tempVec[3] == "Forward") {
                ForwardStatistics *s = new ForwardStatistics(stoi(tempVec[8]), stoi(tempVec[9]), stoi(tempVec[10]), stoi(tempVec[11]));
                stats_virtual = s;
            }

            Player *p = new Player(tempVec[0], tempBirth, tempVec[2], tempVec[3], stoi(tempVec[4]), stoi(tempVec[5]), stoi(tempVec[6]), stoi(tempVec[7]), stats_virtual);
            players.push_back(p);
            tempVec.clear();
        }
    }
    return players;
}
/// \brief Reads a Staff Member from a .txt file.
/// \param info .txt file containing Staff Members
/// \return Vector of Staff Members belonging to a team
std::vector<Staff *> read_staff(std::string info){
    std::ifstream staff_info(info);
    std::vector<Staff *> staff;
    std::vector<std::string> tempVec;
    std::string str_temp;

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
/// \brief Reads a Game from a .txt file.
/// \param info .txt file containing Games
/// \param called_players Vector of Players called for these Games
/// \return Vector of Games stored in the file
std::vector<Game *> read_games(std::string info, std::vector<Player *> called_players){
    std::ifstream game_info(info);
    std::vector<Game *> games;
    std::vector<std::string> tempVec;
    std::string str_temp;
    while (getline(game_info, str_temp)){
        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            Date game_day(tempVec[4]);
            Statistics game_stats(stoi(tempVec[5]),stoi(tempVec[6]),stoi(tempVec[7]),stoi(tempVec[8]),stoi(tempVec[9]),stoi(tempVec[10]),stoi(tempVec[11]),stoi(tempVec[12]), stoi(tempVec[13]));
            Game *g = new Game(tempVec[0], tempVec[1], tempVec[2], tempVec[3], game_day, called_players, game_stats);
            games.push_back(g);
            tempVec.clear();
        }
    }
    return games;
}
/// \brief Reads a Competition from a .txt file.
/// \param info .txt file containing the Competition
/// \param t Team Whose Competition is being read
/// \return Vector of Competition stored in the file
std::vector<Competition *> read_competion(std::string info, Team * t){
    std::ifstream competion_info(info);
    std::vector<Competition *> competion;
    std::vector<std::string> tempVec;
    std::string str_temp;
    while (getline(competion_info, str_temp)){

        if (str_temp != "-----") tempVec.push_back(str_temp);
        else{
            //Ler Convocados
            std::vector<Player *> comp_convocado;
            std::ifstream called(tempVec[1]);
            std::vector<std::string> called_vec;
            while (getline(called, str_temp)) called_vec.push_back(str_temp);

            for(auto it = called_vec.begin(); it != called_vec.end(); it++)
                comp_convocado.push_back(t->findPlayer(*it));

            //Ler Jogos
            std::vector<Game *> competion_games = read_games(tempVec[2], comp_convocado);
            //Data de começo e fim
            Date startcomp(tempVec[3]);
            Date endcomp(tempVec[4]);
            Competition *tempComp = new Competition(tempVec[0], comp_convocado, competion_games, startcomp, endcomp, stod(tempVec[5]), stoi(tempVec[6]));
            competion.push_back(tempComp);
            tempVec.clear();
        }
    }
    return competion;
}


#endif //AEDA_UTILS_H
