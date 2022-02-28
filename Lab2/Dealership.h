//
// Created by otish on 1/20/2022.
//

#ifndef LAB2_DEALERSHIP_H
#define LAB2_DEALERSHIP_H
#pragma once
#include "Showroom.h"
#include <vector>
#endif //LAB2_DEALERSHIP_H
using namespace std;

class Dealership {

private:
    string _name;
    unsigned int _capacity;
    vector<Showroom> Showrooms;

public:
    Dealership();
    Dealership(string name, unsigned int capacity);
    void AddShowroom(Showroom s);
    float GetAveragePrice();
    void ShowInventory();

};