#pragma once

#include <string>
#include "Date.h"

using namespace std;

class Person {
private:
	string name;
	Date birth;
public:
	Person(string name, Date birth);
	string showName() const;
	Date showBirthday() const;
    //virtual void info() const = 0;
};
