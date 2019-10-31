#include "Game.h"

#include <utility>

//Constructor(s)
Game::Game(const string &country,const string &city,const string &stadium, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees)
:country(country),city(city),stadium(stadium),v_called(v_called),v_played(v_played),v_referees(v_referees){
}

//Get Methods
string Game::getCountry() const {
    return country;
}

string Game::getCity() const {
    return city;
}

string Game::getStadium() const {
    return stadium;
}

vector<Player> Game::getCalled() const {
    return v_called;
}

vector<Player> Game::getPlayed() const {
    return v_played;
}

vector<Person> Game::getReferees() const {
    return v_referees;
}

//Show Methods
void Game::showCountry() const {
    cout << country << endl;
}

void Game::showCity() const {
    cout << city << endl;

}

void Game::showStadium() const {
    cout << stadium << endl;
}

void Game::showCalled() const {
    /*Fazer overload na class player
    for(size_t i = 0; i < v_called.size();i++)
    {
        cout << v_called[i] << endl;
    }
     */
}

void Game::showPlayed() const {
    /*Fazer overload na class player
    for(size_t i = 0; i < v_played.size();i++)
    {
        cout << v_played[i] << endl;
    }
     */
}

void Game::showReferees() const {
    /*Fazer overload na class person
    for(size_t i = 0; i < v_referees.size();i++)
    {
        cout << v_referees[i] << endl;
    }
     */

}

void Game::showStats() const {
    /*Fazer overload na class Stats
    cout << stats;
     */
}

