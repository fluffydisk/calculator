#include <iostream>
using namespace std;

int clearInput() {
    cin.clear();
    cin.ignore(1000, '\n');
    return 0;
}
double getNumber(const string& prompt) {
    double num;
    cout << prompt;
    clearInput();
    cin >> num;
    while (cin.fail()) {
        cout << "Please enter a valid number: ";
        clearInput();
        cin >> num;
    }
    return num;
}

int getOperation() {
    int number;
    cout << "Welcome to the Calculator!\n"
         << "Enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division: ";
    cin >> number;
    while (cin.fail() || (number != 1 && number != 2 && number != 3 && number != 4)) {
        cout << "Invalid input. Please enter 1 for addition, 2 for subtraction, 3 for multiplication, 4 for division: ";
        clearInput();
        cin >> number;
    }
    return number;
}



int main() {
    int continueCalculation = 1;
    double num1, num2, result;
    while (continueCalculation == 1) {
        int operation = getOperation();
        num1 = getNumber("Please type the first number: ");
        num2 = getNumber("Please type the second number: ");
        switch (operation) {
            case 1:
                result = num1 + num2;
                cout << "The solution of addition is: " << result;
                break;
            case 2:
                result = num1 - num2;
                cout << "The solution of subtraction is: " << result;
                break;
            case 3:
                result = num1 * num2;
                cout << "The solution of multiplication is: " << result;
                break;
            case 4:
                while (num2 == 0) {
                    cout << "Dividing a number by 0 is undefined please give a correct number to divide: ";
                    num2 = getNumber("");
                }
                result = num1 / num2;
                cout << "The solution of division is: " << result;
                break;
        }
        cout << "\nDo you want to continue to calculation 1(Yes), 2(No): ";
        clearInput();
        cin >> continueCalculation;
        while (cin.fail() || (continueCalculation != 1 && continueCalculation != 2)) {
            cout << "Invalid input. Please enter 1(Yes), 2(No): ";
            clearInput();
            cin >> continueCalculation;
        }
    clearInput();
    }
    cout << "The calculation is finished";
    return 0;
}
