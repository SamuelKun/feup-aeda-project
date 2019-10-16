#pragma once

#include <vector>
#include <string>
#include "Person.h"

using namespace std;

enum enumPosition
{
	GuardaRedes,
	Defesa,
	Medio,
	Avancado
};

class Player : public Person
{
private:
	enumPosition pos;
	string club;
	int peso;
	int altura;
	int valor_passe;
	vector<string> convocatorias;
	int seguro;
public:
	Player(string name, Date birth, enumPosition pos, string club, int peso, int altura, int valor_passe, int seguro);
	Player(string name, Date birth, enumPosition pos, string club);
};
