//
// Created by Jiahao FENG on 8/1/2021.
//

#ifndef OPTION_PRICING_RANDOM_WALK_GENERATOR_H
#define OPTION_PRICING_RANDOM_WALK_GENERATOR_H

#include <iostream>
#include <vector>

using std::vector;

namespace FE{
    class RandomWalkGenerator{
    public:
        RandomWalkGenerator(int size, double start, double step);
        RandomWalkGenerator(const RandomWalkGenerator& rwg) = default;
        ~RandomWalkGenerator() = default;

        RandomWalkGenerator & operator=(const RandomWalkGenerator &p);
        std::vector<double> generateWalk() const;
        double computeRandomStep(double currentPrice) const;

    private:
        int m_numSteps;
        double m_stepSize;
        double m_initialPrice;
    };
}

#endif //OPTION_PRICING_RANDOM_WALK_GENERATOR_H
