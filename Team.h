#ifndef AEDA_TEAM_H
#define AEDA_TEAM_H

#include <vector>

#include "Staff.h"
#include "Player.h"
#include "Game.h"
#include "Competition.h"

class Team {
private:
    std::string teamName;  /// \brief Team file
    std::vector<Player *> team_players; /// \brief Vector with Team's players
    std::vector<Staff *> team_staff; /// \brief Vector with Team's staff
    std::vector<Competition *> team_competitions; /// \brief Vector with Team's competitions

public:
    /**
    * @brief Default constructor
    */
    Team();

    /**
    * @brief Constructor
     * @param file_name file with team information
    */
    Team(std::string file_name);

    /**
    * @brief Getter
    * @return string with team name
    */
    std::string getTeamName() const;
    std::vector<Player *> getPlayers() const;
    std::vector<Staff *> getStaff() const;
    std::vector<Game *> getGames() const;
    std::vector<Competition *> getCompetition() const;
    void addPlayer(Player* p);
    void addStaff(Staff * s);
    void addCompetition(Competition* comp);

    void removePlayer(Player * p);
    void removeStaff(Staff * s);

    double getMoneyPlayers() const;
    double getMoneyStaff() const;
    double getMoneyAccommodation() const;
    int missingPay();

    void showPlayersTable() const;
    void showStaffTable() const;

    void sortPlayersName();
    void sortPlayersPosition();
    void sortPlayersValue();

    void sortStaffName();
    void sortStaffFunction();

    Player * findPlayer(std::string name); // Necessário para ler, alterar depois

    std::vector<Player *> findPlayerName(std::string name);
    std::vector<Staff *> findStaffName(std::string name);

    std::vector<Player *> findPlayerPos(std::string position);
    std::vector<Staff *> findStaffFunction(std::string function);

    std::vector<Competition *> findCompetition(std::string name);
    std::vector<Competition *> findCompetitionDate(Date start, Date end);
};

#endif
