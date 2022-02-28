//
// Created by Lorne Huxtable on 1/18/2022.
//
#pragma once
#ifndef LAB2_SHOWROOM_H
#define LAB2_SHOWROOM_H

#endif //LAB2_SHOWROOM_H
#include "Vehicle.h"
#include <iostream>
#include <vector>
using namespace std;

class Showroom {

private:
    string _name;
    unsigned int _capacity;
    vector<Vehicle> vehicles;

public:
    Showroom();
    Showroom(string name, unsigned int capacity);
    vector<Vehicle> GetVehicleList();
    void AddVehicle(Vehicle v);
    float GetInventoryValue();
    void ShowInventory();
};