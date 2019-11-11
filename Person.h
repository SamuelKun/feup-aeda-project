#ifndef AEDA_PERSON_H
#define AEDA_PERSON_H

#include <string>
#include "Date.h"

//!
/*! Class for a person
 *
 */
class Person {
private:
    std::string name; /*!< Person's name */
	Date birth;  /*!< Person's date of birth */
public:
    Person();

    /// \brief Person Constructor with the following data:
    /// \param name Person's name
    /// \param birth Person's birthday
	Person(std::string name, Date birth);

    /// \brief Get Method
    /// \return Person's name
    std::string getName() const;

    /// \brief Get Method
    /// \return Person's birthdy
	Date getBirthday() const;

	void setName(std::string name);
	void setBirthday(Date birth);

    /// \brief Shows Person's data
	virtual void infoTable() const;
    virtual void info() const;
};

class PersonNotFound{
private:
    std::string name;
public:
    PersonNotFound(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};

class TooManyPeopleFound{
private:
    std::string name;
public:
    TooManyPeopleFound(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};


#endif
