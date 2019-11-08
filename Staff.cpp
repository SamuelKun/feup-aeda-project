#include <string>
#include "Staff.h"

using namespace std;

Staff::Staff(string name, Date birth, double wage, string function) : Person(name,birth),
                                                                       wage(wage), function(function){}

double Staff::getWage() const {
    return wage;
}

void Staff::info() const{
    Person::info();
    cout << "Earnings: " << this->wage << endl;
}



