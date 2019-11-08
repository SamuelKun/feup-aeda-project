#pragma once

#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class Game
{
private:
    string country;
    string city;
    string stadium;
    Date gameDate;
    vector<Player *> called_players;
    //Stats stats;
public:
    Game(string country, string city, string stadium, Date gameDate); //, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees);
    Game(string country, string city, string stadium, Date gameDate, vector<Player *> called_players);
    //Get Methods
    string getCountry() const;
    string getCity() const;
    string getStadium() const;
    Date getDate() const;
    vector<Player *> getCalledPlayers() const;
    //Stats stats getStats()const;
};

class Competion{
private:
    vector<Player *> called;
    vector<Game *> team_games;
    Date start, end;
public:
    Competion(vector<Player *> called, vector<Game *> team_games, Date start, Date end);
    vector<Player *> getCalled() const;
    vector<Game *> getGames() const;
};
