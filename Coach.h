//
// Created by diogo on 22/12/2019.
//

#ifndef COACH_H
#define COACH_H

#include <string>
#include "Date.h"
#include "Person.h"

class Coach : public Person {
private:
    double numTitles;
public:
    Coach(std::string name, Date birth, double titles);
    bool operator < (const Coach &c1) const;
};


#endif
