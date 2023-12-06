//
// Created by otish on 4/12/2022.
//
#pragma once
#include <random>
#ifndef MINESWEEPER_RANDOM_H
#define MINESWEEPER_RANDOM_H
#include <vector>
#endif //MINESWEEPER_RANDOM_H


class Random {
   static std::mt19937 random;
public:
    static int Int(int min, int max);
    static float Float(float min, float max);
    static bool SameNumber(std::vector<int> numbers, int number);
};