#include <string>
#include <utility>

#include "Person.h"
#include "Date.h"

using namespace std;

//Constructor(s)
/// \brief Person Constructor with the following data:
/// \param name Person's name
/// \param birth Person's birthday
Person::Person(string name, Date birth) : name(name), birth(birth) {}

//Get Methods
/// \brief Get Method
/// \return Person's name
string Person::getName() const {return name; }
/// \brief Get Method
/// \return Person's birthdy
Date Person::getBirthday() const {return birth; }

/// \brief Shows Person's data
void Person::info() const {
    cout << "Name: " << this->name << endl;
    cout << "Birthday: " << this->birth;
}

