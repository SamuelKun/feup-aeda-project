#include "Competition.h"

/// \brief Competition Constructor with the following data:
/// \param convocados Competition's called players vector
/// \param team_games Competition's team games vector
/// \param start Starting date
/// \param end Ending date
Competition::Competition(string name, vector<Player *> called, vector<Game *> team_games, Date start, Date end, double moneyAccommodation): name(name), called(called), team_games(team_games),
                                                                                                                 start(start), end(end), moneyAccommodation(moneyAccommodation) {
    this->paid = false;

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
            double value = (*it)->getInsurance() * start.daysUntil(end);
            (*it)->setEarnings(value);
        }
        paid = true;
    }
    else throw(AlreadyPaid(name));

}

Date Competition::getStartDate() const {
    return start;
}

Date Competition::getEndDate() const{
    return end;
}

double Competition::getMoneyAccommodation() const {
    return moneyAccommodation;
}

void Competition::showPlayers() const {
    for(size_t i = 0; i < called.size();i++){
        called[i]->info();
    }
}

void Competition::showGames() const {
    for(size_t i = 0; i < team_games.size();i++){
        team_games[i]->info();
    }
}

void Competition::addGame(Game * g) {
    for(size_t i = 0;i < team_games.size();i++ ){
        if(team_games[i]->getOpponent() == g->getOpponent()&&
           team_games[i]->getCountry() == g->getCountry()&&
           team_games[i]->getCity() == g->getCity()&&
           team_games[i]->getStadium() == g->getStadium()&&
           team_games[i]->getDate().isEqualTo(g->getDate())){
            throw GameAlreadyExists(g->getOpponent(),g->getCountry(),g->getCity(),g->getStadium(),g->getDate());
        }
    }
    team_games.push_back(g);
}


