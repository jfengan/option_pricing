//
// Created by Jiahao FENG on 9/1/2021.
//

#include "../include/utils/Date.h"
#include <iostream>
using namespace Utils;

int main(){
    Date d(2015, 9, 12);
    DayOfTheWeek wd = d.dayOfTheWeek();
    std::cout << " day of the week: " << " " << d.dayOfTheWeek() << std::endl;

    d.print();
    d.add(200);
    d.print();

    d.addTradingDays(120);
    d.print();

    std::cout << " day of the week: " << d.dayOfTheWeek() << " " << std::endl;

    return 0;
}