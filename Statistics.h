#pragma once
#include <iostream>
#include <ostream>

using namespace std;

/// \brief This class refers to the individual statistics of a player during a match
class Statistics {
protected:
    int goals_scored;  /// \brief Number of goals scored
    int goal_attempts; /// \brief Number of goals attempted
    int shots_on_goal; /// \brief Number of shots on goal
    int shots_off_goal;/// \brief Number of shots off goal
    float km_travelled;/// \brief Number of kilometres travelled
    int yellow_cards;  /// \brief Number of yellow cards received
    int red_cards;     /// \brief Number of red cards received
    int injured;       /// \brief 1 if injured, 0 otherwise
    int free_kicks;    /// \brief Number of free kicks
    int corner_kicks;  /// \brief Number of corners
public:
    explicit Statistics(int goalsScored = 0, int goalAttempts = 0, int shotsOnGoal = 0, int shotsOffGoal = 0, float kmTravelled = 0,
               int yellowCards = 0, int redCards = 0, int injured = 0, int freeKicks = 0, int cornerKicks = 0);
    virtual void info() const = 0;
    int getGoalsScored() const;
    void addGoalsScored(int goalsScored);
    int getGoalAttempts() const;
    void addGoalAttempts(int goalAttempts);
    int getShotsOnGoal() const;
    void addShotsOnGoal(int shotsOnGoal);
    int getShotsOffGoal() const;
    void addShotsOffGoal(int shotsOffGoal);
    float getKmTravelled() const;
    void addKmTravelled(float kmTravelled);
    int getYellowCards() const;
    void addYellowCards(int yellowCards);
    int getRedCards() const;
    void addRedCards(int redCards);
    int getInjured() const;
    void addInjured(int injured);
    int getFreeKicks() const;
    void addFreeKicks(int freeKicks);

};
/// \brief This class refers to the game statistics of a Player
class Individual_Statistics : public Statistics{
private:
    int minutes_played; /// \brief Number of minutes played
public:
    Individual_Statistics(int minutesPlayed = 0, int goalsScored = 0, int goalAttempts = 0, int shotsOnGoal = 0, int shotsOffGoal = 0, float kmTravelled = 0,
                          int yellowCards = 0, int redCards = 0, int injured = 0, int freeKicks = 0, int cornerKicks = 0);
    void info() const;
    int getMinutesPlayed() const;
    void addMinutesPlayed(int minutesPlayed);

};
/// \brief This classrefers to the game statistics of a Team
class Colective_Statistics : public Statistics {
private:
    int ball_possession;/// \brief Ball possession as percentage

public:
    Colective_Statistics(int ballPossession = 0, int goalsScored = 0, int goalAttempts = 0, int shotsOnGoal = 0, int shotsOffGoal = 0, float kmTravelled = 0,
                         int yellowCards = 0, int redCards = 0, int injured = 0, int freeKicks = 0, int cornerKicks = 0);
    void info() const;
    int getBallPossession() const;
    void addBallPossession(int ballPossession);

};