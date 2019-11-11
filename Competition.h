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
    double moneyAccommodation;
    bool paid;

public:
    Competition(string name, vector<Player *> called, vector<Game *> team_games, Date start, Date end, double moneyAccommodation);
    string getCompetitionName() const;
    void payPlayers();
    bool getPaid() const;
    double getMoneyAccommodation() const;
    vector<Player *> getCalled() const;
    vector<Game *> getGames() const;
    Date getStartDate() const;
    Date getEndDate() const;
    friend ostream & operator<<(ostream &out, const Competition &comp);

    void showPlayers() const;
    void showGames() const;

    void addGame(Game * g);
};

class AlreadyPaid{
    string name;
public:
    AlreadyPaid(string name): name(name){}
    string getName(){return name;}
};

class CompetitionNotFound{
private:
    string name;
public:
    CompetitionNotFound(string name): name(name) {}
    string getName() const{
        return name;
    }
};

class NoCompetitionsIn{
private:
    Date start;
    Date end;
public:
    NoCompetitionsIn(Date start, Date end): start(start), end(end) {}
    Date getStart() const{
        return start;
    }
    Date getEnd() const{
        return end;
    }
};

#endif
