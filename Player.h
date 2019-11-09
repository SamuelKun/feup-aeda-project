#pragma once

#include <vector>
#include <string>
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
    int earnings;   //!*< Player's insurance.
    //A calcular -> Nº dias do jogador na seleção * passe * 0.05;

public:
    Player();
	Player(string name, Date birth, string club, string position, int weight, int height, int value, double earnings = 0);
	string getClub() const;
    string getPosition() const;
	int getWeight() const;
	int getHeight() const;
	int getValue() const;
	double getEarnings() const;
	void setClub(string club);
	void setWeight(int weight);
	void setHeight(int height);
	void setValue(int value);
	void setEarnings(double value);
    void info() const;
    bool equalName(Player p) const;
    bool equalPosition(Player p) const;

    bool operator==(const Player &p);

};

class PlayerNotFound{
private:
    string name;
public:
  PlayerNotFound(string name): name(name) {}
  string getName() const{
      return name;
  }
};