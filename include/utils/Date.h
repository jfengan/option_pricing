//
// Created by Jiahao FENG on 8/1/2021.
//

#ifndef OPTION_PRICING_DATE_H
#define OPTION_PRICING_DATE_H

#include <vector>
#include <string>

namespace Utils{

    enum DayOfTheWeek{
        DayOfTheWeek_Sunday,
        DayOfTheWeek_Monday,
        DayOfTheWeek_Tuesday,
        DayOfTheWeek_Wednesday,
        DayOfTheWeek_Thursday,
        DayOfTheWeek_Friday,
        DayOfTheWeek_Saturday,
        DayOfTheWeek_UNKNOWN
    };

    enum Month{
        Month_January = 1,
        Month_February,
        Month_March,
        Month_April,
        Month_May,
        Month_June,
        Month_July,
        Month_August,
        Month_September,
        Month_October,
        Month_November,
        Month_December,
    };

    class Date{
    public:
        Date(int year, int month, int day);
        Date(const Date& p) = default;
        ~Date() = default;
        Date & operator=(const Date &p);

        void setHolidays(const std::vector<Date> &days);
        std::string month() const;
        std::string dayOfWeek();

        void add(int numDays);
        void addTradingDays(int numDays);
        void subtract(int numDays);
        void subtractTradingDays(int numDays);
        int dateDifference(const Date& date);
        int tradingDateDifference(const Date& date);
        DayOfTheWeek dayOfTheWeek();
        bool isHoliday();
        bool isWeekDay();
        Date nextTradingDay();
        bool isLeapYear() const;
        bool isTradingDay();
        void print() const;

        Date& operator++();
        Date& operator--();
        bool operator<(const Date& d) const;
        bool operator==(const Date& d) const;

    private:
        int m_year;
        int m_month;
        int m_day;
        DayOfTheWeek m_weekDay;
        std::vector<Date> m_holidays;
    };
}

#endif //OPTION_PRICING_DATE_H
