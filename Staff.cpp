#include <string>
#include "Staff.h"
#include <iomanip>

using namespace std;


Staff::Staff(string name, Date birth, double salary, string function) : Person(name,birth),
                                                                       salary(salary), function(function){}
double Staff::getSalary() const {
    return salary;
}
string Staff::getFunction() const {
    return function;
}

void Staff::infoTable() const {
    Person::infoTable();
    cout << setw(12) << this->function << " | " << setw(9) << this->salary << " | " << endl;
}

void Staff::info() const{
    Person::info();
    cout << "Position: " << this->function << endl;
    cout << "Earnings: " << this->salary << endl;
}

std::ostream &operator<<(std::ostream &out, const Staff &s) {
    out << s.getName() << endl;
    out << s.getBirthday() << endl;
    out << s.salary << endl;
    out << s.function;

    return out;
}

void Staff::setSalary(double salary) {
    this->salary = salary;
}

void Staff::setFunction(std::string function){

    this->function = function;
}
