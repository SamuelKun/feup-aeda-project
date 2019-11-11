#ifndef AEDA_STAFF_H
#define AEDA_STAFF_H

#include <string>
#include "Person.h"

class Staff : public Person
{
private:
    double salary;
    std::string function;
public:
    Staff(std::string name, Date birth, double salary, std::string function);
    double getSalary() const;
    std::string getFunction() const;
    void infoTable() const;
    void info() const;
};

class StaffMemberNotFound{
private:
    std::string name;
public:
    StaffMemberNotFound(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};

class FunctionNotFound{
private:
    std::string function;
public:
    FunctionNotFound(std::string function): function(function) {}
    std::string getFunction() const{
        return function;
    }
};
class StaffMemberAlreadyExists{
private:
    std::string name;
public:
    StaffMemberAlreadyExists(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};

class TooManyStaffFound{
private:
    std::string name;
public:
    TooManyStaffFound(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};


#endif
