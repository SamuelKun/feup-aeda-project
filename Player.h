#ifndef AEDA_PLAYER_H
#define AEDA_PLAYER_H

#include <string>
#include <ostream>
#include "Person.h"

using namespace std;

/*!
 * Class for a Player
 */
class Player : public Person
{
private:
	string club;     //!*< Player's club.
	string position; //!*< Player's position.
	int weight;      //!*< Player's weight in kg.
	int height;      //!*< Player's height in cm.
	int value;       //!*< Player's value in euros.
    double earnings; //!*< Player's earnings.
    double insurance;//!*< Player's insurance.


public:
    Player();
	Player(string name, Date birth, string club, string position, int weight, int height, int value, double earnings);
	string getClub() const;
    string getPosition() const;
	int getWeight() const;
	int getHeight() const;
	int getValue() const;
	double getEarnings() const;
    double getInsurance() const;

	void setClub(string club);
    void setPosition(string pos);
	void setWeight(int weight);
	void setHeight(int height);
	void setValue(int value);
	void setEarnings(double value);
    void infoTable() const;
    void info() const;

};

class NoPlayersForPos{
private:
    string position;
public:
    NoPlayersForPos(string position): position(position) {}
    string getPosition() const{
        return position;
    }
};

#endif //AEDA_UTILS_H
