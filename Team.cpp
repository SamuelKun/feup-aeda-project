#include "Player.h"
#include "Team.h"
#include "Game.h"
#include <vector>
#include <string>
#include <fstream>
#include "utils.h"


template <class form>
void failInput(form input)
{
    while (cin.fail())
    {
        cin.clear();
        cin.ignore();
        cin.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        cin >> input;
    }
}

/// \brief Constructor
Team::Team() {
}

/// \brief Constructor
/// \param file_name file containing team
Team::Team(string file_name) {
    //Read Agency File
    ifstream info(file_name);
    vector<string> file_info;
    string str_temp;

    while (getline(info, str_temp)) file_info.push_back(str_temp);

    this->teamName = file_info[0];
    this->team_players = read_player(file_info[1]);
    this->team_staff = read_staff(file_info[2]);
    cout << team_players[0] << endl;
    this->team_competions = read_competion(file_info[3], this);
    cout << team_competions[0]->getCalled()[0];
}

/// \brief Get Method
/// \return Team's name
string Team::getTeamName() const {
    return teamName;
}
/// \brief Get Method
/// \return Team's vector with teams players
vector<Player *> Team::getPlayers() const {
    return team_players;
}
/// \brief Get Method
/// \return Team's vector with staff members
vector<Staff *> Team::getStaff() const {
    return team_staff;
}
/// \brief Get Method
/// \return Team's vector with Competitions
vector<Competion *> Team::getCompetion() const {
    return team_competions;
}

vector<Game *> Team::getGame() const {
    return team_games;
}

Player * Team::findPlayer(string name) {
    for (size_t i = 0; i < team_players.size(); i++)
    {
        if (team_players[i]->getName().find(name) != string::npos)
            return team_players[i];
    }
    throw(PlayerNotFound(name));
}

int Team::addPlayer() {
    string n, b, c, pos;
    int wei,hei,val,earn;

    cout << "Write the name of the Player you wish to add: " << endl;
    cout << "0. Return to the Player menu: " << endl;
    getline(cin,n);
    cin.ignore(1000, '\n');
    if(n == "0") return 0;

    cout << "Write " << n << "'s birthday " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> b;
    if(b == "0") return 0;

    cout << "Write " << n << "'s club " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> c;
    if(c == "0") return 0;

    cout << "Write " << n << "'s position " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> pos;
    if(pos == "0") return 0;

    cout << "Write " << n << "'s weight " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> wei;
    failInput(wei);
    if(wei == 0) return 0;

    cout << "Write " << n << "'s height " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> hei;
    failInput(hei);
    if(hei == 0) return 0;

    cout << "Write " << n << "'s value " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> val;
    failInput(val);
    if(val == 0) return 0;

    cout << "Write " << n << "'s earnings " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> earn;
    failInput(earn);
    if(earn == 0) return 0;

    Player *play = new Player(n,b,c,pos,wei,hei,val,earn);
    team_players.push_back(play);
    return 0;
}

int Team::addStaff() {
    string n, b, f;
    double w;

    cout << "Write the name of the Player you wish to add: " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin.ignore(1000, '\n');
    getline(cin,n);
    if( n == "0") return 0;

    cout << "Write " << n << "'s birthday " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> b;
    if( b == "0") return 0;

    cout << "Write " << n << "'s wage " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> w;
    failInput(w);
    if( w == 0) return 0;

    cout << "Write " << n   << "'s function " << endl;
    cout << "0. Return to the Player menu: " << endl;
    cin >> f;
    failInput(f);
    if(f == "0") return 0;

    Staff *s = new Staff(n,b,w,f);
    team_staff.push_back(s);
    return 0;
}
/*
vector<Player *> & Team::findPlayerByPos(string position) {
    vector<Player *> to_return;
    for (size_t i = 0; i < team_players.size(); i++) {
        if (team_players[i]->getPosition() == position) {
            to_return.push_back(team_players[i]);
        }
    }
    if (to_return.empty()) { throw(NoPlayersForPos(position)); }
    else { return to_return; }
}

Staff & Team::findStaff(string name) {
    for (size_t i = 0; i < team_staff.size(); i++)
    {
        if (team_staff[i]->getName().find(name) != string::npos)
            return *team_staff[i];
    }
    throw(StaffNotFound(name));
}

Competion & Team::findCompetion(string name) {
    for (size_t i = 0; i < team_competions.size(); i++)
    {
        if (team_competions[i]->getCompetionName().find(name) != string::npos)
            return *team_competions[i];
    }
    throw(CompetionNotFound(name));
}

vector<Staff *> & Team::findStaffByFunction(string function) {
    vector<Staff *> to_return;
    for (size_t i = 0; i < team_staff.size(); i++) {
        if (team_staff[i]->getFunction() == function) {
            to_return.push_back(team_staff[i]);
        }
    }
    if (to_return.empty()) { throw(NoStaffForFunction(function)); }
    else { return to_return; }
}

vector<Competion *> & Team::findCompetionByDate(Date start, Date end) {
    vector<Competion *> to_return;
    for (size_t i = 0; i < team_competions.size(); i++) {
        if (team_competions[i]->getStartDate() >= start && team_competions[i]->getEndDate() <= end) {
            to_return.push_back(team_competions[i]);
        }
    }
    if (to_return.empty()) { throw(NoCompetionsIn(Date start, Date end)); }
    else { return to_return; }
}
*/