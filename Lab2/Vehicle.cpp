//
// Created by Lorne Huxtable on 1/18/2022.
//
#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle() {
    _make = "COP3503";
    _model = "Rust Bucket";
    _year = 1900;
    _price = 0;
    _milage = 0;
}

Vehicle::Vehicle(string make, string model, int year, float price, int milesDriven) {
    _make = make;
    _model = model;
    _year = year;
    _price = price;
    _milage = milesDriven;
}

void Vehicle::Display() {
    cout << _year << " " << _make << " " << _model << " $" << _price << " " << _milage << endl;
}

string Vehicle::GetYearMakeModel() { // figure out how to print multiple values
    string yearMakeModel;
    yearMakeModel = to_string(_year) + " " + _make + " " + _model;
    return yearMakeModel;
}

float Vehicle::GetPrice() {
    return _price;
}