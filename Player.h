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
	string club; //!*< Player's club.
	int weight;  //!*< Player's weight.
	int height;  //!*< Player's height.
	int value;   //!*< Player's value.
    int insurance; //!*< Player's insurance.
    //A calcular -> Nº dias do jogador na seleção * passe * 0.05;

public:
	Player(string name, Date birth, string club, int weight, int height, int value, int insurance = 0);
	string getClub() const;
	//string pos; ARRANJAR MANEIRA DE FAZER ISTO DEPOIS
	int getWeight() const;
	int getHeight() const;
	int getValue() const;
	int getInsurance() const;
	void setClub(string club);
	void setWeight(int weight);
	void setHeight(int height);
	void setValue(int value);
	void setInsurance(int insurance);
    void info() const;
	/*
	bool operator <(const Player &p);
	friend ostream & operator <<(ostream& os,const Player & p);
	 */
};
