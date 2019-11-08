#include "Game.h"
#include <algorithm>

#include <utility>



bool cmpName( const Person &p1, const Person & p2)
{
    return p1.getName() > p2.getName();
}



//Constructor(s)
/// \brief Game constructor with the following data:
/// \param country Game's country
/// \param city Game's city
/// \param stadium Game's stadium
Game::Game(string country, string city, string stadium): country(country), city(city), stadium(stadium) {

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

//Show Methods
/// \brief shows Game's country
void Game::showCountry() const {
    cout << country << endl;
}
/// \brief shows Game's city
void Game::showCity() const {
    cout << city << endl;

}
/// \brief shows Game's stadium
void Game::showStadium() const {
    cout << stadium << endl;
}

/// \brief Competition Constructor with the following data:
/// \param convocados Competition's called players vector
/// \param team_games Competition's team games vector
/// \param start Starting date
/// \param end Ending date
Competion::Competion(vector<Player *> convocados, vector<Game *> team_games, Date start, Date end): convocados(convocados), start(start), end(end) {

}
/// \brief Get Method
/// \return Vector with called players
vector<Player *> Competion::getConvocados() const {
    return convocados;
}
/// \brief Get Method
/// \return Vector with played Games
vector<Game *> Competion::getGames() const {
    return team_games;
}
