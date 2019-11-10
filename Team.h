#ifndef AEDA_TEAM_H
#define AEDA_TEAM_H

#include <vector>

#include "Staff.h"
#include "Player.h"
#include "Game.h"
#include "Competition.h"

using namespace std;

class Team {
private:
    string teamName;  /// \brief Team file
    vector<Player *> team_players; /// \brief Vector with Team's players
    vector<Staff *> team_staff; /// \brief Vector with Team's staff
    vector<Game *> team_games; /// \brief Vector with Team's Games
    vector<Competition *> team_competitions; /// \brief Vector with Team's competitions

public:
    Team();
    Team(string file_name);

    string getTeamName() const;
    vector<Player *> getPlayers() const;
    vector<Staff *> getStaff() const;
    vector<Game *> getGame() const;
    vector<Competition *> getCompetition() const;
    double getMoneyPlayers() const;
    double getMoneyStaff() const;

    int missingPay();

    Player * findPlayer(string name);
    Staff * findStaff(string name);
    Game * findGame(string country, string city, string stadium );

    int addPlayer();
    int addStaff();

    /*
    vector<Player *> & findPlayerByPos(string position);
    Competition & findCompetion(string name);
    vector<Staff *> & findStaffByFunction(string function);
    vector<Competition *> & findCompetionByDate(Date start, Date end);
    */
};

#endif
