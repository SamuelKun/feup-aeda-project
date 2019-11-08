#include <string>
#include "Staff.h"

using namespace std;

Staff::Staff(string name, Date birth, int salario, enumFunction function) : Person(name,birth),
salario(salario), function(function){}


int Staff::getSalario() const {
    return salario;
}

void Staff::info() const{
    Person::info();
    cout << "Salário: " << this->salario << endl;
}

