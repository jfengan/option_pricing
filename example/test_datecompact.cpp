//
// Created by Jiahao FENG on 9/1/2021.
//

#include "../include/utils/DateCompact.h"
#include "../include/utils/Date.h"
#include <iostream>

using namespace Utils;

int main(){
    DateCompact d(2008, 3, 27);
    DateCompact e(2008, 5, 11);

    std::cout << "size of DateCompact: " << sizeof(DateCompact) << std::endl;

    d.print();
    e.print();

    if(d < e){
        std::cout << "d is less thant e" << std::endl;
    }

    else{
        std::cout << "d is not less than e" << std::endl;
    }

    Date date(2008, 3, 17);
    std::cout << "size of Date: " << sizeof(Date) << std::endl;

    return 0;
}