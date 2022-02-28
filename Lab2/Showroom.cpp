//
// Created by Lorne Huxtable on 1/18/2022.
//
#include "Showroom.h"
#include <iostream>
#include <utility>
using namespace std;

Showroom::Showroom() {
    _name = "Unnamed Showroom";
    _capacity = 0;
}

Showroom::Showroom(string name, unsigned int capacity) {
    _name = name;
    _capacity = capacity;
}

void Showroom::AddVehicle(Vehicle v) {

    if (vehicles.size() >= _capacity) {
        cout << "Showroom is full! Cannot add " << v.GetYearMakeModel() << endl;
    } else {
        vehicles.push_back(v);
    }
}
void Showroom::ShowInventory() {
    if (vehicles.empty()) {
        cout << _name << " is empty!" << endl;
    }
    else {
        cout << "Vehicles in " << _name << endl;
        for (int i = 0; i < vehicles.size(); i++) {
            vehicles.at(i).Display();
        }
    }
}

vector<Vehicle> Showroom::GetVehicleList() {
    return vehicles;
}

float Showroom::GetInventoryValue() {
    float totalPrice = 0;
    for (int i = 0; i < vehicles.size(); i++) {
        totalPrice += vehicles.at(i).GetPrice();
    }
    return totalPrice;
}



