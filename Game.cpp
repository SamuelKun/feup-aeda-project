#include "Game.h"
#include <algorithm>

#include <utility>



bool cmpName( const Person &p1, const Person & p2)
{
    return p1.getName() > p2.getName();
}



//Constructor(s)
Game::Game(string country, string city, string stadium): country(country), city(city), stadium(stadium) {

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


Competion::Competion(vector<Player *> convocados, vector<Game *> team_games, Date start, Date end): convocados(convocados), start(start), end(end) {

}

vector<Player *> Competion::getConvocados() const {
    return convocados;
}

vector<Game *> Competion::getGames() const {
    return team_games;
}
