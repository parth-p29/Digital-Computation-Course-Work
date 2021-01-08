// Review Activity 4 - Parth Patel


//To test, the output of my program was 9837. this number matches all criteria through my manual testing with a calculator.
//The number is odd
//The number has all 4 digits different
//The number's digits add up to 27
// its thousands place digit (9) equals its tens place digit (3) when multipled by 3 - 3 * 3 = 9


#include <iostream>;
#include <cmath>;

using namespace std;


void specialNum() {   //Create a function that will output a special number which fits 4 specific criteria

	//1: all 4 digits are different
	//2: the number is odd
	//3. the sum of its digit is 27
	//4. the thousands place digit equals the tens place digit multipled by 3

	for (int special = 1001; special < 9999; special += 2) {   // I create a for loop to iterate through all the odd 4 digit numbers - this ensures the number is odd and 4 digit

		int digit1 = special / 1000;
		int digit2 = special % 1000 / 100;  // I declare the following variables which will hold the value of each digit for the number
		int digit3 = special % 100 / 10;
		int digit4 = special % 10;


		if ((digit1 != digit2) && (digit1 != digit3) && (digit1 != digit4)  //checks if the first digit of the number equal any other digit

			&& (digit2 != digit3) && (digit2 != digit4) //checks if the second digit of the number equals any other digit

			&& (digit3 != digit4)) {  //checkd if the third and forth digit equal any other digit

			
				if (digit1  == 3 * digit3) {  //Checks if the thounsands place digit equals the tens place digit multipled by 3
				
					
					if (digit1 + digit2 + digit3 + digit4 == 27) {

						cout << "The number " << special << " Works! \n";  //if the sum of digits is 27, it outputs the number
					}
				}
		}

	}
}


int main() 
{
	specialNum();
}

