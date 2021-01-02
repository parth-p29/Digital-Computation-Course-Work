//*******************************************************************************************************************

// Student Name: Parth Patel

// SYDE 121 Lab Assignment #2 Question 1
// Filename: a2_q1.cpp


// Project: Prime number, Palindromic and odd sum calculator
// Purpose: Output all the numbers which are prime, prime palindromic or has an odd sum from a given range 

//*******************************************************************************************************************

//Test
/*

    The test values I used to see my code's functionality are: 50, 10000, 100000 From all these values all the outputs matched the specifications the question asked for

    Palindromic Prime

    Using the online website which has all the palindromic prime numbers, I saw that all the numbers my program outputted to be palindromic prime matched with the website.
    So, by inputting 10000 all the palindromic primes which my program outputted (e.g. 101) matched with the website.

    
    Sum of Digits is ODD

    By inputting 100000, my program outputs all the numbers whose digits add up to an odd number. To test if all of these values did in fact have an odd sum. I quickly calculated the sum
    and found that yes, the sum was odd (e.g 47 has a odd sum which is also a prime number)


    Prime Number

    By inputting in any number, I saw that all the numbers my program outputted were prime numbers, even if the input was greater than 100000, all the numbers outputted were prime



*/


//Valid Range

/*

The valid range of input for this program is any number greater than 1 and less than INT_MAX

However, after 100000 the program will only output prime numbers rather than the other 2 specifications. So if you only want numbers that match all 3 criteria the range should be from
2 - 100000

   Also, the larger the number you input, the longer the computation takes, so it is better to input a number 100000 or less so the code can output numbers that match all 3 criteria and quicker
*/

#include <iostream>
#include <string>

using namespace std;

bool is_palindromic(int num) {     //This is a boolean function used to determine whether the prime number inputted into as an arguement is palindromic

    string num_string = to_string(num);   // I first convert the number to a string
    string num_reversed;  //Initilize a string variable to hold the reversed version of the orginial number string

    for (int i = num_string.length() - 1; i >= 0; i--) {

        num_reversed += num_string[i];       //I create a for loop that will start at the last character of the number string and concatenate until the first, creating the reversed version
         
    }

    return (num_string == num_reversed);   //If the orginal number string is equal to the reversed string than it will return true, or else it will return false
}

bool is_sum_odd(int num) {    //Creates a boolean function which determines whether the sum of the digits in the prime number is an odd number

    int sum = 0;  //initilizes a sum variable to 0

    while (num > 0) {       //while the number is greater than 0 it will add each digit of the number to the sum

        sum += num % 10;   //num % 10 will give the last digit of the number, it will add this to the sum
        num /= 10;  //num / 10 will take out the last digit, mmaking the second lat digit the last digit. Then this process will continue until the number is 0, breaking out the loop

    }

    return (sum % 2 == 1);   //returns a true or false depending on if the sum is odd or not
}

bool is_prime(int num) {                       //Create a boolean function to determine whether a number is prime

    for (int factor = 2; factor <= num / 2; factor++) {      //for loop will keep iterating from 2 (first prime number) to half the number, since a number can't have a factor greater than half of it

        if (num % factor == 0) {   //If the number is divisble by the potential factor with no remainder it will return false since its no longer a prime

            return false;
        }

    }

    return true;  // if the number has no additional factors it is a prime so it will return true
}

void input_output() {     //create an input and output funcition which will get input from the user and output the final results

    int user_num;
    bool ask_user = true;     // declares the variables which will hold the user input and a boolean which will stay true until the user enters a correct input

    while (ask_user) {

        cout << "Enter a number greater than 1: ";      //until the user enters an acceptable value for the input, it will keep asking
        cin >> user_num;

        if (user_num <= 1) {
            cout << "Please enter a number greater than 1!!! \n";
        }

        else {
            break;
        }

    }

    for (int num = 2; num <= user_num; num++) {     //starting from 2 until the user inputted number, it will output the following numbers which match the specifictions

        if (is_prime(num)) {    //all numbers have to be prime so it calls the is_prime function and chooses only prime numbers to move on
             
            if (is_palindromic(num) && num < 10000) {     //checks if number is also palindromic and less then 10000

                if (is_sum_odd(num)) {

                    cout << num << " (Palindromic) (Sum of Digits is Odd) \n";     //if number is palindromic and has an odd sum it will output the following

                }

                else {

                    cout << num << " (Palindromic) \n";

                }

            }

            else if (is_sum_odd(num) && num < 100000) {

                cout << num << " (Sum of Digits is Odd) \n";     //if the number is less than 100000 and has a odd sum of digits it will output the following

            }

            else {

                cout << num << "\n";  //if it has none of the other specifications it will just output all the prime numbers until the user inputted range

            }

        }
    }
}


int main() {

    input_output();   //calls the function

}