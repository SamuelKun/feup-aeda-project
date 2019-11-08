#pragma once

#include <string>
#include "Date.h"

using namespace std;

//!
/*! Class for a person
 *
 */
class Person {
private:
	string name; /*!< Person's name */
	Date birth;  /*!< Person's date of birth */
public:
	Person(string name, Date birth);
	string getName() const;
	Date getBirthday() const;
	virtual void info() const;
	//virtual double earnings() = 0 const;
};
