//
// Created by diogo on 16/10/2019.
//

#include "Date.h"
#include <fstream>
#include <sstream>

using namespace std;

/// \brief Date empty constructor
Date::Date()
{
}
/// \brief Date constructor
/// \param date Date string in the format YYYY / MM / DD
Date::Date(string date)
{

    stringstream date_info(date);
    string temp;
    vector<string> date_temp;

    while (getline(date_info, temp, '/'))
    {
        date_temp.push_back(temp);
    }

    year = stoi(date_temp[0]);
    month = stoi(date_temp[1]);
    day = stoi(date_temp[2]);
}

/// \brief Date constructor using ints
/// \param day Date's day
/// \param month Date's month
/// \param year Date's year
Date::Date(unsigned short day, unsigned short month, unsigned year):day(day), month(month), year(year){}

/*********************************
 * GET Methods
 ********************************/
 /// \brief Get Method
 /// \return Date's day
unsigned short Date::getDay() const
{
    return day;
}

/// \brief Get Method
/// \return Date's month
unsigned short Date::getMonth() const
{
    return month;
}
/// \brief Get Method
/// \return Date's year
unsigned Date::getYear() const
{
    return year;
}

/*********************************
 * SET Methods
 ********************************/
/// \brief Set Method
/// \param day Date's day
void Date::setDay(unsigned short day)
{
    this->day = day;
}
/// \brief Set Method
/// \param month Date's month
void Date::setMonth(unsigned short month)
{
    this->month = month;
}
/// \brief Set Method
/// \param year Date's year
void Date::setYear(unsigned year)
{
    this->year = year;
}
/// \brief Checks if Date is equal to the one given by parameter
/// \param date Date to compare
/// \return true if dates are equal, false otherwise
bool Date::isEqualTo(const Date & date)
{
    return date.getYear() == year && date.getMonth() == month && date.getDay() == day;
}
/// \brief Checks if Date is after the one given by parameter
/// \param date Date to compare
/// \return true if Date is after is given by parameter, false otherwise
bool Date::isAfter(const Date &date)
{
    if (year > date.year) return true;
    if (year == date.year && month > date.month) return true;
    return year == date.year && month == date.month && day > date.day;
}
/// \brief Checks if Date is before the one given by parameter
/// \param date Date to compare
/// \return true if Date is before the one given by parameter, false otherwise
bool Date::isBefore(const Date &date)
{
    if (year < date.year) return true;
    if (year == date.year && month < date.month) return true;
    return year == date.year && month == date.month && day < date.day;
}

Date &Date::operator-(const Date &other) {
    day -= other.day;
    month -= other.month;
    year -= other.year;
    return *this;
}

/*********************************
 * ostream
 ********************************/
/// \brief Overloads operator "<<" to show the Date
/// \param out ostream similar to "cout"
/// \param date Date shown
/// \return Ostream
ostream& operator<<(ostream& out, const Date &date)
{
    out << date.getYear() << '/' << date.getMonth() << '/' << date.getDay() << endl;
    return out;
}
/// \brief Overloads ">>" operator to get a Date from user input
/// \param in istream similar to "cin"
/// \param date Date where the input is stored
/// \return istream
istream& operator>>(istream& in, Date &date)
{
    int this_year, this_month, this_day;
    cout << "	Year: ";
    in >> this_year;
    while (in.fail())
    {
        in.clear();
        in.ignore();
        in.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        in >> this_year;
    }
    cout << "	Month: ";
    in >> this_month;
    while (cin.fail())
    {
        in.clear();
        in.ignore();
        in.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        in >> this_month;
    }
    cout << "	Day: ";
    in >> this_day;
    while (in.fail())
    {
        in.clear();
        in.ignore();
        in.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        in >> this_day;
    }

    date.year = this_year;
    date.month = this_month;
    date.day = this_day;

    return in;
}


