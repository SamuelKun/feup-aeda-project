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
    vector<Competition *> team_competitions; /// \brief Vector with Team's competitions

public:
    Team();
    Team(string file_name);
    string getTeamName() const;
    vector<Player *> getPlayers() const;
    vector<Staff *> getStaff() const;
    vector<Game *> getGames() const;
    vector<Competition *> getCompetition() const;
    void addPlayer(Player* p);
    void addStaff(Staff * s);

    void removePlayer(Player * p);
    void removeStaff(Staff * s);


    double getMoneyPlayers() const;
    double getMoneyStaff() const;
    int missingPay();

    void showPlayersTable() const;
    void showStaffTable() const;

    void sortPlayersName();
    void sortPlayersPosition();
    void sortPlayersValue();

    void sortStaffName();
    void sortStaffFunction();

    Player * findPlayer(string name); // Necessário para ler, alterar depois

    vector<Player *> findPlayerName(string name);
    vector<Staff *> findStaffName(string name);
    Game * findGame(string country, string city, string stadium); // Colocar como vetor

    vector<Player *> findPlayerPos(string position);
    Competition * findCompetition(string name); // Colocar como vetor
    vector<Staff *> findStaffFunction(string function);
    vector<Competition *> findCompetitionDate(Date start, Date end);

};
/* Esta excecao provavelmente n vai ser necessaria
class TooManyPlayersFound{
    vector<Player *> players;
public:
    TooManyPlayersFound(vector<Player *> players ): players(players){}
    vector<Player *> getPlayers() const {return players;}
};
*/
#endif
