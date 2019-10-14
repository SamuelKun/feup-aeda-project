#pragma once

#include <string>

using namespace std;

class Person {
private:
	string name;
	int bday;
	int bmonth;
	int byear; 
public:
	Person(string name, int bday, int bmonth, int byear);
};
