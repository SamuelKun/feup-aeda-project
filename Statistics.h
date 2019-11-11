#ifndef AEDA_STATISTICS_H
#define AEDA_STATISTICS_H

/// \brief This class refers to the individual statistics of a player during a match
class Statistics {
private:
    int goals_scored;   /// \brief Number of goals scored
    int goals_conceded;   /// \brief Number of goals scored
    int shots;          /// \brief Number of shots on goal
    int ball_possession;/// \brief Ball possession as percentage
    int yellow_cards;   /// \brief Number of yellow cards received
    int red_cards;      /// \brief Number of red cards received
    int injured;        /// \brief 1 if injured, 0 otherwise
    int free_kicks;     /// \brief Number of free kicks
    int corner_kicks;   /// \brief Number of corners
public:
    Statistics();
    Statistics(int goalsScored, int goalsConceded, int shots, int ballPossession, int yellowCards, int redCards,
               int injured, int freeKicks, int cornerKicks);

    int getGoalsScored() const;
    int getShots() const;
    int getBallPossession() const;
    int getYellowCards() const;
    int getRedCards() const;
    int getInjured() const;
    int getFreeKicks() const;
    int getCornerKicks() const;

    void setGoalsScored(int goalsScored);
    void setShots(int shots);
    void setBallPossession(int ballPossession);
    void setYellowCards(int yellowCards);
    void setRedCards(int redCards);
    void setInjured(int injured);
    void setFreeKicks(int freeKicks);
    void setCornerKicks(int cornerKicks);

    void info() const;

    int getGoalsConceded() const;

    void setGoalsConceded(int goalsConceded);

};

#endif