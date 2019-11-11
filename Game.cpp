#include "Game.h"

//Constructor(s)
/// \brief Game constructor with the following data:
/// \param country Game's country
/// \param city Game's city
/// \param stadium Game's stadium
/// \param gameDate Game's date
Game::Game(string opponent, string country, string city, string stadium, Date gameDate): opponent(opponent), country(country), city(city), stadium(stadium),
                                                                                                   gameDate(gameDate) {
}

Game::Game(string opponent, string country, string city, string stadium, Date gameDate,
        vector<Player *> called_players, Statistics stats): opponent(opponent), country(country), city(city), stadium(stadium), gameDate(gameDate),
                                                                      called_players(called_players), game_stats(stats) {
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

void Game::info() const {
    cout << "------------------------------------------------ Game ---------------------------------------------------" <<endl;
    cout << "Opponent: "  << opponent << endl;
    cout << "Country: " << country << endl;
    cout << "City: " <<city << endl;
    cout << "Stadium: " <<stadium << endl;
    cout << "Date: " <<gameDate << endl;
    cout << "--------------------------------------------- Called Players -------------------------------------------" <<endl;
    for (auto it = called_players.begin(); it != called_players.end(); it++){
        (*it)->infoTable();
    }
    cout << "--------------------------------------------- Game Statistics -------------------------------------------" <<endl;
    game_stats.info();
    cout << "---------------------------------------------------------------------------------------------------------" <<endl;
}

string Game::getOpponent() const {
    return opponent;
}

