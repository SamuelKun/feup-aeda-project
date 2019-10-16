#include <string>
#include <utility>
#include "person.h"
#include "Date.h"

using namespace std;

Person::Person(string name, Date birth) : name(std::move(name)), birth(birth) {}

