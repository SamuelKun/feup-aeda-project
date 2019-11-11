//
// Created by diogo on 16/10/2019.
//

#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <vector>

class Date{
public:
    Date();
    Date(std::string date);
    Date(unsigned short day, unsigned short month, unsigned year);

    unsigned short getDay() const;
    unsigned short getMonth() const;
    unsigned getYear() const;
    std::string getDate() const;

    void setDay(unsigned short day);
    void setMonth(unsigned short month);
    void setYear(unsigned year);

    bool isEqualTo(const Date &date);
    bool isAfter(const Date &date);
    bool isBefore(const Date &date);

    int daysUntil(const Date &date) const;

    friend std::ostream& operator<<(std::ostream& out, const Date & date);
    friend std::istream& operator>>(std::istream& in, Date & date);

private:
    unsigned day;
    unsigned month;
    unsigned year;
};


#endif //DATE_H
