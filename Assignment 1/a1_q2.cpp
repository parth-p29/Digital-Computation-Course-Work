//**************************************************************************************************

//Student Name: Parth Patel

//Syde 121 Assignment #1-F2020
//Filename: a1_q2

//I declare this code submitted for credit for this course and is a product of my own efforts.
//The coded solution has not been plagarized from other sources and has not been knowingly plagiarized by others

//Project: summation_calculator
//Purpose: Program is used to compute the value of the sums between a starting and ending integer
//Due Date: Friday , September 25, 2020 (11:00 PM)

//**************************************************************************************************

//Test Values
/*

inputted 1 and 500: output was 12520 (which matched the online calculator)

inputted -1 and 4: output was 9 (which matched online calculator)

inputted 356 and 4567: output was 10367838 (which matched online calculator)

*/

//Valid Range
/*
The valid range for this program is any two integers whose sum doesnt exceed  +/- 2147483647 (INT_MAX or INT_MIN)

Also the user should input a starting number that is less than the ending number

*/

//test Output for step 1
/*
1 to 500: 12520 (tested on online calculator and matched my output)

5 to 2020: 2041210 (tested on online calculator and matched my output)

42 to 32000: 512015139 (tested on online calculator and matched my output)
*/

#include <iostream>;
using namespace std;


//create a summation void function to calulate the sum of the values between starting and ending integers
void summation() {

	//variable declarations 
	double starting_num;   
	double last_num;               //double type variables will hold the user inputted value

	cout << "Welcome to the summation calculator! \n";

	cout << "Enter starting number: ";
	cin >> starting_num;                                               //Simple UI for user to enter in their values

	cout << "Enter Last number: ";
	cin >> last_num;

	double n = last_num - starting_num + 1;    //sets double type variable to store the value of n. Double type is used because if n is odd and it is divided by 2, it will not cause any miscalculations

	int sum = ((n / 2) * (2 * starting_num + (n - 1))); //int type variable will hold the sum of the values betwween starting and ending interger

	cout << "This is the sume of values betwween " <<starting_num<< " and " << last_num << ": " << sum << "\n"; //outputs the sum to user
}
int main()
{
	summation();
	
}

