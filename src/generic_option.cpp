//
// Created by Jiahao FENG on 8/1/2021.
//

#include "../include/generic_option.h"

using namespace FE;

using std::cout;
using std::endl;

GenericOption::GenericOption(double strike, OptionType type, double cost):
m_strike(strike), m_type(type), m_cost(cost){

}

double GenericOption::valueAtExpiration(double underlyingAtExpiration) {
    double value = 0.;
    if(m_type == OptionType_Call){
        if(m_strike < underlyingAtExpiration)
            value = underlyingAtExpiration - m_strike;
    }
    else{
        if(m_strike > underlyingAtExpiration)
            value = m_strike - underlyingAtExpiration;
    }
    return value;
}

double GenericOption::profitAtExpiration(double underlyingAtExpiration) {
    double value = 0.;
    double finalValue = valueAtExpiration(underlyingAtExpiration);
    if(finalValue > value)
        value = finalValue - m_cost;
    return value;
}
