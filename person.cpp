#include <string>
#include <utility>
#include "person.h"

using namespace std;

Person::Person(string name, int day, int month, int year) : name(std::move(name)), bday(day), bmonth(month), byear(year) {}

