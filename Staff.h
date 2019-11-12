#ifndef AEDA_STAFF_H
#define AEDA_STAFF_H

#include <string>
#include "Person.h"

/// \brief Class for a Staff.
class Staff : public Person
{
private:
    double salary;       //!*< Staff's salary
    std::string function;//!*< Staff's function
public:
    /// \brief Staff Constructor.
    /// \param name Staff's name
    /// \param birth Staff's birthday
    /// \param salary Staff's salary in euros
    /// \param function Staff's function
    Staff(std::string name, Date birth, double salary, std::string function);
    /// \brief Get Method.
    /// \return Staff's salary in euros
    double getSalary() const;
    /// \brief Get Method.
    /// \return Staff's function
    std::string getFunction() const;
    /// \brief Shows Staff's info as a table.
    void infoTable() const;
    /// \brief Shows Staff's info.
    void info() const;
};

/// \brief Class for throwing exception when no Staff Member with such name was found.
class StaffMemberNotFound{
private:
    std::string name;
public:
    StaffMemberNotFound(std::string name): name(name) {}
    std::string getName() const{
        return name;
    }
};
/// \brief Class for throwing exception when no Staff Member with such function was found.
class FunctionNotFound{
private:
    std::string function; //! function that doesn't exist
public:
    /// \brief Class constructor for throwing exception when no Staff Member with such function was found.
    /// \param function function that doesn't exist
    FunctionNotFound(std::string function): function(function) {}
    /// \brief Get Method
    /// \return function that doesn't exist
    std::string getFunction() const{
        return function;
    }
};
/// \brief Class for throwing exception when a Staff Member with this name already exists.
class StaffMemberAlreadyExists{
private:
    std::string name; //! Name of the Staff that already exists
public:
    /// \brief Class constructor for throwing exception when a Staff Member with this name already exists.
    /// \param name Name of the Staff that already exists
    StaffMemberAlreadyExists(std::string name): name(name) {}
    /// \brief Get Method.
    /// \return Name of the Staff that already exists
    std::string getName() const{
        return name;
    }
};
/// \brief Class for throwing exception when too many Staff Members were found.
class TooManyStaffFound{
private:
    std::string name; //! Name of the Staff that wasn't found
public:
    /// \brief Class constructor for throwing exception when too many Staff Members were found.
    /// \param name Name of the Staff that wasn't found
    TooManyStaffFound(std::string name): name(name) {}
    /// \brief Get Method
    /// \return Name of the Staff that wasn't found
    std::string getName() const{
        return name;
    }
};


#endif
