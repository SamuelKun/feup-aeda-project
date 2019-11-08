#pragma once

#include <vector>
#include <string>
#include "Person.h"

using namespace std;

enum enumFunction {coach, coach_secondary, medic};

class Staff : public Person
{
private:
    int salario;
    enumFunction function;
public:
    Staff(string name, Date birth, int salario , enumFunction function);
    int getSalario() const;
    void info() const;
};
