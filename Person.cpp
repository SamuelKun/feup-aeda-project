#include <string>
#include <utility>

#include "Person.h"
#include "Date.h"

using namespace std;

Person::Person() {

}

Person::Person(string name, Date birth) : name(name), birth(birth) {}

string Person::getName() const {return name; }

Date Person::getBirthday() const {return birth; }

void Person::info() const {
    cout << "Name: " << this->name << endl;
    cout << "Birthday: " << this->birth;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setBirthday(Date birth) {
    this->birth = birth;
}


