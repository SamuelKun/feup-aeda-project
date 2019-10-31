//
// Created by samuel on 30/10/19.
//

#pragma once

#include <vector>
#include "Player.h"


class Team {
private:
    vector<Player> players;
    string teamName;
public:
    Team();
    Team(string file_name);
    vector<Player> GetPlayers() const;

    void sortByPosition();
    void sortByName();

};


