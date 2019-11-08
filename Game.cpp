#include "Game.h"
#include <algorithm>

#include <utility>

//Constructor(s)
Game::Game(string country, string city, string stadium, Date gameDay): country(country), city(city), stadium(stadium),
                                                                                                   gameDate(gameDate) {
}

Game::Game(string country, string city, string stadium, Date gameDay,
        vector<Player *> called_players): country(country), city(city), stadium(stadium), gameDate(gameDate),
                                                                      called_players(called_players) {
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

Date Game::getDate() const {
    return gameDate;
}

vector<Player *> Game::getCalledPlayers() const {
    return called_players;
}


Competion::Competion(vector<Player *> called, vector<Game *> team_games, Date start, Date end): called(called), team_games(team_games), start(start), end(end) {

}

vector<Player *> Competion::getCalled() const {
    return called;
}

vector<Game *> Competion::getGames() const {
    return team_games;
}

