//
// Created by Lorne Huxtable on 1/18/2022.
//
#pragma once
#ifndef LAB2_VEHICLE_H
#define LAB2_VEHICLE_H

#endif //LAB2_VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle{

private:
    string _make;
    string _model;
    unsigned int _year;
    float _price;
    unsigned int _milage;

public:
    Vehicle();
    Vehicle(string make, string model, int year, float price, int milesDriven);
    void Display();
    string GetYearMakeModel();
    float GetPrice();
};