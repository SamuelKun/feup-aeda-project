#ifndef AEDA_GAME_H
#define AEDA_GAME_H

#include <string>
#include <vector>

#include "Date.h"
#include "Player.h"
#include "Statistics.h"

class Game
{
private:
    std::string opponent;
    std::string country; /*!< Game's country */
    std::string city;    /*!< Game's city    */
    std::string stadium; /*!< Game's stadium */
    Date gameDate;  /*!< Game's Date    */
    std::vector<Player *> called_players; /*!< Vector with called players */
    Statistics game_stats;
public:
    /// \brief Game Constructor.
    /// \param opponent Game's opponent
    /// \param country Game's country
    /// \param city Game's city
    /// \param stadium Game's stadium
    /// \param gameDate Game's Date
    /// \param called_players Game's called players as a vector of PLayer pointers
    /// \param stats Game's stats
    Game(std::string opponent, std::string country, std::string city, std::string stadium, Date gameDate, std::vector<Player *> called_players, Statistics stats);
    /// \brief Get Method.
    /// \return Game's opponent
    std::string getOpponent() const;
    /// \brief Get Method.
    /// \return Game's country
    std::string getCountry() const;
    /// \brief Get Method.
    /// \return Game's city
    std::string getCity() const;
    /// \brief Get Method.
    /// \return Game's stadium
    std::string getStadium() const;
    /// \brief Get Method.
    /// \return Game's date
    Date getDate() const;
    /// \brief Set Method.
    /// \param stats Game's statistics
    void setStats(Statistics stats);
    /// \brief Get Method.
    /// \return Game's called Players
    std::vector<Player *> getCalledPlayers() const;
    /// \brief Shows Game's info.
    void info() const;

};
/// \brief Class for throwing exception when no such Game is found.
class GameNotFound{
    std::string opponent;
    Date d;

public:
    GameNotFound(std::string opponent, Date date) :
            opponent(opponent), d(date){}

    std::string getOpponent() const {return opponent;}
    Date getDate() const {return d;}

};
/// \brief Class for throwing exception when Game already exists.
class GameAlreadyExists{
    std::string country,city,stadium,opponent;
    Date d;

public:
    GameAlreadyExists(std::string opponent, std::string country, std::string city, std::string stadium, Date d) :
            opponent(opponent),country(country), city(city), stadium(stadium), d(d){}
    std::string getCountry() const {return country;}
    std::string getCity() const {return city;}
    std::string getStadium() const {return stadium;}
    std::string getOpponent() const {return opponent;}
    Date getDate() const {return d;}
};

#endif
