#include "Game.h"

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

vector<Player *> Game::getCalledPlayers() const {
    return called_players;
}
