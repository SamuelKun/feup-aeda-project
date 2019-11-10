#include "Competition.h"

/// \brief Competition Constructor with the following data:
/// \param convocados Competition's called players vector
/// \param team_games Competition's team games vector
/// \param start Starting date
/// \param end Ending date
Competition::Competition(string name, vector<Player *> called, vector<Game *> team_games, Date start, Date end): name(name), called(called), team_games(team_games),
                                                                                                                 start(start), end(end) {
    paid = false;
}

string Competition::getCompetitionName() const {
    return name;
}

/// \brief Get method
/// \return Called Players
vector<Player *> Competition::getCalled() const {
    return called;
}

/// \brief Get Method
/// \return Vector with played Games
vector<Game *> Competition::getGames() const {
    return team_games;
}

ostream &operator<<(ostream &out, const Competition &comp) {
    out << "Competition name: " << comp.name << endl;
    out << "Number of Games: " << comp.team_games.size() << endl;
    out << "Start Date: " << comp.start << endl;
    out << "End Date: " << comp.end << endl;
    return out;
}

bool Competition::getPaid() const {
    return paid;
}

void Competition::payPlayers() {
    if(!paid) {
        for (auto it = called.begin(); it != called.end(); it++) {
            double value = (*it)->getInsurance() * 30;
            (*it)->setEarnings(value);
        }
        paid = true;
    }
    else throw(AlreadyPaid(name));

}


