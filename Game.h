#ifndef AEDA_GAME_H
#define AEDA_GAME_H

#include <string>
#include <vector>
#include <ostream>
#include "Player.h"

using namespace std;

class Game
{
private:
    string country; /*!< Game's country */
    string city;    /*!< Game's city    */
    string stadium; /*!< Game's stadium */
    Date gameDate;  /*!< Game's Date    */
    vector<Player *> called_players; /*!< Vector with called players */
    //Stats stats;
public:
    Game(string country, string city, string stadium, Date gameDate);
    Game(string country, string city, string stadium, Date gameDate, vector<Player *> called_players);

    void info() const ;
    string getCountry() const;
    string getCity() const;
    string getStadium() const;
    Date getDate() const;
    vector<Player *> getCalledPlayers() const;

    //Stats stats getStats()const;
};
class CountryNotFound{
    string country;
    CountryNotFound(string country) : country(country){}

public:
    string getCountry() const {return country;}
};

class StadiumNotFound{
    string stadium;
    StadiumNotFound(string stadium) : stadium(stadium){}

public:
    string getStadium() const {return stadium;}
};

class CityNotFound{
    string city;
    CityNotFound(string city) : city(city){}

public:
    string getCity() const {return city;}
};
#endif
