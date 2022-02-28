//
// Created by Lorne Huxtable on 2/23/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>
#include "extrafile.h"
using namespace std;

void extrafile::OpenFile(unsigned int num) {
    // Varibles to make lego sets
    string placeHolder;
    int number = 0;
    string theme = "";
    string name = "";
    int minifigs = 0;
    int pieces = 0;
    double price = 0.00;

    if (num == 1) {
        ifstream file("lego1.csv");
        if (file.is_open()) {
                getline(file, placeHolder);
            while (!file.eof()) {
                    getline(file, placeHolder, ',');
                    try {
                        number = stoi(placeHolder);
                    }
                    catch (invalid_argument const&) {
                        number = 0;
                    }
                    getline(file, theme, ',');

                    getline(file, name, ',');

                    getline(file, placeHolder, ',');
                    try {
                        minifigs = stoi(placeHolder);
                    }
                    catch (invalid_argument const&) {
                        minifigs = 0;
                    }

                    getline(file, placeHolder, ',');
                    try {
                        pieces = stoi(placeHolder);
                    }
                    catch (invalid_argument const&) {
                        pieces = 0;
                    }

                    getline(file, placeHolder);
                    try {
                        price = stof(placeHolder);
                    }
                    catch (invalid_argument const&) {
                        price = 0.00;
                    }
                LegoSet lego(number, theme, name, minifigs, pieces, price);
                legosets.push_back(lego);
            }
            cout << "Total number of sets: " << legosets.size() << endl;

        }
    }
    if (num == 2) {
        ifstream file("lego2.csv");
        if (file.is_open()) {
            getline(file, placeHolder);
            while (!file.eof()) {
                getline(file, placeHolder, ',');
                try {
                    number = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    number = 0;
                }
                getline(file, theme, ',');

                getline(file, name, ',');

                getline(file, placeHolder, ',');
                try {
                    minifigs = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    minifigs = 0;
                }

                getline(file, placeHolder, ',');
                try {
                    pieces = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    pieces = 0;
                }

                getline(file, placeHolder);
                try {
                    price = stof(placeHolder);
                }
                catch (invalid_argument const&) {
                    price = 0.00;
                }
                LegoSet lego(number, theme, name, minifigs, pieces, price);
                legosets.push_back(lego);
            }
            cout << "Total number of sets: " << legosets.size() << endl;

        }
    }
    if (num == 3) {
        ifstream file("lego3.csv");
        if (file.is_open()) {
            getline(file, placeHolder);
            while (!file.eof()) {
                getline(file, placeHolder, ',');
                try {
                    number = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    number = 0;
                }
                getline(file, theme, ',');

                getline(file, name, ',');

                getline(file, placeHolder, ',');
                try {
                    minifigs = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    minifigs = 0;
                }

                getline(file, placeHolder, ',');
                try {
                    pieces = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    pieces = 0;
                }

                getline(file, placeHolder);
                try {
                    price = stof(placeHolder);
                }
                catch (invalid_argument const&) {
                    price = 0.00;
                }
                LegoSet lego(number, theme, name, minifigs, pieces, price);
                legosets.push_back(lego);
            }
            cout << "Total number of sets: " << legosets.size() << endl;

        }
    }
    if (num == 4) {
        ifstream file("lego1.csv");
        if (file.is_open()) {
            getline(file, placeHolder);
            while (!file.eof()) {
                getline(file, placeHolder, ',');
                try {
                    number = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    number = 0;
                }
                getline(file, theme, ',');

                getline(file, name, ',');

                getline(file, placeHolder, ',');
                try {
                    minifigs = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    minifigs = 0;
                }

                getline(file, placeHolder, ',');
                try {
                    pieces = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    pieces = 0;
                }

                getline(file, placeHolder);
                try {
                    price = stof(placeHolder);
                }
                catch (invalid_argument const&) {
                    price = 0.00;
                }
                LegoSet lego(number, theme, name, minifigs, pieces, price);
                legosets.push_back(lego);
            }
            file.close();
        }
        ifstream file2("lego2.csv");
        if (file2.is_open()) {
            getline(file2, placeHolder);
            while (!file2.eof()) {
                getline(file2, placeHolder, ',');
                try {
                    number = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    number = 0;
                }
                getline(file2, theme, ',');

                getline(file2, name, ',');

                getline(file2, placeHolder, ',');
                try {
                    minifigs = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    minifigs = 0;
                }

                getline(file2, placeHolder, ',');
                try {
                    pieces = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    pieces = 0;
                }

                getline(file2, placeHolder);
                try {
                    price = stof(placeHolder);
                }
                catch (invalid_argument const&) {
                    price = 0.00;
                }
                LegoSet lego(number, theme, name, minifigs, pieces, price);
                legosets.push_back(lego);
            }
            file2.close();

        }
        ifstream file3("lego3.csv");
        if (file3.is_open()) {
            getline(file3, placeHolder);
            while (!file3.eof()) {
                getline(file3, placeHolder, ',');
                try {
                    number = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    number = 0;
                }
                getline(file3, theme, ',');

                getline(file3, name, ',');

                getline(file3, placeHolder, ',');
                try {
                    minifigs = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    minifigs = 0;
                }

                getline(file3, placeHolder, ',');
                try {
                    pieces = stoi(placeHolder);
                }
                catch (invalid_argument const&) {
                    pieces = 0;
                }

                getline(file3, placeHolder);
                try {
                    price = stof(placeHolder);
                }
                catch (invalid_argument const&) {
                    price = 0.00;
                }
                LegoSet lego(number, theme, name, minifigs, pieces, price);
                legosets.push_back(lego);
            }
            file3.close();

        }
        cout << "Total number of sets: " << legosets.size() << endl;
    }
}

extrafile::LegoSet::LegoSet(int _number, string _theme, string _name, int _minifigs, int _pieces, double _price) {
 number = _number;
 theme = _theme;
 name = _name;
 minifigs = _minifigs;
 pieces = _pieces;
 price = _price;
}

extrafile::LegoSet extrafile::MostExpensive() {
    double max = legosets.at(0).price;
    mostExpensive = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
       if (max < legosets.at(i).price) {
           max = legosets.at(i).price;
           mostExpensive = i;
       }
       else {
           continue;
       }
    }
    return legosets.at(mostExpensive);
}

extrafile::LegoSet extrafile::LeastExpensive() {
    double min = legosets.at(0).price;
    int leastExpensive = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        if (min > legosets.at(i).price) {
            min = legosets.at(i).price;
            leastExpensive = i;
        }
        else {
            continue;
        }
    }
    return legosets.at(leastExpensive);
}

extrafile::LegoSet extrafile::MostPieces() {
    int max = legosets.at(0).pieces;
    largestPieces = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        if (max < legosets.at(i).pieces) {
            max = legosets.at(i).pieces;
            largestPieces = i;
        }
        else {
            continue;
        }
    }
    return legosets.at(largestPieces);
}

extrafile::LegoSet extrafile::MostMinifigs() {
    int max = legosets.at(0).minifigs;
    largestPieces = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        if (max < legosets.at(i).minifigs) {
            max = legosets.at(i).minifigs;
            largestPieces = i;
        }
        else {
            continue;
        }
    }
    return legosets.at(largestPieces);
}
void extrafile::NameContains(string input) {
    int count = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        if (legosets.at(i).name.find(input) != string::npos) {
            count++;
            if (count == 1) {
                cout << "Sets matching \"" << input << "\":" << endl;
            }
            cout << " " << legosets.at(i).number << " " << legosets.at(i).name << " $" << legosets.at(i).price << endl;
        }
        else {
            continue;
        }
    }
    if (count == 0) {
        cout << "No sets found matching that search term" << endl;
    }
}

void extrafile::ThemeConatins(string input) {
    int count = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        if (legosets.at(i).theme.find(input) != string::npos) {
            count++;
            if (count == 1) {
                cout << "Sets matching \"" << input << "\":" << endl;
            }
            cout << " " << legosets.at(i).number << " " << legosets.at(i).name << " $" << legosets.at(i).price << endl;
        }
        else {
            continue;
        }
    }
    if (count == 0) {
        cout << "No sets found matching that search term" << endl;
    }
}

void extrafile::PartCount() {
    int totalParts = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        totalParts += legosets.at(i).pieces;
    }
    cout << "Average part count for " << legosets.size() << " sets: " << totalParts/legosets.size() << endl;
}

void extrafile::PriceInfo() {
    double totalPrice = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        totalPrice += legosets.at(i).price;
    }
    cout << "Average price for " << legosets.size() << " sets: $" << totalPrice/double(legosets.size()) << endl;
    cout << endl;
    cout << "Least expensive set:" << endl;
    Print(LeastExpensive());
    cout << endl;
    cout << "Most expensive set:" << endl;
    Print(MostExpensive());

}

void extrafile::MinifigInfo() {
    int totalMinifigs = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        totalMinifigs += legosets.at(i).minifigs;
    }
    cout << "Average number of minifigures: " << totalMinifigs/legosets.size() << endl;
    cout << endl;
    cout << "Set with the most minifigures:" << endl;
    Print(MostMinifigs());

}

void extrafile::BuyEverything() {
    double totalPrice = 0;
    int totalPieces = 0;
    int totalMinifigs = 0;
    for (unsigned int i = 0; i < legosets.size(); i++) {
        totalPrice += legosets.at(i).price;
    }
    for (unsigned int i = 0; i < legosets.size(); i++) {
        totalPieces += legosets.at(i).pieces;
    }
    for (unsigned int i = 0; i < legosets.size(); i++) {
        totalMinifigs += legosets.at(i).minifigs;
    }
    cout << "It would cost: $" << totalPrice << endl;
    cout << "You would have " << totalPieces << " pieces in your collection" << endl;
    cout << "You would have an army of " << totalMinifigs << " minifigures!" << endl;
}

void extrafile::Print(LegoSet lego) {
    cout << "Name: " << lego.name << endl;
    cout << "Number: " << lego.number << endl;
    cout << "Theme: " << lego.theme << endl;
    cout << "Price: " << "$" << lego.price << endl;
    cout << "Minifigures: " << lego.minifigs << endl;
    cout << "Piece count: " << lego.pieces << endl;
}
