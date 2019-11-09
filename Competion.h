#ifndef AEDA_COMPETITION_H
#define AEDA_COMPETITION_H

#include "Game.h"
#include "Player.h"
#include <string>
#include <vector>

class Competion{
private:
    string name;
    vector<Player *> called;
    vector<Game *> team_games;
    Date start, end;
public:
    Competion(string name, vector<Player *> called, vector<Game *> team_games, Date start, Date end);
    string getCompetionName() const;
    vector<Player *> getCalled() const;
    vector<Game *> getGames() const;
    friend ostream & operator<<(ostream &out, const Competion &comp);
};



#endif //FEUP_AEDA_PROJECT_COMPETION_H
