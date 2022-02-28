//By: Lorne Huxtable
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

string temp;
string stars(int x) { // method to get correct number of stars

    for (int i = 1; i <= x; i++) {
        temp += '*';
    }
    return temp;
}

int main() {
    //Data Values:
    //String values
    string userTitle;
    string userInput;
    string col1;
    string col2;
    string dataPoint;
    string userName;
    //Int Values
    int comma;
    int commaCount;
    int userNum;
    int i;
    //Vectors
    vector<string> userString;
    vector<int> userNums;


    //Data Title
    cout << "Enter a title for the data:" << endl;
    getline(cin, userTitle);
    cout << "You entered: " << userTitle << endl;

    //Columns
    cout << "Enter the column 1 header:" << endl;
    getline(cin, col1);
    cout << "You entered: " << col1 << endl;
    cout << "Enter the column 2 header:" << endl;
    getline(cin, col2);
    cout << "You entered: " << col2 << endl;
    if (userInput == "-1") {
        return 0;
    }

    //Data Points (make them stored in arrays)
    while (userInput != "-1") { //LOGIC ERRORS: CODE GIVING ERRORS FOR USER INPUT EVEN IF IT IS CORRECT, FIGURE OUT WHY!!
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, userInput);

        try { // Make try catch repeat
            commaCount = 0;

            if (userInput.find(',') == string::npos && userInput != "-1") { // No comma error
                throw userInput;
            }
            if (userInput == "-1") { // Prevents error message from displaying if user chooses to quit
                break;
            }
            for (i = 0; i <= userInput.size() - 1; ++i) { // Too many commas error
                if (userInput[i] == ',') {
                    commaCount++;
                }
                if (commaCount >= 2) {
                    throw commaCount;
                }
                else if (i == userInput.size()-1) { // Splits input and stores them in an array
                    comma = userInput.find(',');
                    userName = userInput.substr(0, comma);
                    userNum = stoi(userInput.substr(comma + 1, userInput.size() - 1));
                    cout << "Data string: " << userName << endl;
                    userString.push_back(userName);
                    cout << "Data integer: " << userNum << endl;
                    userNums.push_back(userNum);
                    break;
                }
            }

        }
        catch (string userInput) {
            cout << "Error: No comma in string." << endl;
        }
        catch (int commaCount) {
            cout << "Error: Too many commas in input." << endl;
        }
        catch (invalid_argument) {
            cout << "Error: Comma not followed by an integer." << endl;
        }
    }
    if (!((userString.at(0).empty)) { // Prevents table and histogram from printing if user exits
        // Top of Table
        cout << endl;
        cout << setw(33) << right << userTitle << endl;
        cout << left << setw(20) << col1 << '|' << right << setw(23) << col2 << endl;
        cout << "--------------------------------------------" << endl;

        for (i = 0; i <= userString.size() - 1; i++) { // User data in table
            cout << left << setw(20) << userString[i] << '|' << right << setw(23) << userNums[i] << endl;
        }
        cout << endl;
        for (i = 0; i <= userString.size() - 1; i++) { // Histogram
            cout << right << setw(20) << userString[i] << " " << stars(userNums[i]) << endl;
            temp = "";
        }
    }
    return 0;
}
