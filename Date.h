//
// Created by diogo on 16/10/2019.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date{
public:
    Date();
    Date(string date);
    Date(unsigned short day, unsigned short month, unsigned year);


    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;

    void setDay(unsigned short day);
    void setMonth(unsigned short month);
    void setYear(unsigned year);

    bool isEqualTo(const Date &date);
    bool isAfter(const Date &date);
    bool isBefore(const Date &date);

    friend ostream& operator<<(ostream& out, const Date & date);
    friend istream& operator>>(istream& in, Date & date);

private:
    unsigned day;
    unsigned month;
    unsigned year;
};


#endif //DATE_H
