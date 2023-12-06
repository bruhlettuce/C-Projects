//
// Created by otish on 4/12/2022.
//

#include "Random.h"
#include <ctime>

std::mt19937 Random::random(time(0));

int Random::Int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(random);
}

float Random::Float(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(random);
}

bool Random::SameNumber(std::vector<int> numbers, int number) {
    for (int i = 0; i < numbers.size(); i++) {
        if (i == 0) {
            continue;
        }
        if (numbers.at(numbers.size()-1) == numbers.at(i-1)) {
            return false;
        }
    }
    return true;
}