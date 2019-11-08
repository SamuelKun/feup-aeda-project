#include <string>
#include "Staff.h"

using namespace std;

Staff::Staff(string name, Date birth, int salario, enumFunction function) : Person(name,birth),
salario(salario), function(function){}


int Staff::getSalario() const {
    return salario;
}

string Staff::getname() const {
    return Person::getName();
}

void Staff::info() const{
    cout << "Name: " << getName() << endl;
    cout << "Birthday: " << getBirthday() << endl;
}

