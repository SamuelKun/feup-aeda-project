#include <string>
#include <utility>

#include "Person.h"
#include "Date.h"

using namespace std;

//Constructor(s)
Person::Person(string name, Date birth) : name(name), birth(birth) {}

//Get Methods
string Person::getName() const {return name; }

Date Person::getBirthday() const {return birth; }


