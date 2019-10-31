#include <string>
#include "Staff.h"

using namespace std;

Staff::Staff(string name, Date birth, int salario, enumFunction function) : Person(name,birth),
salario(salario), function(function){}

void Staff::info() const
{
    //Person::showName();
    //Person::showBirthday();
    cout << endl << salario << endl;

}

int Staff::getSalario() const {
    return salario;
}

string Staff::getname() const {
    return Person::getName();
}

