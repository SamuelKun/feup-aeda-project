#pragma once

#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class  Game
{
public:
    Game(const string &country,const string &city, const string &stadium, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees);

    //Get Methods
    string getCountry() const;
    string getCity() const;
    string getStadium() const;
    vector<Player> getCalled() const;
    vector<Player> getPlayed() const;
    vector<Person> getReferees() const;
    //Stats stats getStats()const;

    //Show Methods
    void showCountry() const;
    void showCity() const;
    void showStadium() const;
    void showCalled() const;
    void showPlayed() const;
    void showReferees() const;
    void showStats() const;

    //Sort methods
    void sortByName();


private:
    string country;
    string city;
    string stadium;
    vector<Player> v_called;
    vector<Player> v_played;
    vector<Person> v_referees;
    //Stats stats;
    //É necessário criar uma classe para as estatisticas todas




};
