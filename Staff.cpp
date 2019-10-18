#include <string>
#include "Staff.h"

using namespace std;

Staff::Staff(string name, Date birth, int salario, enumFunction function) : Person(name,birth){
    this->salario = salario;
    this->function = function;

}
void Staff::Info() const
{
    //Person::showName();
    //Person::showBirthday();
    cout << endl << salario << endl;

}

int Staff::GetSalario() const {
    return salario;
}

string Staff::Getname() const {
    return Person::getName();
}

