#ifndef AEDA_STATISTICS_H
#define AEDA_STATISTICS_H

using namespace std;

/// \brief This class refers to the individual statistics of a player during a match
class Statistics {
public:
    Statistics(int goalsScored = 0, int shots = 0, int ballPossession = 0, float kmTravelled = 0, int yellowCards = 0, int redCards = 0,
               int injured = 0, int freeKicks = 0, int cornerKicks = 0);

    int getGoalsScored() const;
    void setGoalsScored(int goalsScored);
    int getShots() const;
    void setShots(int shots);
    int getBallPossession() const;
    void setBallPossession(int ballPossession);
    float getKmTravelled() const;
    void setKmTravelled(float kmTravelled);
    int getYellowCards() const;
    void setYellowCards(int yellowCards);
    int getRedCards() const;
    void setRedCards(int redCards);
    int getInjured() const;
    void setInjured(int injured);
    int getFreeKicks() const;
    void setFreeKicks(int freeKicks);
    int getCornerKicks() const;
    void setCornerKicks(int cornerKicks);

protected:
    int goals_scored;   /// \brief Number of goals scored
    int shots;          /// \brief Number of shots on goal
    int ball_possession;/// \brief Ball possession as percentage
    float km_travelled; /// \brief Number of kilometres travelled
    int yellow_cards;   /// \brief Number of yellow cards received
    int red_cards;      /// \brief Number of red cards received
    int injured;        /// \brief 1 if injured, 0 otherwise
    int free_kicks;     /// \brief Number of free kicks
    int corner_kicks;   /// \brief Number of corners
public:

};

#endif