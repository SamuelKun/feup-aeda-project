#include <string>
#include <utility>

#include "Person.h"
#include "Date.h"

using namespace std;

Person::Person(string name, Date birth) : name(std::move(name)), birth(birth) {}

string Person::showName() {return name; }

Date Person::showBirthday() {return birth; }

