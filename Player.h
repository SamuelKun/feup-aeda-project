#ifndef AEDA_PLAYER_H
#define AEDA_PLAYER_H

#include <string>
#include "Person.h"

/*!
 * Class for a Player
 */
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
    Player();
	Player(std::string name, Date birth, std::string club, std::string position, int weight, int height, int value, double earnings);
    std::string getClub() const;
    std::string getPosition() const;
	int getWeight() const;
	int getHeight() const;
	int getValue() const;
	double getEarnings() const;
    double getInsurance() const;

	void setClub(std::string club);
    void setPosition(std::string pos);
	void setWeight(int weight);
	void setHeight(int height);
	void setValue(int value);
	void setEarnings(double value);
    void infoTable() const;
    void info() const;

};

class PositionNotFound{
private:
    std::string position;
public:
    PositionNotFound(std::string position): position(position) {}
    std::string getPosition() const{
        return position;
    }
};

class PlayerAlreadyExists{
private:
    std::string name;
public:
    PlayerAlreadyExists(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};

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
