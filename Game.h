#pragma once

#include <string>
#include <vector>
#include "Player.h"

using namespace std;

class  Game
{
public:
    Game(string country, string city, string stadium, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees);
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
