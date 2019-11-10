#ifndef AEDA_STATISTICS_H
#define AEDA_STATISTICS_H

using namespace std;

/// \brief This class refers to the individual statistics of a player during a match
class Statistics {
protected:
    int goals_scored;  /// \brief Number of goals scored
    int shots;         /// \brief Number of shots on goal
    int ball_possession;/// \brief Ball possession as percentage
    int yellow_cards;  /// \brief Number of yellow cards received
    int red_cards;     /// \brief Number of red cards received
    int injured;       /// \brief 1 if injured, 0 otherwise
    int free_kicks;    /// \brief Number of free kicks
    int corner_kicks;  /// \brief Number of corners
public:
    Statistics( );
    int getGoalsScored() const;
    int getShots() const;
    float getKmTravelled() const;
    int getYellowCards() const;
    int getRedCards() const;
    int getInjured() const;
    int getFreeKicks() const;

    void setGoalsScored(int goalsScored);
    void setShots(int goalAttempts);
    void setKmTravelled(float kmTravelled);
    void setYellowCards(int yellowCards);
    void setRedCards(int redCards);
    void setInjured(int injured);
    void setFreeKicks(int freeKicks);
};

#endif