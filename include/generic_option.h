//
// Created by Jiahao FENG on 8/1/2021.
//

#ifndef OPTION_PRICING_GENERIC_OPTION_H
#define OPTION_PRICING_GENERIC_OPTION_H

#include <iostream>

namespace FE{
    enum OptionType{
        OptionType_Call,
        OptionType_Put
    };

    class GenericOption{
    public:
        GenericOption(double strike, OptionType type, double cost);
        GenericOption(const GenericOption & opt) = default;
        ~GenericOption() = default;

        double valueAtExpiration(double underlyingAtExpiration);
        double profitAtExpiration(double underlyingAtExpiration);

    private:
        double m_strike;
        OptionType m_type;
        double m_cost;
    };
}

#endif //OPTION_PRICING_GENERIC_OPTION_H
