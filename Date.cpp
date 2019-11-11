#include <sstream>
#include <iomanip>
#include "Date.h"

using namespace std;

/// \brief Date empty constructor
Date::Date()
{
}
/// \brief Date constructor
/// \param date Date string in the format DD // MM // YYYY
Date::Date(string date)
{

    stringstream date_info(date);
    string temp;
    vector<string> date_temp;

    while (getline(date_info, temp, '/')) {
        date_temp.push_back(temp);
    }

    day = stoi(date_temp[0]);
    month = stoi(date_temp[1]);
    year = stoi(date_temp[2]);

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

string Date::getDate() const {
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
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

/*********************************
 * ostream
 ********************************/
/// \brief Overloads operator "<<" to show the Date
/// \param out ostream similar to "cout"
/// \param date Date shown
/// \return Ostream
ostream& operator<<(ostream& out, const Date &date)
{
    out << date.getDay() << '/' << date.getMonth() << '/' << date.getYear();
    return out;
}
/// \brief Overloads ">>" operator to get a Date from user input
/// \param in istream similar to "cin"
/// \param date Date where the input is stored
/// \return istream
istream& operator>>(istream& in, Date &date)
{
    int this_year, this_month, this_day;
    cout << "Year:";
    in >> this_year;
    in.ignore(1000,'\n');
    while (in.fail())
    {
        in.clear();
        in.ignore();
        in.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        in >> this_year;
    }
    cout << "Month:";
    in >> this_month;
    in.ignore(1000,'\n');
    while (cin.fail())
    {
        in.clear();
        in.ignore();
        in.ignore(1000, '\n');
        cout << "Not a valid number. Please reenter: ";
        in >> this_month;
    }
    cout << "Day:";
    in >> this_day;
    in.ignore(1000,'\n');
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

int Date::daysUntil(const Date &date) const {
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    long int n1 = year*365 + day;

    for (int i=0; i< month - 1; i++)
        n1 += monthDays[i];

    long int n2 = date.getYear()*365 + date.getDay();

    for (int i=0; i<date.getMonth() - 1; i++)
        n2 += monthDays[i];
    return n2 - n1;
}





