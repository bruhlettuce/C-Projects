//
// Created by Lorne Huxtable on 2/23/2022.
//

#ifndef LAB4_EXTRAFILE_H
#define LAB4_EXTRAFILE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#endif //LAB4_EXTRAFILE_H
using namespace std;

class extrafile {

    struct LegoSet {
        LegoSet(int _number, string _theme, string _name, int _minifigs, int _pieces, double _price);
        int number;
        string theme;
        string name;
        int minifigs;
        int pieces;
        double price;
    };
private:

    //Miscellaneous:
    int mostExpensive = 0;
    int largestPieces = 0;

public:
    void OpenFile(unsigned int num);
    void Print(LegoSet lego);
    LegoSet MostExpensive();
    LegoSet LeastExpensive();
    LegoSet MostPieces();
    LegoSet MostMinifigs();
    void NameContains(string input);
    void ThemeConatins(string input);
    void PartCount();
    void PriceInfo();
    void MinifigInfo();
    void BuyEverything();

    //Vectors:
    vector<LegoSet> legosets;
};
