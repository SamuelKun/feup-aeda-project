//
// Created by samuel on 30/10/19.
//

#pragma once

#include <vector>
#include "Player.h"
#include "Staff.h"
#include "Game.h"


class Team {
private:
    string teamName;  /// \brief Team file
    vector<Player *> team_players; /// \brief Vector with Team's players
    vector<Staff *> team_staff; /// \brief Vector with Team's staff
    vector<Competion *> team_competions; /// \brief Vector with Team's competitions
public:
    Team();
    Team(string file_name);
    string getTeamName() const;
    vector<Player *> getPlayers() const;
    vector<Staff *> getStaff() const;
    vector<Competion *> getCompetion() const;
};


