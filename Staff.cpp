#include <string>
#include "Staff.h"

using namespace std;

/// \brief Staff constructor with the following data
/// \param name Staff Member's name
/// \param birth Staff Member's birth
/// \param wage Staff Member's wage
/// \param function Staff Member's function
Staff::Staff(string name, Date birth, double salary, string function) : Person(name,birth),
                                                                       salary(salary), function(function){}
/// Get Method
/// \return Staff Member's wage
double Staff::getSalary() const {
    return salary;
}
/// \brief Shows Staff Member's data
void Staff::info() const{
    Person::info();
    cout << "Position: " << this->function << endl;
    cout << "Earnings: " << this->salary << endl;
}



