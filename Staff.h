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
    string getFunction() const;
    void infoTable() const;
    void info() const;
};



class FunctionNotFound{
private:
    string function;
public:
    FunctionNotFound(string function): function(function) {}
    string getFunction() const{
        return function;
    }
};
class StaffMemberAlreadyExists{
private:
    string name;
public:
    StaffMemberAlreadyExists(string name): name(name) {}
    string getName() const{
        return name;
    }
};


#endif
