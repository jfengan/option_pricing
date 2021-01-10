//
// Created by Jiahao FENG on 9/1/2021.
//

#include "../include/utils/DateCompact.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace Utils;
using std::cout;
using std::endl;

DateCompact::DateCompact(int year, int month, int day) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

void DateCompact::setYear(int year) {
    m_date[3] = (char)(year % 10);
    year /= 10;
    m_date[2] = (char)(year % 10);
    year /= 10;
    m_date[1] = (char)(year % 10);
    year /= 10;
    m_date[0] = (char)(year % 10);
}

void DateCompact::setMonth(int month) {
    m_date[5] = (char)(month % 10);
    month /= 10;
    m_date[4] = (char)(month % 10);
}

void DateCompact::setDay(int day) {
    m_date[7] = (char)(day % 10);
    day /= 10;
    m_date[6] = (char)(day % 10);
}

DateCompact::DateCompact(const DateCompact &p) {
    strcpy(m_date, p.m_date);
}

DateCompact & DateCompact::operator=(const DateCompact &p) {
    if(&p != this){
        strcpy(m_date, p.m_date);
    }
    return *this;
}

bool DateCompact::operator==(const DateCompact &d) const {
    return strncmp(m_date, d.m_date, 8) == 0;
}

bool DateCompact::operator<(const DateCompact &d) const {
    return strncmp(m_date, d.m_date, 8) < 0;
}

int DateCompact::year() {
    int year = 1000 * static_cast<int>(m_date[0])
            + 100 * static_cast<int>(m_date[1])
            + 10 * static_cast<int>(m_date[2])
            + static_cast<int>(m_date[3]);
    return year;
}

int DateCompact::month() {
    int month = 10 * static_cast<int>(m_date[4]) + static_cast<int>(m_date[5]);
    return month;
}

int DateCompact::day() {
    int day = 10 * static_cast<int>(m_date[6]) + static_cast<int>(m_date[7]);
    return day;
}

void DateCompact::print() {
    std::cout << year();
    std::cout << std::setw(2) << std::setfill('0') << month() << day() << std::endl;
}
