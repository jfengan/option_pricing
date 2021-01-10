//
// Created by Jiahao FENG on 8/1/2021.
//

#include "../include/random_walk_generator.h"

using namespace FE;

#include <iostream>
#include <vector>
#include <random>

using std::cout;
using std::endl;
using std::vector;

RandomWalkGenerator::RandomWalkGenerator(int size, double start, double step)
:m_numSteps(size), m_stepSize(step), m_initialPrice(start){

}

RandomWalkGenerator & RandomWalkGenerator::operator=(const RandomWalkGenerator &p) {
    if(this != &p){
       m_numSteps = p.m_numSteps;
       m_stepSize = p.m_stepSize;
       m_initialPrice = p.m_initialPrice;
    }

    return *this;
}

double RandomWalkGenerator::computeRandomStep(double currentPrice) const {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<int> dist;
    const int num_directions = 3;
    int r = dist(gen) % num_directions;

    double val = currentPrice;
    if(r == 0){
        val += (m_stepSize * val);
    }
    else if(r == 1){
        val -= (m_stepSize * val);
    }
    return val;
}

std::vector<double> RandomWalkGenerator::generateWalk() const {
    vector<double> walk;
    double prev = m_initialPrice;

    for(int i = 0; i < m_numSteps; ++i){
        double val = computeRandomStep(prev);
        walk.push_back(val);
        prev = val;
    }

    return walk;
}