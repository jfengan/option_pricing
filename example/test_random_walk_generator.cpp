//
// Created by Jiahao FENG on 8/1/2021.
//

#include "../include/random_walk_generator.h"
#include <iostream>

int main(){
    FE::RandomWalkGenerator rw(100, 30, 0.01);
    vector<double> walk = rw.generateWalk();
    for(auto it: walk)
        std::cout << it << std::endl;
    return 0;
}