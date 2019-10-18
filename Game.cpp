#include "Game.h"

#include <utility>

//Constructor(s)
Game::Game(string country, string city, string stadium, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees) {
    this->country = std::move(country);
    this->city = std::move(city);
    this->stadium = std::move(stadium);
    this->v_called = std::move(v_called);
    this->v_played = std::move(v_played);
    this->v_referees= std::move(v_referees);
}

//Get Methods
string Game::GetCountry() const {
    return country;
}

string Game::GetCity() const {
    return city;
}

string Game::GetStadium() const {
    return stadium;
}

vector<Player> Game::GetCalled() const {
    return v_called;
}

vector<Player> Game::GetPlayed() const {
    return v_played;
}

vector<Person> Game::GetReferees() const {
    return v_referees;
}

//Show Methods
void Game::ShowCountry() const {
    cout << country << endl;
}

void Game::ShowCity() const {
    cout << city << endl;

}

void Game::ShowStadium() const {
    cout << stadium << endl;
}

void Game::ShowCalled() const {
    /*Fazer overload na class player
    for(size_t i = 0; i < v_called.size();i++)
    {
        cout << v_called[i] << endl;
    }
     */
}

void Game::ShowPlayed() const {
    /*Fazer overload na class player
    for(size_t i = 0; i < v_played.size();i++)
    {
        cout << v_played[i] << endl;
    }
     */
}

void Game::ShowReferees() const {
    /*Fazer overload na class person
    for(size_t i = 0; i < v_referees.size();i++)
    {
        cout << v_referees[i] << endl;
    }
     */

}

void Game::ShowStats() const {
    /*Fazer overload na class Stats
    cout << stats;
     */
}

