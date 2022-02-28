//
// Created by otish on 1/20/2022.
//
#include "Dealership.h"
using namespace std;

Dealership::Dealership() {
    _name = "Generic Dealership";
    _capacity = 0;
}

Dealership::Dealership(string name, unsigned int capacity) {
    _name = name;
    _capacity = capacity;
}

void Dealership::AddShowroom(Showroom s) {
    if (Showrooms.size() >= _capacity) {
        cout << "Dealership is full, can't add another showroom!" << endl;
    }
    else {
        Showrooms.push_back(s);
    }
}

float Dealership::GetAveragePrice() {
    float totalPrice = 0;
    int divisor = 0;
    if (Showrooms.empty()) {
        return 0;
    }
    else {
        for (int i = 0; i < Showrooms.size(); i++) {
            totalPrice += Showrooms.at(i).GetInventoryValue();
            divisor += Showrooms.at(i).GetVehicleList().size();
        }
        return (totalPrice / divisor);
    }
}

void Dealership::ShowInventory() {
    if (Showrooms.empty()) {
        cout << _name << " is empty!" << endl;
    }
    else {
        for (int i = 0; i < Showrooms.size(); i++) {
            Showrooms.at(i).ShowInventory();
            cout << endl;
        }
    }
    cout << "Average car price: $" << GetAveragePrice();
}