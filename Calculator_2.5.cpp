#include <iostream>
#include <string>
using namespace std;

double firstNum, secNum, resultRoot;
int numberForCalculation, operation, endOrContinue=1;

int clearLastInput(){
    cin.clear();
    cin.ignore(1000, '\n');
    return 0;
}

int question(string questionSentence){
    cout << questionSentence;
    cin >> numberForCalculation;
    while (!(numberForCalculation == 1 || numberForCalculation == 2 || numberForCalculation == 3 || numberForCalculation == 4 || numberForCalculation == 5 || numberForCalculation == 6)){
        cout << questionSentence;
        clearLastInput();
        cin >> numberForCalculation;
    }
    return numberForCalculation;
}

int getNumbersForCalculation(){
    if (numberForCalculation == 5 || numberForCalculation == 6){
        cout << "Please provide a number for calculation: ";
        clearLastInput();
        cin >> firstNum;
        while (cin.fail()){
            cout << "Please provide a valid number for calculation: ";
            clearLastInput();
            cin >> firstNum;
        }
    }
    else{
        cout << "Please provide the first number for calculation: ";
        clearLastInput();
        cin >> firstNum;
        while (cin.fail()){
            cout << "Please provide a valid number for calculation: ";
            clearLastInput();
            cin >> firstNum;            
        }
        cout << "Please provide the second number for calculation: ";
        clearLastInput();
        cin >> secNum;
        while (cin.fail() || (numberForCalculation==4 && secNum==0)){
            if (numberForCalculation==4 && secNum==0){
                cout << "Dividing by 0 is undefined, please enter a defined number: ";
                clearLastInput();
                cin >> secNum;   
            }
            else{
                cout << "Please provide a valid number for calculation: ";
                clearLastInput();
                cin >> secNum;   
            }         
        }      
    }
    return 0;
}

int calculateARoot(){
    for (int i=0; (i*i) <= firstNum; i++){
        resultRoot=i;
    }
    if (((resultRoot * resultRoot)-firstNum) > (firstNum-((resultRoot-1)*(resultRoot-1)))){
        resultRoot--;
    }
    for (int x=0; x<10; x++){
        resultRoot=(resultRoot+(firstNum/resultRoot))/2;
    }
    return 0;
}

int main(){
    while (endOrContinue==1){
        operation = question("Please provide addition(1), subtraction(2), multiplication(3), division(4), squaring(5), square root(6): ");
        switch(operation){
            case(1):
                getNumbersForCalculation();
                cout << "Program has ended calculation is:  " << (firstNum + secNum) << endl;
                break;
            case(2):
                getNumbersForCalculation();
                cout << "Program has ended calculation is:s " << (firstNum - secNum) << endl;
                break;
            case(3):
                getNumbersForCalculation();
                cout << "Program has ended calculation is: " << (firstNum * secNum) << endl;
                break;
            case(4):
                getNumbersForCalculation();
                cout << "Program has ended calculation is: " << (firstNum / secNum) << endl;
                break;
            case(5):
                getNumbersForCalculation();
                cout << "Program has ended calculation is: " << (firstNum * firstNum) << endl;
                break;
            case(6):
                getNumbersForCalculation();
                calculateARoot();
                cout << "Program has ended calculation is: " << (resultRoot) << endl;
                break;
        }            
        cout << "Do you want to continue yes(1) or no(0): ";
        cin  >> endOrContinue;
        while(!(endOrContinue==1 || endOrContinue==0)){
            cout <<"Do you want to continue yes(1) or no(0): ";
            clearLastInput();
            cin >> endOrContinue;
        }
    } 
}
