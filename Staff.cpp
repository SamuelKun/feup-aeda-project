#include <string>
#include "Staff.h"

using namespace std;

/// \brief Staff constructor with the following data
/// \param name Staff Member's name
/// \param birth Staff Member's birth
/// \param salario Staff Member's salary
/// \param function Staff Member's function
Staff::Staff(string name, Date birth, int salario, enumFunction function) : Person(name,birth),
salario(salario), function(function){}

/// Get Method
/// \return Staff Member's salary
int Staff::getSalario() const {
    return salario;
}
/// \brief Shows Staff Member's data
void Staff::info() const{
    Person::info();
    cout << "Salário: " << this->salario << endl;
}

