// Created by Lorne Huxtable on 2/23/2022.
#include <iomanip>
#include <iostream>
#include "extrafile.h"
#include <string>
using namespace std;

int main()
{
    cout << std::fixed << setprecision(2);
    cout << "Which file(s) to open?\n";
    cout << "1. lego1.csv" << endl;
    cout << "2. lego2.csv" << endl;
    cout << "3. lego3.csv" << endl;
    cout << "4. All 3 files" << endl;
    extrafile a;
    int option;
    cin >> option;
    a.OpenFile(option);


    /*======= Load data from file(s) =======*/
    string userInput;
    int choice = 1;
    while (choice != 0) {
        cin >> choice;
        if (choice == 1) {
            cout << "The most expensive set is:" << endl;
            a.Print(a.MostExpensive());
        }
        if (choice == 2) {
            cout << "The set with the highest parts count:" << endl;
            a.Print(a.MostPieces());
        }
        if (choice == 3) {
            cin.get();
            getline(cin, userInput);
            a.NameContains(userInput);
        }
        if (choice == 4) {
            cin.get();
            getline(cin, userInput);
            a.ThemeConatins(userInput);
        }
        if (choice == 5) {
            a.PartCount();
        }
        if (choice == 6) {
            a.PriceInfo();
        }
        if (choice == 7) {
            a.MinifigInfo();
        }
        if (choice == 8) {
            cout << "If you bought one of everything..." << endl;
            a.BuyEverything();
        }
        if (choice == 0) {
            cout << "0. Exit" << endl;
        }
    }

    

    return 0;
}


