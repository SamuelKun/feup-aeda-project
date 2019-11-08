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
    //! A constructor
    //! \param name creates a person with this name
    //! \param birth that person's birthday
	Person(string name, Date birth);
    //! Get Method
    //! \return person's name
	string getName() const;
	//! Get Method
	//! \return person's birthday
	Date getBirthday() const;
    //! A virtual member
    /*! Shows person's info:
     *  Shows name
     *  Shows birthday
     */
	virtual void info() const;
	//virtual FUNÇÃO DE CADA UM IMPLEMENTAR DEPOIS
};
