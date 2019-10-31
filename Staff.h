#pragma once

#include <vector>
#include <string>
#include "Person.h"

using namespace std;

enum enumFunction {coach, coach_secondary, medic};

class Staff : public Person
{
public:
    Staff(string name, Date birth, int salario , enumFunction function);
    void info() const;
    int getSalario() const;
    string getname() const;
private:
    int salario;
    enumFunction function;


};
