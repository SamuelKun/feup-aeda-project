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
    string teamName;
    vector<Player *> team_players;
    vector<Staff *> team_staff;
    vector<Competion *> team_competions;
public:
    Team();
    Team(string file_name);
    string getTeamName() const;
    vector<Player *> GetPlayers() const;
    vector<Staff *> GetStaff() const;
    vector<Competion *> Competion() const;
};


