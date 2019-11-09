#include "Statistics.h"


Statistics::Statistics(int goalsScored, int goalAttempts, int shotsOnGoal, int shotsOffGoal, float kmTravelled,int yellowCards, int redCards, int injured, int freeKicks, int cornerKicks):
        goals_scored(goalsScored),goal_attempts(goalAttempts),shots_on_goal(shotsOnGoal),
        shots_off_goal(shotsOffGoal),km_travelled(kmTravelled),yellow_cards(yellowCards),
        red_cards(redCards),injured(injured),free_kicks(freeKicks),
        corner_kicks(cornerKicks){}
    
int Statistics::getGoalsScored() const {
    return goals_scored;
}

void Statistics::addGoalsScored(int goalsScored) {
    goals_scored += goalsScored;
}

int Statistics::getGoalAttempts() const {
    return goal_attempts;
}

void Statistics::addGoalAttempts(int goalAttempts) {
    goal_attempts += goalAttempts;
}

int Statistics::getShotsOnGoal() const {
    return shots_on_goal;
}

void Statistics::addShotsOnGoal(int shotsOnGoal) {
    shots_on_goal += shotsOnGoal;
}

int Statistics::getShotsOffGoal() const {
    return shots_off_goal;
}

void Statistics::addShotsOffGoal(int shotsOffGoal) {
    shots_off_goal += shotsOffGoal;
}


float Statistics::getKmTravelled() const {
    return km_travelled;
}

void Statistics::addKmTravelled(float kmTravelled) {
    km_travelled += kmTravelled;
}

int Statistics::getYellowCards() const {
    return yellow_cards;
}

void Statistics::addYellowCards(int yellowCards) {
    yellow_cards += yellowCards;
}

int Statistics::getRedCards() const {
    return red_cards;
}

void Statistics::addRedCards(int redCards) {
    red_cards += redCards;
}

int Statistics::getInjured() const {
    return injured;
}

void Statistics::addInjured(int injured) {
    Statistics::injured += injured;
}

int Statistics::getFreeKicks() const {
    return free_kicks;
}

void Statistics::addFreeKicks(int freeKicks) {
    free_kicks += freeKicks;
}


Colective_Statistics::Colective_Statistics(int ballPossession, int goalsScored, int goalAttempts, int shotsOnGoal, int shotsOffGoal,float kmTravelled, int yellowCards, int redCards, int injured, int freeKicks, int cornerKicks):
    Statistics(goalsScored,goalAttempts,shotsOnGoal,shotsOffGoal,kmTravelled,yellowCards,redCards,injured,freeKicks,cornerKicks),
    ball_possession(ballPossession) {}

int Colective_Statistics::getBallPossession() const {
    return ball_possession;
}

void Colective_Statistics::addBallPossession(int ballPossession) {
    ball_possession += ballPossession;
}

void Colective_Statistics::info() const {
    cout << " goals_scored: " << goals_scored << endl;
    cout << " goal_attempts: " << goal_attempts << endl;
    cout << " shots_on_goal: " << shots_on_goal << endl;
    cout << " shots_off_goal: " << shots_off_goal << endl;
    cout << " km_travelled: " << km_travelled << endl;
    cout << " yellow_cards: " << yellow_cards << endl;
    cout << " red_cards: " << red_cards << endl;
    cout << " injured: " << injured << endl;
    cout << " free_kicks: " << free_kicks << endl;
    cout << " corner_kicks: " << corner_kicks << endl;
    cout << " ball_possession: " << ball_possession << endl;
}

Individual_Statistics::Individual_Statistics(int minutesPlayed, int goalsScored, int goalAttempts, int shotsOnGoal,int shotsOffGoal, float kmTravelled, int yellowCards, int redCards, int injured, int freeKicks, int cornerKicks):
    Statistics(goalsScored,goalAttempts,shotsOnGoal,shotsOffGoal,kmTravelled,yellowCards,redCards,injured,freeKicks,cornerKicks),
    minutes_played(minutesPlayed){}

int Individual_Statistics::getMinutesPlayed() const {
    return minutes_played;
}

void Individual_Statistics::addMinutesPlayed(int minutesPlayed) {
    minutes_played += minutesPlayed;
}

void Individual_Statistics::info() const {
    cout << " goals_scored: " << goals_scored << endl;
    cout << " goal_attempts: " << goal_attempts << endl;
    cout << " shots_on_goal: " << shots_on_goal << endl;
    cout << " shots_off_goal: " << shots_off_goal << endl;
    cout << " km_travelled: " << km_travelled << endl;
    cout << " yellow_cards: " << yellow_cards << endl;
    cout << " red_cards: " << red_cards << endl;
    cout << " injured: " << injured << endl;
    cout << " free_kicks: " << free_kicks << endl;
    cout << " corner_kicks: " << corner_kicks << endl;
    cout << " minutes_played: " << minutes_played << endl;
}
