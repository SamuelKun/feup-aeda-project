#ifndef AEDA_COMPETITION_H
#define AEDA_COMPETITION_H

#include "Player.h"
#include "Game.h"
#include <string>
#include <vector>

class Competition{
private:
    string name;
    vector<Player *> called;
    vector<Game *> team_games;
    Date start, end;
    bool paid;
public:
    Competition(string name, vector<Player *> called, vector<Game *> team_games, Date start, Date end);
    string getCompetitionName() const;
    void payPlayers();
    bool getPaid() const;
    vector<Player *> getCalled() const;
    vector<Game *> getGames() const;
    friend ostream & operator<<(ostream &out, const Competition &comp);
};

class AlreadyPaid{
    string name;
public:
    AlreadyPaid(string name): name(name){}
    string getName(){return name;}
};

#endif
