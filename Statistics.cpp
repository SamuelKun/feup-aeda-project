#include "Statistics.h"
#include <iostream>


std::ostream &operator<<(std::ostream &os, const Individual_Statistics &statistics) {
    os << "goals_scored: " << statistics.goals_scored << " goal_attempts: " << statistics.goal_attempts
       << " shots_on_goal: " << statistics.shots_on_goal << " shots_off_goal: " << statistics.shots_off_goal
       << " minutes_played: " << statistics.minutes_played << " km_travelled: " << statistics.km_travelled
       << " yellow_cards: " << statistics.yellow_cards << " red_cards: " << statistics.red_cards << " injured: "
       << statistics.injured;
    return os;
}

Individual_Statistics::Individual_Statistics(int gs, int ga, int son, int soff, int min, float km, int yellow, int red, int inj, int free_kicks, int cornerKicks):
    goals_scored(gs),goal_attempts(ga),shots_on_goal(son),
    shots_off_goal(soff), minutes_played(min), km_travelled(km),
    yellow_cards(yellow), red_cards(red), injured(inj),
    free_kicks(free_kicks), corner_kicks(cornerKicks) {}

int Individual_Statistics::getGoalsScored() const {
    return goals_scored;
}

void Individual_Statistics::setGoalsScored(int goalsScored) {
    goals_scored = goalsScored;
}

int Individual_Statistics::getGoalAttempts() const {
    return goal_attempts;
}

void Individual_Statistics::setGoalAttempts(int goalAttempts) {
    goal_attempts = goalAttempts;
}

int Individual_Statistics::getShotsOnGoal() const {
    return shots_on_goal;
}

void Individual_Statistics::setShotsOnGoal(int shotsOnGoal) {
    shots_on_goal = shotsOnGoal;
}

int Individual_Statistics::getShotsOffGoal() const {
    return shots_off_goal;
}

void Individual_Statistics::setShotsOffGoal(int shotsOffGoal) {
    shots_off_goal = shotsOffGoal;
}

int Individual_Statistics::getMinutesPlayed() const {
    return minutes_played;
}

void Individual_Statistics::setMinutesPlayed(int minutesPlayed) {
    minutes_played = minutesPlayed;
}

float Individual_Statistics::getKmTravelled() const {
    return km_travelled;
}

void Individual_Statistics::setKmTravelled(float kmTravelled) {
    km_travelled = kmTravelled;
}

int Individual_Statistics::getYellowCards() const {
    return yellow_cards;
}

void Individual_Statistics::setYellowCards(int yellowCards) {
    yellow_cards = yellowCards;
}

int Individual_Statistics::getRedCards() const {
    return red_cards;
}

void Individual_Statistics::setRedCards(int redCards) {
    red_cards = redCards;
}

int Individual_Statistics::getInjured() const {
    return injured;
}

void Individual_Statistics::setInjured(int injured) {
    Individual_Statistics::injured = injured;
}

int Individual_Statistics::getFreeKicks() const {
    return free_kicks;
}

void Individual_Statistics::setFreeKicks(int freeKicks) {
    free_kicks = freeKicks;
}


Colective_Statistics::Colective_Statistics(int ball_possession, int goalsScored, int goalAttempts, int shotsOnGoal, int shotsOffGoal,float kmTravelled, int yellowCards, int redCards, int injured, int freeKicks, int cornerKicks):
    goals_scored(goalsScored), goal_attempts(goalAttempts),
    shots_on_goal(shotsOnGoal), ball_possession(ball_possession),
    shots_off_goal(shotsOffGoal), km_travelled(kmTravelled),
    yellow_cards(yellowCards), red_cards(redCards),
    injured(injured), free_kicks(freeKicks),
    corner_kicks(cornerKicks){}

int Colective_Statistics::getGoalsScored() const {
    return goals_scored;
}

void Colective_Statistics::setGoalsScored(int goalsScored) {
    goals_scored = goalsScored;
}

int Colective_Statistics::getGoalAttempts() const {
    return goal_attempts;
}

void Colective_Statistics::setGoalAttempts(int goalAttempts) {
    goal_attempts = goalAttempts;
}

int Colective_Statistics::getShotsOnGoal() const {
    return shots_on_goal;
}

void Colective_Statistics::setShotsOnGoal(int shotsOnGoal) {
    shots_on_goal = shotsOnGoal;
}

int Colective_Statistics::getShotsOffGoal() const {
    return shots_off_goal;
}

void Colective_Statistics::setShotsOffGoal(int shotsOffGoal) {
    shots_off_goal = shotsOffGoal;
}

float Colective_Statistics::getKmTravelled() const {
    return km_travelled;
}

void Colective_Statistics::setKmTravelled(float kmTravelled) {
    km_travelled = kmTravelled;
}

int Colective_Statistics::getYellowCards() const {
    return yellow_cards;
}

void Colective_Statistics::setYellowCards(int yellowCards) {
    yellow_cards = yellowCards;
}

int Colective_Statistics::getRedCards() const {
    return red_cards;
}

void Colective_Statistics::setRedCards(int redCards) {
    red_cards = redCards;
}

int Colective_Statistics::getInjured() const {
    return injured;
}

void Colective_Statistics::setInjured(int injured) {
    Colective_Statistics::injured = injured;
}

void Colective_Statistics::addGoalsScored(int goalsScored) {
    goals_scored += goalsScored;
}

void Colective_Statistics::addGoalAttempts(int goalAttempts) {
    goal_attempts += goalAttempts;
}

void Colective_Statistics::addShotsOnGoal(int shotsOnGoal) {
    shots_on_goal += shotsOnGoal;
}

void Colective_Statistics::addShotsOffGoal(int shotsOffGoal) {
    shots_off_goal += shotsOffGoal;
}

void Colective_Statistics::addKmTravelled(float kmTravelled) {
    km_travelled += kmTravelled;
}

void Colective_Statistics::addYellowCards(int yellowCards) {
    yellow_cards += yellowCards;
}

void Colective_Statistics::addRedCards(int redCards) {
    red_cards += redCards;
}

void Colective_Statistics::addInjured(int injured) {

}

int Colective_Statistics::getBallPossession() const {
    return ball_possession;
}

void Colective_Statistics::setBallPossession(int ballPossession) {
    ball_possession = ballPossession;
}

int Colective_Statistics::getFreeKicks() const {
    return free_kicks;
}

void Colective_Statistics::setFreeKicks(int freeKicks) {
    free_kicks = freeKicks;
}

int Colective_Statistics::getCornerKicks() const {
    return corner_kicks;
}

void Colective_Statistics::setCornerKicks(int cornerKicks) {
    corner_kicks = cornerKicks;
}

void Colective_Statistics::addBallPossession(int ballPossession) {
    ball_possession += ballPossession;
}

void Colective_Statistics::addFreeKicks(int freeKicks) {
    free_kicks += freeKicks;
}

void Colective_Statistics::addCornerKicks(int cornerKicks) {
    corner_kicks += cornerKicks;
}
