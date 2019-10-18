#pragma once

#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class  Game
{
public:
    Game(string country, string city, string stadium, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees);

    //Get Methods
    string GetCountry() const;
    string GetCity() const;
    string GetStadium() const;
    vector<Player> GetCalled() const;
    vector<Player> GetPlayed() const;
    vector<Person> GetReferees() const;
    //Stats stats GetStats()const;

    //Show Methods
    void ShowCountry() const;
    void ShowCity() const;
    void ShowStadium() const;
    void ShowCalled() const;
    void ShowPlayed() const;
    void ShowReferees() const;
    void ShowStats() const;


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
