#pragma once

#include <vector>
#include <string>
#include "Person.h"

using namespace std;

enum enumPosition
{
	Goalkeeper,
	Defense,
	Midfield,
	Forward
};

class Player : public Person
{
private:
	enumPosition pos;
	string club;
	int weight;
	int height;
	int value;
    int insurance;
	vector<string> convocatoria;

public:
	Player(string name, Date birth, enumPosition pos, string club, int weight, int height, int value, int insurance);
	Player(string name, Date birth, enumPosition pos, string club, int weight, int height, int value);
	enumPosition getPosition() const;
	string getClub() const;
	int getWeight() const;
	int getHeight() const;
	int getValue() const;
	int getInsurance() const;
	vector<string> getConvocatoria() const;
	void setPos(enumPosition pos);
	void setClub(string club);
	void setWeight(int weight);
	void setHeight(int height);
	void setValue(int value);
	void setInsurance(int insurance);
	friend ostream & operator <<(ostream& os,const Person & p);
};
