#pragma once

#include <string>
#include "Date.h"

using namespace std;

class Person {
private:
	string name;
	Date birth;
public:
	Person(string name, Date birth);
};