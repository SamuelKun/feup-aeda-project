#ifndef AEDA_GAME_H
#define AEDA_GAME_H

#include <string>
#include <vector>

#include "Date.h"
#include "Player.h"
#include "Statistics.h"

class Game
{
private:
    std::string opponent;
    std::string country; /*!< Game's country */
    std::string city;    /*!< Game's city    */
    std::string stadium; /*!< Game's stadium */
    Date gameDate;  /*!< Game's Date    */
    std::vector<Player *> called_players; /*!< Vector with called players */
    Statistics game_stats;
public:
    Game(std::string opponent, std::string country, std::string city, std::string stadium, Date gameDate, std::vector<Player *> called_players, Statistics stats);

    std::string getOpponent() const;
    std::string getCountry() const;
    std::string getCity() const;
    std::string getStadium() const;
    Date getDate() const;
    void setStats(Statistics stats);
    std::vector<Player *> getCalledPlayers() const;
    void info() const;

};
class GameNotFound{
    std::string country,city,stadium,opponent;
    Date d;

public:
    GameNotFound(std::string country, std::string city, std::string stadium) :
            country(country), city(city), stadium(stadium){}

    GameNotFound(std::string opponent, std::string country, std::string city, std::string stadium, Date date) :
    opponent(opponent),country(country), city(city),
    stadium(stadium),d(date){}

    std::string getOpponent() const {return opponent;}
    std::string getCountry() const {return country;}
    std::string getCity() const {return city;}
    std::string getStadium() const {return stadium;}
    Date getDate() const {return d;}

};

class GameAlreadyExists{
    std::string country,city,stadium,opponent;
    Date d;

public:
    GameAlreadyExists(std::string opponent, std::string country, std::string city, std::string stadium, Date d) :
            opponent(opponent),country(country), city(city), stadium(stadium), d(d){}
    std::string getCountry() const {return country;}
    std::string getCity() const {return city;}
    std::string getStadium() const {return stadium;}
    std::string getOpponent() const {return opponent;}
    Date getDate() const {return d;}
};

#endif
