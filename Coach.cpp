//
// Created by diogo on 22/12/2019.
//

#include "Coach.h"

Coach::Coach(std::string name, Date birth, double titles): Person(name, birth), titles(numTitles) {

}

bool Coach::operator<(const Coach &c1) const {
    return false;
}
