#pragma once

#include <vector>
#include <string>
#include <map>
#include "Person.h"

using namespace std;

class Staff : public Person
{
private:
    double wage;
    string function;
public:
    Staff(string name, Date birth, double wage, string function);
    double getWage() const;
    void info() const;
};
