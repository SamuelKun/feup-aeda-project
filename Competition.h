#ifndef AEDA_COMPETITION_H
#define AEDA_COMPETITION_H

#include "Player.h"
#include "Game.h"
#include <string>
#include <vector>

class Competition{
private:
    std::string name;
    std::vector<Player *> called;
    std::vector<Game *> team_games;
    Date start, end;
    double moneyAccommodation;
    bool paid;

public:
    Competition(std::string name, std::vector<Player *> called, Date start, Date end);
    Competition(std::string name, std::vector<Player *> called, std::vector<Game *> team_games, Date start, Date end, double moneyAccommodation);
    std::string getCompetitionName() const;
    void payPlayers();
    bool getPaid() const;
    double getMoneyAccommodation() const;
    std::vector<Player *> getCalled() const;
    std::vector<Game *> getGames() const;
    Date getStartDate() const;
    Date getEndDate() const;
    friend std::ostream & operator<<(std::ostream &out, const Competition &comp);

    void showPlayers() const;
    void showGames() const;

    void addGame(Game * g);


    Game * findGame(std::string opponent, std::string country, std::string city, std::string stadium,Date date) const;
};

class AlreadyPaid{
    std::string name;
public:
    AlreadyPaid(std::string name): name(name){}
    std::string getName(){return name;}
};

class CompetitionNotFound{
private:
    std::string name;
public:
    CompetitionNotFound(std::string name): name(name) {}
    std::string getName() const{
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
class CompetitionAlreadyExists{
private:
    std::string name;
public:
    CompetitionAlreadyExists(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};


#endif
