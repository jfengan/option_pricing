//
// Created by Jiahao FENG on 9/1/2021.
//

#ifndef OPTION_PRICING_DATECOMPACT_H
#define OPTION_PRICING_DATECOMPACT_H

namespace Utils{
    class DateCompact{
    public:
        DateCompact(int year, int month, int day);
        DateCompact(const DateCompact &p);
        ~DateCompact() = default;

        DateCompact & operator=(const DateCompact & p);

        void setYear(int y);
        void setMonth(int m);
        void setDay(int d);

        int year();
        int month();
        int day();

        void print();

        bool operator==(const DateCompact &d) const;
        bool operator<(const DateCompact &d) const;

    private:
        char m_date[8]{};
    };
}

#endif //OPTION_PRICING_DATECOMPACT_H
