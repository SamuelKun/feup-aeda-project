#include <iostream>
#include "Statistics.h"


Statistics::Statistics(): goals_scored(0), goals_conceded(0), shots(0), ball_possession(0), km_travelled(0), yellow_cards(0), red_cards(0),
                            injured(0), free_kicks(0), corner_kicks(0) {
}


Statistics::Statistics(int goalsScored, int goalsConceded, int shots, int ballPossession, float kmTravelled, int yellowCards, int redCards,int injured, int freeKicks, int cornerKicks) :
    goals_scored(goalsScored), goals_conceded(goalsConceded),
    shots(shots), ball_possession(ballPossession), km_travelled(kmTravelled),
    yellow_cards(yellowCards), red_cards(redCards),
    injured(injured), free_kicks(freeKicks),
    corner_kicks(cornerKicks) {
}

int Statistics::getGoalsScored() const {
    return goals_scored;
}

void Statistics::setGoalsScored(int goalsScored) {
    goals_scored = goalsScored;
}

int Statistics::getGoalsConceded() const {
    return goals_conceded;
}

void Statistics::setGoalsConceded(int goalsConceded) {
    this->goals_conceded = goalsConceded;
}

int Statistics::getShots() const {
    return shots;
}

void Statistics::setShots(int shots) {
    Statistics::shots = shots;
}

int Statistics::getBallPossession() const {
    return ball_possession;
}

void Statistics::setBallPossession(int ballPossession) {
    ball_possession = ballPossession;
}

float Statistics::getKmTravelled() const {
    return km_travelled;
}

void Statistics::setKmTravelled(float kmTravelled) {
    km_travelled = kmTravelled;
}

int Statistics::getYellowCards() const {
    return yellow_cards;
}

void Statistics::setYellowCards(int yellowCards) {
    yellow_cards = yellowCards;
}

int Statistics::getRedCards() const {
    return red_cards;
}

void Statistics::setRedCards(int redCards) {
    red_cards = redCards;
}

int Statistics::getInjured() const {
    return injured;
}

void Statistics::setInjured(int injured) {
    Statistics::injured = injured;
}

int Statistics::getFreeKicks() const {
    return free_kicks;
}

void Statistics::setFreeKicks(int freeKicks) {
    free_kicks = freeKicks;
}

int Statistics::getCornerKicks() const {
    return corner_kicks;
}

void Statistics::setCornerKicks(int cornerKicks) {
    corner_kicks = cornerKicks;
}

void Statistics::info() const {
    cout << "Goal Scored: " << goals_scored << endl;
    cout << "Goal Conceded: " << goals_conceded << endl;
    cout << "Shots: " <<shots << endl;
    cout << "Ball Possession: " <<ball_possession << endl;
    cout << "Km Travelled: " << km_travelled << endl;
    cout << "Yellow Cards: " <<yellow_cards << endl;
    cout << "Red Cards: " << red_cards << endl;
    cout << "Injured Players: " << injured << endl;
    cout << "Free Kicks: " << free_kicks << endl;
    cout << "Corner Kicks: " << corner_kicks << endl;

}
