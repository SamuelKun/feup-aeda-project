#include <string>
#include <utility>

#include "Person.h"
#include "Date.h"

using namespace std;


//Constructor(s)
Person::Person(string name, Date birth) : name(std::move(name)), birth(birth) {}

//Get Methods
string Person::getName() const {return name; }

Date Person::getBirthday() const {return birth; }

//Show Methods
void Person::showName() const {
    cout << "Name: " << name << endl;
}

void Person::showBirthday() const {
    //cout << "Birth date: " << birth;
}

