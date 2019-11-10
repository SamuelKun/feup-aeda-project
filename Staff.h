#ifndef AEDA_STAFF_H
#define AEDA_STAFF_H

#include <string>
#include "Person.h"

using namespace std;

class Staff : public Person
{
private:
    double salary;
    string function;
public:
    Staff(string name, Date birth, double salary, string function);
    double getSalary() const;
    void info() const;
};

#endif
