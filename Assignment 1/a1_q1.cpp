//**************************************************************************************************

//Student Name: Parth Patel

//Syde 121 Assignment #1-F2020
//Filename: a1_q1

//Project: weight_calculator
//Purpose: Program is used to compute and output the number of each type of weight (125lb, 75lb, 42lb, 15lb, 1lb) that is required to weigh an object of 2048 (or any user input) pounds
//Due Date: Friday , September 25, 2020 (11:00 PM)

//**************************************************************************************************

//Test Cases
/*
Test Cases - I used 2048, 2147483647 (INT_MAX), 0, 15 and 15

Test cases were verified by seeing what value my program outputted and then comparing that with manually computing the values with a calculator. For all these cases, my program matched the calculator.

*/


//Valid Range of Input  
/*

input has to be greater than 0 (weight cant be 0 or less) and input can't be greater than INT_MAX

*/

//Verifying Output for Step 1: weight_given = 2048
/*
with calculator - 2048 / 125 = 16 (integer) which is the number of 125lb weights that make up 2048 (the remainder is 48)
with calculator - 48/ 42  = 1 (integer) which is the number of 42lb weights which make up 2048 (the remainder is 6)
with calcultor - 6/1 - 6 which is the number of 1lb weight which makes up 2048 (the remainder is 0 so I can exit the loop)

so, with calculator (125 * 16) + (42 * 1) + (1 * 6) = 2048. Therefore, my program works for this case.

*/

#include <iostream>;
using namespace std;

void calculate_weight() {  //void function determines the value for each type of weight for the original weight

    //Variable declaration
    int weight_given;     //stores the value of the initial weight
    //int weight_given = 2048;   - hardcoded value of the weight

    //user input
    cout << "Enter in an initial weight value (lbs): ";
    cin >> weight_given;                               //simple UI where the user can input in their value


    while (weight_given > 0) {    //loop used to iterate while weight_given is greater than 0, to determine the values of the different types of weights

        if (weight_given > 125) {

            cout << "Number of 125 lb Weights: " << weight_given / 125 << "\n";   //If the inputted weight is greater than 125, then it will calculate the number of those weights (weight / 125) and output that to the user

            weight_given %= 125;  // Sets the weight to the remainder of the division so it can be used for the next if statement test
        }

        else if (weight_given >= 75 && weight_given < 125) {
            cout << "Number of 75 lb Weights: " << weight_given / 75 << "\n";    // Same process is used for the remaining else if statements
            weight_given %= 75;
        }

        else if (weight_given >= 42 && weight_given < 75) {
            cout << "Number of 42 lb Weights: " << weight_given / 42 << "\n";
            weight_given %= 42;
        }

        else if (weight_given >= 15 && weight_given < 42) {
            cout << "Number of 15 lb Weights: " << weight_given / 15 << "\n";
            weight_given %= 15;
        }

        else {
            cout << "Number of 1 lb Weights: " << weight_given << "\n";    //none of the other weight types can be divided with the remaining weight so it is kept the same (which is the same as dividing by 1) 
            weight_given %= 1; //the remainder of this statement is 0, which is what breaks the loop (0 is not greater than 0)
        }
    }

}


int main()
{   

    calculate_weight(); //calls the calculate_weight function
}