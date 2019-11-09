//
// Created by samuel on 30/10/19.
//

#pragma once

#include <vector>
#include "Player.h"
#include "Staff.h"
#include "Game.h"
#include "Competion.h"


class Team {
private:
    string teamName;  /// \brief Team file
    vector<Player *> team_players; /// \brief Vector with Team's players
    vector<Staff *> team_staff; /// \brief Vector with Team's staff
    vector<Game *> team_games;
    vector<Competion *> team_competions; /// \brief Vector with Team's competitions

public:
    Team();
    Team(string file_name);
    string getTeamName() const;
    vector<Player *> getPlayers() const;
    vector<Staff *> getStaff() const;
    vector<Game *> getGame() const;
    vector<Competion *> getCompetion() const;
    double getMoneyPlayers() const;
    double getMoneyStaff() const;
    Player * findPlayer(string name);
    vector<Player *> & findPlayerByPos(string position);
    Staff & findStaff(string name);
    Competion & findCompetion(string name);
    vector<Staff *> & findStaffByFunction(string function);
    vector<Competion *> & findCompetionByDate(Date start, Date end);

    int addPlayer();
    int addStaff();
};


