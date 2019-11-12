#ifndef AEDA_PLAYER_H
#define AEDA_PLAYER_H

#include <string>
#include "Person.h"

/// \brief Class for a Player.
class Player : public Person
{
private:
    std::string club;     //!*< Player's club.
    std::string position; //!*< Player's position.
	int weight;      //!*< Player's weight in kg.
	int height;      //!*< Player's height in cm.
	int value;       //!*< Player's value in euros.
    double earnings; //!*< Player's earnings.
    double insurance;//!*< Player's insurance.


public:
    /// \brief Player empty constructor.
    Player();
    /// \brief Player constructor with all parameters
    /// \param name Player's name.
    /// \param birth Player's birthday.
    /// \param club Player's club.
    /// \param position Player's position Goalkeeper/Defender/Midfielder/Forward.
    /// \param weight Player's weight in Kg.
    /// \param height Player's height in cm.
    /// \param value Player's value in euros.
    /// \param earnings Player's in euros.
	Player(std::string name, Date birth, std::string club, std::string position, int weight, int height, int value, double earnings);
	/// \brief GetMethod.
	/// \return Player's club
	std::string getClub() const;
	/// \brief Get Method.
	/// \return Player's position Goalkeeper/Defender/Midfielder/Forward
    std::string getPosition() const;
    /// \brief Get Method.
    /// \return Player's weight in Kg
	int getWeight() const;
	/// \brief Get Method.
	/// \return Player's height in cm
	int getHeight() const;
	/// \brief Get Method.
	/// \return Player's Value in euros
	int getValue() const;
	/// \brief Get Method.
	/// \return Player's earnings in euros
	double getEarnings() const;
	/// \brief Get Method.
	/// \return Player's insurance in euros
    double getInsurance() const;
    /// \brief Set Method.
    /// \param club Player's club
	void setClub(std::string club);
    /// \brief Set Method.
    /// \param pos Player's position
    void setPosition(std::string pos);
    /// \brief Set Method.
    /// \param weight Player's weight in kg
	void setWeight(int weight);
    /// \brief Set Method.
    /// \param height Player's height in cm
	void setHeight(int height);
    /// \brief Set Method.
    /// \param value Player's value in euros
	void setValue(int value);
    /// \brief Set Method.
    /// \param value Player's value in euros
	void setEarnings(double value);
	/// \brief Shows Player's attributes in a table.
    void infoTable() const;
    /// \brief Shows Player's attributes.
    void info() const;

};
/// \brief Class for throwing exceptions when no position is found.
class PositionNotFound{
private:
    std::string position;
public:
    PositionNotFound(std::string position): position(position) {}
    std::string getPosition() const{
        return position;
    }
};
/// \brief Class for throwing exceptions a Player already exists.
class PlayerAlreadyExists{
private:
    std::string name;
public:
    PlayerAlreadyExists(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};
/// \brief Class for throwing exceptions an incorrect Player name is used.
class CantUseThatName{
private:
    std::string name;
public:
    CantUseThatName(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};

#endif //AEDA_UTILS_H
