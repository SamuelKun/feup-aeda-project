#include "Game.h"

#include <utility>

Game::Game(string country, string city, string stadium, vector<Player> v_called, vector<Player> v_played, vector<Person> v_referees) {
    this->country = std::move(country);
    this->city = std::move(city);
    this->stadium = std::move(stadium);
    this->v_called = std::move(v_called);
    this->v_played = std::move(v_played);
    this->v_referees= std::move(v_referees);
}
