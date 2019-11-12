#ifndef AEDA_GAME_H
#define AEDA_GAME_H

#include <string>
#include <vector>

#include "Date.h"
#include "Player.h"
#include "Statistics.h"

/// \brief Class for a Game.
class Game
{
private:
    std::string opponent;
    std::string country; /*!< Game's country */
    std::string city;    /*!< Game's city    */
    std::string stadium; /*!< Game's stadium */
    Date gameDate;  /*!< Game's Date    */
    std::vector<Player *> called_players; /*!< Vector with Game's called players */
    Statistics game_stats; /*!< Game's stats */
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
    /// \brief Get Method.
    /// \return Game's Statistics
    Statistics getStatistics() const;
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
    std::string country; //! country that already exists
    std::string city;    //! city that already exists
    std::string stadium; //! stadium that already exists
    std::string opponent;//! opponent that already exists
    Date d;              //! day that already exists

public:
    /// \brief Class constructor for throwing exception when Game already exists.
    /// \param opponent opponent that already exists
    /// \param country country that already exists
    /// \param city city that already exists
    /// \param stadium stadium that already exists
    /// \param d date that already exists
    GameAlreadyExists(std::string opponent, std::string country, std::string city, std::string stadium, Date d) :
            opponent(opponent),country(country), city(city), stadium(stadium), d(d){}

    /// \brief Get Method.
    /// \return country that already exists
    std::string getCountry() const {return country;}
    /// \brief Get Method.
    /// \return city that already exists
    std::string getCity() const {return city;}
    /// \brief Get Method.
    /// \return stadium that already exists
    std::string getStadium() const {return stadium;}
    /// \brief Get Method.
    /// \return opponent that already exists
    std::string getOpponent() const {return opponent;}
    /// \brief Get Method.
    /// \return date that already exists
    Date getDate() const {return d;}
};

#endif
