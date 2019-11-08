#include "Game.h"
#include <algorithm>

#include <utility>

//Constructor(s)
/// \brief Game constructor with the following data:
/// \param country Game's country
/// \param city Game's city
/// \param stadium Game's stadium
/// \param gameDate Game's date
Game::Game(string country, string city, string stadium, Date gameDate): country(country), city(city), stadium(stadium),
                                                                                                   gameDate(gameDate) {
}

Game::Game(string country, string city, string stadium, Date gameDate,
        vector<Player *> called_players): country(country), city(city), stadium(stadium), gameDate(gameDate),
                                                                      called_players(called_players) {
}

//Get Methods
/// \brief Get method
/// \return Game's country
string Game::getCountry() const {
    return country;
}
/// \brief Get method
/// \return Game's city
string Game::getCity() const {
    return city;
}
/// \brief Get method
/// \return Game's stadium
string Game::getStadium() const {
    return stadium;
}

/// \brief Get method
/// \return Game's Date
Date Game::getDate() const {
    return gameDate;
}

/// \brief Get method
/// \return Called Players
vector<Player *> Competion::getCalled() const {
    return called;

/// \brief Competition Constructor with the following data:
/// \param convocados Competition's called players vector
/// \param team_games Competition's team games vector
/// \param start Starting date
/// \param end Ending date
Competion::Competion(vector<Player *> called, vector<Game *> team_games, Date start, Date end): called(called), team_games(team_games), start(start), end(end) {

}
}
/// \brief Get Method
/// \return Vector with played Games
vector<Game *> Competion::getGames() const {
    return team_games;
}

