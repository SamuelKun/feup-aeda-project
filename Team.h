#ifndef AEDA_TEAM_H
#define AEDA_TEAM_H

#include <vector>

#include "Staff.h"
#include "Player.h"
#include "Game.h"
#include "Competition.h"

/// \brief Class for a Team.
class Team {
private:
    std::string teamName;  //!*< Team file
    std::vector<Player *> team_players; //!*< Vector with Team's players
    std::vector<Staff *> team_staff; //!*< Vector with Team's staff
    std::vector<Competition *> team_competitions; //!*< Vector with Team's competitions

public:
    /// \brief Class Team empty constructor.
    Team();
    /// \brief Team constructor using .txt file
    /// \param file_name label of the .txt file containing a Team
    Team(std::string file_name);

    /// \brief Get Method.
    /// \return Team's name
    std::string getTeamName() const;
    /// \brief Get Method.
    /// \return vector of Team's Players pointers
    std::vector<Player *> getPlayers() const;
    /// \brief Get Method.
    /// \return vector of Team's Staff Members pointers
    std::vector<Staff *> getStaff() const;
    /// \brief Get Method.
    /// \return vector of Team's Games pointers
    std::vector<Game *> getGames() const;
    /// \brief Get Method.
    /// \return vector of Team's Competitions pointers
    std::vector<Competition *> getCompetition() const;
    /// \brief Adds a Player pointer to the vector of Team's Players pointers.
    /// \param p Player pointer to add
    void addPlayer(Player* p);
    /// \brief Adds a Staff Member pointer to the vector of Team's Staff Member pointers.
    /// \param s Staff Member pointer to add
    void addStaff(Staff * s);
    /// \brief Adds a Competition pointer to the vector of Team's Competition pointers.
    /// \param comp Competition pointer to add
    void addCompetition(Competition* comp);
    /// \brief Removes a Player pointer from the vector of Team's Players pointers.
    /// \param p Player pointer to be removed
    void removePlayer(Player * p);
    /// \brief Removes a Staff Member pointer from the vector of Team's Staff Members pointers.
    /// \param s Staff Member pointer to be removed
    void removeStaff(Staff * s);
    /// \brief Get Method.
    /// \return The earnings from all Team's Players
    double getMoneyPlayers() const;
    /// \brief Get Method.
    /// \return The earnings from all Team's Staff Members
    double getMoneyStaff() const;
    /// \brief Get Method.
    /// \return The money accommodation from all the Team's Competitions
    double getMoneyAccommodation() const;
    /// \brief Checks how many Players have not had their insurance paid.
    /// \return The number of Player whose insurance has not been paid
    int missingPay();
    /// \brief Shows Team's Players' info as a Table.
    void showPlayersTable() const;
    /// \brief Shows Team's Players' info.
    void showStaffTable() const;
    /// \brief Sorts team_players by name.
    void sortPlayersName();
    /// \brief Sorts team_players by position.
    void sortPlayersPosition();
    /// \brief Sorts team_players by value
    void sortPlayersValue();
    /// \brief Sorts team_staff by name
    void sortStaffName();
    /// \brief Sorts team_staff by function
    void sortStaffFunction();
    /// \brief Finds a Player in the Team by its name.
    /// \param name Player's name
    /// \return Pointer for Player with the indicated name, throws exception otherwise
    Player * findPlayer(std::string name); // Necessário para ler, alterar depois
    /// \brief Finds all Team PLayers containing name as a substring.
    /// \param name Player's name or substring of name
    /// \return Vector off PLayer Pointers containing name as substring, throws exception otherwise
    std::vector<Player *> findPlayerName(std::string name);
    /// \brief Finds all Staff Members containing name as a substring.
    /// \param name Staff Member's name or substring of name
    /// \return Vector of Staff Member Pointers containing name as substring, throws exception otherwise
    std::vector<Staff *> findStaffName(std::string name);
    /// \brief Finds all Team PLayers that play in this position.
    /// \param position Position of the Players you wish to search
    /// \return Vector with pointers for Players that play in this position
    std::vector<Player *> findPlayerPos(std::string position);
    /// \brief Finds all Staff Members with this function.
    /// \param function Function of the Staff Members you wish to search
    /// \return Vector with pointers for Staff Members with this function
    std::vector<Staff *> findStaffFunction(std::string function);
    /// \brief Finds all competition with this name.
    /// \param name Competition's name
    /// \return Vector with pointers for Competitions with this name
    std::vector<Competition *> findCompetition(std::string name);
    /// \brief Finds all competitions that occur between these 2 dates.
    /// \param start Starting Date
    /// \param end Ending Date
    /// \return Vector with pointers for Competitions between start and end
    std::vector<Competition *> findCompetitionDate(Date start, Date end);
};

#endif
