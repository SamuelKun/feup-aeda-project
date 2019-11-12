#ifndef AEDA_STATISTICS_H
#define AEDA_STATISTICS_H

/// \brief This class refers to the individual statistics of a player during a match
class Statistics {
private:
    int goals_scored;   //!  Number of goals scored
    int goals_conceded; //!  Number of goals conceded
    int shots;          //!  Number of shots on goal
    int ball_possession;//!  Ball possession as percentage
    int yellow_cards;   //!  Number of yellow cards received
    int red_cards;      //!  Number of red cards received
    int injured;        //!  1 if injured, 0 otherwise
    int free_kicks;     //!  Number of free kicks
    int corner_kicks;   //!  Number of corners
public:
    /// \brief Statistics empty constructor.
    Statistics();
    /// \brief Statistics constructor
    /// \param goalsScored Number of goals scored
    /// \param goalsConceded Number of goals conceded
    /// \param shots  Number of shots on goal
    /// \param ballPossession Ball possession as percentage
    /// \param yellowCards Number of yellow cards received
    /// \param redCards Number of red cards received
    /// \param injured 1 if injured, 0 otherwise
    /// \param freeKicks Number of free kicks
    /// \param cornerKicks Number of corners
    Statistics(int goalsScored, int goalsConceded, int shots, int ballPossession, int yellowCards, int redCards,
               int injured, int freeKicks, int cornerKicks);
    /// \brief Get Method.
    /// \return Number of goals scored
    int getGoalsScored() const;
    /// \brief Get Method.
    /// \return Number of goals conceded
    int getGoalsConceded() const;
    /// \brief Get Method.
    /// \return Number of shots on goal
    int getShots() const;
    /// \brief Get Method.
    /// \return Ball possession as percentage
    int getBallPossession() const;
    /// \brief Get Method.
    /// \return Number of yellow cards received
    int getYellowCards() const;
    /// \brief Get Method.
    /// \return Number of red cards received
    int getRedCards() const;
    /// \brief Get Method.
    /// \return 1 if injured, 0 otherwise
    int getInjured() const;
    /// \brief Get Method.
    /// \return Number of free kicks
    int getFreeKicks() const;
    /// \brief Get Method.
    /// \return Number of corners
    int getCornerKicks() const;

    /// \brief Set Method.
    /// \param goalsScored Number of goals scored
    void setGoalsScored(int goalsScored);
    /// \brief Set Method.
    /// \param goalsConceded Number of goals conceded
    void setGoalsConceded(int goalsConceded);
    /// \brief Set Method.
    /// \param shots Number of shots on goal
    void setShots(int shots);
    /// \brief Set Method.
    /// \param ballPossession Ball possession as percentage
    void setBallPossession(int ballPossession);
    /// \brief Set Method.
    /// \param yellowCards Number of yellow cards received
    void setYellowCards(int yellowCards);
    /// \brief Set Method.
    /// \param redCards Number of red cards received
    void setRedCards(int redCards);
    /// \brief Set Method.
    /// \param injured 1 if injured, 0 otherwise
    void setInjured(int injured);
    /// \brief Set Method.
    /// \param freeKicks Number of free kicks
    void setFreeKicks(int freeKicks);
    /// \brief Set Method.
    /// \param cornerKicks Number of corners
    void setCornerKicks(int cornerKicks);

    /// \brief Shows Statistics
    void info() const;

    /// \brief overload of operator "<<" allowing to write Statistics
    /// \param os
    /// \param statistics
    /// \return
    friend std::ostream& operator<<(std::ostream& os, const Statistics & statistics);
};



#endif