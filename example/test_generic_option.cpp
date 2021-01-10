//
// Created by Jiahao FENG on 8/1/2021.
//

#include <iostream>
#include "../include/generic_option.h"

int main(){
    FE::GenericOption option(100., FE::OptionType_Put, 1.4);
    double price1 = 120.;
    double value = option.valueAtExpiration(price1);

    std::cout << "For 100PUT,value at expiration for price " << price1 << " is " << value << std::endl;

    double price2 = 85.;
    value = option.valueAtExpiration(85.);
    std::cout << "For 100PUT,value at expiration for price " << price2 << " is " << value << std::endl;

    auto limit = 120.;
    for (auto price = 80.; price <= limit; price += 0.1){
        value = option.profitAtExpiration(price);
        std::cout << price << ", " << value << std::endl;
    }
    return 0;
}