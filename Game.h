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
    //vector<Player> v_called;
    //vector<Player> v_played;
    //vector<Person> v_referees;
    //Stats stats;
    //É necessário criar uma classe para as estatisticas todas
public:
    Game(string country,string city, string stadium); //, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees);
    //virtual
    //Get Methods
    string getCountry() const;
    string getCity() const;
    string getStadium() const;
    /*
    vector<Player> getCalled() const;
    vector<Player> getPlayed() const;
    vector<Person> getReferees() const;
    //Stats stats getStats()const;
    */
    //Show Methods
    void showCountry() const;
    void showCity() const;
    void showStadium() const;
    /*
     void showCalled() const;
    void showPlayed() const;
    void showReferees() const;
    void showStats() const;
     */
};

class Competion{
private:
    vector<Player *> convocados;
    vector<Game *> team_games;
    Date start, end;
public:
    Competion(vector<Player *> convocados, vector<Game *> team_games, Date start, Date end);
    vector<Player *> getConvocados() const;
    vector<Game *> getGames() const;
};
