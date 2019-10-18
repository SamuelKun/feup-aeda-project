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
	vector<string> convocatoria;
	int insurance;
public:
	Player(string name, Date birth, enumPosition pos, string club, int weight, int height, int value, int insurance);
	Player(string name, Date birth, enumPosition pos, string club);
};
