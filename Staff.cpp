#include <string>
#include "Staff.h"

using namespace std;

Staff::Staff(string name, Date birth, int salario, enumFunction function) : Person(name,birth){
    this->salario = salario;
    this->function = function;

}
void Staff::Info() const
{
    cout << "Name: " << Person::showName() << endl;
    cout << "Date ";
    Person::showBirthday();

}

