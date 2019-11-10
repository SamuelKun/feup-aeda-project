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
    Person();

    /// \brief Person Constructor with the following data:
    /// \param name Person's name
    /// \param birth Person's birthday
	Person(string name, Date birth);

    /// \brief Get Method
    /// \return Person's name
	string getName() const;

    /// \brief Get Method
    /// \return Person's birthdy
	Date getBirthday() const;

	void setName(string name);
	void setBirthday(Date birth);

    /// \brief Shows Person's data
	virtual void info() const;

	//virtual double earnings() = 0 const;
};

class PersonNotFound{
private:
    string name;
public:
    PersonNotFound(string name): name(name) {}
    string getName() const{
        return name;
    }
};

