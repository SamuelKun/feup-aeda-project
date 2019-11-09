#pragma once
#include <iostream>
#include <ostream>

class Statistics{
private:
    int ball_possession;
    int goal_attempts;
    int shots_on_goal;
    int shots_of_goal;
public:
};

/// \brief This class refers to the individual statistics of a player during a match
class Individual_Statistics{
private:
    int goals_scored;  /// \brief Number of goals scored
    int goal_attempts; /// \brief Number of goals attempted
    int shots_on_goal; /// \brief Number of shots on goal
    int shots_off_goal;/// \brief Number of shots off goal
    int minutes_played;/// \brief Number of minutes played
    float km_travelled;/// \brief Number of kilometres travelled
    int yellow_cards;  /// \brief Number of yellow cards received
    int red_cards;     /// \brief Number of red cards received
    int injured;      /// \brief 1 if injured, 0 otherwise
public:
    Individual_Statistics(int gs=0,int ga=0,int son=0,int soff=0,int min=0,float km=0,int yellow = 0,int red=0, int inj=0);

    friend std::ostream &operator<<(std::ostream &os, const Individual_Statistics &statistics);
    int getGoalsScored() const;
    void setGoalsScored(int goalsScored);
    int getGoalAttempts() const;
    void setGoalAttempts(int goalAttempts);
    int getShotsOnGoal() const;
    void setShotsOnGoal(int shotsOnGoal);
    int getShotsOffGoal() const;
    void setShotsOffGoal(int shotsOffGoal);
    int getMinutesPlayed() const;
    void setMinutesPlayed(int minutesPlayed);
    float getKmTravelled() const;
    void setKmTravelled(float kmTravelled);
    int getYellowCards() const;
    void setYellowCards(int yellowCards);
    int getRedCards() const;
    void setRedCards(int redCards);
    int getInjured() const;
    void setInjured(int injured);

};

class Colective_Statistics {
public:
    Colective_Statistics(int goalsScored = 0, int goalAttempts = 0, int shotsOnGoal = 0, int shotsOffGoal = 0, float kmTravelled = 0,
                         int yellowCards = 0, int redCards = 0, int injured = 0);

    int getGoalsScored() const;
    void setGoalsScored(int goalsScored);
    int getGoalAttempts() const;
    void setGoalAttempts(int goalAttempts);
    int getShotsOnGoal() const;
    void setShotsOnGoal(int shotsOnGoal);
    int getShotsOffGoal() const;
    void setShotsOffGoal(int shotsOffGoal);
    float getKmTravelled() const;
    void setKmTravelled(float kmTravelled);
    int getYellowCards() const;
    void setYellowCards(int yellowCards);
    int getRedCards() const;
    void setRedCards(int redCards);
    int getInjured() const;
    void setInjured(int injured);

private:
    int goals_scored;  /// \brief Number of goals scored
    int goal_attempts; /// \brief Number of goals attempted
    int shots_on_goal; /// \brief Number of shots on goal
    int shots_off_goal;/// \brief Number of shots off goal
    float km_travelled;/// \brief Number of kilometres travelled
    int yellow_cards;  /// \brief Number of yellow cards received
    int red_cards;     /// \brief Number of red cards received
    int injured;       /// \brief Number of injuries

public:
};