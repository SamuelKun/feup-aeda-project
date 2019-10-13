#pragma once

#include <vector>
#include <string>
#include "Person.h"

using namespace std;

enum enum_Posicao {GuardaRedes, Defese, Medio ,Avancado};

class Players : public Person
{
private:
	enum_Posicao pos;
	const string club;
	int peso;
	int altura;
	int valor_passe;
	vector<string> convocatorias;
	int seguro;
public:
	;
};
