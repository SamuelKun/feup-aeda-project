//
// Created by diogo on 09/11/2019.
//

#include "Competion.h"

/// \brief Competition Constructor with the following data:
/// \param convocados Competition's called players vector
/// \param team_games Competition's team games vector
/// \param start Starting date
/// \param end Ending date
Competion::Competion(string name, vector<Player *> called, vector<Game *> team_games, Date start, Date end): name(name), called(called), team_games(team_games),
                                                                                                             start(start), end(end) {
    for(auto it = called.begin(); it != called.end(); it++)
        (*it)->setEarnings(1000);
}

string Competion::getCompetionName() const {
    return name;
}

/// \brief Get method
/// \return Called Players
vector<Player *> Competion::getCalled() const {
    return called;
}

/// \brief Get Method
/// \return Vector with played Games
vector<Game *> Competion::getGames() const {
    return team_games;
}

ostream &operator<<(ostream &out, const Competion &comp) {
    out << "Competion name: " << comp.name << endl;
    out << "Number of Games: " << comp.team_games.size() << endl;
    out << "Start Date: " << comp.start << endl;
    out << "End Date: " << comp.end << endl;
    return out;
}
